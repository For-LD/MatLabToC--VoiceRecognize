//
// File: melSpectrogram.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 23-Oct-2020 20:33:52
//

// Include Files
#include "melSpectrogram.h"
#include "DeepLearningNetwork.h"
#include "VoiceRecognize.h"
#include "designMelFilterBank.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"
#include "stft.h"

// Function Definitions

//
// Arguments    : const double x[16000]
//                double varargout_1[3920]
// Return Type  : void
//
void melSpectrogram(const double x[16000], double varargout_1[3920])
{
  static double fbank[20480];
  bool FFTLengthTooSmall;
  int i;
  static double dv[25186];
  int filterBank_tmp;
  static double filterBank[20480];
  static const double dv1[40] = { 0.022165053041906892, 0.020941113162435111,
    0.019784758450737502, 0.018692256897603794, 0.017660082572956211,
    0.016684904246293094, 0.015763574635504592, 0.014893120249361425,
    0.014070731790894891, 0.013293755090696266, 0.012559682540873331,
    0.01186614500201807, 0.01121090415706695, 0.010591845287375648,
    0.010006970447694295, 0.0094543920180161951, 0.00893232661148945,
    0.0084390893187295986, 0.0079730882699574953, 0.0075328194974127408,
    0.0071168620814609507, 0.0067238735647300475, 0.0063525856194749826,
    0.006001799954187639, 0.00567038444624125, 0.0053572694880875456,
    0.0050614445352146313, 0.00478195484472434, 0.0045178983940031975,
    0.0042684229695425669, 0.00403272341651199, 0.0038100390402094919,
    0.0035996511510020864, 0.0034008807448330665, 0.0032130863118101064,
    0.0030356617658018259, 0.0028680344883607271, 0.0027096634806591854,
    0.0025600376174746064, 0.002418673997588331 };

  double d;
  designMelFilterBank(fbank, &FFTLengthTooSmall);
  for (i = 0; i < 512; i++) {
    for (filterBank_tmp = 0; filterBank_tmp < 40; filterBank_tmp++) {
      filterBank[filterBank_tmp + 40 * i] = fbank[i + (filterBank_tmp << 9)];
    }
  }

  stft(x, dv);
  for (int b_i = 0; b_i < 40; b_i++) {
    for (i = 0; i < 512; i++) {
      filterBank_tmp = b_i + 40 * i;
      filterBank[filterBank_tmp] *= dv1[b_i];
    }

    for (i = 0; i < 98; i++) {
      d = 0.0;
      for (filterBank_tmp = 0; filterBank_tmp < 257; filterBank_tmp++) {
        d += filterBank[b_i + 40 * filterBank_tmp] * dv[filterBank_tmp + 257 * i];
      }

      varargout_1[b_i + 40 * i] = d;
    }
  }
}

//
// File trailer for melSpectrogram.cpp
//
// [EOF]
//
