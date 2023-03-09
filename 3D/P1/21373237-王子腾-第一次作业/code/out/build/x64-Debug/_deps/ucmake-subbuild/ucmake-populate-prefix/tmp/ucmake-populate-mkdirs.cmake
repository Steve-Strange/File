# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/MGLDT/Desktop/3D/Project/_deps/UCMake-0.6.0"
  "C:/Users/MGLDT/Desktop/3D/Project/out/build/x64-Debug/_deps/ucmake-build"
  "C:/Users/MGLDT/Desktop/3D/Project/out/build/x64-Debug/_deps/ucmake-subbuild/ucmake-populate-prefix"
  "C:/Users/MGLDT/Desktop/3D/Project/out/build/x64-Debug/_deps/ucmake-subbuild/ucmake-populate-prefix/tmp"
  "C:/Users/MGLDT/Desktop/3D/Project/out/build/x64-Debug/_deps/ucmake-subbuild/ucmake-populate-prefix/src/ucmake-populate-stamp"
  "C:/Users/MGLDT/Desktop/3D/Project/out/build/x64-Debug/_deps/ucmake-subbuild/ucmake-populate-prefix/src"
  "C:/Users/MGLDT/Desktop/3D/Project/out/build/x64-Debug/_deps/ucmake-subbuild/ucmake-populate-prefix/src/ucmake-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/MGLDT/Desktop/3D/Project/out/build/x64-Debug/_deps/ucmake-subbuild/ucmake-populate-prefix/src/ucmake-populate-stamp/${subDir}")
endforeach()
