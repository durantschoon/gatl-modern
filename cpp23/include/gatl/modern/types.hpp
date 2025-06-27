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
 * Modern implementation using C++23 features:
 * - std::variant for sum types
 * - Concepts for type safety
 * - Template-based grade indexing
 * - Zero-cost abstractions
 */

#ifndef GATL_MODERN_TYPES_HPP
#define GATL_MODERN_TYPES_HPP

#include <variant>
#include <vector>
#include <array>
#include <tuple>
#include <concepts>
#include <cstdint>
#include <type_traits>

namespace gatl::modern {

// ============================================================================
// Type Aliases and Constants
// ============================================================================

using Scalar = double;
using Index = std::uint64_t;
using Grade = std::int64_t;

// Maximum basis vector index supported
constexpr Index MAX_BASIS_VECTOR_INDEX = 63;

// ============================================================================
// Grade-Indexed Types
// ============================================================================

/**
 * @brief Compile-time grade tag for type safety
 * @tparam G The grade value (0 = scalar, 1 = vector, 2 = bivector, etc.)
 */
template<Grade G>
struct GradeTag {
    static constexpr Grade value = G;
    using type = GradeTag<G>;
};

/**
 * @brief Grade-indexed type wrapper for compile-time grade checking
 * @tparam T The underlying type
 * @tparam G The grade value
 */
template<typename T, Grade G>
struct GradeIndexed {
    T value;
    using grade_type = GradeTag<G>;
    using value_type = T;
    
    static constexpr Grade grade = G;
    
    constexpr GradeIndexed() = default;
    constexpr GradeIndexed(const T& v) : value(v) {}
    constexpr GradeIndexed(T&& v) : value(std::move(v)) {}
    
    // Implicit conversion to underlying type
    constexpr operator T&() { return value; }
    constexpr operator const T&() const { return value; }
};

// ============================================================================
// Product Types for Blade-Coefficient Pairs
// ============================================================================

/**
 * @brief Represents a basis blade with coefficient
 * @tparam T The coefficient type
 */
template<typename T = Scalar>
struct BladeTerm {
    std::vector<Index> basis;  // e.g., [1, 2] = e1^e2
    T coeff;
    
    constexpr BladeTerm() = default;
    constexpr BladeTerm(const std::vector<Index>& b, const T& c) 
        : basis(b), coeff(c) {}
    constexpr BladeTerm(std::vector<Index>&& b, T&& c) 
        : basis(std::move(b)), coeff(std::move(c)) {}
    
