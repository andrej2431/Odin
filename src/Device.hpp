#ifndef ODIN_DEVICE_HPP
#define ODIN_DEVICE_HPP

#include "portaudio.h"
#include "AudioException.hpp"
#include <string>
#include <iostream>

constexpr int framesPerBuffer = 256;

class Device {
public:
    explicit Device(const PaDeviceInfo *deviceInfo);

    ~Device() noexcept;

    static int routeCallbackToMemberFunction(const void *input,
                     void *output,
                     unsigned long frameCount,
                     const PaStreamCallbackTimeInfo* timeInfo,
                     PaStreamCallbackFlags statusFlags,
                     void *instancePtr){
        if(auto self = reinterpret_cast<Device*>(instancePtr))
            return self->callback(input, output, frameCount, timeInfo, statusFlags);
        return 0;
    }

    int callback(const void *input,
                 void *output,
                 unsigned long frameCount,
                 const PaStreamCallbackTimeInfo* timeInfo,
                 PaStreamCallbackFlags statusFlags){
        std::cout << "callback" << std::endl;
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
