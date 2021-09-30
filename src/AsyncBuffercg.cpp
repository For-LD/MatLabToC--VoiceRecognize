//
// File: AsyncBuffercg.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 23-Oct-2020 20:33:52
//

// Include Files
#include "AsyncBuffercg.h"
#include "AsyncBuffercgHelper.h"
#include "DeepLearningNetwork.h"
#include "SystemCore.h"
#include "VoiceRecognize.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : dsp_private_AsyncBuffercg *
//
dsp_private_AsyncBuffercg *dsp_private_AsyncBuffercg::init()
{
  dsp_private_AsyncBuffercg *obj;
  obj = this;
  obj->pBuffer.init();
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

//
// Arguments    : void
// Return Type  : void
//
void dsp_private_AsyncBuffercg::write()
{
  this->pBuffer.step();
}

//
// File trailer for AsyncBuffercg.cpp
//
// [EOF]
//
