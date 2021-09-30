#include "MWFusedConvReLULayerImpl.hpp"
#include "MWFusedConvReLULayer.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"
#include <cassert>
#include <cstring>
#include <stdio.h>
#if MW_CONV_TAP
 extern void mw_interm_tap(arm_compute::Tensor& armTensor, int size, int 
count); extern int tap_count;
#endif
 MWFusedConvReLULayerImpl::MWFusedConvReLULayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, int filt_H, int filt_W, int numGrps, int 
numChnls, int numFilts, int IIiwAtyrOtLzLWAUlTey, int IpFhwalnAlrMvcuyQpQD, int 
FeVcBgtQmTLtmnNcJGMY, int FLuSVNoPhAFKtLUchSvv, int GFggoMvRWucDMqzlWzCl, 
int GLovsOhUpzOJhKgXUAJY, int BUOdotSvmFyUWQKMUdra, int 
BdqURaHPmdnfzvtUvocl, int , const char* yeRJnYjpvmkKjBpyWlaV, const 
char* QMNXyOvXaZDsCpiIJPsn) : MWCNNLayerImpl(layer, ntwk_impl) , 
BlRIQPyqJZORKENzSdYf(filt_H) , BuyZFXzwOMxcePIbCLfl(filt_W) , 
ClEhcJFlvGCgiavziIag(numGrps) , IIiwAtyrOtLzLWAUlTey(IIiwAtyrOtLzLWAUlTey) , 
IpFhwalnAlrMvcuyQpQD(IpFhwalnAlrMvcuyQpQD) , 
FeVcBgtQmTLtmnNcJGMY(FeVcBgtQmTLtmnNcJGMY) , 
FLuSVNoPhAFKtLUchSvv(FLuSVNoPhAFKtLUchSvv) , 
GFggoMvRWucDMqzlWzCl(GFggoMvRWucDMqzlWzCl) , 
GLovsOhUpzOJhKgXUAJY(GLovsOhUpzOJhKgXUAJY) , 
BUOdotSvmFyUWQKMUdra(BUOdotSvmFyUWQKMUdra) , 
BdqURaHPmdnfzvtUvocl(BdqURaHPmdnfzvtUvocl) { 
setarmTensor(std::make_shared<arm_compute::Tensor>()); int gNROjwaqhxDPvBWUCUcQ = 
numChnls * ClEhcJFlvGCgiavziIag * numFilts * BlRIQPyqJZORKENzSdYf * 
BuyZFXzwOMxcePIbCLfl; if (ClEhcJFlvGCgiavziIag != 1 && numChnls == 1 && 
numFilts == 1) { 
m_fusedConvLayerWgtTensor.allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape( (long unsigned int)BuyZFXzwOMxcePIbCLfl, (long 
unsigned int)BlRIQPyqJZORKENzSdYf, (long unsigned int)ClEhcJFlvGCgiavziIag), 
1, arm_compute::DataType::F32)); } else { 
m_fusedConvLayerWgtTensor.allocator()->init(arm_compute::TensorInfo( 
arm_compute::TensorShape( (long unsigned int)BuyZFXzwOMxcePIbCLfl, (long 
unsigned int)BlRIQPyqJZORKENzSdYf, (long unsigned int)numChnls, (long 
unsigned int)numFilts * ClEhcJFlvGCgiavziIag), 1, arm_compute::DataType::F32)); 
} m_fusedConvLayerBiasTensor.allocator()->init( 
arm_compute::TensorInfo(arm_compute::TensorShape((long unsigned int)numFilts * 
ClEhcJFlvGCgiavziIag), 1, arm_compute::DataType::F32)); wJyXsrUCMgxdIKVIJSyx = 
CREATE_BUFFER(gNROjwaqhxDPvBWUCUcQ); OiVqrkNdXioJhALWMMvm = 
CREATE_BUFFER(ClEhcJFlvGCgiavziIag * numFilts); 
loadWeights(yeRJnYjpvmkKjBpyWlaV, gNROjwaqhxDPvBWUCUcQ); 
loadBias(QMNXyOvXaZDsCpiIJPsn, ClEhcJFlvGCgiavziIag * numFilts); } 
MWFusedConvReLULayerImpl::~MWFusedConvReLULayerImpl() { } void 
MWFusedConvReLULayerImpl::propagateSize() { MWFusedConvReLULayer* 
FusedconvLayer = static_cast<MWFusedConvReLULayer*>(getLayer()); MWTensor* 
ipTensor = FusedconvLayer->getInputTensor(0); MWTensor* opTensor = 
FusedconvLayer->getOutputTensor(0); arm_compute::Tensor* prevLayerarmTensor = 
getprevLayerarmTensor(ipTensor); 
getarmTensor()->allocator()->init(arm_compute::TensorInfo(arm_compute::TensorShape((long 
unsigned int)opTensor->getWidth(), (long unsigned int)opTensor->getHeight(), 
(long unsigned int)opTensor->getChannels(), (long unsigned 
int)opTensor->getBatchSize()), 1, arm_compute::DataType::F32)); if 
(ClEhcJFlvGCgiavziIag != 1) { if (ClEhcJFlvGCgiavziIag == 
ipTensor->getChannels()) { if (BuyZFXzwOMxcePIbCLfl == 3 && 
BlRIQPyqJZORKENzSdYf == 3) { m_fusedDepthwiseconvLayer3x3 = 
std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer3x3>( new 
arm_compute::NEDepthwiseConvolutionLayer3x3); 
m_fusedDepthwiseconvLayer3x3->configure( prevLayerarmTensor, 
&m_fusedConvLayerWgtTensor, &m_fusedConvLayerBiasTensor, getarmTensor(), 
arm_compute::PadStrideInfo(IpFhwalnAlrMvcuyQpQD, IIiwAtyrOtLzLWAUlTey, 
GFggoMvRWucDMqzlWzCl, GLovsOhUpzOJhKgXUAJY, FeVcBgtQmTLtmnNcJGMY, 
FLuSVNoPhAFKtLUchSvv, arm_compute::DimensionRoundingType::FLOOR)); } else { 
m_fusedDepthwiseconvLayer = 
std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer>( new 
arm_compute::NEDepthwiseConvolutionLayer); 
m_fusedDepthwiseconvLayer->configure( prevLayerarmTensor, 
&m_fusedConvLayerWgtTensor, &m_fusedConvLayerBiasTensor, getarmTensor(), 
arm_compute::PadStrideInfo(IpFhwalnAlrMvcuyQpQD, IIiwAtyrOtLzLWAUlTey, 
GFggoMvRWucDMqzlWzCl, GLovsOhUpzOJhKgXUAJY, FeVcBgtQmTLtmnNcJGMY, 
FLuSVNoPhAFKtLUchSvv, arm_compute::DimensionRoundingType::FLOOR)); } } else { 
m_fusedConvLayer = std::unique_ptr<arm_compute::NEConvolutionLayer>(new 
arm_compute::NEConvolutionLayer); m_fusedConvLayerSecondGroup = 
std::unique_ptr<arm_compute::NEConvolutionLayer>(new 
arm_compute::NEConvolutionLayer); m_prevLayer1 = new arm_compute::SubTensor( 
prevLayerarmTensor, arm_compute::TensorShape((long unsigned 
int)ipTensor->getHeight(), (long unsigned int)ipTensor->getWidth(), (long 
unsigned int)(ipTensor->getChannels() / ClEhcJFlvGCgiavziIag), (long unsigned 
int)ipTensor->getBatchSize()), arm_compute::Coordinates()); m_prevLayer2 = new 
arm_compute::SubTensor( prevLayerarmTensor, arm_compute::TensorShape((long 
unsigned int)ipTensor->getHeight(), (long unsigned int)ipTensor->getWidth(), 
(long unsigned int)(ipTensor->getChannels() / ClEhcJFlvGCgiavziIag), (long 
unsigned int)ipTensor->getBatchSize()), arm_compute::Coordinates(0, 0, 
ipTensor->getChannels() / ClEhcJFlvGCgiavziIag)); m_curLayer1 = new 
arm_compute::SubTensor( getarmTensor(), arm_compute::TensorShape((long unsigned 
int)opTensor->getWidth(), (long unsigned int)opTensor->getHeight(), (long 
unsigned int)(opTensor->getChannels() / ClEhcJFlvGCgiavziIag), (long unsigned 
int)opTensor->getBatchSize()), arm_compute::Coordinates()); m_curLayer2 = new 
arm_compute::SubTensor( getarmTensor(), arm_compute::TensorShape((long unsigned 
int)opTensor->getWidth(), (long unsigned int)opTensor->getHeight(), (long 
unsigned int)(opTensor->getChannels() / ClEhcJFlvGCgiavziIag), (long unsigned 
int)opTensor->getBatchSize()), arm_compute::Coordinates(0, 0, 
opTensor->getChannels() / ClEhcJFlvGCgiavziIag)); m_fusedConvLayerWgtMWTensor = 
new arm_compute::SubTensor( &m_fusedConvLayerWgtTensor, 
arm_compute::TensorShape((long unsigned int)BlRIQPyqJZORKENzSdYf, (long 
unsigned int)BuyZFXzwOMxcePIbCLfl, (long unsigned 
int)(ipTensor->getChannels() / ClEhcJFlvGCgiavziIag), (long unsigned 
int)(opTensor->getChannels() / ClEhcJFlvGCgiavziIag)), 
arm_compute::Coordinates()); m_fusedConvLayerWgtTensor2 = new 
arm_compute::SubTensor( &m_fusedConvLayerWgtTensor, 
arm_compute::TensorShape((long unsigned int)BlRIQPyqJZORKENzSdYf, (long 
unsigned int)BuyZFXzwOMxcePIbCLfl, (long unsigned 
int)(ipTensor->getChannels() / ClEhcJFlvGCgiavziIag), (long unsigned 
int)(opTensor->getChannels() / ClEhcJFlvGCgiavziIag)), 
arm_compute::Coordinates(0, 0, 0, opTensor->getChannels() / 
ClEhcJFlvGCgiavziIag)); m_fusedConvLayerBiasMWTensor = new 
arm_compute::SubTensor( &m_fusedConvLayerBiasTensor, 
arm_compute::TensorShape((long unsigned int)(opTensor->getChannels() / 
ClEhcJFlvGCgiavziIag)), arm_compute::Coordinates()); 
m_fusedConvLayerBiasTensor2 = new arm_compute::SubTensor( 
&m_fusedConvLayerBiasTensor, arm_compute::TensorShape((long unsigned 
int)(opTensor->getChannels() / ClEhcJFlvGCgiavziIag)), 
arm_compute::Coordinates(opTensor->getChannels() / ClEhcJFlvGCgiavziIag)); 
m_fusedConvLayer->configure( m_prevLayer1, m_fusedConvLayerWgtMWTensor, 
m_fusedConvLayerBiasMWTensor, m_curLayer1, 
arm_compute::PadStrideInfo(IpFhwalnAlrMvcuyQpQD, IIiwAtyrOtLzLWAUlTey, 
GFggoMvRWucDMqzlWzCl, GLovsOhUpzOJhKgXUAJY, FeVcBgtQmTLtmnNcJGMY, 
FLuSVNoPhAFKtLUchSvv, arm_compute::DimensionRoundingType::FLOOR), 
arm_compute::WeightsInfo(false, (long unsigned int)BuyZFXzwOMxcePIbCLfl, 
(long unsigned int)BlRIQPyqJZORKENzSdYf, (long unsigned 
int)opTensor->getChannels()), 
arm_compute::Size2D((size_t)(BdqURaHPmdnfzvtUvocl), 
(size_t)(BUOdotSvmFyUWQKMUdra)), 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo::ActivationFunction::RELU)); 
m_fusedConvLayerSecondGroup->configure( m_prevLayer2, 
m_fusedConvLayerWgtTensor2, m_fusedConvLayerBiasTensor2, m_curLayer2, 
arm_compute::PadStrideInfo(IpFhwalnAlrMvcuyQpQD, IIiwAtyrOtLzLWAUlTey, 
GFggoMvRWucDMqzlWzCl, GLovsOhUpzOJhKgXUAJY, FeVcBgtQmTLtmnNcJGMY, 
FLuSVNoPhAFKtLUchSvv, arm_compute::DimensionRoundingType::FLOOR), 
arm_compute::WeightsInfo(false, (long unsigned int)BuyZFXzwOMxcePIbCLfl, 
(long unsigned int)BlRIQPyqJZORKENzSdYf, (long unsigned 
int)opTensor->getChannels()), 
arm_compute::Size2D((size_t)(BdqURaHPmdnfzvtUvocl), 
(size_t)(BUOdotSvmFyUWQKMUdra)), 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo::ActivationFunction::RELU)); 
} } else { m_fusedConvLayer = 
std::unique_ptr<arm_compute::NEConvolutionLayer>(new 
arm_compute::NEConvolutionLayer); m_fusedConvLayer->configure( 
prevLayerarmTensor, &m_fusedConvLayerWgtTensor, &m_fusedConvLayerBiasTensor, 
getarmTensor(), arm_compute::PadStrideInfo(IpFhwalnAlrMvcuyQpQD, 
IIiwAtyrOtLzLWAUlTey, GFggoMvRWucDMqzlWzCl, GLovsOhUpzOJhKgXUAJY, 
FeVcBgtQmTLtmnNcJGMY, FLuSVNoPhAFKtLUchSvv, 
arm_compute::DimensionRoundingType::FLOOR), arm_compute::WeightsInfo(false, 
(long unsigned int)BuyZFXzwOMxcePIbCLfl, (long unsigned 
int)BlRIQPyqJZORKENzSdYf, (long unsigned int)opTensor->getChannels()), 
arm_compute::Size2D((size_t)(BdqURaHPmdnfzvtUvocl), 
(size_t)(BUOdotSvmFyUWQKMUdra)), 
arm_compute::ActivationLayerInfo(arm_compute::ActivationLayerInfo::ActivationFunction::RELU)); 
} return; } void MWFusedConvReLULayerImpl::predict() { MWFusedConvReLULayer* 
FusedconvLayer = static_cast<MWFusedConvReLULayer*>(getLayer()); MWTensor* 
opTensor = FusedconvLayer->getOutputTensor(0); MWTensor* ipTensor = 
FusedconvLayer->getInputTensor(0); if (ClEhcJFlvGCgiavziIag == 1) { 
m_fusedConvLayer->run(); } else { if (ClEhcJFlvGCgiavziIag == 
ipTensor->getChannels()) { m_fusedDepthwiseconvLayer->run(); } else { 
m_fusedConvLayer->run(); m_fusedConvLayerSecondGroup->run(); } }
#if MW_CONV_TAP
 mw_interm_tap(*getarmTensor(), opTensor->getNumElements(), tap_count++);
#endif
 return; } void MWFusedConvReLULayerImpl::allocate() { MWFusedConvReLULayer* 
FusedconvLayer = static_cast<MWFusedConvReLULayer*>(getLayer()); MWTensor* 
opTensor = FusedconvLayer->getOutputTensor(0); MWTensor* ipTensor = 
FusedconvLayer->getInputTensor(0); int gNROjwaqhxDPvBWUCUcQ = ipTensor->getChannels() 
/ ClEhcJFlvGCgiavziIag * opTensor->getChannels() * BlRIQPyqJZORKENzSdYf * 
BuyZFXzwOMxcePIbCLfl;  
MWACLUtils::allocateAndFillTensor(m_fusedConvLayerWgtTensor, wJyXsrUCMgxdIKVIJSyx, 
gNROjwaqhxDPvBWUCUcQ, isWgtsPadding); 
MWACLUtils::allocateAndFillTensor(m_fusedConvLayerBiasTensor, OiVqrkNdXioJhALWMMvm, 
opTensor->getChannels(), isBiasPadding); return; } void 
MWFusedConvReLULayerImpl::deallocate() { if (ClEhcJFlvGCgiavziIag != 1) { 
delete m_prevLayer1; delete m_prevLayer2; delete m_curLayer1; delete 
m_curLayer2; delete m_fusedConvLayerWgtMWTensor; delete 
m_fusedConvLayerWgtTensor2; delete m_fusedConvLayerBiasMWTensor; delete 
m_fusedConvLayerBiasTensor2; } if(isWgtsPadding){ 
m_fusedConvLayerWgtTensor.allocator()->free(); isWgtsPadding = false; } 
if(isBiasPadding){ m_fusedConvLayerWgtTensor.allocator()->free(); isWgtsPadding 
= false; } return; } void MWFusedConvReLULayerImpl::cleanup(){ 
FREE_BUFFER_MEMORY(wJyXsrUCMgxdIKVIJSyx); FREE_BUFFER_MEMORY(OiVqrkNdXioJhALWMMvm); return; } 
void MWFusedConvReLULayerImpl::loadWeights(const char* THfVbcZJtANcLKxEriuV, int 
gNROjwaqhxDPvBWUCUcQ) { float* wvufwFZlsnpjbxmTBVYE = GET_BUFFER(wJyXsrUCMgxdIKVIJSyx); std::string 
fileString = getLinuxPath(THfVbcZJtANcLKxEriuV); FILE* TbrNrGxaFFHrzKUcfHNZ = 
MWCNNLayer::openBinaryFile(fileString.c_str()); call_fread(wvufwFZlsnpjbxmTBVYE, 
sizeof(float), gNROjwaqhxDPvBWUCUcQ, TbrNrGxaFFHrzKUcfHNZ, THfVbcZJtANcLKxEriuV); 
fclose(TbrNrGxaFFHrzKUcfHNZ); return; } void MWFusedConvReLULayerImpl::loadBias(const 
char* THfVbcZJtANcLKxEriuV, int gNROjwaqhxDPvBWUCUcQ) { float* OzygUJRIZYnGLzSjgahB = 
GET_BUFFER(OiVqrkNdXioJhALWMMvm); std::string fileString = 
getLinuxPath(THfVbcZJtANcLKxEriuV); FILE* TbrNrGxaFFHrzKUcfHNZ = 
MWCNNLayer::openBinaryFile(fileString.c_str()); call_fread(OzygUJRIZYnGLzSjgahB, 
sizeof(float), gNROjwaqhxDPvBWUCUcQ, TbrNrGxaFFHrzKUcfHNZ, THfVbcZJtANcLKxEriuV); 
fclose(TbrNrGxaFFHrzKUcfHNZ); return; }