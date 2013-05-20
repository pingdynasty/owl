#include "StompBox.h"

class CopyPatch : public Patch {
public:
  void processAudio(AudioInputBuffer &input, AudioOutputBuffer &output){
    float buf[input.getSize()];
    int size = input.getSize();
    input.getSamples(0, size, buf);
    output.setSamples(0, size, buf);
  }
};

class GainPatch : public Patch {
public:
  void processAudio(AudioInputBuffer &input, AudioOutputBuffer &output){
    float buf[input.getSize()];
    int size = input.getSize();
    float gain;
    getParameterValue(PARAMETER_D, gain);
    input.getSamples(0, size, buf);
    for(int i=0; i<size; ++i)
      buf[i] = gain*buf[i];
    output.setSamples(0, size, buf);
  }
};
