/* Copyright 2018 The MathWorks, Inc. */

#ifndef _MW_FUSED_CONV_LAYER_IMPL
#define _MW_FUSED_CONV_LAYER_IMPL

#include "MWCNNLayerImpl.hpp"
#include "MWTargetNetworkImpl.hpp"

// Convolution2DWCNNLayer
class MWFusedConvReLULayerImpl : public MWCNNLayerImpl {

  private:
    int BlRIQPyqJZORKENzSdYf;
    int BuyZFXzwOMxcePIbCLfl;
    int ClEhcJFlvGCgiavziIag;

    int IIiwAtyrOtLzLWAUlTey;
    int IpFhwalnAlrMvcuyQpQD;
    int FeVcBgtQmTLtmnNcJGMY;
    int FLuSVNoPhAFKtLUchSvv;
    int GFggoMvRWucDMqzlWzCl;
    int GLovsOhUpzOJhKgXUAJY;
    int BUOdotSvmFyUWQKMUdra;
    int BdqURaHPmdnfzvtUvocl;

    #if defined(USE_18_05_LIBRARY) | defined(USE_18_08_LIBRARY)
    arm_compute::MemoryRegion* wJyXsrUCMgxdIKVIJSyx;
    arm_compute::MemoryRegion* OiVqrkNdXioJhALWMMvm;
    #else
    float* wJyXsrUCMgxdIKVIJSyx;
    float* OiVqrkNdXioJhALWMMvm;
    #endif

    bool isWgtsPadding = false;
    bool isBiasPadding = false;

    std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer3x3> m_fusedDepthwiseconvLayer3x3;  // used for Depthwise Convolution Layer with 3x3 kernels
    std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer> m_fusedDepthwiseconvLayer;       // used for Depthwise Convolution Layer
    std::unique_ptr<arm_compute::NEConvolutionLayer> m_fusedConvLayer;            // used for Convolution/1st half of grouped conv
    std::unique_ptr<arm_compute::NEConvolutionLayer> m_fusedConvLayerSecondGroup; // used for 2nd half of grouped conv
    arm_compute::Tensor m_fusedConvLayerWgtTensor;
    arm_compute::Tensor m_fusedConvLayerBiasTensor;
    arm_compute::SubTensor* m_prevLayer1; // subtensor for current layer input (1st half in grp conv)
    arm_compute::SubTensor* m_prevLayer2; // subtensor for current layer input (2nd half in grp conv)
    arm_compute::SubTensor* m_curLayer1;  // subtensor for current layer output (1st half in grp conv)
    arm_compute::SubTensor* m_curLayer2;  // subtensor for current layer output (2nd half in grp conv)

    arm_compute::SubTensor* m_fusedConvLayerWgtMWTensor;  // subtensor for conv weights (1st half in grp conv)
    arm_compute::SubTensor* m_fusedConvLayerWgtTensor2;   // subtensor for conv weights (2nd half in grp conv)
    arm_compute::SubTensor* m_fusedConvLayerBiasMWTensor; // subtensor for conv bias (1st half in grp conv)
    arm_compute::SubTensor* m_fusedConvLayerBiasTensor2;  // subtensor for conv bias (2nd half in grp conv)
    void propagateSize();

    void predict();
    void cleanup();
    void allocate();
    void deallocate();
    void loadWeights(const char*, int);
    void loadBias(const char*, int);

  public:
    MWFusedConvReLULayerImpl(MWCNNLayer*,
                             MWTargetNetworkImpl*,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             const char*,
                             const char*);
    ~MWFusedConvReLULayerImpl();
};

#endif
