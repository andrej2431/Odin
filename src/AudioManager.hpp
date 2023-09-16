#ifndef ODIN_AUDIOMANAGER_HPP
#define ODIN_AUDIOMANAGER_HPP

#include <vector>
#include <portaudio.h>
#include "AudioException.hpp"
#include "Device.hpp"


class AudioManager {
public:
    AudioManager();
    ~AudioManager();

    int getDeviceCount();

    static const PaDeviceInfo *getDeviceInfo(int deviceNumber);

    const PaHostApiInfo *getHostApiInfo() const;

    void updateDevices();

private:
    PaError err_;
    PaHostApiIndex hostApiIndex_;
    std::vector<Device> devices_;
};


#endif //ODIN_AUDIOMANAGER_HPP
