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

#ifndef __GA_CORE_DEFAULT_TOLERANCE_HPP__
#define __GA_CORE_DEFAULT_TOLERANCE_HPP__

#include <limits>
#include <type_traits>

namespace ga {

    // C++23: Default tolerance constants with compile-time validation
    namespace tolerance {
        
        // Default tolerance for float (32-bit)
        constexpr float default_float_tolerance = 1.0e-6f;
        static_assert(default_float_tolerance >= 0.0f, "Default float tolerance must be non-negative");
        static_assert(default_float_tolerance < std::numeric_limits<float>::max(), "Default float tolerance must be finite");

        // Default tolerance for double (64-bit)
        constexpr double default_double_tolerance = 1.0e-12;
        static_assert(default_double_tolerance >= 0.0, "Default double tolerance must be non-negative");
        static_assert(default_double_tolerance < std::numeric_limits<double>::max(), "Default double tolerance must be finite");

        // Default tolerance for long double (extended precision)
        constexpr long double default_long_double_tolerance = 1.0e-15L;
        static_assert(default_long_double_tolerance >= 0.0L, "Default long double tolerance must be non-negative");
        static_assert(default_long_double_tolerance < std::numeric_limits<long double>::max(), "Default long double tolerance must be finite");

        // C++23: Template function to get default tolerance for any floating-point type
        template<std::floating_point T>
        constexpr T get_default_tolerance() GA_NOEXCEPT {
            if constexpr (std::is_same_v<T, float>) {
                return default_float_tolerance;
            } else if constexpr (std::is_same_v<T, double>) {
                return default_double_tolerance;
            } else if constexpr (std::is_same_v<T, long double>) {
                return default_long_double_tolerance;
            } else {
                // For other floating-point types, use a reasonable default
                return T(1.0e-12);
            }
        }

        // C++23: Template function to get default tolerance for any arithmetic type
        template<typename T>
        constexpr auto get_default_tolerance() GA_NOEXCEPT {
            if constexpr (std::floating_point<T>) {
                return get_default_tolerance<T>();
            } else if constexpr (std::integral<T>) {
                // For integral types, use 0 (exact comparison)
                return T(0);
            } else {
                // For other types, return a default-constructed value
                return T{};
            }
        }

        // C++23: Template function to check if two values are approximately equal
        template<typename T>
        constexpr bool approximately_equal(T a, T b, T tolerance = get_default_tolerance<T>()) GA_NOEXCEPT {
            if constexpr (std::floating_point<T>) {
                return std::abs(a - b) <= tolerance;
            } else {
                return a == b;
            }
        }

        // C++23: Template function to check if a value is approximately zero
        template<typename T>
        constexpr bool approximately_zero(T value, T tolerance = get_default_tolerance<T>()) GA_NOEXCEPT {
            return approximately_equal(value, T(0), tolerance);
        }

        // C++23: Template function to check if a value is approximately one
        template<typename T>
        constexpr bool approximately_one(T value, T tolerance = get_default_tolerance<T>()) GA_NOEXCEPT {
            return approximately_equal(value, T(1), tolerance);
        }

        // C++23: Template function to check if two values are approximately equal using relative tolerance
        template<std::floating_point T>
        constexpr bool relatively_equal(T a, T b, T relative_tolerance = get_default_tolerance<T>()) GA_NOEXCEPT {
            if (a == b) return true;
            if (a == T(0) || b == T(0)) return std::abs(a - b) <= relative_tolerance;
            
            T max_abs = std::max(std::abs(a), std::abs(b));
            return std::abs(a - b) <= relative_tolerance * max_abs;
        }

        // C++23: Template function to check if a value is relatively zero
        template<std::floating_point T>
        constexpr bool relatively_zero(T value, T relative_tolerance = get_default_tolerance<T>()) GA_NOEXCEPT {
            return std::abs(value) <= relative_tolerance;
        }

        // C++23: Template function to check if a value is relatively one
        template<std::floating_point T>
        constexpr bool relatively_one(T value, T relative_tolerance = get_default_tolerance<T>()) GA_NOEXCEPT {
            return relatively_equal(value, T(1), relative_tolerance);
        }

