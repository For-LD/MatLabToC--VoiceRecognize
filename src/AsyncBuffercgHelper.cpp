//
// File: AsyncBuffercgHelper.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 23-Oct-2020 20:33:52
//

// Include Files
#include "AsyncBuffercgHelper.h"
#include "DeepLearningNetwork.h"
#include "SystemCore.h"
#include "VoiceRecognize.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : dsp_private_AsyncBuffercgHelper *
//
dsp_private_AsyncBuffercgHelper *dsp_private_AsyncBuffercgHelper::init()
{
  dsp_private_AsyncBuffercgHelper *obj;
  obj = this;
  obj->NumChannels = -1;
  obj->isInitialized = 0;
  obj->matlabCodegenIsDeleted = false;
  this->setupAndReset();
  return obj;
}

//
// Arguments    : void
// Return Type  : int
//
int dsp_private_AsyncBuffercgHelper::write()
{
  int overrun;
  int wPtr;
  int rPtr;
  int qY;
  int c;
  wPtr = this->WritePointer;
  rPtr = this->ReadPointer;
  overrun = 0;
  if (wPtr > 2147467647) {
    qY = MAX_int32_T;
  } else {
    qY = wPtr + 16000;
  }

  c = qY - 1;
  if (c > 16001) {
    c -= 16001;
    if (wPtr <= rPtr) {
      if (rPtr < -2147467646) {
        qY = MAX_int32_T;
      } else {
        qY = 16001 - rPtr;
      }

      if (qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY++;
      }

      if ((qY < 0) && (c < MIN_int32_T - qY)) {
        overrun = MIN_int32_T;
      } else if ((qY > 0) && (c > MAX_int32_T - qY)) {
        overrun = MAX_int32_T;
      } else {
        overrun = qY + c;
      }
    } else {
      if (rPtr <= c) {
        if (rPtr < c - MAX_int32_T) {
          qY = MAX_int32_T;
        } else {
          qY = c - rPtr;
        }

        if (qY > 2147483646) {
          overrun = MAX_int32_T;
        } else {
          overrun = qY + 1;
        }
      }
    }
  } else {
    if ((wPtr <= rPtr) && (rPtr <= c)) {
      if ((c >= 0) && (rPtr < c - MAX_int32_T)) {
        qY = MAX_int32_T;
      } else if ((c < 0) && (rPtr > c - MIN_int32_T)) {
        qY = MIN_int32_T;
      } else {
        qY = c - rPtr;
      }

      if (qY > 2147483646) {
        overrun = MAX_int32_T;
      } else {
        overrun = qY + 1;
      }
    }
  }

  if (c + 1 > 16001) {
    wPtr = 1;
  } else {
    wPtr = c + 1;
  }

  if (overrun != 0) {
    rPtr = wPtr;
  }

  qY = this->CumulativeOverrun;
  if ((qY < 0) && (overrun < MIN_int32_T - qY)) {
    qY = MIN_int32_T;
  } else if ((qY > 0) && (overrun > MAX_int32_T - qY)) {
    qY = MAX_int32_T;
  } else {
    qY += overrun;
  }

  this->CumulativeOverrun = qY;
  this->WritePointer = wPtr;
  this->ReadPointer = rPtr;
  return overrun;
}

//
// File trailer for AsyncBuffercgHelper.cpp
//
// [EOF]
//
