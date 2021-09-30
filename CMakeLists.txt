cmake_minimum_required(VERSION 3.17)
set(CMAKE_CROSSCOMPILING true)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR armv7-a)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

set(CMAKE_INSTALL_RPATH "")


project(VoiceRecognize CXX)

set(CMAKE_VERBOSE_MAKEFILE on)

add_definitions( -DUSE_18_05_LIBRARY )
set(CMAKE_CXX_STANDARD 11)

include_directories(include C:/Users/13542/Desktop/speech/home/bsgcomp/jenkins/workspace/ComputeLibrary_package_release/release_repository/arm_compute C:/Users/13542/Desktop/speech/home/bsgcomp/jenkins/workspace/ComputeLibrary_package_release/release_repository/arm_compute/include)

add_library(arm_compute SHARED IMPORTED)
set_property(TARGET arm_compute PROPERTY IMPORTED_NO_SONAME 1)
set_property(TARGET arm_compute PROPERTY IMPORTED_LOCATION "C:/Users/13542/Desktop/Test/bin/libarm_compute.so")

add_library(arm_compute_core SHARED IMPORTED)
set_property(TARGET arm_compute_core PROPERTY IMPORTED_NO_SONAME 1)
set_property(TARGET arm_compute_core PROPERTY IMPORTED_LOCATION "C:/Users/13542/Desktop/Test/bin/libarm_compute_core.so")

set(USER_C_FLAGS "-mfpu=neon -mfloat-abi=hard -march=armv7-a")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${USER_C_FLAGS} ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USER_C_FLAGS}")

aux_source_directory(src sources)
add_executable(VoiceRecognize ${sources} include/AudioRead.h)

target_link_libraries(VoiceRecognize arm_compute arm_compute_core)