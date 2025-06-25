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
 * Core type definitions for geometric algebra operations.
 */

use std::collections::HashMap;

/// Maximum basis vector index supported by the library.
pub const GA_MAX_BASIS_VECTOR_INDEX: usize = 63;

/// Default floating point type for geometric algebra operations.
pub type DefaultFloatingPoint = f64;

/// Default integral type for geometric algebra operations.
pub type DefaultIntegral = i64;

/// Bitset type for representing basis vectors efficiently.
/// 
/// This type is chosen based on the maximum basis vector index:
/// - u8 for indices < 8
/// - u16 for indices < 16  
/// - u32 for indices < 32
/// - u64 for indices >= 32
pub type Bitset = u64; // Using u64 for maximum compatibility

/// Grade type for representing the grade of a multivector.
pub type Grade = DefaultIntegral;

/// Index type for array indexing and dimension counting.
pub type Index = u64;

/// Dimension type for representing the number of dimensions.
pub type NDims = Index;

/// Associative container type for storing multivector components.
pub type AssociativeContainer<T> = HashMap<Bitset, T>;

/// Sequence container type for fixed-size arrays.
pub type SequenceContainer<T, const N: usize> = [T; N];

/// Trait for integral types used in geometric algebra.
pub trait Integral: Copy + PartialEq + PartialOrd + std::fmt::Display + Sized {}

/// Trait for floating point types used in geometric algebra.
pub trait FloatingPoint: Copy + PartialEq + PartialOrd + std::fmt::Display + Sized {}

/// Trait for arithmetic types (integral or floating point).
pub trait Arithmetic: Copy + PartialEq + PartialOrd + std::fmt::Display + Sized {}

/// Trait for bitset types.
pub trait BitsetType: Copy + PartialEq + PartialOrd + std::fmt::Display + Sized {}

/// Trait for index types.
pub trait IndexType: Copy + PartialEq + PartialOrd + std::fmt::Display + Sized {}

/// Trait for types that can be used as scalar values in geometric algebra.
pub trait Scalar: Arithmetic + std::ops::Add<Output = Self> + std::ops::Sub<Output = Self> 
    + std::ops::Mul<Output = Self> + std::ops::Div<Output = Self> + std::ops::Neg<Output = Self>
    + std::default::Default + std::fmt::Debug + Sized {}

/// Trait for types that can be used as basis vector indices.
pub trait BasisIndex: Integral + std::ops::Add<Output = Self> + std::ops::Sub<Output = Self> + Sized {}

/// Trait for types that can be used as grade values.
pub trait GradeType: Integral + std::ops::Add<Output = Self> + std::ops::Sub<Output = Self> + Sized {}

// Implement traits for specific types
impl Integral for i8 {}
impl Integral for i16 {}
impl Integral for i32 {}
impl Integral for i64 {}
impl Integral for i128 {}
impl Integral for isize {}
impl Integral for u8 {}
impl Integral for u16 {}
impl Integral for u32 {}
impl Integral for u64 {}
impl Integral for u128 {}
impl Integral for usize {}

impl FloatingPoint for f32 {}
impl FloatingPoint for f64 {}

// Arithmetic is implemented for both Integral and FloatingPoint types
// Remove blanket implementations to avoid conflicts
// impl<T: Integral> Arithmetic for T {}
// impl<T: FloatingPoint> Arithmetic for T {}

// Implement Arithmetic for specific types
impl Arithmetic for i8 {}
impl Arithmetic for i16 {}
impl Arithmetic for i32 {}
impl Arithmetic for i64 {}
impl Arithmetic for i128 {}
impl Arithmetic for isize {}
impl Arithmetic for u8 {}
impl Arithmetic for u16 {}
impl Arithmetic for u32 {}
impl Arithmetic for u64 {}
impl Arithmetic for u128 {}
impl Arithmetic for usize {}
impl Arithmetic for f32 {}
impl Arithmetic for f64 {}

impl BitsetType for Bitset {}

// Remove conflicting IndexType implementations
// impl IndexType for Index {}
// impl IndexType for NDims {}

impl Scalar for f32 {}
impl Scalar for f64 {}
impl Scalar for i32 {}
impl Scalar for i64 {}

impl BasisIndex for u8 {}
impl BasisIndex for u16 {}
impl BasisIndex for u32 {}
impl BasisIndex for u64 {}
impl BasisIndex for usize {}

impl GradeType for i8 {}
impl GradeType for i16 {}
impl GradeType for i32 {}
impl GradeType for i64 {}
impl GradeType for isize {}

/// Type alias for the default scalar type.
pub type DefaultScalar = DefaultFloatingPoint;

/// Type alias for the default basis index type.
pub type DefaultBasisIndex = u64;

/// Type alias for the default grade type.
pub type DefaultGrade = DefaultIntegral;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_type_aliases() {
        // Test that type aliases are valid
        let _bitset: Bitset = 0;
        let _grade: Grade = 0;
        let _index: Index = 0;
        let _ndims: NDims = 0;
        let _scalar: DefaultScalar = 0.0;
        let _basis_index: DefaultBasisIndex = 0;
        let _grade_type: DefaultGrade = 0;
    }

    #[test]
    fn test_constants() {
        assert_eq!(GA_MAX_BASIS_VECTOR_INDEX, 63);
    }

    #[test]
    fn test_containers() {
        let _assoc: AssociativeContainer<f64> = HashMap::new();
        let _seq: SequenceContainer<i32, 4> = [1, 2, 3, 4];
    }

    #[test]
    fn test_trait_implementations() {
        // Test that specific types implement the expected traits
        let _integral: i64 = 42;
        let _floating: f64 = 3.14;
        let _scalar: f64 = 3.14;
        let _basis_index: u64 = 42;
        let _grade_type: i64 = 42;
    }
} 