#include "AudioManager.hpp"
#include <iostream>

AudioManager::AudioManager() {
    err_ = Pa_Initialize();
    if (err_ != paNoError) {
        throw AudioException(Pa_GetErrorText(err_));
    }

    PaHostApiTypeId hostApiTypeId;

#ifdef __linux__
    hostApiTypeId = paALSA;
#else
#ifdef __WIN64
    hostApiTypeId = paWDMKS;
#else
    throw AudioException("Unsupported operating system");
#endif
#endif
    hostApiIndex_ = Pa_HostApiTypeIdToHostApiIndex(hostApiTypeId);

    if (hostApiIndex_ < 0) {
        throw AudioException("No supported audio host api installed.");
    }

    updateDevices();
}

void AudioManager::updateDevices() {
    auto hostApiInfo = Pa_GetHostApiInfo(hostApiIndex_);
    for (int i = 0; i < hostApiInfo->deviceCount; ++i) {
        auto deviceIndex = Pa_HostApiDeviceIndexToDeviceIndex(hostApiIndex_, i);
        auto deviceInfo = Pa_GetDeviceInfo(deviceIndex);
        try {
            devices_.emplace_back(deviceInfo);
        } catch (AudioException &ex) {
            std::cout << ex.what() << std::endl;
        }
    }
}

AudioManager::~AudioManager() {
    Pa_Terminate();
}

const PaHostApiInfo *AudioManager::getHostApiInfo() const {
    auto hostApiInfo = Pa_GetHostApiInfo(hostApiIndex_);
    if (hostApiInfo == nullptr) {
        throw AudioException("Unable to retrieve audio host api info.");
    }
    return hostApiInfo;
}

std::size_t AudioManager::getDeviceCount() {
    return devices_.size();
}

const PaDeviceInfo *AudioManager::getDeviceInfo(int deviceNumber) {
    auto deviceInfo = Pa_GetDeviceInfo(deviceNumber);
    if (deviceInfo == nullptr) {
        throw AudioException("Unable to retrieve device info.");
    }

    return deviceInfo;
}