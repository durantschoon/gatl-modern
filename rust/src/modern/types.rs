/*
 * Modern Algebraic Types for Geometric Algebra
 * Copyright (c) 2024 Durant Schoon
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 * 
 * This file is part of the modern GATL implementation.
 * 
 * Modern implementation using Rust features:
 * - enum for sum types
 * - const generics for grade indexing
 * - traits for type safety
 * - zero-cost abstractions
 */

use std::marker::PhantomData;

// ============================================================================
// Type Aliases and Constants
// ============================================================================

pub type Scalar = f64;
pub type Index = u64;
pub type Grade = i64;

// Maximum basis vector index supported
pub const MAX_BASIS_VECTOR_INDEX: Index = 63;

// ============================================================================
// Grade-Indexed Types
// ============================================================================

/// Compile-time grade tag for type safety
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Grade<const G: usize>;

/// Grade-indexed type wrapper for compile-time grade checking
#[derive(Debug, Clone)]
pub struct GradeIndexed<T, const G: usize> {
    pub value: T,
    _phantom: PhantomData<Grade<G>>,
}

impl<T, const G: usize> GradeIndexed<T, G> {
    /// Create a new grade-indexed value
    pub const fn new(value: T) -> Self {
        Self {
            value,
            _phantom: PhantomData,
        }
    }
    
    /// Get the grade value at compile time
    pub const fn grade() -> usize {
        G
    }
    
    /// Get a reference to the underlying value
    pub fn as_ref(&self) -> &T {
        &self.value
    }
    
    /// Get a mutable reference to the underlying value
    pub fn as_mut(&mut self) -> &mut T {
        &mut self.value
    }
    
    /// Consume self and return the underlying value
    pub fn into_inner(self) -> T {
        self.value
    }
}

impl<T, const G: usize> From<T> for GradeIndexed<T, G> {
    fn from(value: T) -> Self {
        Self::new(value)
    }
}

impl<T, const G: usize> AsRef<T> for GradeIndexed<T, G> {
    fn as_ref(&self) -> &T {
        &self.value
    }
}

impl<T, const G: usize> AsMut<T> for GradeIndexed<T, G> {
    fn as_mut(&mut self) -> &mut T {
        &mut self.value
    }
}

// ============================================================================
// Product Types for Blade-Coefficient Pairs
// ============================================================================

/// Represents a basis blade with coefficient
#[derive(Debug, Clone, PartialEq)]
pub struct BladeTerm<T = Scalar> {
    pub basis: Vec<Index>,  // e.g., [1, 2] = e1^e2
    pub coeff: T,
}

impl<T> BladeTerm<T> {
    /// Create a new blade term
    pub fn new(basis: Vec<Index>, coeff: T) -> Self {
        Self { basis, coeff }
    }
    
    /// Get the grade (number of basis vectors)
    pub fn grade(&self) -> Grade {
        self.basis.len() as Grade
    }
    
    /// Check if this is a scalar (grade 0)
    pub fn is_scalar(&self) -> bool {
        self.basis.is_empty()
    }
    
    /// Check if this is a vector (grade 1)
    pub fn is_vector(&self) -> bool {
        self.basis.len() == 1
    }
    
    /// Check if this is a bivector (grade 2)
    pub fn is_bivector(&self) -> bool {
        self.basis.len() == 2
    }
    
    /// Check if this is a trivector (grade 3)
    pub fn is_trivector(&self) -> bool {
        self.basis.len() == 3
    }
}

// ============================================================================
// Sum Types (Tagged Unions) for GA Terms
// ============================================================================

/// Sum type representing different geometric algebra terms
/// Uses enum for type-safe pattern matching
#[derive(Debug, Clone, PartialEq)]
pub enum GATerm {
    /// 0-vector (scalar)
    Scalar(Scalar),
    /// 1-vector
    Vector(Vec<(Index, Scalar)>),
    /// 2-vector (bivector)
    Bivector(Vec<(Index, Index, Scalar)>),
    /// 3-vector (trivector)
    Trivector(Vec<(Index, Index, Index, Scalar)>),
    /// General multivector
    Multivector(Vec<BladeTerm<Scalar>>),
}

