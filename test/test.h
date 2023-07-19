#ifndef ROCNIKOVY_PROJEKT_TEST_H
#define ROCNIKOVY_PROJEKT_TEST_H

#include "portaudio.h"

typedef struct {
    float left_phase;
    float right_phase;
}
        paTestData;

int patestCallback(void const *inputBuffer, void *outputBuffer,
                          unsigned long framesPerBuffer,
                          PaStreamCallbackTimeInfo const *timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData);

#endif //ROCNIKOVY_PROJEKT_TEST_H