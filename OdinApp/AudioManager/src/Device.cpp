#include "Device.hpp"
#include <iostream>
Device::Device(const PaDeviceInfo *deviceInfo) : deviceInfo_(deviceInfo),
                                                 inputParameters_(),
                                                 outputParameters_(),
                                                 stream_(),
                                                 filters_() {
    std::cout << "creating device " << deviceInfo->name << std::endl;
    if (isInputDevice()) {
        inputParameters_.device = deviceId();
        inputParameters_.channelCount = inputChannelCount();
        inputParameters_.sampleFormat = paFloat32;
        inputParameters_.hostApiSpecificStreamInfo = nullptr;
        inputParameters_.suggestedLatency = deviceInfo_->defaultLowInputLatency;

    }

    if (isOutputDevice()) {
        outputParameters_.device = deviceId();
        outputParameters_.channelCount = outputChannelCount();
        outputParameters_.sampleFormat = paFloat32;
        outputParameters_.hostApiSpecificStreamInfo = nullptr;
        outputParameters_.suggestedLatency = deviceInfo_->defaultLowOutputLatency;
    }

    const PaStreamParameters *inputParametersPtr = isInputDevice() ? &inputParameters_ : nullptr;
    const PaStreamParameters *outputParametersPtr = isOutputDevice() ? &outputParameters_ : nullptr;
    double sampleRate = deviceInfo_->defaultSampleRate;

    PaError err = Pa_IsFormatSupported(inputParametersPtr, outputParametersPtr, sampleRate);
    if (err != paNoError) {
        throw AudioException(Pa_GetErrorText(err));
    }

    err = Pa_OpenStream(&stream_,
                        inputParametersPtr,
                        outputParametersPtr,
                        sampleRate,
                        64,
                        paNoFlag,
                        &routeCallbackToMemberFunction,
                        this);

    if (err != paNoError) {
        throw AudioException(Pa_GetErrorText(err));
    }
}

Device::~Device() noexcept {
    Pa_CloseStream(stream_);
}

int Device::deviceId() {
    for (int i = 0; i < Pa_GetDeviceCount(); ++i) {
        if (Pa_GetDeviceInfo(i) == deviceInfo_) {
            return i;
        }
    }

    return -1;
}

int Device::routeCallbackToMemberFunction(const void *input,
                                          void *output,
                                          unsigned long frameCount,
                                          const PaStreamCallbackTimeInfo *timeInfo,
                                          PaStreamCallbackFlags statusFlags,
                                          void *instancePtr) {
    if (auto self = reinterpret_cast<Device *>(instancePtr))
        return self->callback(input, output, frameCount, timeInfo, statusFlags);
    return 0;
}

int Device::callback(const void *input,
                     void *output,
                     unsigned long frameCount,
                     const PaStreamCallbackTimeInfo *timeInfo,
                     PaStreamCallbackFlags statusFlags) {
    return 0;
}



