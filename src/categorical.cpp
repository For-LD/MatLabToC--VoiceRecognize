//
// File: categorical.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 23-Oct-2020 20:33:52
//

// Include Files
#include "categorical.h"
#include "DeepLearningNetwork.h"
#include "VoiceRecognize.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const cell_wrap_0 inputData[1]
// Return Type  : void
//
void c_matlab_internal_coder_categor::init(const cell_wrap_0 inputData[1])
{
  int b_j1;
  static const bool bv[128] = { false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false
  };

  int j2;
  emxArray_cell_wrap_0_1 tempValueSet;
  int loop_ub;
  int i;
  emxArray_cell_wrap_0_1 valueSet;
  b_j1 = 0;
  while ((b_j1 + 1 <= inputData[0].f1.size[1]) && bv[static_cast<unsigned char>
         (inputData[0].f1.data[b_j1])] && (!(inputData[0].f1.data[b_j1] ==
           '\x00'))) {
    b_j1++;
  }

  j2 = inputData[0].f1.size[1] - 1;
  while ((j2 + 1 > 0) && bv[static_cast<unsigned char>(inputData[0].f1.data[j2])]
         && (!(inputData[0].f1.data[j2] == '\x00'))) {
    j2--;
  }

  if (b_j1 + 1 > j2 + 1) {
    b_j1 = 0;
    j2 = -1;
  }

  tempValueSet.data[0].f1.size[0] = 1;
  loop_ub = j2 - b_j1;
  tempValueSet.data[0].f1.size[1] = loop_ub + 1;
  for (i = 0; i <= loop_ub; i++) {
    tempValueSet.data[0].f1.data[i] = inputData[0].f1.data[b_j1 + i];
  }

  j2 = 1;
  if (tempValueSet.data[0].f1.size[1] == 0) {
    j2 = 0;
    valueSet.size[0] = 0;
  } else {
    valueSet.size[0] = 1;
    valueSet.data[0] = tempValueSet.data[0];
  }

  if (valueSet.size[0] != 0) {
    this->categoryNames.size[0] = 1;
    loop_ub = valueSet.data[0].f1.size[1];
    this->categoryNames.data[0].f1.size[0] = 1;
    this->categoryNames.data[0].f1.size[1] = valueSet.data[0].f1.size[1];
    for (i = 0; i < loop_ub; i++) {
      this->categoryNames.data[0].f1.data[i] = valueSet.data[0].f1.data[i];
    }
  } else {
    this->categoryNames.size[0] = 0;
  }

  this->codes = static_cast<unsigned char>(j2);
}

//
// File trailer for categorical.cpp
//
// [EOF]
//
