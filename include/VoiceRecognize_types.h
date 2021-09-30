//
// File: VoiceRecognize_types.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 23-Oct-2020 20:33:52
//
#ifndef VOICERECOGNIZE_TYPES_H
#define VOICERECOGNIZE_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
#include "cnn_api.hpp"
#include "MWTargetNetworkImpl.hpp"

// Type Definitions
class FFTImplementationCallback
{
 public:
  static void doHalfLengthRadix2(const double x[39200], int xoffInit, creal_T y
    [512]);
};

class b_trainedNet_0
{
 public:
  void allocate();
  void postsetup();
  b_trainedNet_0();
  void deallocate();
  void setSize();
  void resetState();
  void setup();
  void predict();
  void cleanup();
  float *getLayerOutput(int layerIndex, int portIndex);
  float *getInputDataPointer();
  float *getOutputDataPointer();
  ~b_trainedNet_0();
  int batchSize;
  int numLayers;
  MWTensor *inputTensor;
  MWTensor *outputTensor;
  MWCNNLayer *layers[15];
  float *inputData;
  float *outputData;
 private:
  MWTargetNetworkImpl *targetImpl;
};

struct emxArray_char_T_1x11
{
  char data[11];
  int size[2];
};

struct cell_wrap_0
{
  emxArray_char_T_1x11 f1;
};

struct emxArray_cell_wrap_0_1
{
  cell_wrap_0 data[1];
  int size[1];
};

class c_matlab_internal_coder_categor
{
 public:
  void init(const cell_wrap_0 inputData[1]);
  void cellstr(cell_wrap_0 b[1]) const;
 protected:
  unsigned char codes;
  emxArray_cell_wrap_0_1 categoryNames;
};

struct cell_wrap_4
{
  unsigned int f1[8];
};

class dsp_private_AsyncBuffercgHelper
{
 public:
  dsp_private_AsyncBuffercgHelper *init();
  int step();
  void setupAndReset();
  void b_setup();
  int write();
  void matlabCodegenDestructor();
  void release();
  void releaseWrapper();
  ~dsp_private_AsyncBuffercgHelper();
  bool matlabCodegenIsDeleted;
 protected:
  int isInitialized;
  int CumulativeOverrun;
  int ReadPointer;
  int WritePointer;
 private:
  bool isSetupComplete;
  cell_wrap_4 inputVarSize[1];
  int NumChannels;
};

class dsp_private_AsyncBuffercg
{
 public:
  dsp_private_AsyncBuffercg *init();
  void write();
  void matlabCodegenDestructor();
  ~dsp_private_AsyncBuffercg();
  bool matlabCodegenIsDeleted;
  dsp_private_AsyncBuffercgHelper pBuffer;
};

#endif

//
// File trailer for VoiceRecognize_types.h
//
// [EOF]
//
