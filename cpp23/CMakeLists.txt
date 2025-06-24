cmake_minimum_required(VERSION 3.20)
project(GATL_Cpp23 VERSION 1.0.0 LANGUAGES CXX)

# Set C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set compiler flags for C++23
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od /Zi")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /DNDEBUG")
endif()

# Include directories
include_directories(include)

# Test executable
add_executable(test_phase1_foundation test/test_phase1_foundation.cpp)

# Set output directory
set_target_properties(test_phase1_foundation PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Add test
enable_testing()
add_test(NAME Phase1Foundation COMMAND test_phase1_foundation)

# Print configuration info
message(STATUS "GATL C++23 Configuration:")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "  Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  C++ Flags: ${CMAKE_CXX_FLAGS}")

# Check for C++23 features
include(CheckCXXSourceCompiles)

check_cxx_source_compiles("
#include <concepts>
#include <bit>
#include <type_traits>

template<std::integral T>
constexpr T test_concept(T x) { return x; }

int main() {
    constexpr auto result = test_concept(42);
    return result;
}" CXX23_FEATURES_AVAILABLE)

if(NOT CXX23_FEATURES_AVAILABLE)
    message(FATAL_ERROR "C++23 features not available. Please use a C++23 compatible compiler.")
endif()

message(STATUS "C++23 features: OK") 