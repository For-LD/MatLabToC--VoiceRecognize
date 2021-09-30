//
// File: SystemCore.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 23-Oct-2020 20:33:52
//

// Include Files
#include "SystemCore.h"
#include "AsyncBuffercgHelper.h"
#include "DeepLearningNetwork.h"
#include "VoiceRecognize.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void dsp_private_AsyncBuffercgHelper::b_setup()
{
  this->isSetupComplete = false;
  this->isInitialized = 1;
  this->NumChannels = 1;
  this->isSetupComplete = true;
}

//
// Arguments    : void
// Return Type  : void
//
void dsp_private_AsyncBuffercgHelper::releaseWrapper()
{
  if (this->isSetupComplete) {
    this->ReadPointer = 1;
    this->WritePointer = 2;
    this->CumulativeOverrun = 0;
    this->NumChannels = -1;
  }
}

//
// Arguments    : void
// Return Type  : void
//
void dsp_private_AsyncBuffercgHelper::release()
{
  if (this->isInitialized == 1) {
    this->isInitialized = 2;
    this->releaseWrapper();
  }
}

//
// Arguments    : void
// Return Type  : void
//
void dsp_private_AsyncBuffercgHelper::setupAndReset()
{
  this->b_setup();
  this->ReadPointer = 1;
  this->WritePointer = 2;
  this->CumulativeOverrun = 0;
}

//
// Arguments    : void
// Return Type  : int
//
int dsp_private_AsyncBuffercgHelper::step()
{
  return this->write();
}

//
// File trailer for SystemCore.cpp
//
// [EOF]
//
