# MatLabToC--VoiceRecognize

 ![image](https://github.com/For-LD/MatLabToC--VoiceRecognize/blob/main/source/1.png)
 
# 项目描述
针对已经使用了支持NEON扩展的ARM®处理器的嵌入式平台，将基于已经训练完成的卷积神经网络的语音识别Matlab代码，生成适用于嵌入式平台的c++代码。

# 环境要求
- MATLAB Coder Interface for Deep Learning Libraries.
- ARM Compute Library
- Deep Learning Toolbox™
- GNU Toolchain for the A-profile architecture
- Environment variables for the compilers and libraries

# [详细转换过程---->CSDN](https://blog.csdn.net/qq_39716995/article/details/120512407)  



# 源码目录
```
│  CMakeLists.txt
│  commandNet.mat
│  README.md
│  VoiceRecognize.m
│  
├─.idea
│      .gitignore
│      .name
│      misc.xml
│      modules.xml
│      Test.iml
│      workspace.xml
│      
├─bin
│      1.wav
│      cnn_trainedNet_conv_1_b.bin
│      cnn_trainedNet_conv_1_w.bin
│      cnn_trainedNet_conv_2_b.bin
│      cnn_trainedNet_conv_2_w.bin
│      cnn_trainedNet_conv_3_b.bin
│      cnn_trainedNet_conv_3_w.bin
│      cnn_trainedNet_conv_4_b.bin
│      cnn_trainedNet_conv_4_w.bin
│      cnn_trainedNet_conv_5_b.bin
│      cnn_trainedNet_conv_5_w.bin
│      cnn_trainedNet_fc_b.bin
│      cnn_trainedNet_fc_w.bin
│      cnn_trainedNet_imageinput_offset.bin
│      cnn_trainedNet_imageinput_scale.bin
│      libarm_compute.so
│      libarm_compute_core.so
│      
├─cmake-build-debug
│  │  CMakeCache.txt
│  │  cmake_install.cmake
│  │  Makefile
│  │  VoiceRecognize
│  │  VoiceRecognize.cbp
│  │  
│  └─CMakeFiles
│      │  clion-environment.txt
│      │  clion-log.txt
│      │  cmake.check_cache
│      │  CMakeDirectoryInformation.cmake
│      │  CMakeOutput.log
│      │  feature_tests.bin
│      │  feature_tests.cxx
│      │  Makefile.cmake
│      │  Makefile2
│      │  progress.marks
│      │  TargetDirectories.txt
│      │  
│      ├─3.17.3
│      │  │  CMakeCXXCompiler.cmake
│      │  │  CMakeDetermineCompilerABI_CXX.bin
│      │  │  CMakeSystem.cmake
│      │  │  
│      │  └─CompilerIdCXX
│      │      │  a.out
│      │      │  CMakeCXXCompilerId.cpp
│      │      │  
│      │      └─tmp
│      ├─CMakeTmp
│      └─VoiceRecognize.dir
│          │  build.make
│          │  cmake_clean.cmake
│          │  CXX.includecache
│          │  depend.internal
│          │  depend.make
│          │  DependInfo.cmake
│          │  flags.make
│          │  link.txt
│          │  progress.make
│          │  
│          └─src
│                  
│                  
├─include
│      AsyncBuffercg.h
│      AsyncBuffercgHelper.h
│      AudioFile.h
│      AudioRead.h
│      blas.h
│      blascompat32.h
│      categorical.h
│      cellstr.h
│      classify.h
│      cnn_api.hpp
│      coder_array.h
│      covrt.h
│      cvstCG_acfObjectDetector.h
│      cvstCG_ComputeMetric.h
│      cvstCG_disparitySGM.h
│      cvstCG_foregroundDetector.h
│      cvstCG_kdtree.h
│      cvstCG_ocrutils.h
│      cvstCG_searchOrganizedPointCloud.h
│      cvstCG_voxelGridFilter.h
│      DeepLearningNetwork.h
│      designMelFilterBank.h
│      emlrt.h
│      engine.h
│      FFTImplementationCallback.h
│      fintrf.h
│      io64.h
│      lapack.h
│      lapacke.h
│      lapacke_config.h
│      libmwboxfilter.h
│      libmwboxfilter3.h
│      libmwbwdistEDT.h
│      libmwbwdistEDTFT.h
│      libmwbwdistEDTFT_tbb.h
│      libmwbwdistEDT_tbb.h
│      libmwbwlookup.h
│      libmwbwlookup_tbb.h
│      libmwbwpackc.h
│      libmwbwpackctbb.h
│      libmwbwunpackc.h
│      libmwbwunpackctbb.h
│      libmwcannythresholding_tbb.h
│      libmwddist.h
│      libmwedgesobelprewitt_tbb.h
│      libmwedgethinning_tbb.h
│      libmwgetnumcores.h
│      libmwgrayto16.h
│      libmwgrayto8.h
│      libmwgrayxform.h
│      libmwgrayxform_tbb.h
│      libmwimfilter.h
│      libmwimlincomb.h
│      libmwimlincomb_tbb.h
│      libmwimreconstruct.h
│      libmwimregionalmax.h
│      libmwimterp2d.h
│      libmwint16touint16.h
│      libmwint32touint32.h
│      libmwint8touint8.h
│      libmwintlut.h
│      libmwintluttbb.h
│      libmwippfilter.h
│      libmwippgeotrans.h
│      libmwippmedianfilter.h
│      libmwippreconstruct.h
│      libmwjpegreader.h
│      libmwmorphop_binary.h
│      libmwmorphop_binary_tbb.h
│      libmwmorphop_flat.h
│      libmwmorphop_flat_tbb.h
│      libmwmorphop_ipp.h
│      libmwmorphop_nonflat.h
│      libmwmorphop_nonflat_tbb.h
│      libmwmorphop_packed.h
│      libmwordfilt2.h
│      libmwremap.h
│      libmwremaptbb.h
│      libmwrgb2gray_tbb.h
│      libmwrgb2hsv_tbb.h
│      libmwtbbhist.h
│      libmwuint16toint16.h
│      main.h
│      mat.h
│      matlabCodegenHandle.h
│      MatlabCppSharedLib.hpp
│      MatlabDataArray.hpp
│      MatlabEngine.hpp
│      MatlabExecutionInterface.hpp
│      matrix.h
│      mclbase.h
│      mclcom.h
│      mclcomclass.h
│      mclcommain.h
│      mclcppclass.h
│      mclmcr.h
│      mclmcrrt.h
│      mclxlmain.h
│      mcr.h
│      melSpectrogram.h
│      mex.h
│      mex.hpp
│      mexAdapter.hpp
│      MWACLUtils.hpp
│      MWCNNLayerImpl.hpp
│      MWElementwiseAffineLayer.hpp
│      MWElementwiseAffineLayerImpl.hpp
│      MWFusedConvReLULayer.hpp
│      MWFusedConvReLULayerImpl.hpp
│      mwmathutil.h
│      mwservices.h
│      mwstringutil.h
│      MWTargetNetworkImpl.hpp
│      opencvgpumex.hpp
│      opencvmex.hpp
│      polygonBoolean.h
│      predict.h
│      rtGetInf.h
│      rtGetNaN.h
│      rtwtypes.h
│      rt_nonfinite.h
│      stft.h
│      SystemCore.h
│      tmwtypes.h
│      VoiceRecognize.h
│      VoiceRecognize_data.h
│      VoiceRecognize_initialize.h
│      VoiceRecognize_rtwutil.h
│      VoiceRecognize_terminate.h
│      VoiceRecognize_types.h
│      
├─source
│      1.png
│      
├─src
│      AsyncBuffercg.cpp
│      AsyncBuffercgHelper.cpp
│      AudioRead.cpp
│      categorical.cpp
│      cellstr.cpp
│      classify.cpp
│      cnn_api.cpp
│      DeepLearningNetwork.cpp
│      designMelFilterBank.cpp
│      FFTImplementationCallback.cpp
│      main.cpp
│      matlabCodegenHandle.cpp
│      melSpectrogram.cpp
│      MWACLUtils.cpp
│      MWCNNLayerImpl.cpp
│      MWElementwiseAffineLayer.cpp
│      MWElementwiseAffineLayerImpl.cpp
│      MWFusedConvReLULayer.cpp
│      MWFusedConvReLULayerImpl.cpp
│      MWTargetNetworkImpl.cpp
│      predict.cpp
│      rtGetInf.cpp
│      rtGetNaN.cpp
│      rt_nonfinite.cpp
│      stft.cpp
│      SystemCore.cpp
│      VoiceRecognize.cpp
│      VoiceRecognize_data.cpp
│      VoiceRecognize_initialize.cpp
│      VoiceRecognize_rtwutil.cpp
│      VoiceRecognize_terminate.cpp
│      
└─VoiceRecognize1_pkg
        buildInfo.mat
        rtw_proj.tmw
        

```
