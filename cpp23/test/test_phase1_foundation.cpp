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

#include <iostream>
#include <cassert>
#include <cmath>
#include <bit>
#include <concepts>

// Include our Phase 1 foundation
#include "../include/gatl/ga/core.hpp"

// Test framework (simple)
#define TEST_ASSERT(condition) \
    do { \
        if (!(condition)) { \
            std::cerr << "FAILED: " << #condition << " at line " << __LINE__ << std::endl; \
            return false; \
        } \
    } while(0)

#define TEST_PASS(name) \
    std::cout << "PASSED: " << name << std::endl

bool test_core_types() {
    // Test type aliases
    static_assert(std::is_same_v<ga::default_floating_point_t, std::double_t>);
    static_assert(std::is_same_v<ga::default_integral_t, std::int64_t>);
    static_assert(std::is_same_v<ga::grade_t, std::int64_t>);
    static_assert(std::is_same_v<ga::index_t, std::uint64_t>);
    static_assert(std::is_same_v<ga::ndims_t, std::uint64_t>);
    
    // Test bitset_t selection
    static_assert(sizeof(ga::bitset_t) >= 1);
    static_assert(sizeof(ga::bitset_t) <= 8);
    
    TEST_PASS("Core types");
    return true;
}

bool test_concepts() {
    // Test Arithmetic concept
    static_assert(ga::Arithmetic<int>);
    static_assert(ga::Arithmetic<double>);
    static_assert(ga::Arithmetic<float>);
    static_assert(!ga::Arithmetic<std::string>);
    
    // Test Integral concept
    static_assert(ga::Integral<int>);
    static_assert(ga::Integral<std::int64_t>);
    static_assert(!ga::Integral<double>);
    
    // Test FloatingPoint concept
    static_assert(ga::FloatingPoint<double>);
    static_assert(ga::FloatingPoint<float>);
    static_assert(!ga::FloatingPoint<int>);
    
    TEST_PASS("Concepts");
    return true;
}

bool test_tau_constants() {
    // Test tau constants
    constexpr double tau = ga::constants::tau<double>;
    constexpr double pi = ga::constants::pi<double>;
    constexpr double quarter = ga::constants::quarter_rotation<double>;
    
    // Verify mathematical relationships
    TEST_ASSERT(std::abs(tau - 2.0 * pi) < 1e-15);
    TEST_ASSERT(std::abs(quarter - pi/2.0) < 1e-15);
    TEST_ASSERT(std::abs(quarter - tau/4.0) < 1e-15);
    
    // Test angle conversions
    constexpr double degrees_90 = 90.0;
    constexpr double radians_90 = ga::angles::degrees_to_radians(degrees_90);
    constexpr double back_to_degrees = ga::angles::radians_to_degrees(radians_90);
    
    TEST_ASSERT(std::abs(radians_90 - quarter) < 1e-15);
    TEST_ASSERT(std::abs(back_to_degrees - degrees_90) < 1e-15);
    
    TEST_PASS("Tau constants and angle conversions");
    return true;
}

bool test_constexpr_functions() {
    // Test basic constexpr functions
    constexpr int abs_result = ga::detail::iabs(-42);
    TEST_ASSERT(abs_result == 42);
    
    constexpr int gcd_result = ga::detail::gcd(48, 18);
    TEST_ASSERT(gcd_result == 6);
    
    constexpr int sign_pos = ga::detail::sign(5);
    constexpr int sign_neg = ga::detail::sign(-5);
    constexpr int sign_zero = ga::detail::sign(0);
    TEST_ASSERT(sign_pos == 1);
    TEST_ASSERT(sign_neg == -1);
    TEST_ASSERT(sign_zero == 0);
    
    // Test bit operations
    constexpr std::uint64_t ones_result = ga::detail::ones(std::uint64_t(0b1011));
    TEST_ASSERT(ones_result == 3);
    
    constexpr bool is_power_2 = ga::detail::is_power_of_2(8);
    constexpr bool is_not_power_2 = ga::detail::is_power_of_2(7);
    TEST_ASSERT(is_power_2);
    TEST_ASSERT(!is_not_power_2);
    
    TEST_PASS("Constexpr functions");
    return true;
}