impl GATerm {
    /// Check if this term is a scalar
    pub fn is_scalar(&self) -> bool {
        matches!(self, GATerm::Scalar(_))
    }
    
    /// Check if this term is a vector
    pub fn is_vector(&self) -> bool {
        matches!(self, GATerm::Vector(_))
    }
    
    /// Check if this term is a bivector
    pub fn is_bivector(&self) -> bool {
        matches!(self, GATerm::Bivector(_))
    }
    
    /// Check if this term is a trivector
    pub fn is_trivector(&self) -> bool {
        matches!(self, GATerm::Trivector(_))
    }
    
    /// Check if this term is a general multivector
    pub fn is_multivector(&self) -> bool {
        matches!(self, GATerm::Multivector(_))
    }
    
    /// Get the grade of this term
    pub fn grade(&self) -> Grade {
        match self {
            GATerm::Scalar(_) => 0,
            GATerm::Vector(_) => 1,
            GATerm::Bivector(_) => 2,
            GATerm::Trivector(_) => 3,
            GATerm::Multivector(blades) => {
                // For multivectors, return the maximum grade
                blades.iter().map(|blade| blade.grade()).max().unwrap_or(0)
            }
        }
    }
}

// ============================================================================
// Traits for Type Safety
// ============================================================================

/// Trait for arithmetic types
pub trait Arithmetic: Copy + PartialEq + PartialOrd + std::fmt::Debug {}

impl Arithmetic for f32 {}
impl Arithmetic for f64 {}
impl Arithmetic for i32 {}
impl Arithmetic for i64 {}
impl Arithmetic for u32 {}
impl Arithmetic for u64 {}

/// Trait for geometric algebra terms
pub trait GeometricAlgebraTerm {
    /// Get the grade of this term
    fn grade(&self) -> Grade;
    
    /// Check if this term is zero
    fn is_zero(&self) -> bool;
}

impl GeometricAlgebraTerm for GATerm {
    fn grade(&self) -> Grade {
        self.grade()
    }
    
    fn is_zero(&self) -> bool {
        match self {
            GATerm::Scalar(s) => *s == 0.0,
            GATerm::Vector(v) => v.is_empty(),
            GATerm::Bivector(b) => b.is_empty(),
            GATerm::Trivector(t) => t.is_empty(),
            GATerm::Multivector(m) => m.is_empty(),
        }
    }
}

impl GeometricAlgebraTerm for BladeTerm<Scalar> {
    fn grade(&self) -> Grade {
        self.grade()
    }
    
    fn is_zero(&self) -> bool {
        self.coeff == 0.0
    }
}

/// Trait for grade-indexed types
pub trait GradeIndexedType {
    /// Get the grade value at compile time
    fn grade() -> usize;
    
    /// Get the grade value at runtime
    fn runtime_grade(&self) -> Grade;
}

impl<T, const G: usize> GradeIndexedType for GradeIndexed<T, G> {
    fn grade() -> usize {
        G
    }
    
    fn runtime_grade(&self) -> Grade {
        G as Grade
    }
}

// ============================================================================
// Utility Functions
// ============================================================================

/// Create a scalar term
pub fn scalar(value: Scalar) -> GATerm {
    GATerm::Scalar(value)
}

/// Create a vector term
pub fn vector(components: Vec<(Index, Scalar)>) -> GATerm {
    GATerm::Vector(components)
}

/// Create a bivector term
pub fn bivector(components: Vec<(Index, Index, Scalar)>) -> GATerm {
    GATerm::Bivector(components)
}

/// Create a trivector term
pub fn trivector(components: Vec<(Index, Index, Index, Scalar)>) -> GATerm {
    GATerm::Trivector(components)
}

/// Create a general multivector term
pub fn multivector(components: Vec<BladeTerm<Scalar>>) -> GATerm {
    GATerm::Multivector(components)
}

