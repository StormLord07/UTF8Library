#!/bin/bash

# Default paths
INSTALL_PATH_RELEASE="$(pwd)/UTF8Lib"
INSTALL_PATH_DEBUG="$(pwd)/UTF8LibDebug"

# Check if user provided an install path
if [ "$1" != "" ]; then
    INSTALL_PATH_RELEASE="$1/UTF8Lib"
fi

if [ "$2" != "" ]; then
    INSTALL_PATH_DEBUG="$2/UTF8LibDebug"
fi

# Create build directories if they don't exist
mkdir -p build

# Release
cmake . -B build/Release -DCMAKE_BUILD_TYPE=Release
cmake --build build/Release
cmake --install build/Release --prefix $INSTALL_PATH_RELEASE

# Debug
cmake . -B build/Debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build/Debug
cmake --install build/Debug --prefix $INSTALL_PATH_DEBUG