bool test_type_traits() {
    // Test type traits
    static_assert(ga::detail::is_any_v<int, int, double>);
    static_assert(ga::detail::is_any_v<int, double, int>);
    static_assert(!ga::detail::is_any_v<int, double, float>);
    
    // Test container concepts
    static_assert(ga::detail::Container<std::vector<int>>);
    static_assert(ga::detail::SequenceContainer<std::vector<int>>);
    static_assert(ga::detail::AssociativeContainer<std::map<int, int>>);
    static_assert(!ga::detail::Container<int>);
    
    // Test template specialization detection
    static_assert(ga::detail::is_tuple_v<std::tuple<int, double>>);
    static_assert(ga::detail::is_pair_v<std::pair<int, double>>);
    static_assert(ga::detail::is_array_v<std::array<int, 5>>);
    static_assert(ga::detail::is_map_v<std::map<int, double>>);
    static_assert(ga::detail::is_vector_v<std::vector<int>>);
    
    TEST_PASS("Type traits");
    return true;
}

bool test_tolerance() {
    // Test tolerance functions
    constexpr double tol = ga::tolerance::get_default_tolerance<double>();
    TEST_ASSERT(tol > 0.0);
    TEST_ASSERT(tol < 1.0);
    
    // Test approximate equality
    constexpr bool approx_equal = ga::tolerance::approximately_equal(1.0, 1.0 + 1e-13);
    constexpr bool not_equal = ga::tolerance::approximately_equal(1.0, 2.0);
    TEST_ASSERT(approx_equal);
    TEST_ASSERT(!not_equal);
    
    // Test approximately zero
    constexpr bool approx_zero = ga::tolerance::approximately_zero(1e-13);
    constexpr bool not_zero = ga::tolerance::approximately_zero(0.1);
    TEST_ASSERT(approx_zero);
    TEST_ASSERT(!not_zero);
    
    TEST_PASS("Tolerance functions");
    return true;
}

bool test_exceptions() {
    try {
        // Test exception construction
        ga::not_implemented_error error1("Test error");
        ga::not_implemented_error error2(std::string("Test error"));
        ga::not_implemented_error error3(std::string_view("Test error"));
        
        // Test that we can catch it
        throw ga::not_implemented_error("Test exception");
    } catch (const ga::not_implemented_error& e) {
        std::string what = e.what();
        TEST_ASSERT(what.find("Test exception") != std::string::npos);
    } catch (...) {
        TEST_ASSERT(false); // Should not reach here
    }
    
    TEST_PASS("Exceptions");
    return true;
}

bool test_tag_types() {
    // Test that tag types are empty and have zero size
    static_assert(std::is_empty_v<ga::tags::euclidean>);
    static_assert(std::is_empty_v<ga::tags::conformal>);
    static_assert(std::is_empty_v<ga::tags::geometric_product>);
    static_assert(std::is_empty_v<ga::tags::compile_time>);
    
    // Test that tag types are classes
    static_assert(std::is_class_v<ga::tags::euclidean>);
    static_assert(std::is_class_v<ga::tags::conformal>);
    static_assert(std::is_class_v<ga::tags::geometric_product>);
    
    // Test tag type concepts
    static_assert(ga::tag_traits::TagType<ga::tags::euclidean>);
    static_assert(ga::tag_traits::MetricSpaceTag<ga::tags::euclidean>);
    static_assert(ga::tag_traits::MetricSpaceTag<ga::tags::conformal>);
    static_assert(ga::tag_traits::ProductOperationTag<ga::tags::geometric_product>);
    static_assert(ga::tag_traits::ProductOperationTag<ga::tags::outer_product>);
    static_assert(ga::tag_traits::EvaluationStrategyTag<ga::tags::compile_time>);
    static_assert(ga::tag_traits::EvaluationStrategyTag<ga::tags::runtime>);
    
    // Test tag aliases
    static_assert(std::is_same_v<ga::tag_aliases::euclidean_2d, ga::tags::euclidean>);
    static_assert(std::is_same_v<ga::tag_aliases::gp, ga::tags::geometric_product>);
    static_assert(std::is_same_v<ga::tag_aliases::op, ga::tags::outer_product>);
    static_assert(std::is_same_v<ga::tag_aliases::compile_time_eval, ga::tags::compile_time>);
    
    // Test tag utilities
    constexpr auto euclidean_name = ga::tag_utils::tag_name<ga::tags::euclidean>();
    constexpr auto conformal_name = ga::tag_utils::tag_name<ga::tags::conformal>();
    constexpr auto gp_name = ga::tag_utils::tag_name<ga::tags::geometric_product>();
    
    TEST_ASSERT(euclidean_name == "euclidean");
    TEST_ASSERT(conformal_name == "conformal");
    TEST_ASSERT(gp_name == "geometric_product");
    
    // Test tag compatibility
    static_assert(ga::tag_utils::are_compatible<ga::tags::euclidean, ga::tags::conformal>());
    static_assert(ga::tag_utils::are_compatible<ga::tags::geometric_product, ga::tags::outer_product>());
    
    // Test combined tags
    static_assert(std::is_same_v<
        ga::tag_utils::combined_tag_t<ga::tags::compile_time, ga::tags::runtime>,
        ga::tags::runtime
    >);
    static_assert(std::is_same_v<
        ga::tag_utils::combined_tag_t<ga::tags::optimized, ga::tags::unoptimized>,
        ga::tags::unoptimized
    >);
    
    // Test that tags can be used in template parameters
    struct test_struct {
        [[no_unique_address]] ga::tags::euclidean metric_space;
        [[no_unique_address]] ga::tags::geometric_product product_op;
        [[no_unique_address]] ga::tags::compile_time eval_strategy;
    };
    
    // Verify the struct has minimal size (empty base optimization)
    // Note: Even with [[no_unique_address]], the struct needs at least 1 byte
    static_assert(sizeof(test_struct) >= 1);
    static_assert(sizeof(test_struct) <= 3); // Should be optimized to minimal size
    
    TEST_PASS("Tag types");
    return true;
}