// ============================================================================
// Pattern Matching Utilities
// ============================================================================

/// Visit a GATerm with a visitor function
/// Provides type-safe pattern matching
pub fn visit<F, R>(term: &GATerm, visitor: F) -> R
where
    F: FnOnce(&GATerm) -> R,
{
    visitor(term)
}

/// Extract scalar value if the term is a scalar
pub fn as_scalar(term: &GATerm) -> Option<Scalar> {
    match term {
        GATerm::Scalar(s) => Some(*s),
        _ => None,
    }
}

/// Extract vector components if the term is a vector
pub fn as_vector(term: &GATerm) -> Option<&Vec<(Index, Scalar)>> {
    match term {
        GATerm::Vector(v) => Some(v),
        _ => None,
    }
}

/// Extract bivector components if the term is a bivector
pub fn as_bivector(term: &GATerm) -> Option<&Vec<(Index, Index, Scalar)>> {
    match term {
        GATerm::Bivector(b) => Some(b),
        _ => None,
    }
}

/// Extract trivector components if the term is a trivector
pub fn as_trivector(term: &GATerm) -> Option<&Vec<(Index, Index, Index, Scalar)>> {
    match term {
        GATerm::Trivector(t) => Some(t),
        _ => None,
    }
}

/// Extract multivector components if the term is a multivector
pub fn as_multivector(term: &GATerm) -> Option<&Vec<BladeTerm<Scalar>>> {
    match term {
        GATerm::Multivector(m) => Some(m),
        _ => None,
    }
}

// ============================================================================
// Grade Safety Checks
// ============================================================================

/// Compile-time check that two types have the same grade
pub const fn grade_compatible<const G1: usize, const G2: usize>() -> bool {
    G1 == G2
}

/// Compile-time check that a type has a specific grade
pub const fn has_grade<const G: usize, const TARGET: usize>() -> bool {
    G == TARGET
}

// ============================================================================
// Tests
// ============================================================================

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_grade_indexed_types() {
        let scalar: GradeIndexed<f64, 0> = GradeIndexed::new(3.14);
        let vector: GradeIndexed<Vec<(Index, Scalar)>, 1> = GradeIndexed::new(vec![(1, 1.0)]);
        
        assert_eq!(GradeIndexed::<f64, 0>::grade(), 0);
        assert_eq!(GradeIndexed::<Vec<(Index, Scalar)>, 1>::grade(), 1);
        assert_eq!(scalar.runtime_grade(), 0);
        assert_eq!(vector.runtime_grade(), 1);
    }

    #[test]
    fn test_blade_term() {
        let blade = BladeTerm::new(vec![1, 2], 3.14);
        assert_eq!(blade.grade(), 2);
        assert!(blade.is_bivector());
        assert!(!blade.is_scalar());
        assert!(!blade.is_vector());
    }

    #[test]
    fn test_ga_term_creation() {
        let s = scalar(3.14);
        let v = vector(vec![(1, 1.0), (2, 2.0)]);
        let b = bivector(vec![(1, 2, 1.0)]);
        
        assert!(s.is_scalar());
        assert!(v.is_vector());
        assert!(b.is_bivector());
        
        assert_eq!(s.grade(), 0);
        assert_eq!(v.grade(), 1);
        assert_eq!(b.grade(), 2);
    }

    #[test]
    fn test_pattern_matching() {
        let term = vector(vec![(1, 1.0)]);
        
        assert_eq!(as_scalar(&term), None);
        assert_eq!(as_vector(&term), Some(&vec![(1, 1.0)]));
        assert_eq!(as_bivector(&term), None);
    }

    #[test]
    fn test_grade_safety() {
        assert!(grade_compatible::<1, 1>());
        assert!(!grade_compatible::<1, 2>());
        
        assert!(has_grade::<0, 0>());
        assert!(has_grade::<1, 1>());
        assert!(!has_grade::<1, 2>());
    }
} 