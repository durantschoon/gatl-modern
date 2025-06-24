.PHONY: cpp23 cpp23-test cpp23-clean

# Makefile for GATL

# Default: build original C++ code (cpp/)
all:
	cmake -S cpp -B build -DCMAKE_CXX_STANDARD=23
	cmake --build build

test: all
	./build/gatl_tests

clean:
	rm -rf build

# --- C++23 Modernized Code (cpp23/) ---

cpp23:
	cmake -S cpp23 -B cpp23/build
	cmake --build cpp23/build

cpp23-test: cpp23
	cd cpp23/build && ctest --output-on-failure

cpp23-clean:
	rm -rf cpp23/build

# Usage:
#   make            # Build original C++ code (cpp/)
#   make test       # Run tests for original C++ code
#   make clean      # Clean original build
#   make cpp23      # Build C++23 modernized code (cpp23/)
#   make cpp23-test # Run tests for C++23 code
#   make cpp23-clean# Clean C++23 build
