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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GATL. If not, see <https://www.gnu.org/licenses/>.
 * 
 * C++23 modernization by: durantschoon
 * Date: 2024-06-24
 */

#ifndef __GA_CORE_TAG_TYPES_HPP__
#define __GA_CORE_TAG_TYPES_HPP__

namespace ga {

    // C++23: Type-safe tag types using [[no_unique_address]] for zero-overhead type safety
    // 
    // Usage example:
    // struct my_ga_operation {
    //     [[no_unique_address]] ga::tags::euclidean metric_space;
    //     [[no_unique_address]] ga::tags::geometric_product product_op;
    //     [[no_unique_address]] ga::tags::compile_time eval_strategy;
    //     // ... other members
    // };
    // 
    // The [[no_unique_address]] attribute should be applied to member variables,
    // not to the struct declarations themselves.
    
    namespace tags {

        // Metric space types
        struct euclidean {};
        struct conformal {};
        struct minkowski {};
        struct homogeneous {};
        struct plane_based {};
        struct general_metric {};

        // Evaluation strategies
        struct compile_time {};
        struct runtime {};
        struct lazy_evaluation {};

        // Grade types for basis blades
        struct scalar_grade {};
        struct vector_grade {};
        struct bivector_grade {};
        struct trivector_grade {};
        struct quadvector_grade {};
        struct pseudoscalar_grade {};

        // Product operation types
        struct geometric_product {};
        struct outer_product {};
        struct inner_product {};
        struct left_contraction {};
        struct right_contraction {};
        struct hestenes_inner_product {};
        struct regressive_product {};
        struct scalar_product {};

        // Sign operations
        struct reversion {};
        struct conjugation {};
        struct involution {};
        struct grade_involution {};

        // Special operations
        struct dualization {};
        struct meet_operation {};
        struct join_operation {};
        struct plunge_operation {};

        // Expression types
        struct constant_expression {};
        struct dynamic_expression {};
        struct lazy_expression {};
        struct stored_expression {};

        // Storage types
        struct sequential_storage {};
        struct associative_storage {};
        struct sparse_storage {};
        struct dense_storage {};

        // Optimization tags
        struct optimized {};
        struct unoptimized {};
        struct debug_mode {};
        struct release_mode {};

        // Mathematical constants
        struct tau_constant {};
        struct pi_constant {};
        struct e_constant {};
        struct i_constant {};

        // Tolerance types
        struct absolute_tolerance {};
        struct relative_tolerance {};
        struct machine_epsilon_tolerance {};

        // Bit manipulation tags
        struct bit_counting {};
        struct bit_rotation {};
        struct bit_reversal {};
        struct bit_combination {};

        // Template metaprogramming tags
        struct type_list {};
        struct value_list {};
        struct index_sequence {};

        // Error handling tags
        struct noexcept_operation {};
        struct throwing_operation {};
        struct error_handling {};

        // Memory management tags
        struct stack_allocated {};
        struct heap_allocated {};
        struct custom_allocator {};

        // Threading tags
        struct single_threaded {};
        struct multi_threaded {};
        struct thread_safe {};

        // SIMD optimization tags
        struct scalar_operation {};
        struct vectorized_operation {};
        struct simd_optimized {};

        // Precision tags
        struct single_precision {};
        struct double_precision {};
        struct extended_precision {};

        // Validation tags
        struct validated {};
        struct unvalidated {};
        struct debug_validated {};

    } // namespace tags

    // C++23: Type aliases for common tag combinations
    namespace tag_aliases {

        // Common metric space combinations
        using euclidean_2d = tags::euclidean;
        using euclidean_3d = tags::euclidean;
        using conformal_2d = tags::conformal;
        using conformal_3d = tags::conformal;
        using minkowski_4d = tags::minkowski;

        // Common evaluation strategies
        using compile_time_eval = tags::compile_time;
        using runtime_eval = tags::runtime;
        using lazy_eval = tags::lazy_evaluation;

        // Common product operations
        using gp = tags::geometric_product;
        using op = tags::outer_product;
        using ip = tags::inner_product;
        using lc = tags::left_contraction;
        using rc = tags::right_contraction;
        using hip = tags::hestenes_inner_product;

        // Common sign operations
        using rev = tags::reversion;
        using conj = tags::conjugation;
        using inv = tags::involution;

        // Common storage strategies
        using seq_storage = tags::sequential_storage;
        using assoc_storage = tags::associative_storage;
        using sparse_storage = tags::sparse_storage;
        using dense_storage = tags::dense_storage;

    } // namespace tag_aliases

    // C++23: Type traits for tag types
    namespace tag_traits {

        // Check if a type is a tag type
        template<typename T>
        concept TagType = std::is_empty_v<T> && std::is_class_v<T>;

        // Check if a type is a metric space tag
        template<typename T>
        concept MetricSpaceTag = TagType<T> && (
            std::is_same_v<T, tags::euclidean> ||
            std::is_same_v<T, tags::conformal> ||
            std::is_same_v<T, tags::minkowski> ||
            std::is_same_v<T, tags::homogeneous> ||
            std::is_same_v<T, tags::plane_based> ||
            std::is_same_v<T, tags::general_metric>
        );

