#include "StompBox.h"

class CopyPatch : public Patch {
public:
  void processAudio(AudioInputBuffer &input, AudioOutputBuffer &output){
    int size = input.getSize();
    float* buf = input.getFloats();
    output.setFloats(buf);
  }
};

class GainPatch : public Patch {
public:
  void processAudio(AudioInputBuffer &input, AudioOutputBuffer &output){
    int size = input.getSize();
    float gain = getParameterValue(PARAMETER_A);
    float* buf = input.getFloats();
    for(int i=0; i<size; ++i)
      buf[i] = gain*buf[i];
    output.setFloats(buf);
  }
};
