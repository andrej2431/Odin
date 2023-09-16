#ifndef ODIN_AUDIOMANAGER_HPP
#define ODIN_AUDIOMANAGER_HPP

#include <vector>
#include <portaudio.h>
#include "AudioException.hpp"
class Device {

};

class AudioManager {
public:
    AudioManager();
    ~AudioManager();

    int getDeviceCount();

    const PaDeviceInfo* getDeviceInfo(int deviceNumber);



private:
    PaError err_;
};


#endif //ODIN_AUDIOMANAGER_HPP
