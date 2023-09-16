#ifndef ODIN_FILTER_HPP
#define ODIN_FILTER_HPP

constexpr float sampleMinSize = -1;
constexpr float sampleMaxSize = 1;

class Filter {
public:
    virtual void apply(float buffer[], int bufferSize) = 0;

    static void clipBuffer(float buffer[], int bufferSize);

};


class VolumeFilter : public Filter {
public:
    explicit VolumeFilter(float volumeMultiplier = 1) : volumeMultiplier_(volumeMultiplier) {}

    void apply(float *buffer, int bufferSize) override;


private:
    float volumeMultiplier_;
};


#endif //ODIN_FILTER_HPP
