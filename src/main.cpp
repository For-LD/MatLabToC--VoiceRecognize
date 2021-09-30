//
// File: main.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 23-Oct-2020 20:33:52
//

//***********************************************************************
// This automatically generated example C++ main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************

// Include Files
#include "main.h"
#include "DeepLearningNetwork.h"
#include "VoiceRecognize.h"
#include "VoiceRecognize_terminate.h"
#include "matlabCodegenHandle.h"
#include "rt_nonfinite.h"
#include "AudioRead.h"

// Function Declarations
static void argInit_16000x1_real_T(double result[16000]);
static double argInit_real_T();
static void main_VoiceRecognize();
void examples::loadAudioFileAndPrintSummary(double audio[16000]);

// Function Definitions

//
// Arguments    : double result[16000]
// Return Type  : void
//
static void argInit_16000x1_real_T(double result[16000])
{
  // Loop over the array to initialize each element.
  for (int idx0 = 0; idx0 < 16000; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_VoiceRecognize()
{
  double dv[16000];
  cell_wrap_0 out[1];

  // Initialize function 'VoiceRecognize' input arguments.
  // Initialize function input argument 'x'.
  // Call the entry-point 'VoiceRecognize'.
    double *audio = new double[16000];
    examples::loadAudioFileAndPrintSummary(audio);

    std::cout << audio[1] << ' ' << audio[500] << ' ' << audio[1000] << ' ' << audio[12000] << std::endl;

  //argInit_16000x1_real_T(dv);
  VoiceRecognize(audio, out);
  std::cout << ""<<out[0].f1.data<<std::endl;
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. 
  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_VoiceRecognize();

  // Terminate the application.
  // You do not need to do this more than one time.
  VoiceRecognize_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
