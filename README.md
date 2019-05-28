Floor Detection
======================

Implementation of the Floor Detection Algorithm with maxima suppression.
For I/O and displaying the transformed image, OpenCV is used, whereas the Floor Detection Algorithm is completely self-implemented.

Prerequisite software
----------
- OpenCV 4.1 [http://opencv.org/]
- CMake [http://www.cmake.org/install/]

Build instructions
----------
- open a shell and cd into a directory wished to git-clone in.
- clone the repo: 
> git clone https://github.com/nolanle/floor-detection.git
- cd into it: 
> cd floor-detection
- create a build directory and cd into it: 
> mkdir build && cd build
- run cmake and initiate the build process: 
> cmake .. -DCMAKE_CXX_FLAGS="-std=c++11" && make

Usage
----------
./floordetection [jpg-file]
- Test images files can be found in "TestImages".
- Training images files can be found in "training_images".
