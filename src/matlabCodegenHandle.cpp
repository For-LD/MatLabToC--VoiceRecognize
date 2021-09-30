//
// File: matlabCodegenHandle.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 23-Oct-2020 20:33:52
//

// Include Files
#include "matlabCodegenHandle.h"
#include "DeepLearningNetwork.h"
#include "SystemCore.h"
#include "VoiceRecognize.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
dsp_private_AsyncBuffercg::~dsp_private_AsyncBuffercg()
{
  this->matlabCodegenDestructor();
}

//
// Arguments    : void
// Return Type  : void
//
dsp_private_AsyncBuffercgHelper::~dsp_private_AsyncBuffercgHelper()
{
  this->matlabCodegenDestructor();
}

//
// Arguments    : void
// Return Type  : void
//
void dsp_private_AsyncBuffercg::matlabCodegenDestructor()
{
  if (!this->matlabCodegenIsDeleted) {
    this->matlabCodegenIsDeleted = true;
  }
}

//
// Arguments    : void
// Return Type  : void
//
void dsp_private_AsyncBuffercgHelper::matlabCodegenDestructor()
{
  if (!this->matlabCodegenIsDeleted) {
    this->matlabCodegenIsDeleted = true;
    this->release();
  }
}

//
// File trailer for matlabCodegenHandle.cpp
//
// [EOF]
//
