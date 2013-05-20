#ifndef __StompBox_h__
#define __StompBox_h__

class AudioInputBuffer {
public:
  virtual void getSamples(int from, int length, short* data) = 0;
  virtual void getSamples(int from, int length, float* data) = 0;
  virtual int getSize() = 0;
};

class AudioOutputBuffer {
public:    
  virtual void setSamples(int from, int length, short* data) = 0;
  virtual void setSamples(int from, int length, float* data) = 0;
  virtual int getSize() = 0;
};

#define PARAMETER_A 0
#define PARAMETER_B 1
#define PARAMETER_C 2
#define PARAMETER_D 3
#define PARAMETER_E 4

class Patch {
protected:
  uint16_t blocksize;
  uint16_t samplerate;
public:
  /** sets @param value to a value between 0 and 4096 */
  void getParameterValue(int pid, int &value);
  /** sets @param value to a value between 0.0 and 1.0 */
  void getParameterValue(int pid, float &value);
  int getBlockSize();
  double getSampleRate();
public:
  virtual void processAudio(AudioInputBuffer &input, AudioOutputBuffer &output) = 0;
};

#endif // __StompBox_h__
