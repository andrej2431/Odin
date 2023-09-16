#ifndef ODIN_DEVICE_HPP
#define ODIN_DEVICE_HPP

#include "portaudio.h"
#include "AudioException.hpp"
#include <string>

constexpr framesPerBuffer = 

class Device {
public:
    explicit Device(const PaDeviceInfo *deviceInfo) : deviceInfo_(deviceInfo) {
        if (isInputDevice()) {
            inputParameters_.device = id();
            inputParameters_.channelCount = inputChannelCount();
            inputParameters_.sampleFormat = paFloat32;
            inputParameters_.hostApiSpecificStreamInfo = nullptr;
            inputParameters_.suggestedLatency = deviceInfo_->defaultLowInputLatency;

        }

        if (isOutputDevice()) {
            outputParameters_.device = id();
            outputParameters_.channelCount = outputChannelCount();
            outputParameters_.sampleFormat = paFloat32;
            outputParameters_.hostApiSpecificStreamInfo = nullptr;
            outputParameters_.suggestedLatency = deviceInfo_->defaultLowOutputLatency;
        }

        const PaStreamParameters *inputParametersPtr = isInputDevice() ? &inputParameters_ : nullptr;
        const PaStreamParameters *outputParametersPtr = isOutputDevice() ? &outputParameters_ : nullptr;
        double sampleRate = deviceInfo_->defaultSampleRate;

        PaError err = Pa_IsFormatSupported(inputParametersPtr, outputParametersPtr, sampleRate);
        if(err != paNoError){
            throw AudioException(Pa_GetErrorText(err));
        }

        Pa_OpenStream(&stream_, inputParametersPtr, outputParametersPtr, sampleRate, )

    }

    int playCallback(const void *input,
                     void *output,
                     unsigned long frameCount,
                     const PaStreamCallbackTimeInfo* timeInfo,
                     PaStreamCallbackFlags statusFlags,
                     void *userData){

    }

    int id() {
        for (int i = 0; i < Pa_GetDeviceCount(); ++i) {
            if (Pa_GetDeviceInfo(i) == deviceInfo_) {
                return i;
            }
        }

        return -1;
    }

    std::string name() const { return deviceInfo_->name; }

    std::string nickname() const { return nickname_; }

    bool isInputDevice() const { return deviceInfo_->maxInputChannels > 0; }

    bool isOutputDevice() const { return deviceInfo_->maxOutputChannels > 0; }

    int inputChannelCount() const { return deviceInfo_->maxInputChannels; }

    int outputChannelCount() const { return deviceInfo_->maxOutputChannels; }


private:
    std::string nickname_;
    const PaDeviceInfo *deviceInfo_;
    PaStreamParameters inputParameters_;
    PaStreamParameters outputParameters_;
    PaStream* stream_;

};


#endif //ODIN_DEVICE_HPP