bool test_geometric_algebra_basics() {
    // Test that our foundation supports basic GA concepts
    
    // Test bitset operations for basis vectors
    constexpr ga::bitset_t e1 = 0b001;  // First basis vector
    constexpr ga::bitset_t e2 = 0b010;  // Second basis vector
    constexpr ga::bitset_t e3 = 0b100;  // Third basis vector
    
    // Test bivector (e1 ∧ e2)
    constexpr ga::bitset_t e1e2 = e1 | e2;  // 0b011
    
    // Test trivector (e1 ∧ e2 ∧ e3)
    constexpr ga::bitset_t e1e2e3 = e1 | e2 | e3;  // 0b111
    
    TEST_ASSERT(e1 == 1);
    TEST_ASSERT(e2 == 2);
    TEST_ASSERT(e3 == 4);
    TEST_ASSERT(e1e2 == 3);
    TEST_ASSERT(e1e2e3 == 7);
    
    // Test bit counting
    constexpr auto ones_e1 = ga::detail::ones(e1);
    constexpr auto ones_e1e2 = ga::detail::ones(e1e2);
    constexpr auto ones_e1e2e3 = ga::detail::ones(e1e2e3);
    
    TEST_ASSERT(ones_e1 == 1);      // Grade 1
    TEST_ASSERT(ones_e1e2 == 2);    // Grade 2 (bivector)
    TEST_ASSERT(ones_e1e2e3 == 3);  // Grade 3 (trivector)
    
    // Test rotation angle (90 degrees = τ/4)
    constexpr double angle_90 = ga::constants::quarter_rotation<double>;
    constexpr double angle_180 = ga::constants::half_rotation<double>;
    constexpr double angle_360 = ga::constants::full_rotation<double>;
    
    TEST_ASSERT(std::abs(angle_90 - ga::constants::tau<double>/4.0) < 1e-15);
    TEST_ASSERT(std::abs(angle_180 - ga::constants::tau<double>/2.0) < 1e-15);
    TEST_ASSERT(std::abs(angle_360 - ga::constants::tau<double>) < 1e-15);
    
    TEST_PASS("Geometric Algebra basics");
    return true;
}

