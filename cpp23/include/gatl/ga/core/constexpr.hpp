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
 * C++23 modernization by: durantschoon
 * Date: 2024-06-24
 */

#ifndef __GA_CORE_CONSTEXPR_HPP__
#define __GA_CORE_CONSTEXPR_HPP__

#include <bit>
#include <cstdint>
#include <limits>
#include <type_traits>

namespace ga {

    namespace detail {

        // C++23: Returns the absolute integer value using modern std::abs
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr T iabs(T arg) GA_NOEXCEPT {
            return std::abs(arg);
        }

        // C++23: Returns the greatest common divisor using manual implementation
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr T gcd(T lhs, T rhs) GA_NOEXCEPT {
            while (rhs != 0) {
                T temp = rhs;
                rhs = lhs % rhs;
                lhs = temp;
            }
            return lhs;
        }

        // C++23: Returns the sign of the given integer value
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr T sign(T arg) GA_NOEXCEPT {
            return arg > 0 ? T(1) : (arg < 0 ? T(-1) : T(0));
        }

        // C++23: Returns the A raised to the power of B, where A is an integer value and B is non-negative
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr T ipow(T base, T exponent) GA_NOEXCEPT {
            if (exponent == 0) return T(1);
            if (exponent == 1) return base;
            
            T result = T(1);
            while (exponent > 0) {
                if (exponent & 1) {
                    result *= base;
                }
                base *= base;
                exponent >>= 1;
            }
            return result;
        }

        // C++23: Returns the square root of the given integer value using modern std::sqrt
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr T isqrt(T arg) GA_NOEXCEPT {
            if (arg < 0) return T(0);
            if (arg <= 1) return arg;
            
            T x = arg;
            T y = (x + arg / x) / 2;
            while (y < x) {
                x = y;
                y = (x + arg / x) / 2;
            }
            return x;
        }

        // C++23: Returns the number of 1 bits in the given bitset using modern std::popcount
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr T ones(T arg) GA_NOEXCEPT {
            return static_cast<T>(std::popcount(static_cast<std::make_unsigned_t<T>>(arg)));
        }

        // C++23: Returns the number of swaps performed to merge two basis blades
        GA_ALWAYS_INLINE constexpr default_integral_t swaps_count(bitset_t const lhs, bitset_t const rhs) GA_NOEXCEPT {
            return lhs != bitset_t(0) ? (ones(lhs & rhs) + swaps_count((lhs >> 1), rhs)) : 0;
        }

        // C++23: Returns the leftmost set bit in the given bitset using modern std::bit_floor
        GA_ALWAYS_INLINE constexpr bitset_t leftmost_set_bit(bitset_t const arg) GA_NOEXCEPT {
            return arg != bitset_t(0) ? static_cast<bitset_t>(std::bit_floor(static_cast<std::uint64_t>(arg))) : bitset_t(0);
        }

        // C++23: Returns the rightmost set bit in the given bitset using modern std::bit_floor
        GA_ALWAYS_INLINE constexpr bitset_t rightmost_set_bit(bitset_t const arg) GA_NOEXCEPT {
            return arg & -std::make_signed_t<bitset_t>(arg);
        }

        // C++23: Returns the index of the set bit, assuming that there is a single set bit in the bitset
        GA_ALWAYS_INLINE constexpr index_t set_bit_index(bitset_t const arg) GA_NOEXCEPT {
            return ones(arg - bitset_t(1));
        }

        // C++23: Returns the bitset of the first k-combination
        GA_ALWAYS_INLINE constexpr bitset_t first_combination(ndims_t const k) GA_NOEXCEPT {
            return bitset_t((bitset_t(1) << k) - 1);
        }
        
        // C++23: Returns the next combination of k elements in n, or zero when there is not more combinations
        GA_ALWAYS_INLINE constexpr bitset_t _next_combination_impl_b(bitset_t const curr, bitset_t const rightmost_one, bitset_t const temp) GA_NOEXCEPT {
            return temp != bitset_t(0) ? (temp + (((temp ^ curr) / rightmost_one) >> 2)) : bitset_t(0);
        }

        GA_ALWAYS_INLINE constexpr bitset_t _next_combination_impl_a(bitset_t const curr, bitset_t const mask, bitset_t const rightmost_one) GA_NOEXCEPT {
            return _next_combination_impl_b(curr, rightmost_one, (rightmost_one + curr) & mask);
        }

        GA_ALWAYS_INLINE constexpr bitset_t next_combination(bitset_t const curr, bitset_t const mask) GA_NOEXCEPT {
            return _next_combination_impl_a(curr, mask, rightmost_set_bit(curr));
        }

        // C++23: Cast the given integral type to the default floating point type
        template<typename Type>
        requires std::integral<Type>
        GA_ALWAYS_INLINE constexpr decltype(auto) cast_to_floating_point(Type const& arg) GA_NOEXCEPT {
            return static_cast<default_floating_point_t>(arg);
        }

