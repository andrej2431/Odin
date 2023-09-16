#include "AudioManager.hpp"

AudioManager::AudioManager() {
    err_ = Pa_Initialize();
    if (err_ != paNoError) {
        throw AudioException(Pa_GetErrorText(err_));
    }
}


AudioManager::~AudioManager() {
    Pa_Terminate();
}

int AudioManager::getDeviceCount() {
    int numDevices = Pa_GetDeviceCount();
    if (numDevices < 0) {
        err_ = numDevices;
        throw AudioException("Pa_GetDeviceCount() returned " + std::to_string(numDevices));
    }

    return numDevices;
}

const PaDeviceInfo *AudioManager::getDeviceInfo(int deviceNumber) {
    auto deviceInfo = Pa_GetDeviceInfo(deviceNumber);
    if (deviceInfo == nullptr) {
        throw AudioException("Pa_GetDeviceInfo(" + std::to_string(deviceNumber) + ") returned nullptr");
    }

    return deviceInfo;
}


