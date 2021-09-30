//
// File: predict.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 23-Oct-2020 20:33:52
//

// Include Files
#include "predict.h"
#include "DeepLearningNetwork.h"
#include "VoiceRecognize.h"
#include "VoiceRecognize_rtwutil.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"
#include <cstring>

// Type Definitions
struct cell_wrap_29
{
  float f1[12];
};

// Function Definitions

//
// Arguments    : void
// Return Type  : int *
//

//
// Arguments    : b_trainedNet_0 *obj
//                const double in[3920]
//                float varargout_1[12]
// Return Type  : void
//
void DeepLearningNetwork_predict(b_trainedNet_0 *obj, const double in[3920],
  float varargout_1[12])
{
  int i;
  float miniBatchT[3920];
  cell_wrap_29 outputsMiniBatch[1];
  for (i = 0; i < 40; i++) {
    for (int i1 = 0; i1 < 98; i1++) {
      miniBatchT[i1 + 98 * i] = static_cast<float>(in[i + 40 * i1]);
    }
  }

  memcpy(obj->getInputDataPointer(), miniBatchT, obj->layers[1]->getOutputTensor
         (0)->getNumElements() * sizeof(float));
  obj->predict();
  memcpy(outputsMiniBatch[0].f1, obj->getLayerOutput(14, 0), obj->layers[14]
         ->getOutputTensor(0)->getNumElements() * sizeof(float));
  for (i = 0; i < 12; i++) {
    varargout_1[i] = outputsMiniBatch[0].f1[i];
  }
}

//
// File trailer for predict.cpp
//
// [EOF]
//
