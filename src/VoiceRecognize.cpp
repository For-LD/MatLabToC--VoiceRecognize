//
// File: VoiceRecognize.cpp
//
// MATLAB Coder version            : 5.0
//

// Include Files
#include "VoiceRecognize.h"
#include "AsyncBuffercg.h"
#include "DeepLearningNetwork.h"
#include "VoiceRecognize_data.h"
#include "VoiceRecognize_initialize.h"
#include "cellstr.h"
#include "classify.h"
#include "matlabCodegenHandle.h"
#include "melSpectrogram.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <iostream>

// Function Definitions

//
// Arguments    : const double x[16000]
//                cell_wrap_0 out[1]
// Return Type  : void
//
void VoiceRecognize(const double x[16000], cell_wrap_0 out[1])
{
  dsp_private_AsyncBuffercg audioBuffer;
  b_trainedNet_0 trainedNet;
  double spec[3920];
  c_matlab_internal_coder_categor YPredicted;
  float probs[12];
  if (!isInitialized_VoiceRecognize) {
    VoiceRecognize_initialize();
  }

  audioBuffer.pBuffer.matlabCodegenIsDeleted = true;
  audioBuffer.matlabCodegenIsDeleted = true;

  // persistent trainedNet;
  DeepLearningNetwork_setup(&trainedNet);
  audioBuffer.init();
  audioBuffer.write();
  melSpectrogram(x, spec);
  for (int k = 0; k < 3920; k++) {
    spec[k] = std::log10(spec[k] + 1.0E-6);
  }

  DeepLearningNetwork_classify(&trainedNet, spec, &YPredicted, probs);
  for (float prob : probs)
      std::cout << prob << " ";
  std::cout << std::endl;
  YPredicted.cellstr(out);
  audioBuffer.matlabCodegenDestructor();
  audioBuffer.pBuffer.matlabCodegenDestructor();
}

//
// File trailer for VoiceRecognize.cpp
//
// [EOF]
//
