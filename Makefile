.PHONY: help all test clean cpp23 cpp23-test cpp23-clean rust rust-test rust-clean modern modern-test modern-clean legacy legacy-test legacy-clean

# Makefile for GATL - Dual License Structure
# Legacy system: GPL v3.0 (cpp/, cpp23/include/gatl/ga/)
# Modern system: MPL 2.0 (cpp23/include/gatl/modern/, rust/)

help:
	@echo "GATL Build System - Dual License Structure"
	@echo "=========================================="
	@echo ""
	@echo "LEGACY SYSTEM (GPL v3.0):"
	@echo "  legacy        - Build legacy C++17 template metaprogramming (cpp/)"
	@echo "  legacy-test   - Run tests for legacy C++17 system"
	@echo "  legacy-clean  - Clean legacy build"
	@echo ""
	@echo "MODERN SYSTEM (MPL 2.0):"
	@echo "  modern        - Build modern C++23 + Rust implementations"
	@echo "  modern-test   - Run tests for modern system (C++23 + Rust)"
	@echo "  modern-clean  - Clean modern builds"
	@echo ""
	@echo "INDIVIDUAL TARGETS:"
	@echo "  cpp23         - Build C++23 modernized code only"
	@echo "  cpp23-test    - Run C++23 tests only"
	@echo "  cpp23-clean   - Clean C++23 build only"
	@echo "  rust          - Build Rust implementation only"
	@echo "  rust-test     - Run Rust tests only"
	@echo "  rust-clean    - Clean Rust build only"
	@echo ""
	@echo "CONVENIENCE TARGETS:"
	@echo "  all           - Build legacy system (backward compatibility)"
	@echo "  test          - Run legacy tests (backward compatibility)"
	@echo "  clean         - Clean all builds"
	@echo "  help          - Show this help message"
	@echo ""
	@echo "LICENSE INFO:"
	@echo "  - Legacy: GPL v3.0 (cpp/, cpp23/include/gatl/ga/)"
	@echo "  - Modern: MPL 2.0 (cpp23/include/gatl/modern/, rust/)"
	@echo "  - See LICENSING.md for detailed usage guidelines"

# ============================================================================
# LEGACY SYSTEM (GPL v3.0) - Original template metaprogramming
# ============================================================================

# Backward compatibility aliases
all: legacy
test: legacy-test
clean: legacy-clean cpp23-clean rust-clean

# Legacy C++17 template metaprogramming system
legacy:
	@echo "Building legacy C++17 template metaprogramming system (GPL v3.0)..."
	cmake -S cpp -B build -DCMAKE_CXX_STANDARD=17
	cmake --build build

legacy-test: legacy
	@echo "Running legacy C++17 tests..."
	./build/gatl_tests

legacy-clean:
	@echo "Cleaning legacy build..."
	rm -rf build

# ============================================================================
# MODERN SYSTEM (MPL 2.0) - New algebraic types
# ============================================================================

# Build both C++23 and Rust modern implementations
modern: cpp23 rust
	@echo "Modern system build complete (MPL 2.0)"

# Test both C++23 and Rust modern implementations
modern-test: cpp23-test rust-test
	@echo "Modern system tests complete (MPL 2.0)"

# Clean both modern builds
modern-clean: cpp23-clean rust-clean
	@echo "Modern system clean complete"

# ============================================================================
# C++23 MODERNIZED CODE (MPL 2.0)
# ============================================================================

cpp23:
	@echo "Building C++23 modernized code (MPL 2.0)..."
	cmake -S cpp23 -B cpp23/build
	cmake --build cpp23/build

cpp23-test: cpp23
	@echo "Running C++23 tests..."
	cd cpp23/build && ctest --output-on-failure

cpp23-clean:
	@echo "Cleaning C++23 build..."
	rm -rf cpp23/build

# ============================================================================
# RUST IMPLEMENTATION (MPL 2.0)
# ============================================================================

rust:
	@echo "Building Rust implementation (MPL 2.0)..."
	cd rust && cargo build

rust-test: rust
	@echo "Running Rust tests..."
	cd rust && cargo test

rust-clean:
	@echo "Cleaning Rust build..."
	cd rust && cargo clean

# ============================================================================
# DEVELOPMENT TARGETS
# ============================================================================

# Check both modern implementations
check: modern-test
	@echo "All modern system checks passed"

# Format code (if formatters are available)
format:
	@echo "Formatting C++23 code..."
	@if command -v clang-format >/dev/null 2>&1; then \
		find cpp23 -name "*.hpp" -o -name "*.cpp" | xargs clang-format -i; \
	else \
		echo "clang-format not found, skipping C++ formatting"; \
	fi
	@echo "Formatting Rust code..."
	@if command -v rustfmt >/dev/null 2>&1; then \
		cd rust && cargo fmt; \
	else \
		echo "rustfmt not found, skipping Rust formatting"; \
	fi

# Lint code (if linters are available)
lint:
	@echo "Linting C++23 code..."
	@if command -v clang-tidy >/dev/null 2>&1; then \
		cd cpp23 && cmake -B build && cmake --build build && \
		clang-tidy -p build -checks=*,-fuchsia-*,-google-*,-zircon-*,-abseil-*,-modernize-use-trailing-return-type; \
	else \
		echo "clang-tidy not found, skipping C++ linting"; \
	fi
	@echo "Linting Rust code..."
	@if command -v cargo-clippy >/dev/null 2>&1; then \
		cd rust && cargo clippy; \
	else \
		echo "cargo-clippy not found, skipping Rust linting"; \
	fi

# ============================================================================
# USAGE EXAMPLES
# ============================================================================

# Usage examples are now documented in the help target above
# Key usage patterns:
#
# Legacy system (GPL v3.0):
#   make legacy        # Build original template metaprogramming
#   make legacy-test   # Test original system
#
# Modern system (MPL 2.0):
#   make modern        # Build both C++23 and Rust
#   make modern-test   # Test both modern implementations
#
# Individual targets:
#   make cpp23         # Build only C++23 modern code
#   make rust          # Build only Rust implementation
#
# Development:
#   make format        # Format all code
#   make lint          # Lint all code
#   make check         # Run all tests for modern system