        // Check if a type is a product operation tag
        template<typename T>
        concept ProductOperationTag = TagType<T> && (
            std::is_same_v<T, tags::geometric_product> ||
            std::is_same_v<T, tags::outer_product> ||
            std::is_same_v<T, tags::inner_product> ||
            std::is_same_v<T, tags::left_contraction> ||
            std::is_same_v<T, tags::right_contraction> ||
            std::is_same_v<T, tags::hestenes_inner_product> ||
            std::is_same_v<T, tags::regressive_product> ||
            std::is_same_v<T, tags::scalar_product>
        );

        // Check if a type is an evaluation strategy tag
        template<typename T>
        concept EvaluationStrategyTag = TagType<T> && (
            std::is_same_v<T, tags::compile_time> ||
            std::is_same_v<T, tags::runtime> ||
            std::is_same_v<T, tags::lazy_evaluation>
        );

        // Check if a type is a grade tag
        template<typename T>
        concept GradeTag = TagType<T> && (
            std::is_same_v<T, tags::scalar_grade> ||
            std::is_same_v<T, tags::vector_grade> ||
            std::is_same_v<T, tags::bivector_grade> ||
            std::is_same_v<T, tags::trivector_grade> ||
            std::is_same_v<T, tags::quadvector_grade> ||
            std::is_same_v<T, tags::pseudoscalar_grade>
        );

        // Check if a type is a storage tag
        template<typename T>
        concept StorageTag = TagType<T> && (
            std::is_same_v<T, tags::sequential_storage> ||
            std::is_same_v<T, tags::associative_storage> ||
            std::is_same_v<T, tags::sparse_storage> ||
            std::is_same_v<T, tags::dense_storage>
        );

        // Check if a type is a precision tag
        template<typename T>
        concept PrecisionTag = TagType<T> && (
            std::is_same_v<T, tags::single_precision> ||
            std::is_same_v<T, tags::double_precision> ||
            std::is_same_v<T, tags::extended_precision>
        );

        // Check if a type is an optimization tag
        template<typename T>
        concept OptimizationTag = TagType<T> && (
            std::is_same_v<T, tags::optimized> ||
            std::is_same_v<T, tags::unoptimized> ||
            std::is_same_v<T, tags::debug_mode> ||
            std::is_same_v<T, tags::release_mode>
        );

        // Check if a type is a threading tag
        template<typename T>
        concept ThreadingTag = TagType<T> && (
            std::is_same_v<T, tags::single_threaded> ||
            std::is_same_v<T, tags::multi_threaded> ||
            std::is_same_v<T, tags::thread_safe>
        );

        // Check if a type is a SIMD tag
        template<typename T>
        concept SimdTag = TagType<T> && (
            std::is_same_v<T, tags::scalar_operation> ||
            std::is_same_v<T, tags::vectorized_operation> ||
            std::is_same_v<T, tags::simd_optimized>
        );

    } // namespace tag_traits

    // C++23: Utility functions for tag types
    namespace tag_utils {

        // Get the name of a tag type as a string (for debugging)
        template<typename Tag>
        requires tag_traits::TagType<Tag>
        constexpr std::string_view tag_name() {
            if constexpr (std::is_same_v<Tag, tags::euclidean>) return "euclidean";
            else if constexpr (std::is_same_v<Tag, tags::conformal>) return "conformal";
            else if constexpr (std::is_same_v<Tag, tags::minkowski>) return "minkowski";
            else if constexpr (std::is_same_v<Tag, tags::geometric_product>) return "geometric_product";
            else if constexpr (std::is_same_v<Tag, tags::outer_product>) return "outer_product";
            else if constexpr (std::is_same_v<Tag, tags::compile_time>) return "compile_time";
            else if constexpr (std::is_same_v<Tag, tags::runtime>) return "runtime";
            else return "unknown_tag";
        }

        // Check if two tags are compatible
        template<typename Tag1, typename Tag2>
        requires tag_traits::TagType<Tag1> && tag_traits::TagType<Tag2>
        constexpr bool are_compatible() {
            // Define compatibility rules here
            return true; // Default: all tags are compatible
        }

        // Get the combined tag type
        template<typename Tag1, typename Tag2>
        requires tag_traits::TagType<Tag1> && tag_traits::TagType<Tag2>
        struct combined_tag {
            using type = Tag1; // Default: use first tag
        };

        // Specializations for specific combinations
        template<>
        struct combined_tag<tags::compile_time, tags::runtime> {
            using type = tags::runtime; // Runtime takes precedence
        };

        template<>
        struct combined_tag<tags::optimized, tags::unoptimized> {
            using type = tags::unoptimized; // Unoptimized takes precedence
        };

        template<typename Tag1, typename Tag2>
        using combined_tag_t = typename combined_tag<Tag1, Tag2>::type;

    } // namespace tag_utils

} // namespace ga

#endif // __GA_CORE_TAG_TYPES_HPP__ 