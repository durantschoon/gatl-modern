#!/bin/bash

# Master script to run all tests
set -e

echo "=== GATL Test Runner ==="
echo "1. Run new C++23 tests"
echo "2. Run original codebase tests (C++17)"
echo "3. Run both"
echo "4. Run Rust tests"
echo "5. Run all tests"
echo ""
read -p "Choose option (1-5): " choice

case $choice in
    1)
        echo "Running C++23 tests..."
        ./scripts/run_cpp23_tests.sh
        ;;
    2)
        echo "Running original codebase tests..."
        ./scripts/run_original_tests.sh
        ;;
    3)
        echo "Running both C++ test suites..."
        ./scripts/run_cpp23_tests.sh
        echo ""
        ./scripts/run_original_tests.sh
        ;;
    4)
        echo "Running Rust tests..."
        cd rust
        cargo test
        cd ..
        ;;
    5)
        echo "Running all tests..."
        ./scripts/run_cpp23_tests.sh
        echo ""
        ./scripts/run_original_tests.sh
        echo ""
        cd rust
        cargo test
        cd ..
        ;;
    *)
        echo "Invalid option. Please run the script again."
        exit 1
        ;;
esac

echo "All selected tests completed!" 