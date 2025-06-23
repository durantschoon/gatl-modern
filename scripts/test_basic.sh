#!/bin/bash

# Basic test runner - always works, shows placeholder status
set -e

echo "=== Basic Test Runner (String-based Placeholder) ==="
echo "This test uses string manipulation to verify the test infrastructure."
echo "It does NOT use actual GATL geometric algebra operations."
echo "Compiled with C++23 standard."
echo ""

cd cpp
mkdir -p build_basic
cd build_basic

# Create a simple CMakeLists.txt for basic testing
cat > CMakeLists.txt << 'EOF'
cmake_minimum_required(VERSION 3.21)
project(GATL-Basic-Test)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find nlohmann/json
find_package(nlohmann_json 3.11.2 REQUIRED)

# Add the basic test executable
add_executable(basic_test ../tools/test/wedge_product_tests.cpp)

# Link nlohmann/json
target_link_libraries(basic_test PRIVATE nlohmann_json::nlohmann_json)

# Include directories
target_include_directories(basic_test PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../tools/test
)

# Define USE_GATL=0 to ensure only string-based implementation is used
target_compile_definitions(basic_test PRIVATE USE_GATL=0)
EOF

# Build and run
cmake .
make

echo ""
echo "Running basic tests..."
./basic_test

echo ""
echo "✓ Basic test infrastructure is working!"
echo "  (This uses string-based placeholder implementation with C++23)" 