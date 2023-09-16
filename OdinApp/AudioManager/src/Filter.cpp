#include "Filter.hpp"


void Filter::clipBuffer(float *buffer, int bufferSize) {
    for (int i = 0; i < bufferSize; ++i) {

        if (buffer[i] < sampleMinSize) {
            buffer[i] = sampleMinSize;

        } else if (buffer[i] > sampleMaxSize) {
            buffer[i] = sampleMaxSize;
        }
    }
}

void VolumeFilter::apply(float *buffer, int bufferSize) {
    for(int i = 0; i < bufferSize; ++i){
        buffer[i] *= volumeMultiplier_;
    }
    clipBuffer(buffer, bufferSize);
}