    // Grade is the number of basis vectors
    constexpr Grade grade() const { return static_cast<Grade>(basis.size()); }
};

// ============================================================================
// Sum Types (Tagged Unions) for GA Terms
// ============================================================================

/**
 * @brief Sum type representing different geometric algebra terms
 * Uses std::variant for type-safe dispatch
 */
using GATerm = std::variant<
    Scalar,                                    // 0-vector (scalar)
    std::vector<std::pair<Index, Scalar>>,     // 1-vector
    std::vector<std::tuple<Index, Index, Scalar>>, // 2-vector (bivector)
    std::vector<std::tuple<Index, Index, Index, Scalar>>, // 3-vector (trivector)
    std::vector<BladeTerm<Scalar>>             // General multivector
>;

// ============================================================================
// Concepts for Type Safety
// ============================================================================

/**
 * @brief Concept for arithmetic types
 */
template<typename T>
concept Arithmetic = std::integral<T> || std::floating_point<T>;

/**
 * @brief Concept for geometric algebra terms
 */
template<typename T>
concept GeometricAlgebraTerm = std::same_as<T, GATerm> || 
                               std::same_as<T, Scalar> ||
                               std::same_as<T, BladeTerm<Scalar>>;

/**
 * @brief Concept for grade-indexed types
 */
template<typename T>
concept GradeIndexedType = requires(T t) {
    typename T::grade_type;
    { T::grade } -> std::convertible_to<Grade>;
};

// ============================================================================
// Type Traits
// ============================================================================

/**
 * @brief Get the grade of a type at compile time
 */
template<typename T>
struct grade_of;

template<Grade G>
struct grade_of<GradeTag<G>> : std::integral_constant<Grade, G> {};

template<typename T, Grade G>
struct grade_of<GradeIndexed<T, G>> : std::integral_constant<Grade, G> {};

template<typename T>
constexpr Grade grade_of_v = grade_of<T>::value;

/**
 * @brief Check if two types have the same grade
 */
template<typename T1, typename T2>
constexpr bool same_grade = (grade_of_v<T1> == grade_of_v<T2>);

// ============================================================================
// Utility Functions
// ============================================================================

/**
 * @brief Create a scalar term
 */
constexpr Scalar scalar(Scalar value) {
    return value;
}

/**
 * @brief Create a vector term
 */
constexpr std::vector<std::pair<Index, Scalar>> vector(
    std::vector<std::pair<Index, Scalar>> components) {
    return components;
}

/**
 * @brief Create a bivector term
 */
constexpr std::vector<std::tuple<Index, Index, Scalar>> bivector(
    std::vector<std::tuple<Index, Index, Scalar>> components) {
    return components;
}

/**
 * @brief Create a trivector term
 */
constexpr std::vector<std::tuple<Index, Index, Index, Scalar>> trivector(
    std::vector<std::tuple<Index, Index, Index, Scalar>> components) {
    return components;
}

/**
 * @brief Create a general multivector term
 */
constexpr std::vector<BladeTerm<Scalar>> multivector(
    std::vector<BladeTerm<Scalar>> components) {
    return components;
}

// ============================================================================
// Pattern Matching Utilities
// ============================================================================

/**
 * @brief Visit a GATerm with a visitor function
 * Provides type-safe pattern matching
 */
template<typename Visitor>
constexpr auto visit(const GATerm& term, Visitor&& visitor) {
    return std::visit(std::forward<Visitor>(visitor), term);
}

/**
 * @brief Check if a GATerm is a scalar
 */
constexpr bool is_scalar(const GATerm& term) {
    return std::holds_alternative<Scalar>(term);
}

/**
 * @brief Check if a GATerm is a vector
 */
constexpr bool is_vector(const GATerm& term) {
    return std::holds_alternative<std::vector<std::pair<Index, Scalar>>>(term);
}

/**
 * @brief Check if a GATerm is a bivector
 */
constexpr bool is_bivector(const GATerm& term) {
    return std::holds_alternative<std::vector<std::tuple<Index, Index, Scalar>>>(term);
}

/**
 * @brief Check if a GATerm is a trivector
 */
constexpr bool is_trivector(const GATerm& term) {
    return std::holds_alternative<std::vector<std::tuple<Index, Index, Index, Scalar>>>(term);
}

/**
 * @brief Check if a GATerm is a general multivector
 */
constexpr bool is_multivector(const GATerm& term) {
    return std::holds_alternative<std::vector<BladeTerm<Scalar>>>(term);
}

// ============================================================================
// Grade Safety Checks
// ============================================================================

/**
 * @brief Compile-time check that two types have the same grade
 */
template<typename T1, typename T2>
constexpr bool grade_compatible = same_grade<T1, T2>;

/**
 * @brief Compile-time check that a type has a specific grade
 */
template<typename T, Grade G>
constexpr bool has_grade = (grade_of_v<T> == G);

// ============================================================================
// Static Assertions for Type Safety
// ============================================================================

// Ensure grade-indexed types work correctly
static_assert(grade_of_v<GradeTag<0>> == 0);
static_assert(grade_of_v<GradeTag<1>> == 1);
static_assert(grade_of_v<GradeTag<2>> == 2);

// Ensure grade compatibility works
static_assert(grade_compatible<GradeTag<1>, GradeTag<1>>);
static_assert(!grade_compatible<GradeTag<1>, GradeTag<2>>);

// Ensure grade checking works
static_assert(has_grade<GradeTag<0>, 0>);
static_assert(has_grade<GradeTag<1>, 1>);
static_assert(!has_grade<GradeTag<1>, 2>);

} // namespace gatl::modern

#endif // GATL_MODERN_TYPES_HPP 