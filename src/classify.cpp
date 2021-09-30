//
// File: classify.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 23-Oct-2020 20:33:52
//

// Include Files
#include "classify.h"
#include "DeepLearningNetwork.h"
#include "VoiceRecognize.h"
#include "categorical.h"
#include "matlabCodegenHandle.h"
#include "predict.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : b_trainedNet_0 *obj
//                const double indata[3920]
//                c_matlab_internal_coder_categor *labels
//                float scores[12]
// Return Type  : void
//
void DeepLearningNetwork_classify(b_trainedNet_0 *obj, const double indata[3920],
  c_matlab_internal_coder_categor *labels, float scores[12])
{
  int idx;
  int k;
  int i;
  int n;
  cell_wrap_0 labelCells[1];
  static const char classNames[120] = { 'd', 'g', 'l', 'n', 'o', 'o', 'r', 's',
    'u', 'y', 'u', 'b', 'o', 'o', 'e', 'o', 'f', 'n', 'i', 't', 'p', 'e', 'n',
    'a', 'w', '\x00', 'f', '\x00', 'f', '\x00', 'g', 'o', '\x00', 's', 'k', 'c',
    'n', '\x00', 't', '\x00', '\x00', '\x00', 'h', 'p', '\x00', '\x00', 'n', 'k',
    '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', 't', '\x00', '\x00', '\x00',
    'o', 'g', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00',
    '\x00', '\x00', 'w', 'r', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00',
    '\x00', '\x00', '\x00', '\x00', 'n', 'o', '\x00', '\x00', '\x00', '\x00',
    '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', 'u', '\x00', '\x00',
    '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', 'n',
    '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00',
    '\x00', '\x00', 'd' };

  char v_data[10];
  DeepLearningNetwork_predict(obj, indata, scores);
  if (!rtIsNaNF(scores[0])) {
    idx = 1;
  } else {
    bool exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!rtIsNaNF(scores[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    idx = 1;
  } else {
    float ex;
    ex = scores[idx - 1];
    i = idx + 1;
    for (k = i; k < 13; k++) {
      float f;
      f = scores[k - 1];
      if (ex < f) {
        ex = f;
        idx = k;
      }
    }
  }

  n = 0;
  i = -1;
  for (k = 0; k < 10; k++) {
    char c;
    c = classNames[(idx + 12 * k) - 1];
    if (c != 0) {
      n++;
      i++;
      v_data[i] = c;
    }
  }

  labelCells[0].f1.size[0] = 1;
  labelCells[0].f1.size[1] = n;
  for (i = 0; i < n; i++) {
    labelCells[0].f1.data[i] = v_data[i];
  }

  labels->init(labelCells);
}

//
// File trailer for classify.cpp
//
// [EOF]
//
