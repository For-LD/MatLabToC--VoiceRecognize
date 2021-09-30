//
// File: DeepLearningNetwork.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 23-Oct-2020 20:33:52
//

// Include Files
#include "DeepLearningNetwork.h"
#include "VoiceRecognize.h"
#include "VoiceRecognize_rtwutil.h"
#include "matlabCodegenHandle.h"
#include "predict.h"
#include "rt_nonfinite.h"

// Type Definitions
#include "MWElementwiseAffineLayer.hpp"
#include "cnn_api.hpp"
#include "MWFusedConvReLULayer.hpp"
#include "MWTargetNetworkImpl.hpp"

// Function Definitions

//
// Arguments    : int numBufstoAllocate
//                MWCNNLayer *layers[15]
//                int numLayers
// Return Type  : void
//

//
// Arguments    : void
// Return Type  : void
//

//
// Arguments    : void
// Return Type  : void
//

//
// Arguments    : void
// Return Type  : void
//

//
// Arguments    : MWTargetNetworkImpl *targetImpl
//                MWTensor *b
//                int ScaleHeight
//                int ScaleWidth
//                int ScaleChannels
//                int OffsetHeight
//                int OffsetWidth
//                int OffsetChannels
//                bool IsClippedAffine
//                int LowerBound
//                int UpperBound
//                const char * c_a___codegen_lib_VoiceRecogniz
//                const char * d_a___codegen_lib_VoiceRecogniz
//                int c
// Return Type  : void
//

//
// Arguments    : MWTargetNetworkImpl *targetImpl
//                MWTensor *b
//                int InputSize
//                int OutputSize
//                const char * c_a___codegen_lib_VoiceRecogniz
//                const char * d_a___codegen_lib_VoiceRecogniz
//                int c
// Return Type  : void
//

//
// Arguments    : MWTargetNetworkImpl *targetImpl
//                MWTensor *m_in
//                int height
//                int width
//                int channels
//                int withAvg
//                const char * b
//                int c
// Return Type  : void
//

//
// Arguments    : MWTargetNetworkImpl *targetImpl
//                MWTensor *b
//                int c
// Return Type  : void
//

//
// Arguments    : MWTargetNetworkImpl *targetImpl
//                MWTensor *b
//                int c
// Return Type  : void
//

//
// Arguments    : MWTargetNetworkImpl *targetImpl
//                MWTensor *b
//                int c
// Return Type  : void
//

//
// Arguments    : void
// Return Type  : void
//

//
// Arguments    : void
// Return Type  : void
//

//
// Arguments    : void
// Return Type  : float *
//

//
// Arguments    : int handle
// Return Type  : void
//

//
// Arguments    : MWCNNLayer *layers[15]
//                int layerIdx
//                int portIdx
// Return Type  : float *
//

//
// Arguments    : void
// Return Type  : void
//

//
// Arguments    : void
// Return Type  : void
//

//
// Arguments    : void
// Return Type  : void
//

//
// Arguments    : void
// Return Type  : void
//

//
// Arguments    : int batchSize
// Return Type  : void
//

//
// Arguments    : int channels
// Return Type  : void
//

//
// Arguments    : float *data
// Return Type  : void
//

//
// Arguments    : int height
// Return Type  : void
//

//
// Arguments    : const char * name
// Return Type  : void
//

//
// Arguments    : int sequenceLength
// Return Type  : void
//

//
// Arguments    : int width
// Return Type  : void
//

//
// Arguments    : void
// Return Type  : void
//
void b_trainedNet_0::allocate()
{
  this->targetImpl->allocate(2, this->layers, this->numLayers);
  for (int idx = 0; idx < 15; idx++) {
    this->layers[idx]->allocate();
  }

  this->inputTensor->setData(this->layers[0]->getLayerOutput(0));
  this->outputTensor->setData(this->layers[14]->getLayerOutput(0));
}

//
// Arguments    : void
// Return Type  : void
//
void b_trainedNet_0::cleanup()
{
  this->deallocate();
  for (int idx = 0; idx < 15; idx++) {
    this->layers[idx]->cleanup();
  }

  if (this->targetImpl) {
    this->targetImpl->cleanup();
  }
}