bool test_operator_symbols() {
    // Test operator symbol constants
    static_assert(ga::operators::symbols::geometric_product == '*');
    static_assert(ga::operators::symbols::outer_product == '^');
    static_assert(ga::operators::symbols::inner_product == '|');
    static_assert(ga::operators::symbols::left_contraction == '<');
    static_assert(ga::operators::symbols::right_contraction == '>');
    static_assert(ga::operators::symbols::reversion == '~');
    
    // Test operator precedence
    static_assert(ga::operators::precedence::reversion == 15);
    static_assert(ga::operators::precedence::geometric_product == 13);
    static_assert(ga::operators::precedence::outer_product == 13);
    static_assert(ga::operators::precedence::inner_product == 13);
    static_assert(ga::operators::precedence::addition == 12);
    
    // Test operator properties
    static_assert(!ga::operators::properties::commutative_geometric_product);
    static_assert(!ga::operators::properties::commutative_outer_product);
    static_assert(!ga::operators::properties::commutative_inner_product);
    static_assert(ga::operators::properties::commutative_addition);
    static_assert(ga::operators::properties::associative_geometric_product);
    static_assert(ga::operators::properties::associative_outer_product);
    static_assert(ga::operators::properties::associative_addition);
    
    // Test operator names
    static_assert(ga::operators::names::geometric_product == "geometric product");
    static_assert(ga::operators::names::outer_product == "outer product");
    static_assert(ga::operators::names::inner_product == "inner product");
    static_assert(ga::operators::names::reversion == "reversion");
    
    // Test library conventions
    static_assert(ga::operators::library_conventions::gatl::geometric_product == '*');
    static_assert(ga::operators::library_conventions::gatl::outer_product == '^');
    static_assert(ga::operators::library_conventions::python_clifford::geometric_product == '*');
    static_assert(ga::operators::library_conventions::python_clifford::outer_product == '^');
    
    // Test operator utility functions
    static_assert(ga::operator_utils::get_operator_name<'*'>() == "geometric product");
    static_assert(ga::operator_utils::get_operator_name<'^'>() == "outer product");
    static_assert(ga::operator_utils::get_operator_name<'|'>() == "inner product");
    static_assert(ga::operator_utils::get_operator_name<'~'>() == "reversion");
    
    static_assert(!ga::operator_utils::is_commutative<'*'>());
    static_assert(!ga::operator_utils::is_commutative<'^'>());
    static_assert(!ga::operator_utils::is_commutative<'|'>());
    static_assert(ga::operator_utils::is_commutative<'+'>());
    
    static_assert(ga::operator_utils::is_associative<'*'>());
    static_assert(ga::operator_utils::is_associative<'^'>());
    static_assert(!ga::operator_utils::is_associative<'|'>());
    static_assert(ga::operator_utils::is_associative<'+'>());
    
    static_assert(ga::operator_utils::get_precedence<'~'>() == 15);
    static_assert(ga::operator_utils::get_precedence<'*'>() == 13);
    static_assert(ga::operator_utils::get_precedence<'^'>() == 13);
    static_assert(ga::operator_utils::get_precedence<'|'>() == 13);
    static_assert(ga::operator_utils::get_precedence<'+'>() == 12);
    
    static_assert(ga::operator_utils::get_associativity<'*'>() == ga::operators::associativity::left);
    static_assert(ga::operator_utils::get_associativity<'^'>() == ga::operators::associativity::left);
    static_assert(ga::operator_utils::get_associativity<'|'>() == ga::operators::associativity::left);
    static_assert(ga::operator_utils::get_associativity<'+'>() == ga::operators::associativity::left);
    
    // Test operator overload templates
    using gatl_symbols = ga::operator_overloads::gatl_symbols;
    using python_symbols = ga::operator_overloads::python_symbols;
    
    static_assert(gatl_symbols::geometric_product == '*');
    static_assert(gatl_symbols::outer_product == '^');
    static_assert(python_symbols::geometric_product == '*');
    static_assert(python_symbols::outer_product == '^');
    
    // Test default convention
    using default_symbols = ga::operator_overloads::operator_symbols<>;
    static_assert(default_symbols::geometric_product == '*');
    static_assert(default_symbols::outer_product == '^');
    
    return true;
}

int main() {
    std::cout << "Testing GATL C++23 Phase 1 Foundation\n";
    std::cout << "=====================================\n\n";
    
    bool all_passed = true;
    
    all_passed &= test_core_types();
    all_passed &= test_concepts();
    all_passed &= test_tau_constants();
    all_passed &= test_constexpr_functions();
    all_passed &= test_type_traits();
    all_passed &= test_tolerance();
    all_passed &= test_exceptions();
    all_passed &= test_tag_types();
    all_passed &= test_geometric_algebra_basics();
    all_passed &= test_operator_symbols();
    
    std::cout << "\n=====================================\n";
    if (all_passed) {
        std::cout << "ALL TESTS PASSED! ✓\n";
        std::cout << "Phase 1 foundation is working correctly.\n";
        return 0;
    } else {
        std::cout << "SOME TESTS FAILED! ✗\n";
        return 1;
    }
} 