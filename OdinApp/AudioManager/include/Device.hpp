#ifndef ODIN_DEVICE_HPP
#define ODIN_DEVICE_HPP

#include "portaudio.h"
#include "AudioException.hpp"
#include "Filter.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <memory>

constexpr int framesPerBuffer = 256;

class Device {
public:
    explicit Device(const PaDeviceInfo *deviceInfo);

    ~Device() noexcept;

    static int routeCallbackToMemberFunction(const void *input,
                                             void *output,
                                             unsigned long frameCount,
                                             const PaStreamCallbackTimeInfo *timeInfo,
                                             PaStreamCallbackFlags statusFlags,
                                             void *instancePtr);

    int callback(const void *input,
                 void *output,
                 unsigned long frameCount,
                 const PaStreamCallbackTimeInfo *timeInfo,
                 PaStreamCallbackFlags statusFlags);

    int deviceId();

    void setNickname(const std::string &newNickname) { nickname_ = newNickname; }

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
    PaStream *stream_;

    float buffer_[framesPerBuffer];
    std::vector<std::shared_ptr<Filter>> filters_;
};


#endif //ODIN_DEVICE_HPP
