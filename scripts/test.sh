#!/bin/bash

# Master test runner
set -e

echo "=== GATL Test Runner ==="
echo "1. Basic test (always works, string-based placeholder)"
echo "2. C++23 test (attempts real GATL, shows modernization needs)"
echo "3. Run both"
echo ""
read -p "Choose option (1-3): " choice

case $choice in
    1)
        echo "Running basic test..."
        ./scripts/test_basic.sh
        ;;
    2)
        echo "Running C++23 test..."
        ./scripts/test_cpp23.sh
        ;;
    3)
        echo "Running both tests..."
        ./scripts/test_basic.sh
        echo ""
        echo "---"
        echo ""
        ./scripts/test_cpp23.sh
        ;;
    *)
        echo "Invalid option. Please run the script again."
        exit 1
        ;;
esac 