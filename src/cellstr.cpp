//
// File: cellstr.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 23-Oct-2020 20:33:52
//

// Include Files
#include "cellstr.h"
#include "DeepLearningNetwork.h"
#include "VoiceRecognize.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"

// Type Definitions
struct emxArray_cell_wrap_0_2
{
  cell_wrap_0 data[2];
  int size[1];
};

// Function Definitions

//
// Arguments    : cell_wrap_0 b[1]
// Return Type  : void
//
void c_matlab_internal_coder_categor::cellstr(cell_wrap_0 b[1]) const
{
  emxArray_cell_wrap_0_2 names;
  int i;
  static const char cv[11] = { '<', 'u', 'n', 'd', 'e', 'f', 'i', 'n', 'e', 'd',
    '>' };

  int loop_ub;
  int i1;
  c_matlab_internal_coder_categor localCopyOfThis;
  localCopyOfThis = *this;
  names.data[0].f1.size[0] = 1;
  names.data[0].f1.size[1] = 11;
  for (i = 0; i < 11; i++) {
    names.data[0].f1.data[i] = cv[i];
  }

  i = localCopyOfThis.categoryNames.size[0];
  if (0 <= i - 1) {
    names.data[1].f1.size[0] = 1;
    names.data[1].f1.size[1] = localCopyOfThis.categoryNames.data[0].f1.size[1];
    loop_ub = localCopyOfThis.categoryNames.data[0].f1.size[0] *
      localCopyOfThis.categoryNames.data[0].f1.size[1];
    for (i = 0; i < loop_ub; i++) {
      names.data[1].f1.data[i] = localCopyOfThis.categoryNames.data[0].f1.data[i];
    }
  }

  b[0].f1.size[0] = 1;
  i = static_cast<int>(localCopyOfThis.codes + 1U);
  i1 = i;
  if (static_cast<unsigned int>(i) > 255U) {
    i1 = 255;
  }

  b[0].f1.size[1] = names.data[static_cast<unsigned char>(i1) - 1].f1.size[1];
  i1 = i;
  if (static_cast<unsigned int>(i) > 255U) {
    i1 = 255;
  }

  loop_ub = names.data[static_cast<unsigned char>(i1) - 1].f1.size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    int i2;
    i2 = i;
    if (static_cast<unsigned int>(i) > 255U) {
      i2 = 255;
    }

    b[0].f1.data[i1] = names.data[static_cast<unsigned char>(i2) - 1].f1.data[i1];
  }
}

//
// File trailer for cellstr.cpp
//
// [EOF]
//
