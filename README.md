# Branch info: feature/modernize-cpp23

⚙️ **Modernization in Progress**: This fork of GATL is being actively updated to C++23, with a focus on test-driven development using doctest. We're modernizing the codebase to take advantage of new language features while preserving compatibility with the original API. Future phases might explore C++26 enhancements.

⚙️ **Multi-Language Goals**: This fork will experiment with Rust implementations, using shared tests to ensure consistency across language versions. The Rust implementation provides a parallel, memory-safe alternative with the same geometric algebra capabilities.

⚙️ **Dual License Structure**: The project now uses a dual license approach - the legacy template metaprogramming system remains under GPL v3.0, while the new modern algebraic types are under MPL 2.0 for more permissive usage.

## 🚀 Development Goals

- **C++23 Modernization**: Update codebase to leverage C++23 features while maintaining API compatibility
- **Test-Driven Development**: Implement comprehensive test suite using doctest framework
- **Rust Implementation**: Create parallel Rust version with shared test specifications and memory-safe geometric algebra operations
- **Cross-Language Consistency**: Ensure both C++ and Rust implementations produce identical results through shared test data
- **Performance Optimization**: Leverage compile-time optimizations and modern language features
- **Documentation**: Maintain comprehensive documentation for both C++ and Rust versions

## 🧪 Testing Infrastructure

The project includes a comprehensive testing framework with multiple test runners:

### Test Scripts (./scripts/)

- **`test.sh`** - Master test runner with interactive menu
- **`test_basic.sh`** - Basic C++23 tests (string-based placeholder, always works)
- **`test_cpp23.sh`** - Advanced C++23 tests (attempts real GATL operations)
- **`run_all_tests.sh`** - Comprehensive test runner for all language versions
- **`run_original_tests.sh`** - Original C++17 codebase tests

### Quick Start Testing

**Modern System (C++23 + Rust):**
```bash
make modern-test    # Run both C++23 and Rust tests
```

**Legacy System (C++17):**
```bash
make legacy-test    # Run original C++17 tests
```

**Individual Language Tests:**
```bash
make cpp23-test     # Run C++23 tests only
make rust-test      # Run Rust tests only
```

**Interactive Test Menu:**
```bash
./scripts/test.sh   # Interactive menu for all test types
```

## 🛠️ Build and Installation

### Modern System (C++23 + Rust - Recommended)
```bash
git clone https://github.com/durantschoon/gatl.git
cd gatl
make modern
make modern-test
```

The `cpp23/include` directory contains the modernized C++23 headers with:
- Modern C++23 features (concepts, constexpr, etc.)
- Tau-based mathematical constants (τ = 2π)
- Enhanced type safety with concepts
- Improved error handling and exception safety
- Better performance with modern standard library usage

### Legacy System (Original C++17)
```bash
git clone https://github.com/durantschoon/gatl.git
cd gatl
make legacy
make legacy-test
```

The directory `cpp/include` contains the original C++17 headers.

### All Available Make Targets
```bash
make help          # Show all available targets
make modern        # Build modern system (C++23 + Rust)
make modern-test   # Test modern system (C++23 + Rust)
make modern-clean  # Clean modern builds
make legacy        # Build legacy C++17 system
make legacy-test   # Test legacy C++17 system
make legacy-clean  # Clean legacy build
```

## 3. Compiling Examples

### Modern System Examples (C++23)
```bash
cd cpp23/tools/example
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### Legacy System Examples (C++17)
```bash
cd cpp/tools/example
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

The executable files produced by the last command start with `gatl_example_`.

### CMake extensions from preset file:

On any platform:

```sh
# Configure and build debug version
cmake --preset debug
cmake --build --preset debug

# Configure and build release version
cmake --preset release
cmake --build --preset release

# Run tests
ctest --preset debug  # or release
```

For debugging memory issues:
```sh
cmake --preset asan
cmake --build --preset asan
```

For debugging undefined behavior:
```sh
cmake --preset ubsan
cmake --build --preset ubsan
```

## 4. Compiling and Running Unit-Tests

### Modern System Tests (C++23 + Rust)
```bash
make modern-test    # Run both C++23 and Rust tests
./scripts/test.sh   # Interactive test menu
```

### Legacy System Tests (C++17)
```bash
make legacy-test    # Run original C++17 tests
```

### Individual Language Tests
```bash
make cpp23-test     # Run C++23 tests only
make rust-test      # Run Rust tests only
```

### Cross-Language Tests
```bash
./scripts/test.sh   # Interactive menu for all test types
```

## 5. Documentation

Here you find a brief description of the namespaces, macros, classes, functions, procedures, and operators available for the user. The detailed documentation is not ready yet.

According to GATL conventions, in the following definitions, `lhs` and `rhs` are informal shorthand for, respectively, the left-hand side and the right-hand side arguments of binary procedures. In addition, the `mtr` argument must be an instance of the `metric_space<...>` class, while all other arguments can be either an instances of the `clifford_expression<...>` class or other numerical types (*e.g.*, `double`, `float`, `int`, or instances of third-party classes). Numerical types are automatically converted by GATL to scalar Clifford expression using the `scalar` function.

Contents:

