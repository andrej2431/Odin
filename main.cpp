#include <iostream>
#include "test/test.h"

const int SAMPLE_RATE = 44100;
const int NUM_SECONDS = 4;


int main() {
    paTestData data;
    PaStream *stream;
    PaError err;

    printf("PortAudio Test: output sawtooth wave.\n");
    /* Initialize our data for use by callback. */
    data.left_phase = data.right_phase = 0.0;
    /* Initialize library before making any other calls. */
    err = Pa_Initialize();
    if (err != paNoError) goto error;

    /* Open an audio I/O stream. */
    int numDevices;
    numDevices = Pa_GetDeviceCount();
    if (numDevices < 0) {
        printf("ERROR: Pa_CountDevices returned 0x%x\n", numDevices);
        err = numDevices;
        return err;
    }

    const PaDeviceInfo *deviceInfo;
    for (int i = 0; i < numDevices; i++) {
        deviceInfo = Pa_GetDeviceInfo(i);
        std::cout << deviceInfo->name << std::endl;
    }

    err = Pa_OpenDefaultStream(
            &stream,
            0,          /* no input channels */
            2,          /* stereo output */
            paFloat32,  /* 32 bit floating point output */
            SAMPLE_RATE,
            256,        /* frames per buffer */
            patestCallback,
            &data);

    if (err != paNoError) goto error;

    err = Pa_StartStream(stream);
    if (err != paNoError) goto error;

    /* Sleep for several seconds. */
    Pa_Sleep(0 * 1000);

    err = Pa_StopStream(stream);
    if (err != paNoError) goto error;
    err = Pa_CloseStream(stream);
    if (err != paNoError) goto error;
    Pa_Terminate();
    printf("Test finished.\n");
    return err;


    error:
    Pa_Terminate();
    std::cerr << "An error occurred while using the portaudio stream\n"
    << "Error number: %d\n" << err
    << "Error message: %s\n" <<  Pa_GetErrorText(err);
    return err;
}
