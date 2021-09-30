/* Copyright 2019 The MathWorks, Inc. */
#ifndef __ELEMENTWISE_AFFINE_LAYER_IMPL_HPP
#define __ELEMENTWISE_AFFINE_LAYER_IMPL_HPP

#include "MWCNNLayerImpl.hpp"
#include "MWElementwiseAffineLayer.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"

/**
 *  Codegen class for Scaling Factor layer
 **/
class MWCNNLayer;
class MWTargetNetworkImpl;
class MWElementwiseAffineLayerImpl : public MWCNNLayerImpl {
  public:
    MWElementwiseAffineLayerImpl(MWCNNLayer* layer,
                                 MWTargetNetworkImpl* ntwk_impl,
                                 int scale_H,
                                 int scale_W,
                                 int scale_C,
                                 int offset_H,
                                 int offset_W,
                                 int offset_C,
                                 bool isClipped,
                                 int lowerbound,
                                 int upperbound,
                                 const char* scale_file,
                                 const char* offsetfile);
    ~MWElementwiseAffineLayerImpl();

    void propagateSize();
    virtual void predict();
    virtual void cleanup();
    void allocate();
    void deallocate();

  private:
    std::unique_ptr<arm_compute::NEActivationLayer> m_actLayer;
    std::unique_ptr<arm_compute::NEPixelWiseMultiplication> m_prodLayer;
    std::unique_ptr<arm_compute::NEArithmeticAddition> m_addLayer;
    std::unique_ptr<arm_compute::NEDepthwiseConvolutionLayer> m_depthwiseLayer; 
    arm_compute::Tensor tmparmTensor;
    arm_compute::Tensor scaleTensor;
    arm_compute::Tensor tmpScaleTensor;
    arm_compute::Tensor offsetTensor;
    void loadScale(const char*);
    void loadOffset(const char*);
    #if defined(USE_18_05_LIBRARY) | defined(USE_18_08_LIBRARY)
    arm_compute::MemoryRegion* rIcMzXptfYweLArNRnBw;
    arm_compute::MemoryRegion* jHzoRQWaHafftmrmuvHO;
    #else
    float* rIcMzXptfYweLArNRnBw;
    float* jHzoRQWaHafftmrmuvHO;
    #endif
    bool isScalePadded = false;
    bool isOffsetPadded = false;

    double rrWNoFNRUEdlTvIOmCla;
    double rytJDHzuydvYOLNNROYf;
    double rlQsibXJSWJVnUVpdNeL;
    double kFQQPKSOkZeHlmrkAXuE;
    double kqftrrQBBOgGsrDSkIUk;
    double jmcFOAbZArjGDNhshSro;
    bool atVCyzqXZAZxwlkRLBRA;
    int edQOkUJIZbwzEeIcCLzG;
    int vpXxoeEhdEosLSsYXkNG;
    bool isScaleScalar = false, isScaleVector = false, isScaleMatrix = false;
    bool isOffsetScalar = false, isOffsetVector = false, isOffsetMatrix = false;
    void initTempAllocators();
    void initScaleOffsetTensors();
    void createScaleAffine();
    void createOffsetAffine();    
    void getScaleType();
    void getOffsetType();
    void clipAffineOutput();
};



#endif