        template<typename Type>
        requires (!std::integral<Type>)
        GA_ALWAYS_INLINE constexpr decltype(auto) cast_to_floating_point(Type&& arg) GA_NOEXCEPT {
            return std::move(arg);
        }

        // C++23: Returns the square of a given value
        template<typename Type>
        GA_ALWAYS_INLINE constexpr decltype(auto) square(Type&& arg) GA_NOEXCEPT {
            return std::move(arg) * std::move(arg);
        }

        // C++23: Returns the cube of a given value
        template<typename Type>
        GA_ALWAYS_INLINE constexpr decltype(auto) cube(Type&& arg) GA_NOEXCEPT {
            return std::move(arg) * std::move(arg) * std::move(arg);
        }

        // C++23: Safe right-shifting operation
        template<typename LeftType, typename RightType>
        requires std::integral<LeftType> && std::integral<RightType>
        GA_ALWAYS_INLINE constexpr LeftType safe_rshift(LeftType const lhs, RightType const rhs) GA_NOEXCEPT {
            return (sizeof(LeftType) * 8) > rhs ? lhs >> rhs : LeftType(0);
        }

        // C++23: Additional constexpr utilities for Geometric Algebra

        // Check if a number is a power of 2
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr bool is_power_of_2(T value) GA_NOEXCEPT {
            return value > 0 && (value & (value - 1)) == 0;
        }

        // Get the next power of 2 greater than or equal to the given value
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr T next_power_of_2(T value) GA_NOEXCEPT {
            if (value <= 0) return T(1);
            return static_cast<T>(std::bit_ceil(static_cast<std::uint64_t>(value)));
        }

        // Get the previous power of 2 less than or equal to the given value
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr T prev_power_of_2(T value) GA_NOEXCEPT {
            if (value <= 0) return T(0);
            return static_cast<T>(std::bit_floor(static_cast<std::uint64_t>(value)));
        }

        // Count trailing zeros using modern std::countr_zero
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr T count_trailing_zeros(T value) GA_NOEXCEPT {
            return value == 0 ? std::numeric_limits<T>::digits : static_cast<T>(std::countr_zero(static_cast<std::make_unsigned_t<T>>(value)));
        }

        // Count leading zeros using modern std::countl_zero
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr T count_leading_zeros(T value) GA_NOEXCEPT {
            return static_cast<T>(std::countl_zero(static_cast<std::make_unsigned_t<T>>(value)));
        }

        // Reverse bits using modern std::reverse
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr T reverse_bits(T value) GA_NOEXCEPT {
            return static_cast<T>(std::reverse(static_cast<std::make_unsigned_t<T>>(value)));
        }

        // Rotate left using modern std::rotl
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr T rotate_left(T value, int shift) GA_NOEXCEPT {
            return static_cast<T>(std::rotl(static_cast<std::make_unsigned_t<T>>(value), shift));
        }

        // Rotate right using modern std::rotr
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr T rotate_right(T value, int shift) GA_NOEXCEPT {
            return static_cast<T>(std::rotr(static_cast<std::make_unsigned_t<T>>(value), shift));
        }

        // Check if a number is even
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr bool is_even(T value) GA_NOEXCEPT {
            return (value & 1) == 0;
        }

        // Check if a number is odd
        template<std::integral T>
        GA_ALWAYS_INLINE constexpr bool is_odd(T value) GA_NOEXCEPT {
            return (value & 1) == 1;
        }

        // Get the minimum of two values
        template<typename T>
        GA_ALWAYS_INLINE constexpr T min(T a, T b) GA_NOEXCEPT {
            return a < b ? a : b;
        }

        // Get the maximum of two values
        template<typename T>
        GA_ALWAYS_INLINE constexpr T max(T a, T b) GA_NOEXCEPT {
            return a > b ? a : b;
        }

        // Clamp a value between min and max
        template<typename T>
        GA_ALWAYS_INLINE constexpr T clamp(T value, T min_val, T max_val) GA_NOEXCEPT {
            return value < min_val ? min_val : (value > max_val ? max_val : value);
        }

        // Check if a value is in range [min, max]
        template<typename T>
        GA_ALWAYS_INLINE constexpr bool in_range(T value, T min_val, T max_val) GA_NOEXCEPT {
            return value >= min_val && value <= max_val;
        }

        // Check if a value is in range [min, max) (exclusive max)
        template<typename T>
        GA_ALWAYS_INLINE constexpr bool in_range_exclusive(T value, T min_val, T max_val) GA_NOEXCEPT {
            return value >= min_val && value < max_val;
        }

    }

}

#endif // __GA_CORE_CONSTEXPR_HPP__ 