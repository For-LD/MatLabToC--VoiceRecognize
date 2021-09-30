//
// File: designMelFilterBank.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 23-Oct-2020 20:33:52
//

// Include Files
#include "designMelFilterBank.h"
#include "DeepLearningNetwork.h"
#include "VoiceRecognize.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions

//
// Arguments    : double filterBank[20480]
//                bool *FFTLengthTooSmall
// Return Type  : void
//
void designMelFilterBank(double filterBank[20480], bool *FFTLengthTooSmall)
{
  int edgeNumber;
  int b_index;
  short p[42];
  static const double dv[42] = { 49.999999999999979, 93.835057978221641,
    140.23213236704876, 189.34096468368125, 241.32004834943709,
    296.33714021005039, 354.56980195266783, 416.20597316690373,
    481.44457789944852, 550.496166659819, 623.58359594925537, 700.94274750586715,
    782.82328958731853, 869.48948274800864, 961.22103271129947,
    1058.3139930893547, 1161.081720864008, 1269.8558877123849, 1384.987550441203,
    1506.8482839844835, 1635.8313806212823, 1772.3531192837934,
    1916.8541090523831, 2069.8007111735283, 2231.6865441900763,
    2403.0340770414691, 2584.3963152754827, 2776.3585858135611,
    2979.5404260298624, 3194.5975832408344, 3422.2241310584409,
    3663.1547094373354, 3918.1668956455183, 4188.0837138104853,
    4473.7762911401987, 4776.1666693915022, 5096.2307806597446,
    5435.0015970935774, 5793.5724647003481, 6173.1006320015786,
    6574.810984926834, 6999.9999999999973 };

  static const double dv1[41] = { 43.835057978221663, 46.397074388827122,
    49.108832316632487, 51.979083665755837, 55.017091860613306,
    58.232661742617438, 61.6361712142359, 65.238604732544786, 69.051588760370464,
    73.087429289436386, 77.359151556611778, 81.880542081451381,
    86.666193160690113, 91.731549963290831, 97.092960378055182,
    102.76772777465339, 108.77416684837681, 115.13166272881813,
    121.8607335432805, 128.98309663679879, 136.5217386625111, 144.50098976858976,
    152.94660212114513, 161.88583301654808, 171.34753285139277,
    181.3622382340136, 191.96227053807843, 203.18184021630123,
    215.05715721097204, 227.62654781760648, 240.93057837889455,
    255.01218620818281, 269.916818164967, 285.69257732971346, 302.39037825130345,
    320.06411126824241, 338.77081643383281, 358.57086760677066,
    379.5281673012305, 401.71035292525539, 425.18901507316332 };

  std::memset(&filterBank[0], 0, 20480U * sizeof(double));
  *FFTLengthTooSmall = false;
  for (edgeNumber = 0; edgeNumber < 42; edgeNumber++) {
    bool exitg1;
    b_index = 0;
    exitg1 = false;
    while ((!exitg1) && (b_index < 512)) {
      if (31.25 * static_cast<double>(b_index) > dv[edgeNumber]) {
        p[edgeNumber] = static_cast<short>(b_index + 1);
        exitg1 = true;
      } else {
        b_index++;
      }
    }
  }

  for (int k = 0; k < 40; k++) {
    int i;
    int i1;
    int i2;
    int loop_ub;
    int i3;
    i = p[k + 1];
    edgeNumber = i - 1;
    if (p[k] > edgeNumber) {
      b_index = 1;
      i1 = -1;
      i2 = 1;
    } else {
      b_index = p[k];
      i1 = p[k] - 2;
      i2 = i;
    }

    loop_ub = (i2 - i1) - 2;
    for (i2 = 0; i2 < loop_ub; i2++) {
      filterBank[((i1 + i2) + (k << 9)) + 1] = (31.25 * (static_cast<double>
        (b_index + i2) - 1.0) - dv[k]) / dv1[k];
    }

    b_index = p[k + 2];
    i1 = b_index - 1;
    if (i > i1) {
      i2 = 1;
      i3 = -1;
      b_index = 1;
    } else {
      i2 = i;
      i3 = i - 2;
    }

    loop_ub = (b_index - i3) - 2;
    for (b_index = 0; b_index < loop_ub; b_index++) {
      filterBank[((i3 + b_index) + (k << 9)) + 1] = (dv[k + 2] - 31.25 * (
        static_cast<double>(i2 + b_index) - 1.0)) / dv1[k + 1];
    }

    if (!*FFTLengthTooSmall) {
      if (edgeNumber < p[k]) {
        edgeNumber = 0;
      } else {
        edgeNumber = (edgeNumber - p[k]) + 1;
      }

      if (edgeNumber == 0) {
        *FFTLengthTooSmall = true;
      } else {
        if (i1 < i) {
          edgeNumber = 0;
        } else {
          edgeNumber = (i1 - i) + 1;
        }

        if (edgeNumber == 0) {
          *FFTLengthTooSmall = true;
        }
      }
    }
  }
}

//
// File trailer for designMelFilterBank.cpp
//
// [EOF]
//
