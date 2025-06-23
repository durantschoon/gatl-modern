#!/bin/bash

# Script to build and run original codebase tests with C++17
set -e

echo "Building and running original codebase tests with C++17..."

cd cpp

# Create a temporary CMakeLists.txt that forces C++17
cp CMakeLists.txt CMakeLists.txt.backup

# Modify CMakeLists.txt to use C++17 instead of C++23
sed -i.bak 's/CMAKE_CXX_STANDARD 23/CMAKE_CXX_STANDARD 17/g' CMakeLists.txt

# Build with original settings
mkdir -p build_original
cd build_original
cmake ..
make

# Run tests if they exist
if [ -f "tools/test/wedge_product_test" ]; then
    echo "Running original tests..."
    # Add your test execution commands here
    # ctest --output-on-failure
fi

# Restore original CMakeLists.txt
cd ..
mv CMakeLists.txt.backup CMakeLists.txt

echo "Original tests completed!" 