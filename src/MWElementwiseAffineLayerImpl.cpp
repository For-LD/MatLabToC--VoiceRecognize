#include "MWElementwiseAffineLayerImpl.hpp"
#include <cassert>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <arm_neon.h>
#if MW_AFFINE_TAP
 extern int tap_count; extern void mw_interm_tap(arm_compute::Tensor& 
armTensor, int size, int count);
#endif
 MWElementwiseAffineLayerImpl::MWElementwiseAffineLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, int scale_H, int scale_W, int scale_C, int 
offset_H, int offset_W, int offset_C, bool isClipped, int lowerbound, int 
upperbound, const char* scale_file, const char* offset_file) : 
MWCNNLayerImpl(layer, ntwk_impl) , rIcMzXptfYweLArNRnBw(NULL) , 
jHzoRQWaHafftmrmuvHO(NULL) , rrWNoFNRUEdlTvIOmCla(scale_H) , 
rytJDHzuydvYOLNNROYf(scale_W) , rlQsibXJSWJVnUVpdNeL(scale_C) , 
kFQQPKSOkZeHlmrkAXuE(offset_H) , kqftrrQBBOgGsrDSkIUk(offset_W) , 
jmcFOAbZArjGDNhshSro(offset_C) , atVCyzqXZAZxwlkRLBRA(isClipped) , 
edQOkUJIZbwzEeIcCLzG(lowerbound) , vpXxoeEhdEosLSsYXkNG(upperbound) { 
setarmTensor(std::make_shared<arm_compute::Tensor>()); getScaleType(); 
getOffsetType(); long int rxMAtVYGgGtZoKBkJcjc = (long int)(rrWNoFNRUEdlTvIOmCla * 
rytJDHzuydvYOLNNROYf * rlQsibXJSWJVnUVpdNeL); long int kMyEnepVyoNObTPqIpWo = (long 
int)(kFQQPKSOkZeHlmrkAXuE * kqftrrQBBOgGsrDSkIUk * jmcFOAbZArjGDNhshSro); 
rIcMzXptfYweLArNRnBw = CREATE_BUFFER(rxMAtVYGgGtZoKBkJcjc); jHzoRQWaHafftmrmuvHO = 
CREATE_BUFFER(kMyEnepVyoNObTPqIpWo); loadScale(scale_file); 
loadOffset(offset_file); initScaleOffsetTensors();  } 
MWElementwiseAffineLayerImpl::~MWElementwiseAffineLayerImpl() { } void 
MWElementwiseAffineLayerImpl::propagateSize() { MWTensor* ipTensor = 
getLayer()->getInputTensor(0); MWTensor* opTensor = 
getLayer()->getOutputTensor(0); arm_compute::Tensor* prevLayerarmTensor = 
getprevLayerarmTensor(ipTensor); bool doesPrevLayerHas2DArmTensor = 
prevLayerarmTensor->info()->num_dimensions() <= 2 && ipTensor->getHeight() == 1 
&& ipTensor->getWidth()==1; if (doesPrevLayerHas2DArmTensor) { 
getarmTensor()->allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)opTensor->getChannels(), (long 
unsigned int)(opTensor->getSequenceLength()*opTensor->getBatchSize())), 1, 
arm_compute::DataType::F32)); } else { 
getarmTensor()->allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)ipTensor->getWidth(), (long 
unsigned int)ipTensor->getHeight(), (long unsigned int)opTensor->getChannels(), 
(long unsigned int)(opTensor->getSequenceLength()*opTensor->getBatchSize())), 
1, arm_compute::DataType::F32)); } initTempAllocators();  if (isScaleScalar && 
isOffsetScalar) { m_actLayer = 
std::unique_ptr<arm_compute::NEActivationLayer>(new 
arm_compute::NEActivationLayer); m_actLayer->configure(prevLayerarmTensor, 
getarmTensor(), 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo( 
arm_compute::ActivationLayerInfo::ActivationFunction::LINEAR, 
*GET_BUFFER(rIcMzXptfYweLArNRnBw), *GET_BUFFER(jHzoRQWaHafftmrmuvHO)))); } else if 
(isScaleVector && isOffsetVector) { m_depthwiseLayer = 
std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer>(new 
arm_compute::NEDepthwiseConvolutionLayer); m_depthwiseLayer->configure( 
prevLayerarmTensor, &scaleTensor, &offsetTensor, getarmTensor(), 
arm_compute::PadStrideInfo(1, 1, 0, 0, 
arm_compute::DimensionRoundingType::FLOOR)); } else { createScaleAffine(); 
createOffsetAffine(); } } void 
MWElementwiseAffineLayerImpl::initScaleOffsetTensors() { if (!isScaleScalar) { 
scaleTensor.allocator()->init( 
arm_compute::TensorInfo(arm_compute::TensorShape((long unsigned 
int)rytJDHzuydvYOLNNROYf, (long unsigned int)rrWNoFNRUEdlTvIOmCla, (long unsigned 
int)rlQsibXJSWJVnUVpdNeL), 1, arm_compute::DataType::F32)); } if 
(!isOffsetScalar) { offsetTensor.allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)kqftrrQBBOgGsrDSkIUk, (long unsigned 
int)kFQQPKSOkZeHlmrkAXuE, (long unsigned int)jmcFOAbZArjGDNhshSro), 1, 
arm_compute::DataType::F32)); } if (isOffsetVector && !isScaleVector) { 
tmpScaleTensor.allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape((long unsigned int)kqftrrQBBOgGsrDSkIUk, (long unsigned 
int)kFQQPKSOkZeHlmrkAXuE, (long unsigned int)jmcFOAbZArjGDNhshSro), 1, 
arm_compute::DataType::F32)); } } void 
MWElementwiseAffineLayerImpl::initTempAllocators() { MWTensor* ipTensor = 
getLayer()->getInputTensor(0); int fXhhiexIRPLyKXApPmmy = ipTensor->getBatchSize(); int 
QhTesEEIHwhNmHSeYbRR = ipTensor->getChannels(); int TfsmDFpPPOscKZifVzSQ = 
ipTensor->getHeight(); int wJyXsrUCMgxdIKVIJSyx = ipTensor->getWidth(); if 
(!((isScaleScalar && isOffsetScalar) || (isScaleVector && isOffsetVector))) { 
tmparmTensor.allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape( (long unsigned int)wJyXsrUCMgxdIKVIJSyx, (long unsigned 
int)TfsmDFpPPOscKZifVzSQ, (long unsigned int)QhTesEEIHwhNmHSeYbRR, (long unsigned 
int)fXhhiexIRPLyKXApPmmy), 1, arm_compute::DataType::F32)); } } void 
MWElementwiseAffineLayerImpl::createScaleAffine() { MWTensor* ipTensor = 
getLayer()->getInputTensor(0); arm_compute::Tensor* prevLayerarmTensor = 
getprevLayerarmTensor(ipTensor); if (isScaleScalar) { m_actLayer = 
std::unique_ptr<arm_compute::NEActivationLayer>(new 
arm_compute::NEActivationLayer); m_actLayer->configure(prevLayerarmTensor, 
&tmparmTensor, 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo( 
arm_compute::ActivationLayerInfo::ActivationFunction::LINEAR, 
*GET_BUFFER(rIcMzXptfYweLArNRnBw), 0))); } else if (isScaleVector) { 
m_depthwiseLayer = 
std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer>(new 
arm_compute::NEDepthwiseConvolutionLayer); m_depthwiseLayer->configure( 
prevLayerarmTensor, &scaleTensor, nullptr, &tmparmTensor, 
arm_compute::PadStrideInfo(1, 1, 0, 0, 
arm_compute::DimensionRoundingType::FLOOR)); } else if (isScaleMatrix) { 
m_prodLayer = std::unique_ptr<arm_compute::NEPixelWiseMultiplication>(new 
arm_compute::NEPixelWiseMultiplication); 
m_prodLayer->configure(prevLayerarmTensor, &scaleTensor, &tmparmTensor, 1, 
arm_compute::ConvertPolicy::WRAP, arm_compute::RoundingPolicy::TO_ZERO); } } 
void MWElementwiseAffineLayerImpl::createOffsetAffine() { if (isOffsetScalar) { 
m_actLayer = std::unique_ptr<arm_compute::NEActivationLayer>(new 
arm_compute::NEActivationLayer); m_actLayer->configure(&tmparmTensor, 
getarmTensor(), 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo( 
arm_compute::ActivationLayerInfo::ActivationFunction::LINEAR, 1, 
*GET_BUFFER(jHzoRQWaHafftmrmuvHO)))); } else if (isOffsetVector) { 
m_depthwiseLayer = 
std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer>(new 
arm_compute::NEDepthwiseConvolutionLayer); m_depthwiseLayer->configure( 
&tmparmTensor, &tmpScaleTensor, &offsetTensor, getarmTensor(), 
arm_compute::PadStrideInfo(1, 1, 0, 0, 
arm_compute::DimensionRoundingType::FLOOR)); } else if (isOffsetMatrix) { 
m_addLayer = std::unique_ptr<arm_compute::NEArithmeticAddition>(new 
arm_compute::NEArithmeticAddition); m_addLayer->configure(&tmparmTensor, 
&offsetTensor, getarmTensor(), arm_compute::ConvertPolicy::WRAP); } } void 
MWElementwiseAffineLayerImpl::getScaleType() { if (rrWNoFNRUEdlTvIOmCla == 1 && 
rytJDHzuydvYOLNNROYf == 1 && rlQsibXJSWJVnUVpdNeL == 1) { isScaleScalar = true; } 
else if (rrWNoFNRUEdlTvIOmCla == 1 && rytJDHzuydvYOLNNROYf == 1 && 
rlQsibXJSWJVnUVpdNeL != 1) { isScaleVector = true; } else { isScaleMatrix = true; 
} } void MWElementwiseAffineLayerImpl::getOffsetType() { if 
(kFQQPKSOkZeHlmrkAXuE == 1 && kqftrrQBBOgGsrDSkIUk == 1 && jmcFOAbZArjGDNhshSro == 
1) { isOffsetScalar = true; } else if (kFQQPKSOkZeHlmrkAXuE == 1 && 
kqftrrQBBOgGsrDSkIUk == 1 && jmcFOAbZArjGDNhshSro != 1) { isOffsetVector = true; 
} else { isOffsetMatrix = true; } } void 
MWElementwiseAffineLayerImpl::allocate() { MWTensor* opTensor = 
getLayer()->getOutputTensor(0); if (isOffsetVector && !(isScaleVector)) { 
tmpScaleTensor.allocator()->allocate(); MWACLUtils::fillValueToTensor(1.0f, 
tmpScaleTensor); } if (!(isScaleScalar)) { 
MWACLUtils::allocateAndFillTensor(scaleTensor, rIcMzXptfYweLArNRnBw, 
rrWNoFNRUEdlTvIOmCla * rytJDHzuydvYOLNNROYf * rlQsibXJSWJVnUVpdNeL, isScalePadded); } 
if (!(isOffsetScalar)) { MWACLUtils::allocateAndFillTensor(offsetTensor, 
jHzoRQWaHafftmrmuvHO, kFQQPKSOkZeHlmrkAXuE * kqftrrQBBOgGsrDSkIUk * 
jmcFOAbZArjGDNhshSro, isOffsetPadded); } if (!((isScaleScalar && isOffsetScalar) 
|| (isScaleVector && isOffsetVector))) { tmparmTensor.allocator()->allocate(); 
} return; } void MWElementwiseAffineLayerImpl::clipAffineOutput() { 
arm_compute::Tensor* tensor = getarmTensor(); arm_compute::Window 
input_src_window; 
input_src_window.use_tensor_dimensions(tensor->info()->tensor_shape()); 
arm_compute::Iterator input_src(tensor, input_src_window); execute_window_loop( 
input_src_window, [&](const arm_compute::Coordinates& id) { float* inpPtr = 
reinterpret_cast<float*>(input_src.ptr()); *inpPtr = *inpPtr > 
vpXxoeEhdEosLSsYXkNG ? vpXxoeEhdEosLSsYXkNG : *inpPtr; *inpPtr = *inpPtr < 
edQOkUJIZbwzEeIcCLzG ? edQOkUJIZbwzEeIcCLzG : *inpPtr; }, input_src); } void 
MWElementwiseAffineLayerImpl::predict() { MWElementwiseAffineLayer* 
elAffineLayer = static_cast<MWElementwiseAffineLayer*>(getLayer()); MWTensor* 
opTensor = elAffineLayer->getOutputTensor(); MWTensor* inpTensor = 
elAffineLayer->getInputTensor(); if ((isScaleScalar && isOffsetScalar)) { 
m_actLayer->run(); } else if (isScaleVector && isOffsetVector) { 
m_depthwiseLayer->run(); } else { if (isScaleScalar) { m_actLayer->run(); } 
else if (isScaleVector) { m_depthwiseLayer->run(); } else { m_prodLayer->run(); 
} if (isOffsetScalar) { m_actLayer->run(); } else if (isOffsetVector) { 
m_depthwiseLayer->run(); } else { m_addLayer->run(); } } if 
(atVCyzqXZAZxwlkRLBRA) { clipAffineOutput(); }
#if MW_AFFINE_TAP
 mw_interm_tap(*getarmTensor(), opTensor->getNumElements(), tap_count++);
#endif
 return; } void MWElementwiseAffineLayerImpl::deallocate() { MWTensor* opTensor 
= getLayer()->getOutputTensor(0); if (isOffsetVector && !(isScaleVector)) { 
tmpScaleTensor.allocator()->free(); } if (!(isScaleScalar)) { 
if(isScalePadded){ scaleTensor.allocator()->free(); isScalePadded = false; } } 
if (!(isOffsetScalar)) { if(isOffsetPadded){ offsetTensor.allocator()->free(); 
isOffsetPadded = false; } } if (!((isScaleScalar && isOffsetScalar) || 
(isScaleVector && isOffsetVector))) { tmparmTensor.allocator()->free(); } 
return; } void MWElementwiseAffineLayerImpl::cleanup() { 
FREE_BUFFER_MEMORY(rIcMzXptfYweLArNRnBw); FREE_BUFFER_MEMORY(jHzoRQWaHafftmrmuvHO); 
return; } void MWElementwiseAffineLayerImpl::loadScale(const char* 
tGsvtyAVkrDznETdweDC) { float* rMMjgjGRAiLVlTlRSByU = 
GET_BUFFER(rIcMzXptfYweLArNRnBw); FILE* TbrNrGxaFFHrzKUcfHNZ = 
MWCNNLayer::openBinaryFile(tGsvtyAVkrDznETdweDC); assert(TbrNrGxaFFHrzKUcfHNZ); long 
int gNROjwaqhxDPvBWUCUcQ = (long int)(rrWNoFNRUEdlTvIOmCla * rytJDHzuydvYOLNNROYf * 
rlQsibXJSWJVnUVpdNeL); call_fread(rMMjgjGRAiLVlTlRSByU, sizeof(float), 
gNROjwaqhxDPvBWUCUcQ, TbrNrGxaFFHrzKUcfHNZ, tGsvtyAVkrDznETdweDC); fclose(TbrNrGxaFFHrzKUcfHNZ); 
return; } void MWElementwiseAffineLayerImpl::loadOffset(const char* 
lHtftnmGBvlSSoGOXVui) { float* jfkhqXBmwICFStMidrQt = 
GET_BUFFER(jHzoRQWaHafftmrmuvHO); FILE* TbrNrGxaFFHrzKUcfHNZ = 
MWCNNLayer::openBinaryFile(lHtftnmGBvlSSoGOXVui); assert(TbrNrGxaFFHrzKUcfHNZ); long 
int gNROjwaqhxDPvBWUCUcQ = (long int)(kFQQPKSOkZeHlmrkAXuE * kqftrrQBBOgGsrDSkIUk * 
jmcFOAbZArjGDNhshSro); call_fread(jfkhqXBmwICFStMidrQt, sizeof(float), 
gNROjwaqhxDPvBWUCUcQ, TbrNrGxaFFHrzKUcfHNZ, lHtftnmGBvlSSoGOXVui); fclose(TbrNrGxaFFHrzKUcfHNZ); }