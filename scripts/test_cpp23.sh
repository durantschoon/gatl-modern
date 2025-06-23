#!/bin/bash

# C++23 test runner - attempts to use actual GATL code
set -e

echo "=== C++23 Test Runner (Attempts Real GATL) ==="
echo "This test attempts to use actual GATL geometric algebra operations."
echo "It will show errors that need to be fixed as the codebase modernizes."
echo ""

cd cpp
mkdir -p build_cpp23
cd build_cpp23

# Create a CMakeLists.txt for C++23 testing with GATL
cat > CMakeLists.txt << 'EOF'
cmake_minimum_required(VERSION 3.21)
project(GATL-CPP23-Test)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find nlohmann/json
find_package(nlohmann_json 3.11.2 REQUIRED)

# Add the C++23 test executable
add_executable(cpp23_test ../tools/test/wedge_product_tests.cpp)

# Link nlohmann/json
target_link_libraries(cpp23_test PRIVATE nlohmann_json::nlohmann_json)

# Include directories - include GATL headers
target_include_directories(cpp23_test PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../tools/test
)

# Define USE_GATL=1 to enable GATL integration
target_compile_definitions(cpp23_test PRIVATE USE_GATL=1)
EOF

# Build and run
echo "Building with C++23 and GATL headers..."
if cmake . && make; then
    echo ""
    echo "✓ C++23 build successful! Running tests..."
    ./cpp23_test
else
    echo ""
    echo "✗ C++23 build failed. This is expected as GATL needs modernization."
    echo "  Errors above show what needs to be fixed in the codebase."
    echo "  Use './scripts/test_basic.sh' for working tests in the meantime."
    exit 1
fi 