- [Branch info: feature/modernize-cpp23](#branch-info-featuremodernize-cpp23)
  - [🚀 Development Goals](#-development-goals)
  - [🧪 Testing Infrastructure](#-testing-infrastructure)
    - [Test Scripts (./scripts/)](#test-scripts-scripts)
    - [Quick Start Testing](#quick-start-testing)
  - [🛠️ Build and Installation](#️-build-and-installation)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended)
    - [Legacy System (Original C++17)](#legacy-system-original-c17)
    - [All Available Make Targets](#all-available-make-targets)
  - [3. Compiling Examples](#3-compiling-examples)
    - [Modern System Examples (C++23)](#modern-system-examples-c23)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17)
    - [Individual Language Tests](#individual-language-tests)
    - [Cross-Language Tests](#cross-language-tests)
  - [5. Documentation](#5-documentation)
    - [Namespaces](#namespaces)
    - [Macros](#macros)
    - [Classes and Data Types](#classes-and-data-types)
    - [Utilities Constants and Functions](#utilities-constants-and-functions)
    - [Products and Basic Operations](#products-and-basic-operations)
    - [Overloaded Operators](#overloaded-operators)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions)
    - [Tools](#tools)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library)
  - [Acknowledgments](#acknowledgments)
  - [1. Requirements](#1-requirements)
  - [2. How to Build and Install](#2-how-to-build-and-install)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-1)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-1)
    - [All Available Make Targets](#all-available-make-targets-1)
  - [3. Compiling Examples](#3-compiling-examples-1)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-1)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-1)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-1)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-1)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-1)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-1)
    - [Individual Language Tests](#individual-language-tests-1)
    - [Cross-Language Tests](#cross-language-tests-1)
  - [5. Documentation](#5-documentation-1)
    - [Namespaces](#namespaces-1)
    - [Macros](#macros-1)
    - [Classes and Data Types](#classes-and-data-types-1)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-1)
    - [Products and Basic Operations](#products-and-basic-operations-1)
    - [Overloaded Operators](#overloaded-operators-1)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-1)
    - [Tools](#tools-1)
  - [6. Related Project](#6-related-project)
  - [7. License](#7-license)
    - [License Information](#license-information)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-1)
  - [Acknowledgments](#acknowledgments-1)
  - [1. Requirements](#1-requirements-1)
  - [2. How to Build and Install](#2-how-to-build-and-install-1)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-2)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-2)
    - [All Available Make Targets](#all-available-make-targets-2)
  - [3. Compiling Examples](#3-compiling-examples-2)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-2)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-2)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-2)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-2)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-2)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-2)
    - [Individual Language Tests](#individual-language-tests-2)
    - [Cross-Language Tests](#cross-language-tests-2)
  - [5. Documentation](#5-documentation-2)
    - [Namespaces](#namespaces-2)
    - [Macros](#macros-2)
    - [Classes and Data Types](#classes-and-data-types-2)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-2)
    - [Products and Basic Operations](#products-and-basic-operations-2)
    - [Overloaded Operators](#overloaded-operators-2)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-2)
    - [Tools](#tools-2)
  - [6. Related Project](#6-related-project-1)
  - [7. License](#7-license-1)
    - [License Information](#license-information-1)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-2)
  - [Acknowledgments](#acknowledgments-2)
  - [1. Requirements](#1-requirements-2)
  - [2. How to Build and Install](#2-how-to-build-and-install-2)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-3)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-3)
    - [All Available Make Targets](#all-available-make-targets-3)
  - [3. Compiling Examples](#3-compiling-examples-3)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-3)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-3)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-3)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-3)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-3)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-3)
    - [Individual Language Tests](#individual-language-tests-3)
    - [Cross-Language Tests](#cross-language-tests-3)
  - [5. Documentation](#5-documentation-3)
    - [Namespaces](#namespaces-3)
    - [Macros](#macros-3)
    - [Classes and Data Types](#classes-and-data-types-3)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-3)
    - [Products and Basic Operations](#products-and-basic-operations-3)
    - [Overloaded Operators](#overloaded-operators-3)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-3)
    - [Tools](#tools-3)
  - [6. Related Project](#6-related-project-2)
  - [7. License](#7-license-2)
    - [License Information](#license-information-2)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-3)
  - [Acknowledgments](#acknowledgments-3)
  - [1. Requirements](#1-requirements-3)
  - [2. How to Build and Install](#2-how-to-build-and-install-3)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-4)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-4)
    - [All Available Make Targets](#all-available-make-targets-4)
  - [3. Compiling Examples](#3-compiling-examples-4)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-4)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-4)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-4)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-4)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-4)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-4)
    - [Individual Language Tests](#individual-language-tests-4)
    - [Cross-Language Tests](#cross-language-tests-4)
  - [5. Documentation](#5-documentation-4)
    - [Namespaces](#namespaces-4)
    - [Macros](#macros-4)
    - [Classes and Data Types](#classes-and-data-types-4)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-4)
    - [Products and Basic Operations](#products-and-basic-operations-4)
    - [Overloaded Operators](#overloaded-operators-4)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-4)
    - [Tools](#tools-4)

### Namespaces

Namespaces are declarative regions that provide scope to the names of the types, function, variables, *etc.*, inside it. GATL defines the following namespaces.

| Namespace | Description |
| --- | --- |
| `ga` | The main namespace that encloses all GATL implementations |
| `ga1e`, `ga2e`, `ga3e`, `ga4e`, `ga5e` | The namespace of Euclidean geometric algebra of R<sup>*n*</sup> |
| `ga1h`, `ga2h`, `ga3h`, `ga4h` | The namespace of homogeneous/projective geometric algebra of R<sup>*d*</sup> (*n* = *d* + 1) |
| `ga1p`, `ga2p`, `ga3p`, `ga4p` | The namespace of plane-based geometric algebra of R<sup>*d*</sup> (*n* = *d* + 1) |
| `ga1m`, `ga2m`, `ga3m` | The namespace of Mikowski/spacetime algebra of R<sup>*d*</sup> (*n* = *d* + 2) |
| `ga1c`, `ga2c`, `ga3c` | The namespace of conformal geometric algebra of R<sup>*d*</sup> (*n* = *d* + 2) |

The namespaces of specific geometric algebras (*e.g.*, `ga3e`, `ga3h`, `ga3m`, and `ga3c`) already use the `ga` namespace. In addition, they overload all metric operations presented in the following section by setting the `mtr` argument according to their respective spaces.

All above-mentioned namespaces declare a nested `detail` namespace. This is the namespace where the magic happens. Don't touch it!

According to the GATL conventions, the root directory for the header files that you will include in your program is the `gatl` folder. Also, the header file for each namespace is its name followed by the `.hpp` extension. Putting both conventions together, we have `gatl/ga.hpp`, `gatl/ga3e.hpp`, `gatl/ga3h.hpp`, `gatl/ga3m.hpp`, `gatl/ga3c.hpp`, and so on.

### Macros

Optionally, set the following macros before including GATL headers in your program to change some conventions of the library.

| Class | Description |
| --- | --- |
| `GA_DEFAULT_FLOATING_POINT_TYPE` | Defines the floating-point type assumed as default by the library (default is `std::double_t`) |
| `GA_DEFAULT_INTEGRAL_TYPE` | Defines the signed integral type assumed as default by the library (default is `std::int64_t`) |
| `GA_MAX_BASIS_VECTOR_INDEX` | Defines the maximum number of basis vectors assumed while performing algebraic manipulations and setting the size of bitsets (default is `63`) |

### Classes and Data Types

The following basic data types are defined in order to assign a meaning to conventional types, like `double`, `int`, and so on.

| Basic Type | Description |
| --- | --- |
| `default_floating_point_t` | The floating point type assumed as default by the library (see `GA_DEFAULT_FLOATING_POINT_TYPE`) |
| `default_integral_t` | The signed integral type assumed as default by the library (see `GA_DEFAULT_INTEGRAL_TYPE`) |
| `bitset_t` | The bitset type used by the library (uses `GA_MAX_BASIS_VECTOR_INDEX` to select the smallest unsigned integral type capable to meet implementation requirements) |
| `grade_t` | The signed integral type used to represent grade values  (same as `default_integral_t`) |
| `index_t` | The unsigned integral type used to represent the index of basis vectors (set to `std::uint64_t`) |
| `ndims_t` | The unsigned integral type used to represent the number of dimensions of the vector space (same as `index_t`) |
| `associative_container_t<ValueType>` | The associative container class used by the `clifford_expression<...>` class to store components of multivectors (set to `std::map<bitset_t, ValueType>`) |
| `sequence_container_t<EntryType, Size>` | The sequence container class used by the `clifford_expression<...>` class to store components of multivectors (set to `std::array<EntryType, Size>`) |

The following classes correspond to the most important structures of GATL.

| Class | Description |
| --- | --- |
| `clifford_expression<CoefficientType, Expression>` | A Clifford expression |
| `grade_result<Value>` | A class to encode the result of the `grade` function |
| `lazy_context<InputTypes...>` | A class to define lazy arguments for lazy evaluation of Clifford expressions |
| `metric_space<MetricSpaceType>` | The base metric space class |

| Exception Class | Description |
| --- | --- |
| `bad_checked_copy_exception` | An exception of this type is thrown when a checked copy fails |
| `not_implemented_error` | An exception to report errors related to not implemented features |

For the sake of simplicity, GATL provides the following set of class aliases and helper meta-functions to assist type definition. Nevertheless, it is strongly recommended to use the `auto` placeholder type specifier (please, refer to the [C++ specification](https://en.cppreference.com/w/cpp/language/auto) for details) whenever possible.

| Class Alias | Description |
| --- | --- |
| `constant<CoefficientType, IntegralValue>` | An alias for constant scalar Clifford expressions whose coefficient is known in compile time |
| `scalar_clifford_expression<CoefficientType, Coefficient>` | An alias for scalar Clifford expressions |

| Helper for Practical Type Definition | Description |
| --- | --- |
| `full_multivector_t<CoefficientType, VectorSpaceDimensions [, FirstGrade [, LastGrade]]>` | Helper for defining a Clifford expression representing a general multivector with runtime defined coefficients over an *n*-dimensional vector space |
| `full_derived_multivector_t<CoefficientType, Expression>` | Helper for defining a Clifford expression representing a general multivector with runtime defined coefficients in all components of the given Clifford expression |
| `full_kvector_t<CoefficientType, VectorSpaceDimensions, Grade>` | Helper for defining a Clifford expression representing a *k*-vector with runtime defined coefficients over an *n*-dimensional vector space |
| `full_vector_t<CoefficientType, VectorSpaceDimensions>` | Helper for defining a Clifford expression representing a vector with runtime defined coefficients over an *n*-dimensional vector space |
| `scaled_constant_basis_blade_t<CoefficientType, Indices...>` | Helper for defining a Clifford expression representing a scaled compile-time defined basis blade |
| `scaled_constant_basis_vector_t<CoefficientType, Index>` | Helper for defining a Clifford expression representing a scaled compile-time defined basis vector |
| `scaled_basis_blade_t<CoefficientType, FirstPossibleGrade[, LastPossibleGrade]>` | Helper for defining a Clifford expression representing a scaled runtime defined basis blade |
| `scaled_basis_vector_t<CoefficientType>` | Helper for defining a Clifford expression representing a scaled runtime defined basis vector |
| `scaled_scalar_t<CoefficientType>` | Helper for defining a Clifford expression representing a scalar value whose coefficient is unknown in compile time |
| `scaled_pseudoscalar_t<CoefficientType, N>` | Helper for defining a Clifford expression representing a scaled compile-time defined pseudoscalar |
| `unit_constant_basis_blade_t<Indices...>` | Helper for defining a Clifford expression representing an unit compile-time defined basis blade |
| `unit_constant_basis_vector_t<Index>` | Helper for defining a Clifford expression representing an unit compile-time defined basis vector |
| `unit_basis_blade_t<FirstPossibleGrade [, LastPossibleGrade]>` | Helper for defining a Clifford expression representing an unit runtime defined basis blade |
| `unit_basis_vector_t` | Helper for defining a Clifford expression representing an unit runtime defined basis vector |
| `unit_pseudoscalar_t<N>` | Helper for defining a Clifford expression representing an unit compile-time defined pseudoscalar |

### Utilities Constants and Functions

Here you find some useful meta-constants and functions to assist the implementation of your program.

| Constant | Description |
| --- | --- |
| `c<IntegralValue [, CoefficientType]>` | Defines a constant scalar Clifford expression whose coefficient is known in compile time |

| Function | Description |
| --- | --- |
| `make_lazy_context(inputs...)` | Creates a `lazy_context<InputTypes...>` object |
| `make_lazy_context_tuple(inputs...)` | Creates a `std::tuple` object made of `K + 1` entries, where the first is a `lazy_context<InputTypes...>` object and the next `K` entries are the lazy input arguments |
| `e(index)` | Returns a runtime defined unit basis vector (index values can be set using `c<IntegralValue>`, too) |
| `scalar(arg)` | Converts the given numerical value to a scalar Clifford expression |
| `pseudoscalar([mtr])` | Returns the compile-time defined unit pseudoscalar of the given metric space |
| `vector([mtr,] coords...)` | Makes a vector with the given set of coordinates (coordinate values can be set using `c<IntegralValue>`, too) |
| `vector([mtr,] begin, end)` | Makes a vector with the set of coordinates accessed by the iterators |

### Products and Basic Operations

The following tables present a set of basic products and operations from geometric algebra.

| Product | Description |
| --- | --- |
| `cp(lhs, rhs [, mtr])` | Commutator product |
| `dp(lhs, rhs [, tol] [, mtr])` | Delta product |
| `dot(lhs, rhs [, mtr])` | Dot product |
| `gp(lhs, rhs [, mtr])` | Geometric/Clifford product |
| `hip(lhs, rhs [, mtr])` | Hestenes inner product |
| `igp(lhs, rhs [, mtr])` | Inverse geometric/Clifford product (the argument `rhs` must be a versor)  |
| `lcont(lhs, rhs [, mtr])` | Left contraction |
| `op(lhs, rhs [, mtr])` | Outer/Wedge product |
| `rp(lhs, rhs [, mtr])` | Regressive product |
| `rcont(lhs, rhs [, mtr])` | Right contraction |
| `sp(lhs, rhs [, mtr])` | Scalar product |

| Sign-Change Operation | Description |
| --- | --- |
| `conjugate(arg)` | Clifford conjugation |
| `involute(arg)` | Grade involution |
| `reverse(arg)` | Reversion |

| Dualization Operation | Description |
| --- | --- |
| `dual(arg [, pseudoscalar [, mtr]])` | Dualization operation |
| `undual(arg [, pseudoscalar [, mtr]])` | Undualization operation |

| Norm-Based Operation | Description |
| --- | --- |
| `rnorm_sqr(arg [, mtr])` | Squared reverse norm |
| `rnorm(arg [, mtr])` | Reverse norm |
| `inv(arg [, mtr])` | Inverse of the given versor using the squared reverse norm |
| `unit(arg [, mtr])` | Unit under reverse norm |

| Transformation Operation | Description |
| --- | --- |
| `apply_even_versor(versor, arg [, mtr])` | Returns the argument transformed by the even versor using the sandwich product |
| `apply_odd_versor(versor, arg [, mtr])` | Returns the argument transformed by the odd versor using the sandwich product |
| `apply_rotor(rotor, arg [, mtr])` | Returns the argument transformed by the rotor using the sandwich product |

| Blade Operation | Description |
| --- | --- |
| `fast_join(lhs, rhs [, tol] [, mtr])` | Returns the join of the given pair of blades using the algorithm developed by [Fontijne (2008)](https://doi.org/10.1007/978-1-84996-108-0_21) |
| `fast_meet_and_join(lhs, rhs [, tol] [, mtr])` | Returns a `std::tuple<T1, T2>` structure where `T1` is the meet and `T2` is the join of the given pair of blades using the algorithm developed by [Fontijne (2008)](https://doi.org/10.1007/978-1-84996-108-0_21) |
| `fast_plunge(lhs, rhs [, tol] [, mtr])` | Returns the plunge of the given pair of blades as described by [Dorst et al. (2007)](http://www.geometricalgebra.net/), and implemented using the `fast_join` function |
| `meet_and_join(lhs, rhs [, tol] [, mtr])` | Returns a `std::tuple<T1, T2>` structure where `T1` is the meet and `T2` is the join of the given pair of blades using the algorithm described by [Dorst et al. (2007)](http://www.geometricalgebra.net/) |
| `plunge(lhs, rhs [, tol] [, mtr])` | Returns the plunge of the given pair of blades as described by [Dorst et al. (2007)](http://www.geometricalgebra.net/), and implemented using the `meet_and_join` function |

| Misc Operation | Description |
| --- | --- |
| `grade(arg [, tol])` | Returns a `grade_result<Value>` structure encoding the grade of the given argument |
| `largest_grade(arg [, tol])` | Returns a scalar expression with the largest grade part of the argument, such that it is not *zero* |
| `take_grade(arg, k)` | Returns the *k*-grade part of the argument |
| `take_largest_grade(arg [, tol])` | Returns the portion of the argument with the largest grade |

### Overloaded Operators

GATL overload some C++ operators to make the writing of source code closer to the writing of mathematical expressions with geometric algebra.

It is important to notice that the precedence and associativity of C++ operators are different than the one assumed in mathematical functions. For instance, one would expect that the outer/wedge product `^` would be evaluated before the addition operation in the following expression `a + b ^ c`, because product precedes addition in math. However, in C++ the addition operator (`+`) precedes the bitwise XOR operator (`^`), leading to possible mistakes while implementing mathematical procedures (please, refer to the [C++ specification](https://en.cppreference.com/w/cpp/language/operator_precedence) for details). As a result, the resulting expression in this example would be `(a + b) ^ c`. The use of parenthesis is strongly recommended in order to avoid those mistakes. By rewriting the example, `a + (b ^ c)` will guarantee the expected behavior.

| Arithmetic Operator | Description |
| --- | --- |
| `+rhs` | Unary plus |
| `-rhs` | Unary minus |
| `~rhs` | Reversion (same as `reverse(rhs)`) |
| `lhs + rhs` | Addition |
| `lhs - rhs` | Subtraction |
| `lhs * rhs` | Geometric/Clifford product (same as `gp(lhs, rhs)`) |
| `lhs / rhs` | Inverse geometric/Clifford product (same as `igp(lhs, rhs)`) |
| `lhs ^ rhs` | Outer/Wedge product (same as `op(lhs, rhs)`) |
| `lhs < rhs` | Left constraction (same as `lcont(lhs, rhs)`) |
| `lhs > rhs` | Right constraction (same as `rcond(lhs, rhs)`) |
| <code>lhs &#124; rhs</code> | Dot product (same as `dot(lhs, rhs)`) |

| Input/Output Operator | Description |
| --- | --- |
| `os << arg` | Insert formatted output (it uses the `write` function) |

### Overloaded Mathematical Functions

The following tables present the C++ mathematical functions overloaded by GATL to accept Clifford expressions as input.

| Trigonometric Function | Description |
| --- | --- |
| `cos(arg)` | Cosine of the scalar argument (in radians) |
| `sin(arg)` | Sine of the scalar argument (in radians) |
| `tan(arg)` | Tangent of the scalar argument (in radians) |

| Hyperbolic Function | Description |
| --- | --- |
| `cosh(arg)` | Hyperbolic cosine of the scalar argument (in radians) |
| `sinh(arg)` | Hyperbolic sine of the scalar argument (in radians) |
| `tanh(arg)` | Hyperbolic tangent of the scalar argument (in radians) |

| Exponential and Logarithmic Function | Description |
| --- | --- |
| `exp(arg [, tol] [, mtr])` | Base-*e* exponential function of the even blade argument |
| `log(arg)` | Natural logarithm of the scalar argument |

| Power Function | Description |
| --- | --- |
| `pow(base, exponent)` | Scalar argument `base` raised to the scalar power argument `exponent` |
| `cbrt(arg)` | Cubic root of the scalar argument |
| `sqrt(arg)` | Square root of the scalar argument |

| Other Function | Description |
| --- | --- |
| `abs(arg)` | Absolute value of the scalar argument |

### Tools

GATL includes a set of useful functions, procedures, and meta-functions to help developers to write their programs.

| Function | Description |
| --- | --- |
| `default_tolerance<ValueType>()` | Return the standard tolerance value `tol` assumed for the given value type |
| `for_each_basis_vector(arg, f)` | Applies the given function object `f`

# GATL: Geometric Algebra Template Library

## Acknowledgments

Some portions of this repository were generated or refactored with the help of ChatGPT-4 (OpenAI).

GATL is a C++ library for Euclidean, homogeneous/projective, Mikowski/spacetime, conformal, and arbitrary [geometric algebras](https://en.wikipedia.org/wiki/Geometric_algebra).

Geometric algebra is a powerful mathematical system encompassing many mathematical concepts (*e.g.*, [complex numbers](https://en.wikipedia.org/wiki/Complex_number), [quaternions algebra](https://en.wikipedia.org/wiki/Quaternion_algebra), [Grassmann-Cayley algebra](https://en.wikipedia.org/wiki/Grassmann%E2%80%93Cayley_algebra), and [Plücker coordinates](https://en.wikipedia.org/wiki/Pl%C3%BCcker_coordinates)) under the same framework. Geometric algebra is mainly based on the algebraic system called [Clifford algebra](https://en.wikipedia.org/wiki/Clifford_algebra), but with a strong emphasis on geometric interpretation. In geometric algebra, subspaces are treated as primitives for computation. As such, it is an appropriate mathematical tool for modeling and solving geometric problems in physics, chemistry, engineering, and computer science.

GATL uses template meta-programming to implement the [lazy evaluation](https://en.wikipedia.org/wiki/Lazy_evaluation) strategy. This way, GATL is capable of performing some optimizations on the program at compile time. In other words, GATL is designed to automatically execute low-level algebraic manipulation in the procedures described by the users with geometric algebra operations, leading to more efficient programs.

Please, cite [this book chapter](http://www.ic.uff.br/~laffernandes/content/publications/book_chapter/2021_sema_13/fernandes-sema-13-2021-chapter.pdf) if you use GATL in your research:

```txt
@InCollection{fernandes-SEMA-13-2021,
  title     = {Exploring lazy evaluation and compile-time simplifications for efficient geometric algebra computations},
  author    = {Fernandes, Leandro A. F.},
  chapter   = {6},
  pages     = {111--131},
  booktitle = {Systems, Patterns and Data Engineering with Geometric Calculi},
  editor    = {Xambó-Descamps, S.},
  volume    = {13},
  series    = {SEMA SIMAI Springer Series},
  publisher = {Springer, Cham},
  doi       = {https://doi.org/10.1007/978-3-030-74486-1_6},
  isbn      = {978-3-030-74485-4},
  e-isbn    = {978-3-030-74486-1},
  url       = {https://github.com/laffernandes/gatl},
  year      = {2021},
}
```

Let me know if you want to contribute to this project. [Here](http://www.ic.uff.br/~laffernandes) you will find my contact information.

**Contents:**

1. [Requirements](#1-requirements)
2. [How to Build and Install](#2-how-to-build-and-install)
3. [Compiling Examples](#3-compiling-examples)
4. [Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests)
5. [Documentation](#5-documentation)
6. [Related Project](#6-related-project)
7. [License](#7-license)

## 1. Requirements

Make sure that you have the following tools before attempting to use GATL.

**Required tools:**
- **C++23 compiler** (GCC 13+, Clang 17+, or MSVC 2022 17.8+)
- **CMake 3.20+** (recommended for building and testing)

**Optional tools:**
- **Rust toolchain** (for Rust implementation and cross-language testing)

GATL doesn't have any dependencies other than the [C++ standard library](https://en.cppreference.com/w/cpp/header).

## 2. How to Build and Install

### Modern System (C++23 + Rust - Recommended)
```bash
git clone https://github.com/durantschoon/gatl.git
cd gatl
make modern
make modern-test
```

The `cpp23/include` directory contains the modernized C++23 headers with:
- Modern C++23 features (concepts, constexpr, etc.)
- Tau-based mathematical constants (τ = 2π)
- Enhanced type safety with concepts
- Improved error handling and exception safety
- Better performance with modern standard library usage

### Legacy System (Original C++17)
```bash
git clone https://github.com/durantschoon/gatl.git
cd gatl
make legacy
make legacy-test
```

The directory `cpp/include` contains the original C++17 headers.

### All Available Make Targets
```bash
make help          # Show all available targets
make modern        # Build modern system (C++23 + Rust)
make modern-test   # Test modern system (C++23 + Rust)
make modern-clean  # Clean modern builds
make legacy        # Build legacy C++17 system
make legacy-test   # Test legacy C++17 system
make legacy-clean  # Clean legacy build
```

## 3. Compiling Examples

### Modern System Examples (C++23)
```bash
cd cpp23/tools/example
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### Legacy System Examples (C++17)
```bash
cd cpp/tools/example
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

The executable files produced by the last command start with `gatl_example_`.

### CMake extensions from preset file:

On any platform:

```sh
# Configure and build debug version
cmake --preset debug
cmake --build --preset debug

# Configure and build release version
cmake --preset release
cmake --build --preset release

# Run tests
ctest --preset debug  # or release
```

For debugging memory issues:
```sh
cmake --preset asan
cmake --build --preset asan
```

For debugging undefined behavior:
```sh
cmake --preset ubsan
cmake --build --preset ubsan
```

## 4. Compiling and Running Unit-Tests

### Modern System Tests (C++23 + Rust)
```bash
make modern-test    # Run both C++23 and Rust tests
./scripts/test.sh   # Interactive test menu
```

### Legacy System Tests (C++17)
```bash
make legacy-test    # Run original C++17 tests
```

### Individual Language Tests
```bash
make cpp23-test     # Run C++23 tests only
make rust-test      # Run Rust tests only
```

### Cross-Language Tests
```bash
./scripts/test.sh   # Interactive menu for all test types
```

## 5. Documentation

Here you find a brief description of the namespaces, macros, classes, functions, procedures, and operators available for the user. The detailed documentation is not ready yet.

According to GATL conventions, in the following definitions, `lhs` and `rhs` are informal shorthand for, respectively, the left-hand side and the right-hand side arguments of binary procedures. In addition, the `mtr` argument must be an instance of the `metric_space<...>` class, while all other arguments can be either an instances of the `clifford_expression<...>` class or other numerical types (*e.g.*, `double`, `float`, `int`, or instances of third-party classes). Numerical types are automatically converted by GATL to scalar Clifford expression using the `scalar` function.

Contents:

- [Branch info: feature/modernize-cpp23](#branch-info-featuremodernize-cpp23)
  - [🚀 Development Goals](#-development-goals)
  - [🧪 Testing Infrastructure](#-testing-infrastructure)
    - [Test Scripts (./scripts/)](#test-scripts-scripts)
    - [Quick Start Testing](#quick-start-testing)
  - [🛠️ Build and Installation](#️-build-and-installation)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended)
    - [Legacy System (Original C++17)](#legacy-system-original-c17)
    - [All Available Make Targets](#all-available-make-targets)
  - [3. Compiling Examples](#3-compiling-examples)
    - [Modern System Examples (C++23)](#modern-system-examples-c23)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17)
    - [Individual Language Tests](#individual-language-tests)
    - [Cross-Language Tests](#cross-language-tests)
  - [5. Documentation](#5-documentation)
    - [Namespaces](#namespaces)
    - [Macros](#macros)
    - [Classes and Data Types](#classes-and-data-types)
    - [Utilities Constants and Functions](#utilities-constants-and-functions)
    - [Products and Basic Operations](#products-and-basic-operations)
    - [Overloaded Operators](#overloaded-operators)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions)
    - [Tools](#tools)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library)
  - [Acknowledgments](#acknowledgments)
  - [1. Requirements](#1-requirements)
  - [2. How to Build and Install](#2-how-to-build-and-install)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-1)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-1)
    - [All Available Make Targets](#all-available-make-targets-1)
  - [3. Compiling Examples](#3-compiling-examples-1)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-1)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-1)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-1)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-1)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-1)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-1)
    - [Individual Language Tests](#individual-language-tests-1)
    - [Cross-Language Tests](#cross-language-tests-1)
  - [5. Documentation](#5-documentation-1)
    - [Namespaces](#namespaces-1)
    - [Macros](#macros-1)
    - [Classes and Data Types](#classes-and-data-types-1)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-1)
    - [Products and Basic Operations](#products-and-basic-operations-1)
    - [Overloaded Operators](#overloaded-operators-1)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-1)
    - [Tools](#tools-1)
  - [6. Related Project](#6-related-project)
  - [7. License](#7-license)
    - [License Information](#license-information)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-1)
  - [Acknowledgments](#acknowledgments-1)
  - [1. Requirements](#1-requirements-1)
  - [2. How to Build and Install](#2-how-to-build-and-install-1)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-2)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-2)
    - [All Available Make Targets](#all-available-make-targets-2)
  - [3. Compiling Examples](#3-compiling-examples-2)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-2)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-2)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-2)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-2)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-2)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-2)
    - [Individual Language Tests](#individual-language-tests-2)
    - [Cross-Language Tests](#cross-language-tests-2)
  - [5. Documentation](#5-documentation-2)
    - [Namespaces](#namespaces-2)
    - [Macros](#macros-2)
    - [Classes and Data Types](#classes-and-data-types-2)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-2)
    - [Products and Basic Operations](#products-and-basic-operations-2)
    - [Overloaded Operators](#overloaded-operators-2)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-2)
    - [Tools](#tools-2)
  - [6. Related Project](#6-related-project-1)
  - [7. License](#7-license-1)
    - [License Information](#license-information-1)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-2)
  - [Acknowledgments](#acknowledgments-2)
  - [1. Requirements](#1-requirements-2)
  - [2. How to Build and Install](#2-how-to-build-and-install-2)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-3)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-3)
    - [All Available Make Targets](#all-available-make-targets-3)
  - [3. Compiling Examples](#3-compiling-examples-3)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-3)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-3)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-3)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-3)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-3)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-3)
    - [Individual Language Tests](#individual-language-tests-3)
    - [Cross-Language Tests](#cross-language-tests-3)
  - [5. Documentation](#5-documentation-3)
    - [Namespaces](#namespaces-3)
    - [Macros](#macros-3)
    - [Classes and Data Types](#classes-and-data-types-3)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-3)
    - [Products and Basic Operations](#products-and-basic-operations-3)
    - [Overloaded Operators](#overloaded-operators-3)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-3)
    - [Tools](#tools-3)
  - [6. Related Project](#6-related-project-2)
  - [7. License](#7-license-2)
    - [License Information](#license-information-2)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-3)
  - [Acknowledgments](#acknowledgments-3)
  - [1. Requirements](#1-requirements-3)
  - [2. How to Build and Install](#2-how-to-build-and-install-3)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-4)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-4)
    - [All Available Make Targets](#all-available-make-targets-4)
  - [3. Compiling Examples](#3-compiling-examples-4)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-4)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-4)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-4)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-4)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-4)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-4)
    - [Individual Language Tests](#individual-language-tests-4)
    - [Cross-Language Tests](#cross-language-tests-4)
  - [5. Documentation](#5-documentation-4)
    - [Namespaces](#namespaces-4)
    - [Macros](#macros-4)
    - [Classes and Data Types](#classes-and-data-types-4)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-4)
    - [Products and Basic Operations](#products-and-basic-operations-4)
    - [Overloaded Operators](#overloaded-operators-4)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-4)
    - [Tools](#tools-4)

### Namespaces

Namespaces are declarative regions that provide scope to the names of the types, function, variables, *etc.*, inside it. GATL defines the following namespaces.

| Namespace | Description |
| --- | --- |
| `ga` | The main namespace that encloses all GATL implementations |
| `ga1e`, `ga2e`, `ga3e`, `ga4e`, `ga5e` | The namespace of Euclidean geometric algebra of R<sup>*n*</sup> |
| `ga1h`, `ga2h`, `ga3h`, `ga4h` | The namespace of homogeneous/projective geometric algebra of R<sup>*d*</sup> (*n* = *d* + 1) |
| `ga1p`, `ga2p`, `ga3p`, `ga4p` | The namespace of plane-based geometric algebra of R<sup>*d*</sup> (*n* = *d* + 1) |
| `ga1m`, `ga2m`, `ga3m` | The namespace of Mikowski/spacetime algebra of R<sup>*d*</sup> (*n* = *d* + 2) |
| `ga1c`, `ga2c`, `ga3c` | The namespace of conformal geometric algebra of R<sup>*d*</sup> (*n* = *d* + 2) |

The namespaces of specific geometric algebras (*e.g.*, `ga3e`, `ga3h`, `ga3m`, and `ga3c`) already use the `ga` namespace. In addition, they overload all metric operations presented in the following section by setting the `mtr` argument according to their respective spaces.

All above-mentioned namespaces declare a nested `detail` namespace. This is the namespace where the magic happens. Don't touch it!

According to the GATL conventions, the root directory for the header files that you will include in your program is the `gatl` folder. Also, the header file for each namespace is its name followed by the `.hpp` extension. Putting both conventions together, we have `gatl/ga.hpp`, `gatl/ga3e.hpp`, `gatl/ga3h.hpp`, `gatl/ga3m.hpp`, `gatl/ga3c.hpp`, and so on.

### Macros

Optionally, set the following macros before including GATL headers in your program to change some conventions of the library.

| Class | Description |
| --- | --- |
| `GA_DEFAULT_FLOATING_POINT_TYPE` | Defines the floating-point type assumed as default by the library (default is `std::double_t`) |
| `GA_DEFAULT_INTEGRAL_TYPE` | Defines the signed integral type assumed as default by the library (default is `std::int64_t`) |
| `GA_MAX_BASIS_VECTOR_INDEX` | Defines the maximum number of basis vectors assumed while performing algebraic manipulations and setting the size of bitsets (default is `63`) |

### Classes and Data Types

The following basic data types are defined in order to assign a meaning to conventional types, like `double`, `int`, and so on.

| Basic Type | Description |
| --- | --- |
| `default_floating_point_t` | The floating point type assumed as default by the library (see `GA_DEFAULT_FLOATING_POINT_TYPE`) |
| `default_integral_t` | The signed integral type assumed as default by the library (see `GA_DEFAULT_INTEGRAL_TYPE`) |
| `bitset_t` | The bitset type used by the library (uses `GA_MAX_BASIS_VECTOR_INDEX` to select the smallest unsigned integral type capable to meet implementation requirements) |
| `grade_t` | The signed integral type used to represent grade values  (same as `default_integral_t`) |
| `index_t` | The unsigned integral type used to represent the index of basis vectors (set to `std::uint64_t`) |
| `ndims_t` | The unsigned integral type used to represent the number of dimensions of the vector space (same as `index_t`) |
| `associative_container_t<ValueType>` | The associative container class used by the `clifford_expression<...>` class to store components of multivectors (set to `std::map<bitset_t, ValueType>`) |
| `sequence_container_t<EntryType, Size>` | The sequence container class used by the `clifford_expression<...>` class to store components of multivectors (set to `std::array<EntryType, Size>`) |

The following classes correspond to the most important structures of GATL.

| Class | Description |
| --- | --- |
| `clifford_expression<CoefficientType, Expression>` | A Clifford expression |
| `grade_result<Value>` | A class to encode the result of the `grade` function |
| `lazy_context<InputTypes...>` | A class to define lazy arguments for lazy evaluation of Clifford expressions |
| `metric_space<MetricSpaceType>` | The base metric space class |

| Exception Class | Description |
| --- | --- |
| `bad_checked_copy_exception` | An exception of this type is thrown when a checked copy fails |
| `not_implemented_error` | An exception to report errors related to not implemented features |

For the sake of simplicity, GATL provides the following set of class aliases and helper meta-functions to assist type definition. Nevertheless, it is strongly recommended to use the `auto` placeholder type specifier (please, refer to the [C++ specification](https://en.cppreference.com/w/cpp/language/auto) for details) whenever possible.

| Class Alias | Description |
| --- | --- |
| `constant<CoefficientType, IntegralValue>` | An alias for constant scalar Clifford expressions whose coefficient is known in compile time |
| `scalar_clifford_expression<CoefficientType, Coefficient>` | An alias for scalar Clifford expressions |

| Helper for Practical Type Definition | Description |
| --- | --- |
| `full_multivector_t<CoefficientType, VectorSpaceDimensions [, FirstGrade [, LastGrade]]>` | Helper for defining a Clifford expression representing a general multivector with runtime defined coefficients over an *n*-dimensional vector space |
| `full_derived_multivector_t<CoefficientType, Expression>` | Helper for defining a Clifford expression representing a general multivector with runtime defined coefficients in all components of the given Clifford expression |
| `full_kvector_t<CoefficientType, VectorSpaceDimensions, Grade>` | Helper for defining a Clifford expression representing a *k*-vector with runtime defined coefficients over an *n*-dimensional vector space |
| `full_vector_t<CoefficientType, VectorSpaceDimensions>` | Helper for defining a Clifford expression representing a vector with runtime defined coefficients over an *n*-dimensional vector space |
| `scaled_constant_basis_blade_t<CoefficientType, Indices...>` | Helper for defining a Clifford expression representing a scaled compile-time defined basis blade |
| `scaled_constant_basis_vector_t<CoefficientType, Index>` | Helper for defining a Clifford expression representing a scaled compile-time defined basis vector |
| `scaled_basis_blade_t<CoefficientType, FirstPossibleGrade[, LastPossibleGrade]>` | Helper for defining a Clifford expression representing a scaled runtime defined basis blade |
| `scaled_basis_vector_t<CoefficientType>` | Helper for defining a Clifford expression representing a scaled runtime defined basis vector |
| `scaled_scalar_t<CoefficientType>` | Helper for defining a Clifford expression representing a scalar value whose coefficient is unknown in compile time |
| `scaled_pseudoscalar_t<CoefficientType, N>` | Helper for defining a Clifford expression representing a scaled compile-time defined pseudoscalar |
| `unit_constant_basis_blade_t<Indices...>` | Helper for defining a Clifford expression representing an unit compile-time defined basis blade |
| `unit_constant_basis_vector_t<Index>` | Helper for defining a Clifford expression representing an unit compile-time defined basis vector |
| `unit_basis_blade_t<FirstPossibleGrade [, LastPossibleGrade]>` | Helper for defining a Clifford expression representing an unit runtime defined basis blade |
| `unit_basis_vector_t` | Helper for defining a Clifford expression representing an unit runtime defined basis vector |
| `unit_pseudoscalar_t<N>` | Helper for defining a Clifford expression representing an unit compile-time defined pseudoscalar |

### Utilities Constants and Functions

Here you find some useful meta-constants and functions to assist the implementation of your program.

| Constant | Description |
| --- | --- |
| `c<IntegralValue [, CoefficientType]>` | Defines a constant scalar Clifford expression whose coefficient is known in compile time |

| Function | Description |
| --- | --- |
| `make_lazy_context(inputs...)` | Creates a `lazy_context<InputTypes...>` object |
| `make_lazy_context_tuple(inputs...)` | Creates a `std::tuple` object made of `K + 1` entries, where the first is a `lazy_context<InputTypes...>` object and the next `K` entries are the lazy input arguments |
| `e(index)` | Returns a runtime defined unit basis vector (index values can be set using `c<IntegralValue>`, too) |
| `scalar(arg)` | Converts the given numerical value to a scalar Clifford expression |
| `pseudoscalar([mtr])` | Returns the compile-time defined unit pseudoscalar of the given metric space |
| `vector([mtr,] coords...)` | Makes a vector with the given set of coordinates (coordinate values can be set using `c<IntegralValue>`, too) |
| `vector([mtr,] begin, end)` | Makes a vector with the set of coordinates accessed by the iterators |

### Products and Basic Operations

The following tables present a set of basic products and operations from geometric algebra.

| Product | Description |
| --- | --- |
| `cp(lhs, rhs [, mtr])` | Commutator product |
| `dp(lhs, rhs [, tol] [, mtr])` | Delta product |
| `dot(lhs, rhs [, mtr])` | Dot product |
| `gp(lhs, rhs [, mtr])` | Geometric/Clifford product |
| `hip(lhs, rhs [, mtr])` | Hestenes inner product |
| `igp(lhs, rhs [, mtr])` | Inverse geometric/Clifford product (the argument `rhs` must be a versor)  |
| `lcont(lhs, rhs [, mtr])` | Left contraction |
| `op(lhs, rhs [, mtr])` | Outer/Wedge product |
| `rp(lhs, rhs [, mtr])` | Regressive product |
| `rcont(lhs, rhs [, mtr])` | Right contraction |
| `sp(lhs, rhs [, mtr])` | Scalar product |

| Sign-Change Operation | Description |
| --- | --- |
| `conjugate(arg)` | Clifford conjugation |
| `involute(arg)` | Grade involution |
| `reverse(arg)` | Reversion |

| Dualization Operation | Description |
| --- | --- |
| `dual(arg [, pseudoscalar [, mtr]])` | Dualization operation |
| `undual(arg [, pseudoscalar [, mtr]])` | Undualization operation |

| Norm-Based Operation | Description |
| --- | --- |
| `rnorm_sqr(arg [, mtr])` | Squared reverse norm |
| `rnorm(arg [, mtr])` | Reverse norm |
| `inv(arg [, mtr])` | Inverse of the given versor using the squared reverse norm |
| `unit(arg [, mtr])` | Unit under reverse norm |

| Transformation Operation | Description |
| --- | --- |
| `apply_even_versor(versor, arg [, mtr])` | Returns the argument transformed by the even versor using the sandwich product |
| `apply_odd_versor(versor, arg [, mtr])` | Returns the argument transformed by the odd versor using the sandwich product |
| `apply_rotor(rotor, arg [, mtr])` | Returns the argument transformed by the rotor using the sandwich product |

| Blade Operation | Description |
| --- | --- |
| `fast_join(lhs, rhs [, tol] [, mtr])` | Returns the join of the given pair of blades using the algorithm developed by [Fontijne (2008)](https://doi.org/10.1007/978-1-84996-108-0_21) |
| `fast_meet_and_join(lhs, rhs [, tol] [, mtr])` | Returns a `std::tuple<T1, T2>` structure where `T1` is the meet and `T2` is the join of the given pair of blades using the algorithm developed by [Fontijne (2008)](https://doi.org/10.1007/978-1-84996-108-0_21) |
| `fast_plunge(lhs, rhs [, tol] [, mtr])` | Returns the plunge of the given pair of blades as described by [Dorst et al. (2007)](http://www.geometricalgebra.net/), and implemented using the `fast_join` function |
| `meet_and_join(lhs, rhs [, tol] [, mtr])` | Returns a `std::tuple<T1, T2>` structure where `T1` is the meet and `T2` is the join of the given pair of blades using the algorithm described by [Dorst et al. (2007)](http://www.geometricalgebra.net/) |
| `plunge(lhs, rhs [, tol] [, mtr])` | Returns the plunge of the given pair of blades as described by [Dorst et al. (2007)](http://www.geometricalgebra.net/), and implemented using the `meet_and_join` function |

| Misc Operation | Description |
| --- | --- |
| `grade(arg [, tol])` | Returns a `grade_result<Value>` structure encoding the grade of the given argument |
| `largest_grade(arg [, tol])` | Returns a scalar expression with the largest grade part of the argument, such that it is not *zero* |
| `take_grade(arg, k)` | Returns the *k*-grade part of the argument |
| `take_largest_grade(arg [, tol])` | Returns the portion of the argument with the largest grade |

### Overloaded Operators

GATL overload some C++ operators to make the writing of source code closer to the writing of mathematical expressions with geometric algebra.

It is important to notice that the precedence and associativity of C++ operators are different than the one assumed in mathematical functions. For instance, one would expect that the outer/wedge product `^` would be evaluated before the addition operation in the following expression `a + b ^ c`, because product precedes addition in math. However, in C++ the addition operator (`+`) precedes the bitwise XOR operator (`^`), leading to possible mistakes while implementing mathematical procedures (please, refer to the [C++ specification](https://en.cppreference.com/w/cpp/language/operator_precedence) for details). As a result, the resulting expression in this example would be `(a + b) ^ c`. The use of parenthesis is strongly recommended in order to avoid those mistakes. By rewriting the example, `a + (b ^ c)` will guarantee the expected behavior.

| Arithmetic Operator | Description |
| --- | --- |
| `+rhs` | Unary plus |
| `-rhs` | Unary minus |
| `~rhs` | Reversion (same as `reverse(rhs)`) |
| `lhs + rhs` | Addition |
| `lhs - rhs` | Subtraction |
| `lhs * rhs` | Geometric/Clifford product (same as `gp(lhs, rhs)`) |
| `lhs / rhs` | Inverse geometric/Clifford product (same as `igp(lhs, rhs)`) |
| `lhs ^ rhs` | Outer/Wedge product (same as `op(lhs, rhs)`) |
| `lhs < rhs` | Left constraction (same as `lcont(lhs, rhs)`) |
| `lhs > rhs` | Right constraction (same as `rcond(lhs, rhs)`) |
| <code>lhs &#124; rhs</code> | Dot product (same as `dot(lhs, rhs)`) |

| Input/Output Operator | Description |
| --- | --- |
| `os << arg` | Insert formatted output (it uses the `write` function) |

### Overloaded Mathematical Functions

The following tables present the C++ mathematical functions overloaded by GATL to accept Clifford expressions as input.

| Trigonometric Function | Description |
| --- | --- |
| `cos(arg)` | Cosine of the scalar argument (in radians) |
| `sin(arg)` | Sine of the scalar argument (in radians) |
| `tan(arg)` | Tangent of the scalar argument (in radians) |

| Hyperbolic Function | Description |
| --- | --- |
| `cosh(arg)` | Hyperbolic cosine of the scalar argument (in radians) |
| `sinh(arg)` | Hyperbolic sine of the scalar argument (in radians) |
| `tanh(arg)` | Hyperbolic tangent of the scalar argument (in radians) |

| Exponential and Logarithmic Function | Description |
| --- | --- |
| `exp(arg [, tol] [, mtr])` | Base-*e* exponential function of the even blade argument |
| `log(arg)` | Natural logarithm of the scalar argument |

| Power Function | Description |
| --- | --- |
| `pow(base, exponent)` | Scalar argument `base` raised to the scalar power argument `exponent` |
| `cbrt(arg)` | Cubic root of the scalar argument |
| `sqrt(arg)` | Square root of the scalar argument |

| Other Function | Description |
| --- | --- |
| `abs(arg)` | Absolute value of the scalar argument |

### Tools

GATL includes a set of useful functions, procedures, and meta-functions to help developers to write their programs.

| Function | Description |
| --- | --- |
| `default_tolerance<ValueType>()` | Return the standard tolerance value `tol` assumed for the given value type |
| `for_each_basis_vector(arg, f)` | Applies the given function object `f`

## 6. Related Project

## 7. License

### License Information

- **Legacy System (GPL v3.0)**: Original template metaprogramming in `cpp/` and `cpp23/include/gatl/ga/`
- **Modern System (MPL 2.0)**: New algebraic types in `cpp23/include/gatl/modern/` and `rust/`
- See `LICENSING.md` for detailed usage guidelines

# GATL: Geometric Algebra Template Library

## Acknowledgments

Some portions of this repository were generated or refactored with the help of ChatGPT-4 (OpenAI).

GATL is a C++ library for Euclidean, homogeneous/projective, Mikowski/spacetime, conformal, and arbitrary [geometric algebras](https://en.wikipedia.org/wiki/Geometric_algebra).

Geometric algebra is a powerful mathematical system encompassing many mathematical concepts (*e.g.*, [complex numbers](https://en.wikipedia.org/wiki/Complex_number), [quaternions algebra](https://en.wikipedia.org/wiki/Quaternion_algebra), [Grassmann-Cayley algebra](https://en.wikipedia.org/wiki/Grassmann%E2%80%93Cayley_algebra), and [Plücker coordinates](https://en.wikipedia.org/wiki/Pl%C3%BCcker_coordinates)) under the same framework. Geometric algebra is mainly based on the algebraic system called [Clifford algebra](https://en.wikipedia.org/wiki/Clifford_algebra), but with a strong emphasis on geometric interpretation. In geometric algebra, subspaces are treated as primitives for computation. As such, it is an appropriate mathematical tool for modeling and solving geometric problems in physics, chemistry, engineering, and computer science.

GATL uses template meta-programming to implement the [lazy evaluation](https://en.wikipedia.org/wiki/Lazy_evaluation) strategy. This way, GATL is capable of performing some optimizations on the program at compile time. In other words, GATL is designed to automatically execute low-level algebraic manipulation in the procedures described by the users with geometric algebra operations, leading to more efficient programs.

Please, cite [this book chapter](http://www.ic.uff.br/~laffernandes/content/publications/book_chapter/2021_sema_13/fernandes-sema-13-2021-chapter.pdf) if you use GATL in your research:

```txt
@InCollection{fernandes-SEMA-13-2021,
  title     = {Exploring lazy evaluation and compile-time simplifications for efficient geometric algebra computations},
  author    = {Fernandes, Leandro A. F.},
  chapter   = {6},
  pages     = {111--131},
  booktitle = {Systems, Patterns and Data Engineering with Geometric Calculi},
  editor    = {Xambó-Descamps, S.},
  volume    = {13},
  series    = {SEMA SIMAI Springer Series},
  publisher = {Springer, Cham},
  doi       = {https://doi.org/10.1007/978-3-030-74486-1_6},
  isbn      = {978-3-030-74485-4},
  e-isbn    = {978-3-030-74486-1},
  url       = {https://github.com/laffernandes/gatl},
  year      = {2021},
}
```

Let me know if you want to contribute to this project. [Here](http://www.ic.uff.br/~laffernandes) you will find my contact information.

**Contents:**

1. [Requirements](#1-requirements)
2. [How to Build and Install](#2-how-to-build-and-install)
3. [Compiling Examples](#3-compiling-examples)
4. [Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests)
5. [Documentation](#5-documentation)
6. [Related Project](#6-related-project)
7. [License](#7-license)

## 1. Requirements

Make sure that you have the following tools before attempting to use GATL.

**Required tools:**
- **C++23 compiler** (GCC 13+, Clang 17+, or MSVC 2022 17.8+)
- **CMake 3.20+** (recommended for building and testing)

**Optional tools:**
- **Rust toolchain** (for Rust implementation and cross-language testing)

GATL doesn't have any dependencies other than the [C++ standard library](https://en.cppreference.com/w/cpp/header).

## 2. How to Build and Install

### Modern System (C++23 + Rust - Recommended)
```bash
git clone https://github.com/durantschoon/gatl.git
cd gatl
make modern
make modern-test
```

The `cpp23/include` directory contains the modernized C++23 headers with:
- Modern C++23 features (concepts, constexpr, etc.)
- Tau-based mathematical constants (τ = 2π)
- Enhanced type safety with concepts
- Improved error handling and exception safety
- Better performance with modern standard library usage

### Legacy System (Original C++17)
```bash
git clone https://github.com/durantschoon/gatl.git
cd gatl
make legacy
make legacy-test
```

The directory `cpp/include` contains the original C++17 headers.

### All Available Make Targets
```bash
make help          # Show all available targets
make modern        # Build modern system (C++23 + Rust)
make modern-test   # Test modern system (C++23 + Rust)
make modern-clean  # Clean modern builds
make legacy        # Build legacy C++17 system
make legacy-test   # Test legacy C++17 system
make legacy-clean  # Clean legacy build
```

## 3. Compiling Examples

### Modern System Examples (C++23)
```bash
cd cpp23/tools/example
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### Legacy System Examples (C++17)
```bash
cd cpp/tools/example
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

The executable files produced by the last command start with `gatl_example_`.

### CMake extensions from preset file:

On any platform:

```sh
# Configure and build debug version
cmake --preset debug
cmake --build --preset debug

# Configure and build release version
cmake --preset release
cmake --build --preset release

# Run tests
ctest --preset debug  # or release
```

For debugging memory issues:
```sh
cmake --preset asan
cmake --build --preset asan
```

For debugging undefined behavior:
```sh
cmake --preset ubsan
cmake --build --preset ubsan
```

## 4. Compiling and Running Unit-Tests

### Modern System Tests (C++23 + Rust)
```bash
make modern-test    # Run both C++23 and Rust tests
./scripts/test.sh   # Interactive test menu
```

### Legacy System Tests (C++17)
```bash
make legacy-test    # Run original C++17 tests
```

### Individual Language Tests
```bash
make cpp23-test     # Run C++23 tests only
make rust-test      # Run Rust tests only
```

### Cross-Language Tests
```bash
./scripts/test.sh   # Interactive menu for all test types
```

## 5. Documentation

Here you find a brief description of the namespaces, macros, classes, functions, procedures, and operators available for the user. The detailed documentation is not ready yet.

According to GATL conventions, in the following definitions, `lhs` and `rhs` are informal shorthand for, respectively, the left-hand side and the right-hand side arguments of binary procedures. In addition, the `mtr` argument must be an instance of the `metric_space<...>` class, while all other arguments can be either an instances of the `clifford_expression<...>` class or other numerical types (*e.g.*, `double`, `float`, `int`, or instances of third-party classes). Numerical types are automatically converted by GATL to scalar Clifford expression using the `scalar` function.

Contents:

- [Branch info: feature/modernize-cpp23](#branch-info-featuremodernize-cpp23)
  - [🚀 Development Goals](#-development-goals)
  - [🧪 Testing Infrastructure](#-testing-infrastructure)
    - [Test Scripts (./scripts/)](#test-scripts-scripts)
    - [Quick Start Testing](#quick-start-testing)
  - [🛠️ Build and Installation](#️-build-and-installation)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended)
    - [Legacy System (Original C++17)](#legacy-system-original-c17)
    - [All Available Make Targets](#all-available-make-targets)
  - [3. Compiling Examples](#3-compiling-examples)
    - [Modern System Examples (C++23)](#modern-system-examples-c23)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17)
    - [Individual Language Tests](#individual-language-tests)
    - [Cross-Language Tests](#cross-language-tests)
  - [5. Documentation](#5-documentation)
    - [Namespaces](#namespaces)
    - [Macros](#macros)
    - [Classes and Data Types](#classes-and-data-types)
    - [Utilities Constants and Functions](#utilities-constants-and-functions)
    - [Products and Basic Operations](#products-and-basic-operations)
    - [Overloaded Operators](#overloaded-operators)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions)
    - [Tools](#tools)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library)
  - [Acknowledgments](#acknowledgments)
  - [1. Requirements](#1-requirements)
  - [2. How to Build and Install](#2-how-to-build-and-install)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-1)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-1)
    - [All Available Make Targets](#all-available-make-targets-1)
  - [3. Compiling Examples](#3-compiling-examples-1)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-1)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-1)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-1)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-1)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-1)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-1)
    - [Individual Language Tests](#individual-language-tests-1)
    - [Cross-Language Tests](#cross-language-tests-1)
  - [5. Documentation](#5-documentation-1)
    - [Namespaces](#namespaces-1)
    - [Macros](#macros-1)
    - [Classes and Data Types](#classes-and-data-types-1)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-1)
    - [Products and Basic Operations](#products-and-basic-operations-1)
    - [Overloaded Operators](#overloaded-operators-1)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-1)
    - [Tools](#tools-1)
  - [6. Related Project](#6-related-project)
  - [7. License](#7-license)
    - [License Information](#license-information)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-1)
  - [Acknowledgments](#acknowledgments-1)
  - [1. Requirements](#1-requirements-1)
  - [2. How to Build and Install](#2-how-to-build-and-install-1)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-2)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-2)
    - [All Available Make Targets](#all-available-make-targets-2)
  - [3. Compiling Examples](#3-compiling-examples-2)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-2)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-2)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-2)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-2)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-2)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-2)
    - [Individual Language Tests](#individual-language-tests-2)
    - [Cross-Language Tests](#cross-language-tests-2)
  - [5. Documentation](#5-documentation-2)
    - [Namespaces](#namespaces-2)
    - [Macros](#macros-2)
    - [Classes and Data Types](#classes-and-data-types-2)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-2)
    - [Products and Basic Operations](#products-and-basic-operations-2)
    - [Overloaded Operators](#overloaded-operators-2)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-2)
    - [Tools](#tools-2)
  - [6. Related Project](#6-related-project-1)
  - [7. License](#7-license-1)
    - [License Information](#license-information-1)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-2)
  - [Acknowledgments](#acknowledgments-2)
  - [1. Requirements](#1-requirements-2)
  - [2. How to Build and Install](#2-how-to-build-and-install-2)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-3)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-3)
    - [All Available Make Targets](#all-available-make-targets-3)
  - [3. Compiling Examples](#3-compiling-examples-3)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-3)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-3)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-3)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-3)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-3)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-3)
    - [Individual Language Tests](#individual-language-tests-3)
    - [Cross-Language Tests](#cross-language-tests-3)
  - [5. Documentation](#5-documentation-3)
    - [Namespaces](#namespaces-3)
    - [Macros](#macros-3)
    - [Classes and Data Types](#classes-and-data-types-3)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-3)
    - [Products and Basic Operations](#products-and-basic-operations-3)
    - [Overloaded Operators](#overloaded-operators-3)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-3)
    - [Tools](#tools-3)
  - [6. Related Project](#6-related-project-2)
  - [7. License](#7-license-2)
    - [License Information](#license-information-2)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-3)
  - [Acknowledgments](#acknowledgments-3)
  - [1. Requirements](#1-requirements-3)
  - [2. How to Build and Install](#2-how-to-build-and-install-3)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-4)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-4)
    - [All Available Make Targets](#all-available-make-targets-4)
  - [3. Compiling Examples](#3-compiling-examples-4)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-4)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-4)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-4)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-4)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-4)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-4)
    - [Individual Language Tests](#individual-language-tests-4)
    - [Cross-Language Tests](#cross-language-tests-4)
  - [5. Documentation](#5-documentation-4)
    - [Namespaces](#namespaces-4)
    - [Macros](#macros-4)
    - [Classes and Data Types](#classes-and-data-types-4)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-4)
    - [Products and Basic Operations](#products-and-basic-operations-4)
    - [Overloaded Operators](#overloaded-operators-4)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-4)
    - [Tools](#tools-4)

### Namespaces

Namespaces are declarative regions that provide scope to the names of the types, function, variables, *etc.*, inside it. GATL defines the following namespaces.

| Namespace | Description |
| --- | --- |
| `ga` | The main namespace that encloses all GATL implementations |
| `ga1e`, `ga2e`, `ga3e`, `ga4e`, `ga5e` | The namespace of Euclidean geometric algebra of R<sup>*n*</sup> |
| `ga1h`, `ga2h`, `ga3h`, `ga4h` | The namespace of homogeneous/projective geometric algebra of R<sup>*d*</sup> (*n* = *d* + 1) |
| `ga1p`, `ga2p`, `ga3p`, `ga4p` | The namespace of plane-based geometric algebra of R<sup>*d*</sup> (*n* = *d* + 1) |
| `ga1m`, `ga2m`, `ga3m` | The namespace of Mikowski/spacetime algebra of R<sup>*d*</sup> (*n* = *d* + 2) |
| `ga1c`, `ga2c`, `ga3c` | The namespace of conformal geometric algebra of R<sup>*d*</sup> (*n* = *d* + 2) |

The namespaces of specific geometric algebras (*e.g.*, `ga3e`, `ga3h`, `ga3m`, and `ga3c`) already use the `ga` namespace. In addition, they overload all metric operations presented in the following section by setting the `mtr` argument according to their respective spaces.

All above-mentioned namespaces declare a nested `detail` namespace. This is the namespace where the magic happens. Don't touch it!

According to the GATL conventions, the root directory for the header files that you will include in your program is the `gatl` folder. Also, the header file for each namespace is its name followed by the `.hpp` extension. Putting both conventions together, we have `gatl/ga.hpp`, `gatl/ga3e.hpp`, `gatl/ga3h.hpp`, `gatl/ga3m.hpp`, `gatl/ga3c.hpp`, and so on.

### Macros

Optionally, set the following macros before including GATL headers in your program to change some conventions of the library.

| Class | Description |
| --- | --- |
| `GA_DEFAULT_FLOATING_POINT_TYPE` | Defines the floating-point type assumed as default by the library (default is `std::double_t`) |
| `GA_DEFAULT_INTEGRAL_TYPE` | Defines the signed integral type assumed as default by the library (default is `std::int64_t`) |
| `GA_MAX_BASIS_VECTOR_INDEX` | Defines the maximum number of basis vectors assumed while performing algebraic manipulations and setting the size of bitsets (default is `63`) |

### Classes and Data Types

The following basic data types are defined in order to assign a meaning to conventional types, like `double`, `int`, and so on.

| Basic Type | Description |
| --- | --- |
| `default_floating_point_t` | The floating point type assumed as default by the library (see `GA_DEFAULT_FLOATING_POINT_TYPE`) |
| `default_integral_t` | The signed integral type assumed as default by the library (see `GA_DEFAULT_INTEGRAL_TYPE`) |
| `bitset_t` | The bitset type used by the library (uses `GA_MAX_BASIS_VECTOR_INDEX` to select the smallest unsigned integral type capable to meet implementation requirements) |
| `grade_t` | The signed integral type used to represent grade values  (same as `default_integral_t`) |
| `index_t` | The unsigned integral type used to represent the index of basis vectors (set to `std::uint64_t`) |
| `ndims_t` | The unsigned integral type used to represent the number of dimensions of the vector space (same as `index_t`) |
| `associative_container_t<ValueType>` | The associative container class used by the `clifford_expression<...>` class to store components of multivectors (set to `std::map<bitset_t, ValueType>`) |
| `sequence_container_t<EntryType, Size>` | The sequence container class used by the `clifford_expression<...>` class to store components of multivectors (set to `std::array<EntryType, Size>`) |

The following classes correspond to the most important structures of GATL.

| Class | Description |
| --- | --- |
| `clifford_expression<CoefficientType, Expression>` | A Clifford expression |
| `grade_result<Value>` | A class to encode the result of the `grade` function |
| `lazy_context<InputTypes...>` | A class to define lazy arguments for lazy evaluation of Clifford expressions |
| `metric_space<MetricSpaceType>` | The base metric space class |

| Exception Class | Description |
| --- | --- |
| `bad_checked_copy_exception` | An exception of this type is thrown when a checked copy fails |
| `not_implemented_error` | An exception to report errors related to not implemented features |

For the sake of simplicity, GATL provides the following set of class aliases and helper meta-functions to assist type definition. Nevertheless, it is strongly recommended to use the `auto` placeholder type specifier (please, refer to the [C++ specification](https://en.cppreference.com/w/cpp/language/auto) for details) whenever possible.

| Class Alias | Description |
| --- | --- |
| `constant<CoefficientType, IntegralValue>` | An alias for constant scalar Clifford expressions whose coefficient is known in compile time |
| `scalar_clifford_expression<CoefficientType, Coefficient>` | An alias for scalar Clifford expressions |

| Helper for Practical Type Definition | Description |
| --- | --- |
| `full_multivector_t<CoefficientType, VectorSpaceDimensions [, FirstGrade [, LastGrade]]>` | Helper for defining a Clifford expression representing a general multivector with runtime defined coefficients over an *n*-dimensional vector space |
| `full_derived_multivector_t<CoefficientType, Expression>` | Helper for defining a Clifford expression representing a general multivector with runtime defined coefficients in all components of the given Clifford expression |
| `full_kvector_t<CoefficientType, VectorSpaceDimensions, Grade>` | Helper for defining a Clifford expression representing a *k*-vector with runtime defined coefficients over an *n*-dimensional vector space |
| `full_vector_t<CoefficientType, VectorSpaceDimensions>` | Helper for defining a Clifford expression representing a vector with runtime defined coefficients over an *n*-dimensional vector space |
| `scaled_constant_basis_blade_t<CoefficientType, Indices...>` | Helper for defining a Clifford expression representing a scaled compile-time defined basis blade |
| `scaled_constant_basis_vector_t<CoefficientType, Index>` | Helper for defining a Clifford expression representing a scaled compile-time defined basis vector |
| `scaled_basis_blade_t<CoefficientType, FirstPossibleGrade[, LastPossibleGrade]>` | Helper for defining a Clifford expression representing a scaled runtime defined basis blade |
| `scaled_basis_vector_t<CoefficientType>` | Helper for defining a Clifford expression representing a scaled runtime defined basis vector |
| `scaled_scalar_t<CoefficientType>` | Helper for defining a Clifford expression representing a scalar value whose coefficient is unknown in compile time |
| `scaled_pseudoscalar_t<CoefficientType, N>` | Helper for defining a Clifford expression representing a scaled compile-time defined pseudoscalar |
| `unit_constant_basis_blade_t<Indices...>` | Helper for defining a Clifford expression representing an unit compile-time defined basis blade |
| `unit_constant_basis_vector_t<Index>` | Helper for defining a Clifford expression representing an unit compile-time defined basis vector |
| `unit_basis_blade_t<FirstPossibleGrade [, LastPossibleGrade]>` | Helper for defining a Clifford expression representing an unit runtime defined basis blade |
| `unit_basis_vector_t` | Helper for defining a Clifford expression representing an unit runtime defined basis vector |
| `unit_pseudoscalar_t<N>` | Helper for defining a Clifford expression representing an unit compile-time defined pseudoscalar |

### Utilities Constants and Functions

Here you find some useful meta-constants and functions to assist the implementation of your program.

| Constant | Description |
| --- | --- |
| `c<IntegralValue [, CoefficientType]>` | Defines a constant scalar Clifford expression whose coefficient is known in compile time |

| Function | Description |
| --- | --- |
| `make_lazy_context(inputs...)` | Creates a `lazy_context<InputTypes...>` object |
| `make_lazy_context_tuple(inputs...)` | Creates a `std::tuple` object made of `K + 1` entries, where the first is a `lazy_context<InputTypes...>` object and the next `K` entries are the lazy input arguments |
| `e(index)` | Returns a runtime defined unit basis vector (index values can be set using `c<IntegralValue>`, too) |
| `scalar(arg)` | Converts the given numerical value to a scalar Clifford expression |
| `pseudoscalar([mtr])` | Returns the compile-time defined unit pseudoscalar of the given metric space |
| `vector([mtr,] coords...)` | Makes a vector with the given set of coordinates (coordinate values can be set using `c<IntegralValue>`, too) |
| `vector([mtr,] begin, end)` | Makes a vector with the set of coordinates accessed by the iterators |

### Products and Basic Operations

The following tables present a set of basic products and operations from geometric algebra.

| Product | Description |
| --- | --- |
| `cp(lhs, rhs [, mtr])` | Commutator product |
| `dp(lhs, rhs [, tol] [, mtr])` | Delta product |
| `dot(lhs, rhs [, mtr])` | Dot product |
| `gp(lhs, rhs [, mtr])` | Geometric/Clifford product |
| `hip(lhs, rhs [, mtr])` | Hestenes inner product |
| `igp(lhs, rhs [, mtr])` | Inverse geometric/Clifford product (the argument `rhs` must be a versor)  |
| `lcont(lhs, rhs [, mtr])` | Left contraction |
| `op(lhs, rhs [, mtr])` | Outer/Wedge product |
| `rp(lhs, rhs [, mtr])` | Regressive product |
| `rcont(lhs, rhs [, mtr])` | Right contraction |
| `sp(lhs, rhs [, mtr])` | Scalar product |

| Sign-Change Operation | Description |
| --- | --- |
| `conjugate(arg)` | Clifford conjugation |
| `involute(arg)` | Grade involution |
| `reverse(arg)` | Reversion |

| Dualization Operation | Description |
| --- | --- |
| `dual(arg [, pseudoscalar [, mtr]])` | Dualization operation |
| `undual(arg [, pseudoscalar [, mtr]])` | Undualization operation |

| Norm-Based Operation | Description |
| --- | --- |
| `rnorm_sqr(arg [, mtr])` | Squared reverse norm |
| `rnorm(arg [, mtr])` | Reverse norm |
| `inv(arg [, mtr])` | Inverse of the given versor using the squared reverse norm |
| `unit(arg [, mtr])` | Unit under reverse norm |

| Transformation Operation | Description |
| --- | --- |
| `apply_even_versor(versor, arg [, mtr])` | Returns the argument transformed by the even versor using the sandwich product |
| `apply_odd_versor(versor, arg [, mtr])` | Returns the argument transformed by the odd versor using the sandwich product |
| `apply_rotor(rotor, arg [, mtr])` | Returns the argument transformed by the rotor using the sandwich product |

| Blade Operation | Description |
| --- | --- |
| `fast_join(lhs, rhs [, tol] [, mtr])` | Returns the join of the given pair of blades using the algorithm developed by [Fontijne (2008)](https://doi.org/10.1007/978-1-84996-108-0_21) |
| `fast_meet_and_join(lhs, rhs [, tol] [, mtr])` | Returns a `std::tuple<T1, T2>` structure where `T1` is the meet and `T2` is the join of the given pair of blades using the algorithm developed by [Fontijne (2008)](https://doi.org/10.1007/978-1-84996-108-0_21) |
| `fast_plunge(lhs, rhs [, tol] [, mtr])` | Returns the plunge of the given pair of blades as described by [Dorst et al. (2007)](http://www.geometricalgebra.net/), and implemented using the `fast_join` function |
| `meet_and_join(lhs, rhs [, tol] [, mtr])` | Returns a `std::tuple<T1, T2>` structure where `T1` is the meet and `T2` is the join of the given pair of blades using the algorithm described by [Dorst et al. (2007)](http://www.geometricalgebra.net/) |
| `plunge(lhs, rhs [, tol] [, mtr])` | Returns the plunge of the given pair of blades as described by [Dorst et al. (2007)](http://www.geometricalgebra.net/), and implemented using the `meet_and_join` function |

| Misc Operation | Description |
| --- | --- |
| `grade(arg [, tol])` | Returns a `grade_result<Value>` structure encoding the grade of the given argument |
| `largest_grade(arg [, tol])` | Returns a scalar expression with the largest grade part of the argument, such that it is not *zero* |
| `take_grade(arg, k)` | Returns the *k*-grade part of the argument |
| `take_largest_grade(arg [, tol])` | Returns the portion of the argument with the largest grade |

### Overloaded Operators

GATL overload some C++ operators to make the writing of source code closer to the writing of mathematical expressions with geometric algebra.

It is important to notice that the precedence and associativity of C++ operators are different than the one assumed in mathematical functions. For instance, one would expect that the outer/wedge product `^` would be evaluated before the addition operation in the following expression `a + b ^ c`, because product precedes addition in math. However, in C++ the addition operator (`+`) precedes the bitwise XOR operator (`^`), leading to possible mistakes while implementing mathematical procedures (please, refer to the [C++ specification](https://en.cppreference.com/w/cpp/language/operator_precedence) for details). As a result, the resulting expression in this example would be `(a + b) ^ c`. The use of parenthesis is strongly recommended in order to avoid those mistakes. By rewriting the example, `a + (b ^ c)` will guarantee the expected behavior.

| Arithmetic Operator | Description |
| --- | --- |
| `+rhs` | Unary plus |
| `-rhs` | Unary minus |
| `~rhs` | Reversion (same as `reverse(rhs)`) |
| `lhs + rhs` | Addition |
| `lhs - rhs` | Subtraction |
| `lhs * rhs` | Geometric/Clifford product (same as `gp(lhs, rhs)`) |
| `lhs / rhs` | Inverse geometric/Clifford product (same as `igp(lhs, rhs)`) |
| `lhs ^ rhs` | Outer/Wedge product (same as `op(lhs, rhs)`) |
| `lhs < rhs` | Left constraction (same as `lcont(lhs, rhs)`) |
| `lhs > rhs` | Right constraction (same as `rcond(lhs, rhs)`) |
| <code>lhs &#124; rhs</code> | Dot product (same as `dot(lhs, rhs)`) |

| Input/Output Operator | Description |
| --- | --- |
| `os << arg` | Insert formatted output (it uses the `write` function) |

### Overloaded Mathematical Functions

The following tables present the C++ mathematical functions overloaded by GATL to accept Clifford expressions as input.

| Trigonometric Function | Description |
| --- | --- |
| `cos(arg)` | Cosine of the scalar argument (in radians) |
| `sin(arg)` | Sine of the scalar argument (in radians) |
| `tan(arg)` | Tangent of the scalar argument (in radians) |

| Hyperbolic Function | Description |
| --- | --- |
| `cosh(arg)` | Hyperbolic cosine of the scalar argument (in radians) |
| `sinh(arg)` | Hyperbolic sine of the scalar argument (in radians) |
| `tanh(arg)` | Hyperbolic tangent of the scalar argument (in radians) |

| Exponential and Logarithmic Function | Description |
| --- | --- |
| `exp(arg [, tol] [, mtr])` | Base-*e* exponential function of the even blade argument |
| `log(arg)` | Natural logarithm of the scalar argument |

| Power Function | Description |
| --- | --- |
| `pow(base, exponent)` | Scalar argument `base` raised to the scalar power argument `exponent` |
| `cbrt(arg)` | Cubic root of the scalar argument |
| `sqrt(arg)` | Square root of the scalar argument |

| Other Function | Description |
| --- | --- |
| `abs(arg)` | Absolute value of the scalar argument |

### Tools

GATL includes a set of useful functions, procedures, and meta-functions to help developers to write their programs.

| Function | Description |
| --- | --- |
| `default_tolerance<ValueType>()` | Return the standard tolerance value `tol` assumed for the given value type |
| `for_each_basis_vector(arg, f)` | Applies the given function object `f`

## 6. Related Project

## 7. License

### License Information

- **Legacy System (GPL v3.0)**: Original template metaprogramming in `cpp/` and `cpp23/include/gatl/ga/`
- **Modern System (MPL 2.0)**: New algebraic types in `cpp23/include/gatl/modern/` and `rust/`
- See `LICENSING.md` for detailed usage guidelines

# GATL: Geometric Algebra Template Library

## Acknowledgments

Some portions of this repository were generated or refactored with the help of ChatGPT-4 (OpenAI).

GATL is a C++ library for Euclidean, homogeneous/projective, Mikowski/spacetime, conformal, and arbitrary [geometric algebras](https://en.wikipedia.org/wiki/Geometric_algebra).

Geometric algebra is a powerful mathematical system encompassing many mathematical concepts (*e.g.*, [complex numbers](https://en.wikipedia.org/wiki/Complex_number), [quaternions algebra](https://en.wikipedia.org/wiki/Quaternion_algebra), [Grassmann-Cayley algebra](https://en.wikipedia.org/wiki/Grassmann%E2%80%93Cayley_algebra), and [Plücker coordinates](https://en.wikipedia.org/wiki/Pl%C3%BCcker_coordinates)) under the same framework. Geometric algebra is mainly based on the algebraic system called [Clifford algebra](https://en.wikipedia.org/wiki/Clifford_algebra), but with a strong emphasis on geometric interpretation. In geometric algebra, subspaces are treated as primitives for computation. As such, it is an appropriate mathematical tool for modeling and solving geometric problems in physics, chemistry, engineering, and computer science.

GATL uses template meta-programming to implement the [lazy evaluation](https://en.wikipedia.org/wiki/Lazy_evaluation) strategy. This way, GATL is capable of performing some optimizations on the program at compile time. In other words, GATL is designed to automatically execute low-level algebraic manipulation in the procedures described by the users with geometric algebra operations, leading to more efficient programs.

Please, cite [this book chapter](http://www.ic.uff.br/~laffernandes/content/publications/book_chapter/2021_sema_13/fernandes-sema-13-2021-chapter.pdf) if you use GATL in your research:

```txt
@InCollection{fernandes-SEMA-13-2021,
  title     = {Exploring lazy evaluation and compile-time simplifications for efficient geometric algebra computations},
  author    = {Fernandes, Leandro A. F.},
  chapter   = {6},
  pages     = {111--131},
  booktitle = {Systems, Patterns and Data Engineering with Geometric Calculi},
  editor    = {Xambó-Descamps, S.},
  volume    = {13},
  series    = {SEMA SIMAI Springer Series},
  publisher = {Springer, Cham},
  doi       = {https://doi.org/10.1007/978-3-030-74486-1_6},
  isbn      = {978-3-030-74485-4},
  e-isbn    = {978-3-030-74486-1},
  url       = {https://github.com/laffernandes/gatl},
  year      = {2021},
}
```

Let me know if you want to contribute to this project. [Here](http://www.ic.uff.br/~laffernandes) you will find my contact information.

**Contents:**

1. [Requirements](#1-requirements)
2. [How to Build and Install](#2-how-to-build-and-install)
3. [Compiling Examples](#3-compiling-examples)
4. [Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests)
5. [Documentation](#5-documentation)
6. [Related Project](#6-related-project)
7. [License](#7-license)

## 1. Requirements

Make sure that you have the following tools before attempting to use GATL.

**Required tools:**
- **C++23 compiler** (GCC 13+, Clang 17+, or MSVC 2022 17.8+)
- **CMake 3.20+** (recommended for building and testing)

**Optional tools:**
- **Rust toolchain** (for Rust implementation and cross-language testing)

GATL doesn't have any dependencies other than the [C++ standard library](https://en.cppreference.com/w/cpp/header).

## 2. How to Build and Install

### Modern System (C++23 + Rust - Recommended)
```bash
git clone https://github.com/durantschoon/gatl.git
cd gatl
make modern
make modern-test
```

The `cpp23/include` directory contains the modernized C++23 headers with:
- Modern C++23 features (concepts, constexpr, etc.)
- Tau-based mathematical constants (τ = 2π)
- Enhanced type safety with concepts
- Improved error handling and exception safety
- Better performance with modern standard library usage

### Legacy System (Original C++17)
```bash
git clone https://github.com/durantschoon/gatl.git
cd gatl
make legacy
make legacy-test
```

The directory `cpp/include` contains the original C++17 headers.

### All Available Make Targets
```bash
make help          # Show all available targets
make modern        # Build modern system (C++23 + Rust)
make modern-test   # Test modern system (C++23 + Rust)
make modern-clean  # Clean modern builds
make legacy        # Build legacy C++17 system
make legacy-test   # Test legacy C++17 system
make legacy-clean  # Clean legacy build
```

## 3. Compiling Examples

### Modern System Examples (C++23)
```bash
cd cpp23/tools/example
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### Legacy System Examples (C++17)
```bash
cd cpp/tools/example
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

The executable files produced by the last command start with `gatl_example_`.

### CMake extensions from preset file:

On any platform:

```sh
# Configure and build debug version
cmake --preset debug
cmake --build --preset debug

# Configure and build release version
cmake --preset release
cmake --build --preset release

# Run tests
ctest --preset debug  # or release
```

For debugging memory issues:
```sh
cmake --preset asan
cmake --build --preset asan
```

For debugging undefined behavior:
```sh
cmake --preset ubsan
cmake --build --preset ubsan
```

## 4. Compiling and Running Unit-Tests

### Modern System Tests (C++23 + Rust)
```bash
make modern-test    # Run both C++23 and Rust tests
./scripts/test.sh   # Interactive test menu
```

### Legacy System Tests (C++17)
```bash
make legacy-test    # Run original C++17 tests
```

### Individual Language Tests
```bash
make cpp23-test     # Run C++23 tests only
make rust-test      # Run Rust tests only
```

### Cross-Language Tests
```bash
./scripts/test.sh   # Interactive menu for all test types
```

## 5. Documentation

Here you find a brief description of the namespaces, macros, classes, functions, procedures, and operators available for the user. The detailed documentation is not ready yet.

According to GATL conventions, in the following definitions, `lhs` and `rhs` are informal shorthand for, respectively, the left-hand side and the right-hand side arguments of binary procedures. In addition, the `mtr` argument must be an instance of the `metric_space<...>` class, while all other arguments can be either an instances of the `clifford_expression<...>` class or other numerical types (*e.g.*, `double`, `float`, `int`, or instances of third-party classes). Numerical types are automatically converted by GATL to scalar Clifford expression using the `scalar` function.

Contents:

- [Branch info: feature/modernize-cpp23](#branch-info-featuremodernize-cpp23)
  - [🚀 Development Goals](#-development-goals)
  - [🧪 Testing Infrastructure](#-testing-infrastructure)
    - [Test Scripts (./scripts/)](#test-scripts-scripts)
    - [Quick Start Testing](#quick-start-testing)
  - [🛠️ Build and Installation](#️-build-and-installation)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended)
    - [Legacy System (Original C++17)](#legacy-system-original-c17)
    - [All Available Make Targets](#all-available-make-targets)
  - [3. Compiling Examples](#3-compiling-examples)
    - [Modern System Examples (C++23)](#modern-system-examples-c23)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17)
    - [Individual Language Tests](#individual-language-tests)
    - [Cross-Language Tests](#cross-language-tests)
  - [5. Documentation](#5-documentation)
    - [Namespaces](#namespaces)
    - [Macros](#macros)
    - [Classes and Data Types](#classes-and-data-types)
    - [Utilities Constants and Functions](#utilities-constants-and-functions)
    - [Products and Basic Operations](#products-and-basic-operations)
    - [Overloaded Operators](#overloaded-operators)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions)
    - [Tools](#tools)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library)
  - [Acknowledgments](#acknowledgments)
  - [1. Requirements](#1-requirements)
  - [2. How to Build and Install](#2-how-to-build-and-install)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-1)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-1)
    - [All Available Make Targets](#all-available-make-targets-1)
  - [3. Compiling Examples](#3-compiling-examples-1)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-1)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-1)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-1)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-1)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-1)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-1)
    - [Individual Language Tests](#individual-language-tests-1)
    - [Cross-Language Tests](#cross-language-tests-1)
  - [5. Documentation](#5-documentation-1)
    - [Namespaces](#namespaces-1)
    - [Macros](#macros-1)
    - [Classes and Data Types](#classes-and-data-types-1)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-1)
    - [Products and Basic Operations](#products-and-basic-operations-1)
    - [Overloaded Operators](#overloaded-operators-1)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-1)
    - [Tools](#tools-1)
  - [6. Related Project](#6-related-project)
  - [7. License](#7-license)
    - [License Information](#license-information)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-1)
  - [Acknowledgments](#acknowledgments-1)
  - [1. Requirements](#1-requirements-1)
  - [2. How to Build and Install](#2-how-to-build-and-install-1)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-2)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-2)
    - [All Available Make Targets](#all-available-make-targets-2)
  - [3. Compiling Examples](#3-compiling-examples-2)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-2)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-2)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-2)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-2)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-2)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-2)
    - [Individual Language Tests](#individual-language-tests-2)
    - [Cross-Language Tests](#cross-language-tests-2)
  - [5. Documentation](#5-documentation-2)
    - [Namespaces](#namespaces-2)
    - [Macros](#macros-2)
    - [Classes and Data Types](#classes-and-data-types-2)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-2)
    - [Products and Basic Operations](#products-and-basic-operations-2)
    - [Overloaded Operators](#overloaded-operators-2)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-2)
    - [Tools](#tools-2)
  - [6. Related Project](#6-related-project-1)
  - [7. License](#7-license-1)
    - [License Information](#license-information-1)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-2)
  - [Acknowledgments](#acknowledgments-2)
  - [1. Requirements](#1-requirements-2)
  - [2. How to Build and Install](#2-how-to-build-and-install-2)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-3)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-3)
    - [All Available Make Targets](#all-available-make-targets-3)
  - [3. Compiling Examples](#3-compiling-examples-3)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-3)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-3)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-3)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-3)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-3)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-3)
    - [Individual Language Tests](#individual-language-tests-3)
    - [Cross-Language Tests](#cross-language-tests-3)
  - [5. Documentation](#5-documentation-3)
    - [Namespaces](#namespaces-3)
    - [Macros](#macros-3)
    - [Classes and Data Types](#classes-and-data-types-3)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-3)
    - [Products and Basic Operations](#products-and-basic-operations-3)
    - [Overloaded Operators](#overloaded-operators-3)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-3)
    - [Tools](#tools-3)
  - [6. Related Project](#6-related-project-2)
  - [7. License](#7-license-2)
    - [License Information](#license-information-2)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-3)
  - [Acknowledgments](#acknowledgments-3)
  - [1. Requirements](#1-requirements-3)
  - [2. How to Build and Install](#2-how-to-build-and-install-3)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-4)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-4)
    - [All Available Make Targets](#all-available-make-targets-4)
  - [3. Compiling Examples](#3-compiling-examples-4)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-4)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-4)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-4)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-4)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-4)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-4)
    - [Individual Language Tests](#individual-language-tests-4)
    - [Cross-Language Tests](#cross-language-tests-4)
  - [5. Documentation](#5-documentation-4)
    - [Namespaces](#namespaces-4)
    - [Macros](#macros-4)
    - [Classes and Data Types](#classes-and-data-types-4)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-4)
    - [Products and Basic Operations](#products-and-basic-operations-4)
    - [Overloaded Operators](#overloaded-operators-4)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-4)
    - [Tools](#tools-4)

### Namespaces

Namespaces are declarative regions that provide scope to the names of the types, function, variables, *etc.*, inside it. GATL defines the following namespaces.

| Namespace | Description |
| --- | --- |
| `ga` | The main namespace that encloses all GATL implementations |
| `ga1e`, `ga2e`, `ga3e`, `ga4e`, `ga5e` | The namespace of Euclidean geometric algebra of R<sup>*n*</sup> |
| `ga1h`, `ga2h`, `ga3h`, `ga4h` | The namespace of homogeneous/projective geometric algebra of R<sup>*d*</sup> (*n* = *d* + 1) |
| `ga1p`, `ga2p`, `ga3p`, `ga4p` | The namespace of plane-based geometric algebra of R<sup>*d*</sup> (*n* = *d* + 1) |
| `ga1m`, `ga2m`, `ga3m` | The namespace of Mikowski/spacetime algebra of R<sup>*d*</sup> (*n* = *d* + 2) |
| `ga1c`, `ga2c`, `ga3c` | The namespace of conformal geometric algebra of R<sup>*d*</sup> (*n* = *d* + 2) |

The namespaces of specific geometric algebras (*e.g.*, `ga3e`, `ga3h`, `ga3m`, and `ga3c`) already use the `ga` namespace. In addition, they overload all metric operations presented in the following section by setting the `mtr` argument according to their respective spaces.

All above-mentioned namespaces declare a nested `detail` namespace. This is the namespace where the magic happens. Don't touch it!

According to the GATL conventions, the root directory for the header files that you will include in your program is the `gatl` folder. Also, the header file for each namespace is its name followed by the `.hpp` extension. Putting both conventions together, we have `gatl/ga.hpp`, `gatl/ga3e.hpp`, `gatl/ga3h.hpp`, `gatl/ga3m.hpp`, `gatl/ga3c.hpp`, and so on.

### Macros

Optionally, set the following macros before including GATL headers in your program to change some conventions of the library.

| Class | Description |
| --- | --- |
| `GA_DEFAULT_FLOATING_POINT_TYPE` | Defines the floating-point type assumed as default by the library (default is `std::double_t`) |
| `GA_DEFAULT_INTEGRAL_TYPE` | Defines the signed integral type assumed as default by the library (default is `std::int64_t`) |
| `GA_MAX_BASIS_VECTOR_INDEX` | Defines the maximum number of basis vectors assumed while performing algebraic manipulations and setting the size of bitsets (default is `63`) |

### Classes and Data Types

The following basic data types are defined in order to assign a meaning to conventional types, like `double`, `int`, and so on.

| Basic Type | Description |
| --- | --- |
| `default_floating_point_t` | The floating point type assumed as default by the library (see `GA_DEFAULT_FLOATING_POINT_TYPE`) |
| `default_integral_t` | The signed integral type assumed as default by the library (see `GA_DEFAULT_INTEGRAL_TYPE`) |
| `bitset_t` | The bitset type used by the library (uses `GA_MAX_BASIS_VECTOR_INDEX` to select the smallest unsigned integral type capable to meet implementation requirements) |
| `grade_t` | The signed integral type used to represent grade values  (same as `default_integral_t`) |
| `index_t` | The unsigned integral type used to represent the index of basis vectors (set to `std::uint64_t`) |
| `ndims_t` | The unsigned integral type used to represent the number of dimensions of the vector space (same as `index_t`) |
| `associative_container_t<ValueType>` | The associative container class used by the `clifford_expression<...>` class to store components of multivectors (set to `std::map<bitset_t, ValueType>`) |
| `sequence_container_t<EntryType, Size>` | The sequence container class used by the `clifford_expression<...>` class to store components of multivectors (set to `std::array<EntryType, Size>`) |

The following classes correspond to the most important structures of GATL.

| Class | Description |
| --- | --- |
| `clifford_expression<CoefficientType, Expression>` | A Clifford expression |
| `grade_result<Value>` | A class to encode the result of the `grade` function |
| `lazy_context<InputTypes...>` | A class to define lazy arguments for lazy evaluation of Clifford expressions |
| `metric_space<MetricSpaceType>` | The base metric space class |

| Exception Class | Description |
| --- | --- |
| `bad_checked_copy_exception` | An exception of this type is thrown when a checked copy fails |
| `not_implemented_error` | An exception to report errors related to not implemented features |

For the sake of simplicity, GATL provides the following set of class aliases and helper meta-functions to assist type definition. Nevertheless, it is strongly recommended to use the `auto` placeholder type specifier (please, refer to the [C++ specification](https://en.cppreference.com/w/cpp/language/auto) for details) whenever possible.

| Class Alias | Description |
| --- | --- |
| `constant<CoefficientType, IntegralValue>` | An alias for constant scalar Clifford expressions whose coefficient is known in compile time |
| `scalar_clifford_expression<CoefficientType, Coefficient>` | An alias for scalar Clifford expressions |

| Helper for Practical Type Definition | Description |
| --- | --- |
| `full_multivector_t<CoefficientType, VectorSpaceDimensions [, FirstGrade [, LastGrade]]>` | Helper for defining a Clifford expression representing a general multivector with runtime defined coefficients over an *n*-dimensional vector space |
| `full_derived_multivector_t<CoefficientType, Expression>` | Helper for defining a Clifford expression representing a general multivector with runtime defined coefficients in all components of the given Clifford expression |
| `full_kvector_t<CoefficientType, VectorSpaceDimensions, Grade>` | Helper for defining a Clifford expression representing a *k*-vector with runtime defined coefficients over an *n*-dimensional vector space |
| `full_vector_t<CoefficientType, VectorSpaceDimensions>` | Helper for defining a Clifford expression representing a vector with runtime defined coefficients over an *n*-dimensional vector space |
| `scaled_constant_basis_blade_t<CoefficientType, Indices...>` | Helper for defining a Clifford expression representing a scaled compile-time defined basis blade |
| `scaled_constant_basis_vector_t<CoefficientType, Index>` | Helper for defining a Clifford expression representing a scaled compile-time defined basis vector |
| `scaled_basis_blade_t<CoefficientType, FirstPossibleGrade[, LastPossibleGrade]>` | Helper for defining a Clifford expression representing a scaled runtime defined basis blade |
| `scaled_basis_vector_t<CoefficientType>` | Helper for defining a Clifford expression representing a scaled runtime defined basis vector |
| `scaled_scalar_t<CoefficientType>` | Helper for defining a Clifford expression representing a scalar value whose coefficient is unknown in compile time |
| `scaled_pseudoscalar_t<CoefficientType, N>` | Helper for defining a Clifford expression representing a scaled compile-time defined pseudoscalar |
| `unit_constant_basis_blade_t<Indices...>` | Helper for defining a Clifford expression representing an unit compile-time defined basis blade |
| `unit_constant_basis_vector_t<Index>` | Helper for defining a Clifford expression representing an unit compile-time defined basis vector |
| `unit_basis_blade_t<FirstPossibleGrade [, LastPossibleGrade]>` | Helper for defining a Clifford expression representing an unit runtime defined basis blade |
| `unit_basis_vector_t` | Helper for defining a Clifford expression representing an unit runtime defined basis vector |
| `unit_pseudoscalar_t<N>` | Helper for defining a Clifford expression representing an unit compile-time defined pseudoscalar |

### Utilities Constants and Functions

Here you find some useful meta-constants and functions to assist the implementation of your program.

| Constant | Description |
| --- | --- |
| `c<IntegralValue [, CoefficientType]>` | Defines a constant scalar Clifford expression whose coefficient is known in compile time |

| Function | Description |
| --- | --- |
| `make_lazy_context(inputs...)` | Creates a `lazy_context<InputTypes...>` object |
| `make_lazy_context_tuple(inputs...)` | Creates a `std::tuple` object made of `K + 1` entries, where the first is a `lazy_context<InputTypes...>` object and the next `K` entries are the lazy input arguments |
| `e(index)` | Returns a runtime defined unit basis vector (index values can be set using `c<IntegralValue>`, too) |
| `scalar(arg)` | Converts the given numerical value to a scalar Clifford expression |
| `pseudoscalar([mtr])` | Returns the compile-time defined unit pseudoscalar of the given metric space |
| `vector([mtr,] coords...)` | Makes a vector with the given set of coordinates (coordinate values can be set using `c<IntegralValue>`, too) |
| `vector([mtr,] begin, end)` | Makes a vector with the set of coordinates accessed by the iterators |

### Products and Basic Operations

The following tables present a set of basic products and operations from geometric algebra.

| Product | Description |
| --- | --- |
| `cp(lhs, rhs [, mtr])` | Commutator product |
| `dp(lhs, rhs [, tol] [, mtr])` | Delta product |
| `dot(lhs, rhs [, mtr])` | Dot product |
| `gp(lhs, rhs [, mtr])` | Geometric/Clifford product |
| `hip(lhs, rhs [, mtr])` | Hestenes inner product |
| `igp(lhs, rhs [, mtr])` | Inverse geometric/Clifford product (the argument `rhs` must be a versor)  |
| `lcont(lhs, rhs [, mtr])` | Left contraction |
| `op(lhs, rhs [, mtr])` | Outer/Wedge product |
| `rp(lhs, rhs [, mtr])` | Regressive product |
| `rcont(lhs, rhs [, mtr])` | Right contraction |
| `sp(lhs, rhs [, mtr])` | Scalar product |

| Sign-Change Operation | Description |
| --- | --- |
| `conjugate(arg)` | Clifford conjugation |
| `involute(arg)` | Grade involution |
| `reverse(arg)` | Reversion |

| Dualization Operation | Description |
| --- | --- |
| `dual(arg [, pseudoscalar [, mtr]])` | Dualization operation |
| `undual(arg [, pseudoscalar [, mtr]])` | Undualization operation |

| Norm-Based Operation | Description |
| --- | --- |
| `rnorm_sqr(arg [, mtr])` | Squared reverse norm |
| `rnorm(arg [, mtr])` | Reverse norm |
| `inv(arg [, mtr])` | Inverse of the given versor using the squared reverse norm |
| `unit(arg [, mtr])` | Unit under reverse norm |

| Transformation Operation | Description |
| --- | --- |
| `apply_even_versor(versor, arg [, mtr])` | Returns the argument transformed by the even versor using the sandwich product |
| `apply_odd_versor(versor, arg [, mtr])` | Returns the argument transformed by the odd versor using the sandwich product |
| `apply_rotor(rotor, arg [, mtr])` | Returns the argument transformed by the rotor using the sandwich product |

| Blade Operation | Description |
| --- | --- |
| `fast_join(lhs, rhs [, tol] [, mtr])` | Returns the join of the given pair of blades using the algorithm developed by [Fontijne (2008)](https://doi.org/10.1007/978-1-84996-108-0_21) |
| `fast_meet_and_join(lhs, rhs [, tol] [, mtr])` | Returns a `std::tuple<T1, T2>` structure where `T1` is the meet and `T2` is the join of the given pair of blades using the algorithm developed by [Fontijne (2008)](https://doi.org/10.1007/978-1-84996-108-0_21) |
| `fast_plunge(lhs, rhs [, tol] [, mtr])` | Returns the plunge of the given pair of blades as described by [Dorst et al. (2007)](http://www.geometricalgebra.net/), and implemented using the `fast_join` function |
| `meet_and_join(lhs, rhs [, tol] [, mtr])` | Returns a `std::tuple<T1, T2>` structure where `T1` is the meet and `T2` is the join of the given pair of blades using the algorithm described by [Dorst et al. (2007)](http://www.geometricalgebra.net/) |
| `plunge(lhs, rhs [, tol] [, mtr])` | Returns the plunge of the given pair of blades as described by [Dorst et al. (2007)](http://www.geometricalgebra.net/), and implemented using the `meet_and_join` function |

| Misc Operation | Description |
| --- | --- |
| `grade(arg [, tol])` | Returns a `grade_result<Value>` structure encoding the grade of the given argument |
| `largest_grade(arg [, tol])` | Returns a scalar expression with the largest grade part of the argument, such that it is not *zero* |
| `take_grade(arg, k)` | Returns the *k*-grade part of the argument |
| `take_largest_grade(arg [, tol])` | Returns the portion of the argument with the largest grade |

### Overloaded Operators

GATL overload some C++ operators to make the writing of source code closer to the writing of mathematical expressions with geometric algebra.

It is important to notice that the precedence and associativity of C++ operators are different than the one assumed in mathematical functions. For instance, one would expect that the outer/wedge product `^` would be evaluated before the addition operation in the following expression `a + b ^ c`, because product precedes addition in math. However, in C++ the addition operator (`+`) precedes the bitwise XOR operator (`^`), leading to possible mistakes while implementing mathematical procedures (please, refer to the [C++ specification](https://en.cppreference.com/w/cpp/language/operator_precedence) for details). As a result, the resulting expression in this example would be `(a + b) ^ c`. The use of parenthesis is strongly recommended in order to avoid those mistakes. By rewriting the example, `a + (b ^ c)` will guarantee the expected behavior.

| Arithmetic Operator | Description |
| --- | --- |
| `+rhs` | Unary plus |
| `-rhs` | Unary minus |
| `~rhs` | Reversion (same as `reverse(rhs)`) |
| `lhs + rhs` | Addition |
| `lhs - rhs` | Subtraction |
| `lhs * rhs` | Geometric/Clifford product (same as `gp(lhs, rhs)`) |
| `lhs / rhs` | Inverse geometric/Clifford product (same as `igp(lhs, rhs)`) |
| `lhs ^ rhs` | Outer/Wedge product (same as `op(lhs, rhs)`) |
| `lhs < rhs` | Left constraction (same as `lcont(lhs, rhs)`) |
| `lhs > rhs` | Right constraction (same as `rcond(lhs, rhs)`) |
| <code>lhs &#124; rhs</code> | Dot product (same as `dot(lhs, rhs)`) |

| Input/Output Operator | Description |
| --- | --- |
| `os << arg` | Insert formatted output (it uses the `write` function) |

### Overloaded Mathematical Functions

The following tables present the C++ mathematical functions overloaded by GATL to accept Clifford expressions as input.

| Trigonometric Function | Description |
| --- | --- |
| `cos(arg)` | Cosine of the scalar argument (in radians) |
| `sin(arg)` | Sine of the scalar argument (in radians) |
| `tan(arg)` | Tangent of the scalar argument (in radians) |

| Hyperbolic Function | Description |
| --- | --- |
| `cosh(arg)` | Hyperbolic cosine of the scalar argument (in radians) |
| `sinh(arg)` | Hyperbolic sine of the scalar argument (in radians) |
| `tanh(arg)` | Hyperbolic tangent of the scalar argument (in radians) |

| Exponential and Logarithmic Function | Description |
| --- | --- |
| `exp(arg [, tol] [, mtr])` | Base-*e* exponential function of the even blade argument |
| `log(arg)` | Natural logarithm of the scalar argument |

| Power Function | Description |
| --- | --- |
| `pow(base, exponent)` | Scalar argument `base` raised to the scalar power argument `exponent` |
| `cbrt(arg)` | Cubic root of the scalar argument |
| `sqrt(arg)` | Square root of the scalar argument |

| Other Function | Description |
| --- | --- |
| `abs(arg)` | Absolute value of the scalar argument |

### Tools

GATL includes a set of useful functions, procedures, and meta-functions to help developers to write their programs.

| Function | Description |
| --- | --- |
| `default_tolerance<ValueType>()` | Return the standard tolerance value `tol` assumed for the given value type |
| `for_each_basis_vector(arg, f)` | Applies the given function object `f`

## 6. Related Project

## 7. License

### License Information

- **Legacy System (GPL v3.0)**: Original template metaprogramming in `cpp/` and `cpp23/include/gatl/ga/`
- **Modern System (MPL 2.0)**: New algebraic types in `cpp23/include/gatl/modern/` and `rust/`
- See `LICENSING.md` for detailed usage guidelines

# GATL: Geometric Algebra Template Library

## Acknowledgments

Some portions of this repository were generated or refactored with the help of ChatGPT-4 (OpenAI).

GATL is a C++ library for Euclidean, homogeneous/projective, Mikowski/spacetime, conformal, and arbitrary [geometric algebras](https://en.wikipedia.org/wiki/Geometric_algebra).

Geometric algebra is a powerful mathematical system encompassing many mathematical concepts (*e.g.*, [complex numbers](https://en.wikipedia.org/wiki/Complex_number), [quaternions algebra](https://en.wikipedia.org/wiki/Quaternion_algebra), [Grassmann-Cayley algebra](https://en.wikipedia.org/wiki/Grassmann%E2%80%93Cayley_algebra), and [Plücker coordinates](https://en.wikipedia.org/wiki/Pl%C3%BCcker_coordinates)) under the same framework. Geometric algebra is mainly based on the algebraic system called [Clifford algebra](https://en.wikipedia.org/wiki/Clifford_algebra), but with a strong emphasis on geometric interpretation. In geometric algebra, subspaces are treated as primitives for computation. As such, it is an appropriate mathematical tool for modeling and solving geometric problems in physics, chemistry, engineering, and computer science.

GATL uses template meta-programming to implement the [lazy evaluation](https://en.wikipedia.org/wiki/Lazy_evaluation) strategy. This way, GATL is capable of performing some optimizations on the program at compile time. In other words, GATL is designed to automatically execute low-level algebraic manipulation in the procedures described by the users with geometric algebra operations, leading to more efficient programs.

Please, cite [this book chapter](http://www.ic.uff.br/~laffernandes/content/publications/book_chapter/2021_sema_13/fernandes-sema-13-2021-chapter.pdf) if you use GATL in your research:

```txt
@InCollection{fernandes-SEMA-13-2021,
  title     = {Exploring lazy evaluation and compile-time simplifications for efficient geometric algebra computations},
  author    = {Fernandes, Leandro A. F.},
  chapter   = {6},
  pages     = {111--131},
  booktitle = {Systems, Patterns and Data Engineering with Geometric Calculi},
  editor    = {Xambó-Descamps, S.},
  volume    = {13},
  series    = {SEMA SIMAI Springer Series},
  publisher = {Springer, Cham},
  doi       = {https://doi.org/10.1007/978-3-030-74486-1_6},
  isbn      = {978-3-030-74485-4},
  e-isbn    = {978-3-030-74486-1},
  url       = {https://github.com/laffernandes/gatl},
  year      = {2021},
}
```

Let me know if you want to contribute to this project. [Here](http://www.ic.uff.br/~laffernandes) you will find my contact information.

**Contents:**

1. [Requirements](#1-requirements)
2. [How to Build and Install](#2-how-to-build-and-install)
3. [Compiling Examples](#3-compiling-examples)
4. [Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests)
5. [Documentation](#5-documentation)
6. [Related Project](#6-related-project)
7. [License](#7-license)

## 1. Requirements

Make sure that you have the following tools before attempting to use GATL.

**Required tools:**
- **C++23 compiler** (GCC 13+, Clang 17+, or MSVC 2022 17.8+)
- **CMake 3.20+** (recommended for building and testing)

**Optional tools:**
- **Rust toolchain** (for Rust implementation and cross-language testing)

GATL doesn't have any dependencies other than the [C++ standard library](https://en.cppreference.com/w/cpp/header).

## 2. How to Build and Install

### Modern System (C++23 + Rust - Recommended)
```bash
git clone https://github.com/durantschoon/gatl.git
cd gatl
make modern
make modern-test
```

The `cpp23/include` directory contains the modernized C++23 headers with:
- Modern C++23 features (concepts, constexpr, etc.)
- Tau-based mathematical constants (τ = 2π)
- Enhanced type safety with concepts
- Improved error handling and exception safety
- Better performance with modern standard library usage

### Legacy System (Original C++17)
```bash
git clone https://github.com/durantschoon/gatl.git
cd gatl
make legacy
make legacy-test
```

The directory `cpp/include` contains the original C++17 headers.

### All Available Make Targets
```bash
make help          # Show all available targets
make modern        # Build modern system (C++23 + Rust)
make modern-test   # Test modern system (C++23 + Rust)
make modern-clean  # Clean modern builds
make legacy        # Build legacy C++17 system
make legacy-test   # Test legacy C++17 system
make legacy-clean  # Clean legacy build
```

## 3. Compiling Examples

### Modern System Examples (C++23)
```bash
cd cpp23/tools/example
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### Legacy System Examples (C++17)
```bash
cd cpp/tools/example
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

The executable files produced by the last command start with `gatl_example_`.

### CMake extensions from preset file:

On any platform:

```sh
# Configure and build debug version
cmake --preset debug
cmake --build --preset debug

# Configure and build release version
cmake --preset release
cmake --build --preset release

# Run tests
ctest --preset debug  # or release
```

For debugging memory issues:
```sh
cmake --preset asan
cmake --build --preset asan
```

For debugging undefined behavior:
```sh
cmake --preset ubsan
cmake --build --preset ubsan
```

## 4. Compiling and Running Unit-Tests

### Modern System Tests (C++23 + Rust)
```bash
make modern-test    # Run both C++23 and Rust tests
./scripts/test.sh   # Interactive test menu
```

### Legacy System Tests (C++17)
```bash
make legacy-test    # Run original C++17 tests
```

### Individual Language Tests
```bash
make cpp23-test     # Run C++23 tests only
make rust-test      # Run Rust tests only
```

### Cross-Language Tests
```bash
./scripts/test.sh   # Interactive menu for all test types
```

## 5. Documentation

Here you find a brief description of the namespaces, macros, classes, functions, procedures, and operators available for the user. The detailed documentation is not ready yet.

According to GATL conventions, in the following definitions, `lhs` and `rhs` are informal shorthand for, respectively, the left-hand side and the right-hand side arguments of binary procedures. In addition, the `mtr` argument must be an instance of the `metric_space<...>` class, while all other arguments can be either an instances of the `clifford_expression<...>` class or other numerical types (*e.g.*, `double`, `float`, `int`, or instances of third-party classes). Numerical types are automatically converted by GATL to scalar Clifford expression using the `scalar` function.

Contents:

- [Branch info: feature/modernize-cpp23](#branch-info-featuremodernize-cpp23)
  - [🚀 Development Goals](#-development-goals)
  - [🧪 Testing Infrastructure](#-testing-infrastructure)
    - [Test Scripts (./scripts/)](#test-scripts-scripts)
    - [Quick Start Testing](#quick-start-testing)
  - [🛠️ Build and Installation](#️-build-and-installation)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended)
    - [Legacy System (Original C++17)](#legacy-system-original-c17)
    - [All Available Make Targets](#all-available-make-targets)
  - [3. Compiling Examples](#3-compiling-examples)
    - [Modern System Examples (C++23)](#modern-system-examples-c23)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17)
    - [Individual Language Tests](#individual-language-tests)
    - [Cross-Language Tests](#cross-language-tests)
  - [5. Documentation](#5-documentation)
    - [Namespaces](#namespaces)
    - [Macros](#macros)
    - [Classes and Data Types](#classes-and-data-types)
    - [Utilities Constants and Functions](#utilities-constants-and-functions)
    - [Products and Basic Operations](#products-and-basic-operations)
    - [Overloaded Operators](#overloaded-operators)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions)
    - [Tools](#tools)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library)
  - [Acknowledgments](#acknowledgments)
  - [1. Requirements](#1-requirements)
  - [2. How to Build and Install](#2-how-to-build-and-install)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-1)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-1)
    - [All Available Make Targets](#all-available-make-targets-1)
  - [3. Compiling Examples](#3-compiling-examples-1)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-1)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-1)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-1)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-1)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-1)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-1)
    - [Individual Language Tests](#individual-language-tests-1)
    - [Cross-Language Tests](#cross-language-tests-1)
  - [5. Documentation](#5-documentation-1)
    - [Namespaces](#namespaces-1)
    - [Macros](#macros-1)
    - [Classes and Data Types](#classes-and-data-types-1)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-1)
    - [Products and Basic Operations](#products-and-basic-operations-1)
    - [Overloaded Operators](#overloaded-operators-1)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-1)
    - [Tools](#tools-1)
  - [6. Related Project](#6-related-project)
  - [7. License](#7-license)
    - [License Information](#license-information)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-1)
  - [Acknowledgments](#acknowledgments-1)
  - [1. Requirements](#1-requirements-1)
  - [2. How to Build and Install](#2-how-to-build-and-install-1)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-2)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-2)
    - [All Available Make Targets](#all-available-make-targets-2)
  - [3. Compiling Examples](#3-compiling-examples-2)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-2)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-2)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-2)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-2)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-2)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-2)
    - [Individual Language Tests](#individual-language-tests-2)
    - [Cross-Language Tests](#cross-language-tests-2)
  - [5. Documentation](#5-documentation-2)
    - [Namespaces](#namespaces-2)
    - [Macros](#macros-2)
    - [Classes and Data Types](#classes-and-data-types-2)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-2)
    - [Products and Basic Operations](#products-and-basic-operations-2)
    - [Overloaded Operators](#overloaded-operators-2)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-2)
    - [Tools](#tools-2)
  - [6. Related Project](#6-related-project-1)
  - [7. License](#7-license-1)
    - [License Information](#license-information-1)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-2)
  - [Acknowledgments](#acknowledgments-2)
  - [1. Requirements](#1-requirements-2)
  - [2. How to Build and Install](#2-how-to-build-and-install-2)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-3)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-3)
    - [All Available Make Targets](#all-available-make-targets-3)
  - [3. Compiling Examples](#3-compiling-examples-3)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-3)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-3)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-3)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-3)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-3)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-3)
    - [Individual Language Tests](#individual-language-tests-3)
    - [Cross-Language Tests](#cross-language-tests-3)
  - [5. Documentation](#5-documentation-3)
    - [Namespaces](#namespaces-3)
    - [Macros](#macros-3)
    - [Classes and Data Types](#classes-and-data-types-3)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-3)
    - [Products and Basic Operations](#products-and-basic-operations-3)
    - [Overloaded Operators](#overloaded-operators-3)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-3)
    - [Tools](#tools-3)
  - [6. Related Project](#6-related-project-2)
  - [7. License](#7-license-2)
    - [License Information](#license-information-2)
- [GATL: Geometric Algebra Template Library](#gatl-geometric-algebra-template-library-3)
  - [Acknowledgments](#acknowledgments-3)
  - [1. Requirements](#1-requirements-3)
  - [2. How to Build and Install](#2-how-to-build-and-install-3)
    - [Modern System (C++23 + Rust - Recommended)](#modern-system-c23--rust---recommended-4)
    - [Legacy System (Original C++17)](#legacy-system-original-c17-4)
    - [All Available Make Targets](#all-available-make-targets-4)
  - [3. Compiling Examples](#3-compiling-examples-4)
    - [Modern System Examples (C++23)](#modern-system-examples-c23-4)
    - [Legacy System Examples (C++17)](#legacy-system-examples-c17-4)
    - [CMake extensions from preset file:](#cmake-extensions-from-preset-file-4)
  - [4. Compiling and Running Unit-Tests](#4-compiling-and-running-unit-tests-4)
    - [Modern System Tests (C++23 + Rust)](#modern-system-tests-c23--rust-4)
    - [Legacy System Tests (C++17)](#legacy-system-tests-c17-4)
    - [Individual Language Tests](#individual-language-tests-4)
    - [Cross-Language Tests](#cross-language-tests-4)
  - [5. Documentation](#5-documentation-4)
    - [Namespaces](#namespaces-4)
    - [Macros](#macros-4)
    - [Classes and Data Types](#classes-and-data-types-4)
    - [Utilities Constants and Functions](#utilities-constants-and-functions-4)
    - [Products and Basic Operations](#products-and-basic-operations-4)
    - [Overloaded Operators](#overloaded-operators-4)
    - [Overloaded Mathematical Functions](#overloaded-mathematical-functions-4)
    - [Tools](#tools-4)

### Namespaces

Namespaces are declarative regions that provide scope to the names of the types, function, variables, *etc.*, inside it. GATL defines the following namespaces.

| Namespace | Description |
| --- | --- |
| `ga` | The main namespace that encloses all GATL implementations |
| `ga1e`, `ga2e`, `ga3e`, `ga4e`, `ga5e` | The namespace of Euclidean geometric algebra of R<sup>*n*</sup> |
| `ga1h`, `ga2h`, `ga3h`, `ga4h` | The namespace of homogeneous/projective geometric algebra of R<sup>*d*</sup> (*n* = *d* + 1) |
| `ga1p`, `ga2p`, `ga3p`, `ga4p` | The namespace of plane-based geometric algebra of R<sup>*d*</sup> (*n* = *d* + 1) |
| `ga1m`, `ga2m`, `ga3m` | The namespace of Mikowski/spacetime algebra of R<sup>*d*</sup> (*n* = *d* + 2) |
| `ga1c`, `ga2c`, `ga3c` | The namespace of conformal geometric algebra of R<sup>*d*</sup> (*n* = *d* + 2) |

The namespaces of specific geometric algebras (*e.g.*, `ga3e`, `ga3h`, `ga3m`, and `ga3c`) already use the `ga` namespace. In addition, they overload all metric operations presented in the following section by setting the `mtr` argument according to their respective spaces.

All above-mentioned namespaces declare a nested `detail` namespace. This is the namespace where the magic happens. Don't touch it!

According to the GATL conventions, the root directory for the header files that you will include in your program is the `gatl` folder. Also, the header file for each namespace is its name followed by the `.hpp` extension. Putting both conventions together, we have `gatl/ga.hpp`, `gatl/ga3e.hpp`, `gatl/ga3h.hpp`, `gatl/ga3m.hpp`, `gatl/ga3c.hpp`, and so on.

### Macros

Optionally, set the following macros before including GATL headers in your program to change some conventions of the library.

| Class | Description |
| --- | --- |
| `GA_DEFAULT_FLOATING_POINT_TYPE` | Defines the floating-point type assumed as default by the library (default is `std::double_t`) |
| `GA_DEFAULT_INTEGRAL_TYPE` | Defines the signed integral type assumed as default by the library (default is `std::int64_t`) |
| `GA_MAX_BASIS_VECTOR_INDEX` | Defines the maximum number of basis vectors assumed while performing algebraic manipulations and setting the size of bitsets (default is `63`) |

### Classes and Data Types

The following basic data types are defined in order to assign a meaning to conventional types, like `double`, `int`, and so on.

| Basic Type | Description |
| --- | --- |
| `default_floating_point_t` | The floating point type assumed as default by the library (see `GA_DEFAULT_FLOATING_POINT_TYPE`) |
| `default_integral_t` | The signed integral type assumed as default by the library (see `GA_DEFAULT_INTEGRAL_TYPE`) |
| `bitset_t` | The bitset type used by the library (uses `GA_MAX_BASIS_VECTOR_INDEX` to select the smallest unsigned integral type capable to meet implementation requirements) |
| `grade_t` | The signed integral type used to represent grade values  (same as `default_integral_t`) |
| `index_t` | The unsigned integral type used to represent the index of basis vectors (set to `std::uint64_t`) |
| `ndims_t` | The unsigned integral type used to represent the number of dimensions of the vector space (same as `index_t`) |
| `associative_container_t<ValueType>` | The associative container class used by the `clifford_expression<...>` class to store components of multivectors (set to `std::map<bitset_t, ValueType>`) |
| `sequence_container_t<EntryType, Size>` | The sequence container class used by the `clifford_expression<...>` class to store components of multivectors (set to `std::array<EntryType, Size>`) |

The following classes correspond to the most important structures of GATL.

| Class | Description |
| --- | --- |
| `clifford_expression<CoefficientType, Expression>` | A Clifford expression |
| `grade_result<Value>` | A class to encode the result of the `grade` function |
| `lazy_context<InputTypes...>` | A class to define lazy arguments for lazy evaluation of Clifford expressions |
| `metric_space<MetricSpaceType>` | The base metric space class |

| Exception Class | Description |
| --- | --- |
| `bad_checked_copy_exception` | An exception of this type is thrown when a checked copy fails |
| `not_implemented_error` | An exception to report errors related to not implemented features |

For the sake of simplicity, GATL provides the following set of class aliases and helper meta-functions to assist type definition. Nevertheless, it is strongly recommended to use the `auto` placeholder type specifier (please, refer to the [C++ specification](https://en.cppreference.com/w/cpp/language/auto) for details) whenever possible.

| Class Alias | Description |
| --- | --- |
| `constant<CoefficientType, IntegralValue>` | An alias for constant scalar Clifford expressions whose coefficient is known in compile time |
| `scalar_clifford_expression<CoefficientType, Coefficient>` | An alias for scalar Clifford expressions |

| Helper for Practical Type Definition | Description |
| --- | --- |
| `full_multivector_t<CoefficientType, VectorSpaceDimensions [, FirstGrade [, LastGrade]]>` | Helper for defining a Clifford expression representing a general multivector with runtime defined coefficients over an *n*-dimensional vector space |
| `full_derived_multivector_t<CoefficientType, Expression>` | Helper for defining a Clifford expression representing a general multivector with runtime defined coefficients in all components of the given Clifford expression |
| `full_kvector_t<CoefficientType, VectorSpaceDimensions, Grade>` | Helper for defining a Clifford expression representing a *k*-vector with runtime defined coefficients over an *n*-dimensional vector space |
| `full_vector_t<CoefficientType, VectorSpaceDimensions>` | Helper for defining a Clifford expression representing a vector with runtime defined coefficients over an *n*-dimensional vector space |
| `scaled_constant_basis_blade_t<CoefficientType, Indices...>` | Helper for defining a Clifford expression representing a scaled compile-time defined basis blade |
| `scaled_constant_basis_vector_t<CoefficientType, Index>` | Helper for defining a Clifford expression representing a scaled compile-time defined basis vector |
| `scaled_basis_blade_t<CoefficientType, FirstPossibleGrade[, LastPossibleGrade]>` | Helper for defining a Clifford expression representing a scaled runtime defined basis blade |
| `scaled_basis_vector_t<CoefficientType>` | Helper for defining a Clifford expression representing a scaled runtime defined basis vector |
| `scaled_scalar_t<CoefficientType>` | Helper for defining a Clifford expression representing a scalar value whose coefficient is unknown in compile time |
| `scaled_pseudoscalar_t<CoefficientType, N>` | Helper for defining a Clifford expression representing a scaled compile-time defined pseudoscalar |
| `unit_constant_basis_blade_t<Indices...>` | Helper for defining a Clifford expression representing an unit compile-time defined basis blade |
| `unit_constant_basis_vector_t<Index>` | Helper for defining a Clifford expression representing an unit compile-time defined basis vector |
| `unit_basis_blade_t<FirstPossibleGrade [, LastPossibleGrade]>` | Helper for defining a Clifford expression representing an unit runtime defined basis blade |
| `unit_basis_vector_t` | Helper for defining a Clifford expression representing an unit runtime defined basis vector |
| `unit_pseudoscalar_t<N>` | Helper for defining a Clifford expression representing an unit compile-time defined pseudoscalar |

### Utilities Constants and Functions

Here you find some useful meta-constants and functions to assist the implementation of your program.

| Constant | Description |
| --- | --- |
| `c<IntegralValue [, CoefficientType]>` | Defines a constant scalar Clifford expression whose coefficient is known in compile time |

| Function | Description |
| --- | --- |
| `make_lazy_context(inputs...)` | Creates a `lazy_context<InputTypes...>` object |
| `make_lazy_context_tuple(inputs...)` | Creates a `std::tuple` object made of `K + 1` entries, where the first is a `lazy_context<InputTypes...>` object and the next `K` entries are the lazy input arguments |
| `e(index)` | Returns a runtime defined unit basis vector (index values can be set using `c<IntegralValue>`, too) |
| `scalar(arg)` | Converts the given numerical value to a scalar Clifford expression |
| `pseudoscalar([mtr])` | Returns the compile-time defined unit pseudoscalar of the given metric space |
| `vector([mtr,] coords...)` | Makes a vector with the given set of coordinates (coordinate values can be set using `c<IntegralValue>`, too) |
| `vector([mtr,] begin, end)` | Makes a vector with the set of coordinates accessed by the iterators |

### Products and Basic Operations

The following tables present a set of basic products and operations from geometric algebra.

| Product | Description |
| --- | --- |
| `cp(lhs, rhs [, mtr])` | Commutator product |
| `dp(lhs, rhs [, tol] [, mtr])` | Delta product |
| `dot(lhs, rhs [, mtr])` | Dot product |
| `gp(lhs, rhs [, mtr])` | Geometric/Clifford product |
| `hip(lhs, rhs [, mtr])` | Hestenes inner product |
| `igp(lhs, rhs [, mtr])` | Inverse geometric/Clifford product (the argument `rhs` must be a versor)  |
| `lcont(lhs, rhs [, mtr])` | Left contraction |
| `op(lhs, rhs [, mtr])` | Outer/Wedge product |
| `rp(lhs, rhs [, mtr])` | Regressive product |
| `rcont(lhs, rhs [, mtr])` | Right contraction |
| `sp(lhs, rhs [, mtr])` | Scalar product |

| Sign-Change Operation | Description |
| --- | --- |
| `conjugate(arg)` | Clifford conjugation |
| `involute(arg)` | Grade involution |
| `reverse(arg)` | Reversion |

| Dualization Operation | Description |
| --- | --- |
| `dual(arg [, pseudoscalar [, mtr]])` | Dualization operation |
| `undual(arg [, pseudoscalar [, mtr]])` | Undualization operation |

| Norm-Based Operation | Description |
| --- | --- |
| `rnorm_sqr(arg [, mtr])` | Squared reverse norm |
| `rnorm(arg [, mtr])` | Reverse norm |
| `inv(arg [, mtr])` | Inverse of the given versor using the squared reverse norm |
| `unit(arg [, mtr])` | Unit under reverse norm |

| Transformation Operation | Description |
| --- | --- |
| `apply_even_versor(versor, arg [, mtr])` | Returns the argument transformed by the even versor using the sandwich product |
| `apply_odd_versor(versor, arg [, mtr])` | Returns the argument transformed by the odd versor using the sandwich product |
| `apply_rotor(rotor, arg [, mtr])` | Returns the argument transformed by the rotor using the sandwich product |

| Blade Operation | Description |
| --- | --- |
| `fast_join(lhs, rhs [, tol] [, mtr])` | Returns the join of the given pair of blades using the algorithm developed by [Fontijne (2008)](https://doi.org/10.1007/978-1-84996-108-0_21) |
| `fast_meet_and_join(lhs, rhs [, tol] [, mtr])` | Returns a `std::tuple<T1, T2>` structure where `T1` is the meet and `T2` is the join of the given pair of blades using the algorithm developed by [Fontijne (2008)](https://doi.org/10.1007/978-1-84996-108-0_21) |
| `fast_plunge(lhs, rhs [, tol] [, mtr])` | Returns the plunge of the given pair of blades as described by [Dorst et al. (2007)](http://www.geometricalgebra.net/), and implemented using the `fast_join` function |
| `meet_and_join(lhs, rhs [, tol] [, mtr])` | Returns a `std::tuple<T1, T2>` structure where `T1` is the meet and `T2` is the join of the given pair of blades using the algorithm described by [Dorst et al. (2007)](http://www.geometricalgebra.net/) |
| `plunge(lhs, rhs [, tol] [, mtr])` | Returns the plunge of the given pair of blades as described by [Dorst et al. (2007)](http://www.geometricalgebra.net/), and implemented using the `meet_and_join` function |

| Misc Operation | Description |
| --- | --- |
| `grade(arg [, tol])` | Returns a `grade_result<Value>` structure encoding the grade of the given argument |
| `largest_grade(arg [, tol])` | Returns a scalar expression with the largest grade part of the argument, such that it is not *zero* |
| `take_grade(arg, k)` | Returns the *k*-grade part of the argument |
| `take_largest_grade(arg [, tol])` | Returns the portion of the argument with the largest grade |

### Overloaded Operators

GATL overload some C++ operators to make the writing of source code closer to the writing of mathematical expressions with geometric algebra.

It is important to notice that the precedence and associativity of C++ operators are different than the one assumed in mathematical functions. For instance, one would expect that the outer/wedge product `^` would be evaluated before the addition operation in the following expression `a + b ^ c`, because product precedes addition in math. However, in C++ the addition operator (`+`) precedes the bitwise XOR operator (`^`), leading to possible mistakes while implementing mathematical procedures (please, refer to the [C++ specification](https://en.cppreference.com/w/cpp/language/operator_precedence) for details). As a result, the resulting expression in this example would be `(a + b) ^ c`. The use of parenthesis is strongly recommended in order to avoid those mistakes. By rewriting the example, `a + (b ^ c)` will guarantee the expected behavior.

| Arithmetic Operator | Description |
| --- | --- |
| `+rhs` | Unary plus |
| `-rhs` | Unary minus |
| `~rhs` | Reversion (same as `reverse(rhs)`) |
| `lhs + rhs` | Addition |
| `lhs - rhs` | Subtraction |
| `lhs * rhs` | Geometric/Clifford product (same as `gp(lhs, rhs)`) |
| `lhs / rhs` | Inverse geometric/Clifford product (same as `igp(lhs, rhs)`) |
| `lhs ^ rhs` | Outer/Wedge product (same as `op(lhs, rhs)`) |
| `lhs < rhs` | Left constraction (same as `lcont(lhs, rhs)`) |
| `lhs > rhs` | Right constraction (same as `rcond(lhs, rhs)`) |
| <code>lhs &#124; rhs</code> | Dot product (same as `dot(lhs, rhs)`) |

| Input/Output Operator | Description |
| --- | --- |
| `os << arg` | Insert formatted output (it uses the `write` function) |

### Overloaded Mathematical Functions

The following tables present the C++ mathematical functions overloaded by GATL to accept Clifford expressions as input.

| Trigonometric Function | Description |
| --- | --- |
| `cos(arg)` | Cosine of the scalar argument (in radians) |
| `sin(arg)` | Sine of the scalar argument (in radians) |
| `tan(arg)` | Tangent of the scalar argument (in radians) |

| Hyperbolic Function | Description |
| --- | --- |
| `cosh(arg)` | Hyperbolic cosine of the scalar argument (in radians) |
| `sinh(arg)` | Hyperbolic sine of the scalar argument (in radians) |
| `tanh(arg)` | Hyperbolic tangent of the scalar argument (in radians) |

| Exponential and Logarithmic Function | Description |
| --- | --- |
| `exp(arg [, tol] [, mtr])` | Base-*e* exponential function of the even blade argument |
| `log(arg)` | Natural logarithm of the scalar argument |

| Power Function | Description |
| --- | --- |
| `pow(base, exponent)` | Scalar argument `base` raised to the scalar power argument `exponent` |
| `cbrt(arg)` | Cubic root of the scalar argument |
| `sqrt(arg)` | Square root of the scalar argument |

| Other Function | Description |
| --- | --- |
| `abs(arg)` | Absolute value of the scalar argument |

### Tools

GATL includes a set of useful functions, procedures, and meta-functions to help developers to write their programs.

| Function | Description |
| --- | --- |
| `default_tolerance<ValueType>()` | Return the standard tolerance value `tol` assumed for the given value type |
| `for_each_basis_vector(arg, f)` | Applies the given function object `f`