#ifndef ODIN_AUDIOMANAGER_HPP
#define ODIN_AUDIOMANAGER_HPP

#include <vector>
#include "portaudio.h"
#include "AudioException.hpp"
#include "Device.hpp"


class AudioManager {
public:
    AudioManager();

    ~AudioManager();

    std::size_t getDeviceCount();

    static const PaDeviceInfo *getDeviceInfo(int deviceNumber);

    const PaHostApiInfo *getHostApiInfo() const;

    void updateDevices();

    std::vector<Device> &getDevices() { return devices_; }

private:
    PaError err_;
    PaHostApiIndex hostApiIndex_;
    std::vector<Device> devices_;
};


#endif //ODIN_AUDIOMANAGER_HPP
