# Linear Algebra Library

This library hosts C++ implementation of some of the routines which are most frequently encountered in Linear Algebra.

## Installation
The project can be configured using CMake. The steps for the same are given below:

+ Create a directory where you want the binaries to build. Let's call it the build directory.

```shell
mkdir build
```
+ Change the working directory to the build directory and run CMake as follows:

```shell
cd build
cmake ..
```

+ After the configuration is complete, the Makefile is generated inside the build directory. You can now compile the project and run the executable as follows:

```shell
make
./LinearAlgebra
```

## How to Contribute
Each new module should go into a different directory whose name must be synonymous with the module functionality. 

Let us suppose, you want to add a module for Singular Value Decomposition (S.V.D.) and you have implemented two files for this purpose: ``` svd.h ``` and ``` svd.cpp ```. Both these files should reside inside a separate directory named ``` svd ``` which would also contain a ``` CMakeLists.txt ```. Add the follwing line to the ``` CMakeLists.txt ```residing inside the module directory :

```shell
add_library(SVD svd.cpp)
```
This instruction tells CMake to build a library from the function implementations in ```svd.cpp```. 

To make use of this library, we add a few statements to the top level ```CMakeLists.txt``` file, which are given below:

```shell
include_directories("${PROJECT_SOURCE_DIR}/svd")
add_subdirectory(svd)
```
The ``` include_directory() ``` command tells CMake to look inside the ``` svd ``` directory for the header files for this library and the ``` add_subdirectory() ``` call ensures that the ``` svd ``` library gets built.

The final step would be to add (link) the library with the executable where it's actually being used. Say, you want to reference some functions from the ``` svd ``` module in ``` main.cpp ```. Adding the following line to the top level ``` CMakeLists.txt ``` serves this purpose:

```shell
# LinearAlgebra is the name of the executable built from main.cpp
# SVD is the name of the executable built from the library modules
target_link_libraries(LinearAlgebra SVD)
```

The module is now ready to be used with main.cpp with the inclusion of a simple ``` #include "svd.h" ```
