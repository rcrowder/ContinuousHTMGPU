# External dependencies

## SFML 2.2
http://www.sfml-dev.org/index.php  -  Visual C++ 11 (2012) - 32-bit 
http://www.sfml-dev.org/tutorials/2.2/start-vc.php

## OpenGL

## OpenCL - AMD App SDK v3.0(beta) and v2.9.1
http://developer.amd.com/tools-and-sdks/opencl-zone/amd-accelerated-parallel-processing-app-sdk/#appsdkdownloads

## Build steps
cd \GitHub
cd ContinuousHTMGPU\ContinuousHTMGPU
cmake -G "Visual Studio 11 2012" -DSFML_STATIC_LIBRARIES=1 -DSFML_ROOT=..\SFML-2.2 -DOpenCL_INCPATH=C:\\Program Files (x86)\\AMD APP SDK\\3.0-0-Beta\\include -DOpenCL_LIBPATH=C:\\Program Files (x86)\\AMD APP SDK\\3.0-0-Beta\lib\x86 .