//
// Arguments    : void
// Return Type  : void
//
void b_trainedNet_0::deallocate()
{
  this->targetImpl->deallocate();
  for (int idx = 0; idx < 15; idx++) {
    this->layers[idx]->deallocate();
  }
}

//
// Arguments    : void
// Return Type  : float *
//
float *b_trainedNet_0::getInputDataPointer()
{
  return this->inputTensor->getFloatData();
}

//
// Arguments    : int layerIndex
//                int portIndex
// Return Type  : float *
//
float *b_trainedNet_0::getLayerOutput(int layerIndex, int portIndex)
{
  return this->targetImpl->getLayerOutput(this->layers, layerIndex, portIndex);
}

//
// Arguments    : void
// Return Type  : float *
//
float *b_trainedNet_0::getOutputDataPointer()
{
  return this->outputTensor->getFloatData();
}

//
// Arguments    : void
// Return Type  : void
//
void b_trainedNet_0::postsetup()
{
  this->targetImpl->postSetup();
}

//
// Arguments    : void
// Return Type  : void
//
void b_trainedNet_0::predict()
{
  for (int idx = 0; idx < 15; idx++) {
    this->layers[idx]->predict();
  }
}

//
// Arguments    : void
// Return Type  : void
//
void b_trainedNet_0::resetState()
{
}

//
// Arguments    : void
// Return Type  : void
//
void b_trainedNet_0::setSize()
{
  for (int idx = 0; idx < 15; idx++) {
    this->layers[idx]->propagateSize();
  }

  this->allocate();
  this->postsetup();
}

//
// Arguments    : void
// Return Type  : void
//
void b_trainedNet_0::setup()
{
  this->targetImpl->preSetup();
  (dynamic_cast<MWInputLayer *>(this->layers[0]))->createInputLayer
    (this->targetImpl, this->inputTensor, 40, 98, 1, 0, "", 0);
  (dynamic_cast<MWElementwiseAffineLayer *>(this->layers[1]))
    ->createElementwiseAffineLayer(this->targetImpl, this->layers[0]
    ->getOutputTensor(0), 1, 1, 1, 1, 1, 1, false, 1, 1,
    "./bin/cnn_trainedNet_imageinput_scale.bin",
    "./bin/cnn_trainedNet_imageinput_offset.bin", 1);
  (dynamic_cast<MWFusedConvReLULayer *>(this->layers[2]))
    ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[1]
    ->getOutputTensor(0), 3, 3, 1, 12, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    "./bin/cnn_trainedNet_conv_1_w.bin",
    "./bin/cnn_trainedNet_conv_1_b.bin", 0);
  (dynamic_cast<MWMaxPoolingLayer *>(this->layers[3]))->createMaxPoolingLayer
    (this->targetImpl, this->layers[2]->getOutputTensor(0), 3, 3, 2, 2, 0, 1, 0,
     1, 0, 1, 1);
  (dynamic_cast<MWFusedConvReLULayer *>(this->layers[4]))
    ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[3]
    ->getOutputTensor(0), 3, 3, 12, 24, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    "./bin/cnn_trainedNet_conv_2_w.bin",
    "./bin/cnn_trainedNet_conv_2_b.bin", 0);
  (dynamic_cast<MWMaxPoolingLayer *>(this->layers[5]))->createMaxPoolingLayer
    (this->targetImpl, this->layers[4]->getOutputTensor(0), 3, 3, 2, 2, 0, 1, 1,
     1, 0, 1, 1);
  (dynamic_cast<MWFusedConvReLULayer *>(this->layers[6]))
    ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[5]
    ->getOutputTensor(0), 3, 3, 24, 48, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    "./bin/cnn_trainedNet_conv_3_w.bin",
    "./bin/cnn_trainedNet_conv_3_b.bin", 0);
  (dynamic_cast<MWMaxPoolingLayer *>(this->layers[7]))->createMaxPoolingLayer
    (this->targetImpl, this->layers[6]->getOutputTensor(0), 3, 3, 2, 2, 0, 1, 1,
     1, 0, 1, 1);
  (dynamic_cast<MWFusedConvReLULayer *>(this->layers[8]))
    ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[7]
    ->getOutputTensor(0), 3, 3, 48, 48, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    "./bin/cnn_trainedNet_conv_4_w.bin",
    "./bin/cnn_trainedNet_conv_4_b.bin", 0);
  (dynamic_cast<MWFusedConvReLULayer *>(this->layers[9]))
    ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[8]
    ->getOutputTensor(0), 3, 3, 48, 48, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    "./bin/cnn_trainedNet_conv_5_w.bin",
    "./bin/cnn_trainedNet_conv_5_b.bin", 1);
  (dynamic_cast<MWMaxPoolingLayer *>(this->layers[10]))->createMaxPoolingLayer
    (this->targetImpl, this->layers[9]->getOutputTensor(0), 1, 13, 1, 1, 0, 0, 0,
     0, 0, 1, 0);
  (dynamic_cast<MWPassthroughLayer *>(this->layers[11]))->createPassthroughLayer
    (this->targetImpl, this->layers[10]->getOutputTensor(0), 0);
  (dynamic_cast<MWFCLayer *>(this->layers[12]))->createFCLayer(this->targetImpl,
    this->layers[11]->getOutputTensor(0), 240, 12,
    "./bin/cnn_trainedNet_fc_w.bin",
    "./bin/cnn_trainedNet_fc_b.bin", 1);
  (dynamic_cast<MWSoftmaxLayer *>(this->layers[13]))->createSoftmaxLayer
    (this->targetImpl, this->layers[12]->getOutputTensor(0), 0);
  (dynamic_cast<MWOutputLayer *>(this->layers[14]))->createOutputLayer
    (this->targetImpl, this->layers[13]->getOutputTensor(0), 0);
  this->setSize();
}

