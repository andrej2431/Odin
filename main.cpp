#include <iostream>
#include <math.h>
#include <vector>
#include <string>

#include "src/AudioException.hpp"
#include "src/AudioManager.hpp"
#include "portaudio.h"

#define    NUM_SECONDS   (3)
#define    SAMPLE_RATE   (44100)
#define    FRAMES_PER_BUFFER   (1024)
#define    TABLE_SIZE   (200)


typedef struct {
    float sine[TABLE_SIZE];
    int left_phase;
    int right_phase;
    char message[20] = "";
}
        paTestData;

static int patestCallback(const void *inputBuffer, void *outputBuffer,
                          unsigned long framesPerBuffer,
                          const PaStreamCallbackTimeInfo *timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData) {
    paTestData *data = (paTestData *) userData;
    float *out = (float *) outputBuffer;
    unsigned long i;

    (void) timeInfo; /* Prevent unused variable warnings. */
    (void) statusFlags;
    (void) inputBuffer;

    return paContinue;

    for (i = 0; i < framesPerBuffer; i++) {
        *out++ = data->sine[data->left_phase];  /* left */
        *out++ = data->sine[data->right_phase];  /* right */
        data->left_phase += 1;
        if (data->left_phase >= TABLE_SIZE) data->left_phase -= TABLE_SIZE;
        data->right_phase += 3; /* higher pitch so we can distinguish left and right. */
        if (data->right_phase >= TABLE_SIZE) data->right_phase -= TABLE_SIZE;
    }
    return paContinue;
}

static void StreamFinished(void *userData) {
    auto *data = (paTestData *) userData;
    printf("Stream Completed: %s\n", data->message);
    std::cout << "END" << std::endl;
}

void populate_data(paTestData &data) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        data.sine[i] = (float) sin(((double) i / (double) TABLE_SIZE) * M_PI * 2.);
    }
    data.left_phase = data.right_phase = 0;
    std::cout << "data populated" << std::endl;
}

std::vector<const PaDeviceInfo *> get_device_infos() {
    std::vector<const PaDeviceInfo *> device_infos;
    int device_count = Pa_GetDeviceCount();
    for (int i = 0; i < device_count; ++i) {
        device_infos.push_back(Pa_GetDeviceInfo(i));
    }

    return device_infos;
}


void populateOutputParameters(PaStreamParameters &outputParameters) {

    outputParameters.device = 5;
    outputParameters.channelCount = 2;       /* MONO output */
    outputParameters.sampleFormat = paFloat32; /* 32 bit floating point output */
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = nullptr;
}

void test_stuff() {
    int hostApiIndex = Pa_HostApiTypeIdToHostApiIndex(PaHostApiTypeId::paALSA);
    if(hostApiIndex < 0) {
        throw AudioException("ALSA not found");
    }
    auto hostApiInfo = Pa_GetHostApiInfo(hostApiIndex);
    for(int i = 0; i < hostApiInfo->deviceCount; ++i){
        int deviceIndex = Pa_HostApiDeviceIndexToDeviceIndex(hostApiIndex, i);
        auto deviceInfo = Pa_GetDeviceInfo(deviceIndex);
        std::cout << "ALSA device: " << deviceInfo->name << std::endl;
    }
}

PaError play_sound() {
    PaStream *stream;

    test_stuff();

    paTestData data;
    populate_data(data);

    PaStreamParameters outputParameters;
    populateOutputParameters(outputParameters);

    std::cout << "Default output device: " << outputParameters.device << " no device: "
              << paNoDevice << std::endl;

    PaError err;
    err = Pa_OpenStream(
            &stream,
            nullptr, /* no input */
            &outputParameters,
            SAMPLE_RATE,
            FRAMES_PER_BUFFER,
            paClipOff,
            patestCallback,
            &data);
    if (err != paNoError) return err;

    sprintf(data.message, "No Message");
    err = Pa_SetStreamFinishedCallback(stream, &StreamFinished);
    if (err != paNoError) return err;

    err = Pa_StartStream(stream);
    if (err != paNoError) return err;

    /* Sleep for several seconds. */
    Pa_Sleep(NUM_SECONDS * 1000);

    err = Pa_StopStream(stream);
    if (err != paNoError) return err;

    err = Pa_CloseStream(stream);
    return err;
}

int main() {
    try {
        AudioManager audioManager = AudioManager();
        std::cout << "\ndeviceCount: " << audioManager.getDeviceCount() << std::endl;
        std::cout << audioManager.getHostApiInfo()->name << std::endl;
    } catch(AudioException& ex){
        std::cout << ex.what() << std::endl;
    }
}
