/*
 * GATL: Geometric Algebra Template Library
 * 
 * Copyright (c) 2021 Leandro A. F. Fernandes
 * Copyright (c) 2024 Durant Schoon (C++23 modernization)
 * 
 * This file is part of the Rust implementation of GATL.
 * 
 * GATL is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * GATL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GATL.  If not, see <https://www.gnu.org/licenses/>.
 * 
 * Original repository: https://github.com/laffernandes/gatl
 * Modernized fork: https://github.com/durantschoon/gatl
 * 
 * Core geometric algebra functionality and mathematical utilities.
 */

use crate::constants;
use crate::types::*;
use std::f64::consts;

/// Convert degrees to radians using tau-based calculations.
/// 
/// This function uses τ/360 for the conversion factor, which is more
/// natural than π/180.
pub fn degrees_to_radians<T>(degrees: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy + std::ops::Mul<Output = T> + std::ops::Div<Output = T>,
{
    let degrees_f64: f64 = degrees.into();
    let radians_f64 = degrees_f64 * constants::tau::<f64>() / 360.0;
    T::from(radians_f64)
}

/// Convert radians to degrees using tau-based calculations.
/// 
/// This function uses 360/τ for the conversion factor, which is more
/// natural than 180/π.
pub fn radians_to_degrees<T>(radians: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy + std::ops::Mul<Output = T> + std::ops::Div<Output = T>,
{
    let radians_f64: f64 = radians.into();
    let degrees_f64 = radians_f64 * 360.0 / constants::tau::<f64>();
    T::from(degrees_f64)
}

/// Calculate the absolute value of a number.
pub fn abs<T>(value: T) -> T 
where 
    T: Copy + PartialOrd + std::ops::Neg<Output = T> + std::default::Default,
{
    if value >= T::default() {
        value
    } else {
        -value
    }
}

/// Calculate the square of a number.
pub fn square<T>(value: T) -> T 
where 
    T: Copy + std::ops::Mul<Output = T>,
{
    value * value
}

/// Calculate the cube of a number.
pub fn cube<T>(value: T) -> T 
where 
    T: Copy + std::ops::Mul<Output = T>,
{
    value * value * value
}

/// Calculate the power of a number.
pub fn pow<T>(base: T, exponent: u32) -> T 
where 
    T: Copy + std::ops::Mul<Output = T> + std::default::Default + From<u32>,
{
    if exponent == 0 {
        T::from(1u32)
    } else if exponent == 1 {
        base
    } else {
        let mut result = base;
        for _ in 1..exponent {
            result = result * base;
        }
        result
    }
}

/// Calculate the square root of a number.
pub fn sqrt<T>(value: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy,
{
    let value_f64: f64 = value.into();
    T::from(value_f64.sqrt())
}

/// Calculate the cube root of a number.
pub fn cbrt<T>(value: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy,
{
    let value_f64: f64 = value.into();
    T::from(value_f64.cbrt())
}

/// Calculate the exponential function.
pub fn exp<T>(value: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy,
{
    let value_f64: f64 = value.into();
    T::from(value_f64.exp())
}

/// Calculate the natural logarithm.
pub fn ln<T>(value: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy,
{
    let value_f64: f64 = value.into();
    T::from(value_f64.ln())
}

/// Calculate the sine function.
pub fn sin<T>(value: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy,
{
    let value_f64: f64 = value.into();
    T::from(value_f64.sin())
}

/// Calculate the cosine function.
pub fn cos<T>(value: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy,
{
    let value_f64: f64 = value.into();
    T::from(value_f64.cos())
}

/// Calculate the tangent function.
pub fn tan<T>(value: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy,
{
    let value_f64: f64 = value.into();
    T::from(value_f64.tan())
}

/// Calculate the arcsine function.
pub fn asin<T>(value: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy,
{
    let value_f64: f64 = value.into();
    T::from(value_f64.asin())
}

/// Calculate the arccosine function.
pub fn acos<T>(value: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy,
{
    let value_f64: f64 = value.into();
    T::from(value_f64.acos())
}

/// Calculate the arctangent function.
pub fn atan<T>(value: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy,
{
    let value_f64: f64 = value.into();
    T::from(value_f64.atan())
}

/// Calculate the hyperbolic sine function.
pub fn sinh<T>(value: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy,
{
    let value_f64: f64 = value.into();
    T::from(value_f64.sinh())
}

/// Calculate the hyperbolic cosine function.
pub fn cosh<T>(value: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy,
{
    let value_f64: f64 = value.into();
    T::from(value_f64.cosh())
}

/// Calculate the hyperbolic tangent function.
pub fn tanh<T>(value: T) -> T 
where 
    T: From<f64> + Into<f64> + Copy,
{
    let value_f64: f64 = value.into();
    T::from(value_f64.tanh())
}

/// Calculate the minimum of two values.
pub fn min<T>(a: T, b: T) -> T 
where 
    T: Copy + PartialOrd,
{
    if a <= b { a } else { b }
}

/// Calculate the maximum of two values.
pub fn max<T>(a: T, b: T) -> T 
where 
    T: Copy + PartialOrd,
{
    if a >= b { a } else { b }
}

/// Clamp a value between a minimum and maximum.
pub fn clamp<T>(value: T, min_val: T, max_val: T) -> T 
where 
    T: Copy + PartialOrd,
{
    if value < min_val {
        min_val
    } else if value > max_val {
        max_val
    } else {
        value
    }
}

/// Check if a value is approximately equal to another within a tolerance.
pub fn approximately_equal<T>(a: T, b: T, tolerance: T) -> bool 
where 
    T: Copy + PartialOrd + std::ops::Sub<Output = T> + std::ops::Neg<Output = T>,
{
    let diff = if a >= b { a - b } else { b - a };
    diff <= tolerance
}

/// Check if a value is approximately zero within a tolerance.
pub fn approximately_zero<T>(value: T, tolerance: T) -> bool 
where 
    T: Copy + PartialOrd + std::ops::Sub<Output = T> + std::ops::Neg<Output = T> + std::default::Default,
{
    approximately_equal(value, T::default(), tolerance)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_angle_conversions() {
        // Test degree to radian conversion
        let degrees: f64 = 180.0;
        let radians = degrees_to_radians(degrees);
        assert!((radians - constants::pi::<f64>()).abs() < 1e-15f64);

        // Test radian to degree conversion
        let radians: f64 = constants::pi::<f64>();
        let degrees = radians_to_degrees(radians);
        assert!((degrees - 180.0f64).abs() < 1e-15f64);
    }

    #[test]
    fn test_mathematical_functions() {
        // Test basic mathematical functions
        assert_eq!(abs(-5.0), 5.0);
        assert_eq!(abs(5.0), 5.0);
        assert_eq!(square(3.0), 9.0);
        assert_eq!(cube(2.0), 8.0);
        assert_eq!(pow(2.0, 3), 8.0);
        assert_eq!(sqrt(16.0), 4.0);
        assert_eq!(cbrt(27.0), 3.0);
    }

    #[test]
    fn test_trigonometric_functions() {
        // Test trigonometric functions
        assert!((sin(constants::pi::<f64>() / 2.0) - 1.0f64).abs() < 1e-15f64);
        assert!((cos(0.0f64) - 1.0f64).abs() < 1e-15f64);
        assert!((tan(0.0f64) - 0.0f64).abs() < 1e-15f64);
    }

    #[test]
    fn test_utility_functions() {
        // Test utility functions
        assert_eq!(min(3.0, 5.0), 3.0);
        assert_eq!(max(3.0, 5.0), 5.0);
        assert_eq!(clamp(10.0, 0.0, 5.0), 5.0);
        assert_eq!(clamp(-5.0, 0.0, 5.0), 0.0);
        assert_eq!(clamp(3.0, 0.0, 5.0), 3.0);
    }

    #[test]
    fn test_approximation_functions() {
        // Test approximation functions
        assert!(approximately_equal(1.0, 1.0000001, 0.001));
        assert!(!approximately_equal(1.0, 1.1, 0.001));
        assert!(approximately_zero(0.0000001, 0.001));
        assert!(!approximately_zero(0.1, 0.001));
    }
} 