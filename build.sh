#!/bin/bash

# Author: Frank Leveque
# This shell script generates 3 projects in the ./build/ directory 
# 1 - Unix Makefile - Debug
# 2 - Unix Makefile - Release
# 3 - CodeBlocks - Unix Makefile
# Then builds 1 and 2 (Open the codeblocks .cbp manually if needed)
# This should work under GNU/Linux and Windows with MSYS/MinGW

reset; 

# move to this folder
cd "$(dirname "$0")" > /dev/null 2>&1

rm ./CMakeCache.txt > /dev/null 2>&1

# create subfolders
mkdir -p build
mkdir -p build/debug
mkdir -p build/release
mkdir -p build/codeblocks

# generate projects 
cd ./build/debug 
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE="Debug" ../..

cd ../../

cd ./build/release
cmake  -G "Unix Makefiles" -DCMAKE_BUILD_TYPE="Release" ../..

cd ../../

cd ./build/codeblocks
cmake -G "CodeBlocks - Unix Makefiles" -DCMAKE_BUILD_TYPE="Debug" ../.. 

cd ../../

case "$OSTYPE" in
	linux*)   
        echo Linux detected
		make -j5 -C ./build/debug 
		make -j5 -C ./build/release/ > /dev/null 2>&1
		;;
	darwin*)
        echo Mac detected
		make -j5 -C ./build/debug 
		make -j5 -C ./build/release/ > /dev/null 2>&1
		;; 
	msys*)     
        echo Win detected
		mingw32-make -j5 -C ./build/debug/ 
		mingw32-make -j5 -C ./build/release/ > /dev/null 2>&1
		;;
	cygwin*)  echo unsupported: "Cygwin" ;;
	bsd*)     echo unsupported: "BSD" ;;
	solaris*) echo unsupported: "SOLARIS" ;;
	*)        echo "unknown: $OSTYPE" ;;
esac