//
// Arguments    : void
// Return Type  : void
//
b_trainedNet_0::b_trainedNet_0()
{
  this->numLayers = 15;
  this->targetImpl = 0;
  this->layers[0] = new MWInputLayer;
  this->layers[0]->setName("imageinput");
  this->layers[1] = new MWElementwiseAffineLayer;
  this->layers[1]->setName("imageinput_normalization");
  this->layers[2] = new MWFusedConvReLULayer;
  this->layers[2]->setName("conv_1_relu_1");
  this->layers[3] = new MWMaxPoolingLayer;
  this->layers[3]->setName("maxpool_1");
  this->layers[4] = new MWFusedConvReLULayer;
  this->layers[4]->setName("conv_2_relu_2");
  this->layers[5] = new MWMaxPoolingLayer;
  this->layers[5]->setName("maxpool_2");
  this->layers[6] = new MWFusedConvReLULayer;
  this->layers[6]->setName("conv_3_relu_3");
  this->layers[7] = new MWMaxPoolingLayer;
  this->layers[7]->setName("maxpool_3");
  this->layers[8] = new MWFusedConvReLULayer;
  this->layers[8]->setName("conv_4_relu_4");
  this->layers[9] = new MWFusedConvReLULayer;
  this->layers[9]->setName("conv_5_relu_5");
  this->layers[10] = new MWMaxPoolingLayer;
  this->layers[10]->setName("maxpool_4");
  this->layers[11] = new MWPassthroughLayer;
  this->layers[11]->setName("dropout");
  this->layers[12] = new MWFCLayer;
  this->layers[12]->setName("fc");
  this->layers[13] = new MWSoftmaxLayer;
  this->layers[13]->setName("softmax");
  this->layers[14] = new MWOutputLayer;
  this->layers[14]->setName("classoutput");
  this->targetImpl = new MWTargetNetworkImpl;
  this->inputTensor = new MWTensor;
  this->inputTensor->setHeight(40);
  this->inputTensor->setWidth(98);
  this->inputTensor->setChannels(1);
  this->inputTensor->setBatchSize(1);
  this->inputTensor->setSequenceLength(1);
  this->outputTensor = new MWTensor;
}

//
// Arguments    : void
// Return Type  : void
//
b_trainedNet_0::~b_trainedNet_0()
{
  this->cleanup();
  for (int idx = 0; idx < 15; idx++) {
    delete this->layers[idx];
  }

  if (this->targetImpl) {
    delete this->targetImpl;
  }

  delete this->inputTensor;
  delete this->outputTensor;
}

//
// Arguments    : b_trainedNet_0 *obj
// Return Type  : void
//
void DeepLearningNetwork_setup(b_trainedNet_0 *obj)
{
  obj->setup();
  obj->batchSize = 1;
}

//
// File trailer for DeepLearningNetwork.cpp
//
// [EOF]
//
