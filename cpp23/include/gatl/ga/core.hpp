/* Copyright (C) Leandro Augusto Frata Fernandes
 * 
 * author     : Fernandes, Leandro A. F.
 * e-mail     : laffernandes@ic.uff.br
 * home page  : http://www.ic.uff.br/~laffernandes
 * repository : https://github.com/durantschoon/gatl.git
 * 
 * This file is part of The Geometric Algebra Template Library (GATL).
 * 
 * GATL is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * GATL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GATL. If not, see <https://www.gnu.org/licenses/>.
 * 
 * C++23 modernization by: durant
 * Date: 2024-06-24
 */

#ifndef __GA_CORE_HPP__
#define __GA_CORE_HPP__

// C++23 features and modern includes
#include <algorithm>
#include <array>
#include <bit>
#include <cassert>
#include <cmath>
#include <concepts>
#include <cstdint>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

// Compiler-specific optimizations
#ifdef _MSC_VER
    #pragma inline_recursion(on)
    #pragma inline_depth(255)
#endif

// Modern C++23 inline and noexcept definitions
#if defined(__GNUC__) || defined(__clang__)
    #define GA_ALWAYS_INLINE __attribute__((always_inline)) inline
    #define GA_NOEXCEPT noexcept
#elif defined(_MSC_VER)
    #define GA_ALWAYS_INLINE __forceinline
    #define GA_NOEXCEPT noexcept
#else
    #define GA_ALWAYS_INLINE inline
    #define GA_NOEXCEPT noexcept
#endif

// Default type definitions with C++23 features
#ifndef GA_DEFAULT_FLOATING_POINT_TYPE
    #define GA_DEFAULT_FLOATING_POINT_TYPE std::double_t
#endif

#ifndef GA_DEFAULT_INTEGRAL_TYPE
    #define GA_DEFAULT_INTEGRAL_TYPE std::int64_t
#endif

#ifndef GA_MAX_BASIS_VECTOR_INDEX
    #define GA_MAX_BASIS_VECTOR_INDEX 63
#endif

// C++23 static_assert with message
#define _GA_ONE_TIME_WARNING(MESSAGE) \
    { \
        static bool first_time = true; \
        if (first_time) { \
            std::clog << "[WARNING]: " << (MESSAGE) << std::endl; \
            first_time = false; \
        } \
    }

namespace ga {

    // C++23 static_assert with message
    static_assert(std::is_integral_v<decltype((GA_MAX_BASIS_VECTOR_INDEX))> && 
                  1 <= (GA_MAX_BASIS_VECTOR_INDEX) && (GA_MAX_BASIS_VECTOR_INDEX) <= 63, 
                  "GA_MAX_BASIS_VECTOR_INDEX must be an integer value between 1 and 63, inclusive.");

    // Modern type aliases using C++23 features
    using default_floating_point_t = GA_DEFAULT_FLOATING_POINT_TYPE;
    using default_integral_t = GA_DEFAULT_INTEGRAL_TYPE;

    // Modern bitset type selection using C++23 conditional_t
    using bitset_t = std::conditional_t<
        (GA_MAX_BASIS_VECTOR_INDEX) < 8, std::uint8_t,
        std::conditional_t<
            (GA_MAX_BASIS_VECTOR_INDEX) < 16, std::uint16_t,
            std::conditional_t<
                (GA_MAX_BASIS_VECTOR_INDEX) < 32, std::uint32_t,
                std::uint64_t
            >
        >
    >;

    using grade_t = default_integral_t;
    using index_t = std::uint64_t;
    using ndims_t = index_t;

    // Modern container type aliases
    template<typename ValueType>
    using associative_container_t = std::map<bitset_t, ValueType>;

    template<typename EntryType, std::size_t Size>
    using sequence_container_t = std::array<EntryType, Size>;

    // C++23 concepts for better type safety
    template<typename T>
    concept Integral = std::integral<T>;

    template<typename T>
    concept FloatingPoint = std::floating_point<T>;

    template<typename T>
    concept Arithmetic = std::integral<T> || std::floating_point<T>;

    template<typename T>
    concept BitsetType = std::same_as<T, bitset_t>;

    template<typename T>
    concept IndexType = std::same_as<T, index_t> || std::same_as<T, ndims_t>;

    // Mathematical constants using τ/2 (tau/2) instead of π
    namespace constants {
        // τ = 2π (tau is the fundamental circle constant)
        template<typename T>
        constexpr T tau = T(6.2831853071795864769252867665590057683943387987502116419498891846156328125724179972560696506842341359642961730265646132941876892191011644634507188162569622349005682054038770422111192892458979098607639288576219513318668922569512964675735663305424038182912971338469206972209086532964267872145204982825474491740132126311763497630418419256585081834307287357851807200226370610651833054443549874339578891850531496274840235810990172474301736797726423553664399883428838048440817494678528843646008341135112148295234676943283953840470614907609342700921758169833173637541391634078839);

