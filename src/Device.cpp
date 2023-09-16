#include "Device.hpp"

Device::Device(const PaDeviceInfo *deviceInfo) : deviceInfo_(deviceInfo),
                                                 inputParameters_(),
                                                 outputParameters_(),
                                                 stream_() {
    std::cout << "\ncreating device " << deviceInfo->name << std::endl;

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
    std::cout << (isInputDevice() ? "Input device " : "") << (isOutputDevice() ? "Output device" : "") << std::endl;
    float sampleRate = deviceInfo_->defaultSampleRate;
    std::cout << "sample rate: " << sampleRate << std::endl;


    PaError err = Pa_IsFormatSupported(inputParametersPtr, outputParametersPtr, sampleRate);
    if (err != paNoError) {
        std::cout << "unsupported format" << std::endl;
        throw AudioException(Pa_GetErrorText(err));
    }

    err = Pa_OpenStream(&stream_,
                  inputParametersPtr,
                  outputParametersPtr,
                  paFloat32,
                  sampleRate,
                  64,
                  &routeCallbackToMemberFunction,
                  this);

    if(err != paNoError){
        throw AudioException(Pa_GetErrorText(err));
    }
}

Device::~Device() noexcept {
    Pa_CloseStream(stream_);
}