        // C++23: Template function to get machine epsilon for a type
        template<std::floating_point T>
        constexpr T machine_epsilon() GA_NOEXCEPT {
            return std::numeric_limits<T>::epsilon();
        }

        // C++23: Template function to get a tolerance based on machine epsilon
        template<std::floating_point T>
        constexpr T epsilon_based_tolerance(T multiplier = T(10)) GA_NOEXCEPT {
            return machine_epsilon<T>() * multiplier;
        }

        // C++23: Template function to get a tolerance based on the magnitude of a value
        template<std::floating_point T>
        constexpr T magnitude_based_tolerance(T value, T base_tolerance = get_default_tolerance<T>()) GA_NOEXCEPT {
            T magnitude = std::abs(value);
            if (magnitude < machine_epsilon<T>()) {
                return base_tolerance;
            }
            return base_tolerance * magnitude;
        }

        // C++23: Template function to check if two values are equal within magnitude-based tolerance
        template<std::floating_point T>
        constexpr bool magnitude_equal(T a, T b, T base_tolerance = get_default_tolerance<T>()) GA_NOEXCEPT {
            T max_magnitude = std::max(std::abs(a), std::abs(b));
            T tolerance = magnitude_based_tolerance(max_magnitude, base_tolerance);
            return approximately_equal(a, b, tolerance);
        }

        // C++23: Template function to get the minimum tolerance for a type
        template<std::floating_point T>
        constexpr T min_tolerance() GA_NOEXCEPT {
            return machine_epsilon<T>();
        }

        // C++23: Template function to get the maximum tolerance for a type
        template<std::floating_point T>
        constexpr T max_tolerance() GA_NOEXCEPT {
            return T(1) - machine_epsilon<T>();
        }

        // C++23: Template function to clamp tolerance to valid range
        template<std::floating_point T>
        constexpr T clamp_tolerance(T tolerance) GA_NOEXCEPT {
            return std::clamp(tolerance, min_tolerance<T>(), max_tolerance<T>());
        }

        // C++23: Template function to check if tolerance is valid
        template<std::floating_point T>
        constexpr bool is_valid_tolerance(T tolerance) GA_NOEXCEPT {
            return tolerance >= min_tolerance<T>() && tolerance <= max_tolerance<T>();
        }

        // C++23: Template function to get tolerance for comparison operations
        template<typename T>
        constexpr auto comparison_tolerance() GA_NOEXCEPT {
            if constexpr (std::floating_point<T>) {
                return get_default_tolerance<T>();
            } else {
                return T(0);
            }
        }

        // C++23: Template function to get tolerance for geometric operations
        template<typename T>
        constexpr auto geometric_tolerance() GA_NOEXCEPT {
            if constexpr (std::floating_point<T>) {
                // Geometric operations often need higher precision
                return get_default_tolerance<T>() * T(0.1);
            } else {
                return T(0);
            }
        }

        // C++23: Template function to get tolerance for numerical operations
        template<typename T>
        constexpr auto numerical_tolerance() GA_NOEXCEPT {
            if constexpr (std::floating_point<T>) {
                // Numerical operations can use standard tolerance
                return get_default_tolerance<T>();
            } else {
                return T(0);
            }
        }

    }

    // C++23: Legacy function for backward compatibility
    template<typename ValueType>
    constexpr decltype(auto) default_tolerance() GA_NOEXCEPT {
        return tolerance::get_default_tolerance<ValueType>();
    }

    // C++23: Specializations for common floating-point types
    template<>
    constexpr decltype(auto) default_tolerance<std::float_t>() GA_NOEXCEPT {
        return tolerance::get_default_tolerance<std::float_t>();
    }

    template<>
    constexpr decltype(auto) default_tolerance<std::double_t>() GA_NOEXCEPT {
        return tolerance::get_default_tolerance<std::double_t>();
    }

    template<>
    constexpr decltype(auto) default_tolerance<long double>() GA_NOEXCEPT {
        return tolerance::get_default_tolerance<long double>();
    }

}

#endif // __GA_CORE_DEFAULT_TOLERANCE_HPP__ 