        // τ/2 = π (half tau)
        template<typename T>
        constexpr T tau_over_2 = tau<T> / T(2);

        // τ/4 = π/2 (quarter tau)
        template<typename T>
        constexpr T tau_over_4 = tau<T> / T(4);

        // τ/6 = π/3 (one-sixth tau)
        template<typename T>
        constexpr T tau_over_6 = tau<T> / T(6);

        // τ/8 = π/4 (one-eighth tau)
        template<typename T>
        constexpr T tau_over_8 = tau<T> / T(8);

        // τ/12 = π/6 (one-twelfth tau)
        template<typename T>
        constexpr T tau_over_12 = tau<T> / T(12);

        // Common angle constants
        template<typename T>
        constexpr T full_rotation = tau<T>;        // 360° = τ

        template<typename T>
        constexpr T half_rotation = tau_over_2<T>; // 180° = τ/2

        template<typename T>
        constexpr T quarter_rotation = tau_over_4<T>; // 90° = τ/4

        template<typename T>
        constexpr T third_rotation = tau_over_6<T>;   // 60° = τ/6

        template<typename T>
        constexpr T sixth_rotation = tau_over_12<T>;  // 30° = τ/12

        // Legacy π constants for backward compatibility
        template<typename T>
        constexpr T pi = tau_over_2<T>;

        template<typename T>
        constexpr T pi_over_2 = tau_over_4<T>;

        template<typename T>
        constexpr T pi_over_4 = tau_over_8<T>;

        template<typename T>
        constexpr T pi_over_6 = tau_over_12<T>;
    }

    // Convenience functions for common angles
    namespace angles {
        template<typename T>
        constexpr T degrees_to_radians(T degrees) GA_NOEXCEPT {
            return degrees * constants::tau<T> / T(360);
        }

        template<typename T>
        constexpr T radians_to_degrees(T radians) GA_NOEXCEPT {
            return radians * T(360) / constants::tau<T>;
        }

        // Common angle conversions
        template<typename T>
        constexpr T full_rotation_rad = constants::full_rotation<T>;

        template<typename T>
        constexpr T half_rotation_rad = constants::half_rotation<T>;

        template<typename T>
        constexpr T quarter_rotation_rad = constants::quarter_rotation<T>;

        template<typename T>
        constexpr T third_rotation_rad = constants::third_rotation<T>;

        template<typename T>
        constexpr T sixth_rotation_rad = constants::sixth_rotation<T>;
    }

}

// Include Phase 1 foundation files
#include "core/exceptions.hpp"
#include "core/type_traits_extension.hpp"
#include "core/constexpr.hpp"
#include "core/default_tolerance.hpp"
#include "core/tag_types.hpp"
#include "core/operator_symbols.hpp"

// Note: Other includes will be added as we convert more files
// #include "core/expression.hpp"
// #include "core/expression_traits.hpp"
// #include "core/metric_space.hpp"
// #include "core/real_metric_space.hpp"
// #include "core/mapping.hpp"
// #include "core/expression_relational_operators.hpp"
// #include "core/expression_graded_unary_minus.hpp"
// #include "core/rules.hpp"
// #include "core/expression_simplification_addition_values.hpp"
// #include "core/expression_simplification_addition_components.hpp"
// #include "core/expression_simplification_product_values.hpp"
// #include "core/expression_simplification_product_components.hpp"
// #include "core/expression_simplification_power.hpp"
// #include "core/arithmetic_operators.hpp"
// #include "core/geometric_product.hpp"
// #include "core/outer_product.hpp"
// #include "core/inner_product.hpp"
// #include "core/scalar_product.hpp"
// #include "core/left_contraction.hpp"
// #include "core/right_contraction.hpp"
// #include "core/regressive_product.hpp"
// #include "core/reversion.hpp"
// #include "core/conjugation.hpp"
// #include "core/involution.hpp"
// #include "core/grade.hpp"
// #include "core/take_grade.hpp"
// #include "core/dualization.hpp"
// #include "core/meet_and_join.hpp"
// #include "core/plunge.hpp"
// #include "core/versor_inverse.hpp"
// #include "core/apply_versor.hpp"
// #include "core/blade_exponential.hpp"
// #include "core/commutator_product.hpp"
// #include "core/delta_product.hpp"
// #include "core/fast_meet_and_join.hpp"
// #include "core/fast_plunge.hpp"
// #include "core/reverse_norm.hpp"
// #include "core/unit.hpp"
// #include "core/write.hpp"
// #include "core/tests.hpp"

#endif // __GA_CORE_HPP__ 