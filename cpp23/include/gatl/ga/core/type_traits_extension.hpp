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

#ifndef __GA_CORE_TYPE_TRAITS_EXTENSION_HPP__
#define __GA_CORE_TYPE_TRAITS_EXTENSION_HPP__

#include <iterator>
#include <tuple>
#include <type_traits>
#include <utility>

namespace ga {

    namespace detail {

        // C++23: Returns true if T and any element in Rest has the same type with the same const-volatile qualifications
        template<typename T, typename... Rest>
        constexpr bool is_any_v = std::disjunction_v<std::bool_constant<std::is_same_v<T, Rest>>...>;

        // C++23: Modern iterator concept check using concepts
        template<typename T>
        concept Iterator = requires(T t) {
            typename std::iterator_traits<T>::iterator_category;
            typename std::iterator_traits<T>::value_type;
            typename std::iterator_traits<T>::difference_type;
            typename std::iterator_traits<T>::pointer;
            typename std::iterator_traits<T>::reference;
            { ++t } -> std::same_as<T&>;
            { *t } -> std::convertible_to<typename std::iterator_traits<T>::reference>;
        };

        // Legacy iterator trait for backward compatibility
        template<typename T, typename = void>
        struct is_iterator : std::false_type {
        };

        template<typename T>
        struct is_iterator<T, std::void_t<typename std::iterator_traits<T>::iterator_category>> : std::true_type {
        };

        template<typename T>
        constexpr bool is_iterator_v = is_iterator<T>::value;

        // C++23: Modern tuple to initializer_list conversion
        template<typename Tuple, std::size_t... Indices>
        GA_ALWAYS_INLINE constexpr auto 
        _to_list_initialization(Tuple&& tuple, std::index_sequence<Indices...>) GA_NOEXCEPT {
            using value_type = typename std::tuple_element<0, std::remove_reference_t<Tuple>>::type;
            return std::initializer_list<value_type>{ std::get<Indices>(std::forward<Tuple>(tuple))... };
        }

        template<typename Tuple>
        GA_ALWAYS_INLINE constexpr decltype(auto) to_list_initialization(Tuple&& tuple) GA_NOEXCEPT {
            return _to_list_initialization(std::forward<Tuple>(tuple), 
                std::make_index_sequence<std::tuple_size_v<std::remove_cv_t<std::remove_reference_t<Tuple>>>>{});
        }

        // C++23: Additional type traits for Geometric Algebra

        // Check if type is a tuple-like type
        template<typename T>
        concept TupleLike = requires(T t) {
            std::tuple_size<T>::value;
            std::get<0>(t);
        };

        // Check if type is a container
        template<typename T>
        concept Container = requires(T t) {
            typename T::value_type;
            typename T::size_type;
            typename T::iterator;
            typename T::const_iterator;
            { t.begin() } -> std::same_as<typename T::iterator>;
            { t.end() } -> std::same_as<typename T::iterator>;
            { t.size() } -> std::convertible_to<typename T::size_type>;
        };

        // Check if type is a sequence container
        template<typename T>
        concept SequenceContainer = Container<T> && requires(T t, typename T::size_type n) {
            { t[n] } -> std::convertible_to<typename T::reference>;
        };

        // Check if type is an associative container
        template<typename T>
        concept AssociativeContainer = Container<T> && requires(T t, typename T::key_type k) {
            { t[k] } -> std::convertible_to<typename T::mapped_type>;
        };

        // C++23: Type identity for perfect forwarding
        template<typename T>
        using type_identity_t = typename std::type_identity<T>::type;

        // C++23: Remove cvref (remove const, volatile, and reference)
        template<typename T>
        using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

        // C++23: Check if type is a specialization of a template
        template<template<typename...> typename Template, typename T>
        struct is_specialization_of : std::false_type {};

        template<template<typename...> typename Template, typename... Args>
        struct is_specialization_of<Template, Template<Args...>> : std::true_type {};

        template<template<typename...> typename Template, typename T>
        constexpr bool is_specialization_of_v = is_specialization_of<Template, T>::value;

        // C++23: Check if type is a specialization of std::tuple
        template<typename T>
        constexpr bool is_tuple_v = false;

        template<typename... Args>
        constexpr bool is_tuple_v<std::tuple<Args...>> = true;

        // C++23: Check if type is a specialization of std::pair
        template<typename T>
        constexpr bool is_pair_v = false;

        template<typename T1, typename T2>
        constexpr bool is_pair_v<std::pair<T1, T2>> = true;

        // C++23: Check if type is a specialization of std::array
        template<typename T>
        constexpr bool is_array_v = false;

        template<typename T, std::size_t N>
        constexpr bool is_array_v<std::array<T, N>> = true;

        // C++23: Check if type is a specialization of std::map
        template<typename T>
        constexpr bool is_map_v = false;

        template<typename K, typename V, typename C, typename A>
        constexpr bool is_map_v<std::map<K, V, C, A>> = true;

        // C++23: Check if type is a specialization of std::vector
        template<typename T>
        constexpr bool is_vector_v = false;

        template<typename T, typename A>
        constexpr bool is_vector_v<std::vector<T, A>> = true;

        // C++23: Type list utilities
        template<typename... Types>
        struct type_list {
            static constexpr std::size_t size = sizeof...(Types);
        };

        // C++23: Check if all types in a pack satisfy a condition
        template<template<typename> typename Predicate, typename... Types>
        constexpr bool all_satisfy_v = (Predicate<Types>::value && ...);

        // C++23: Check if any type in a pack satisfies a condition
        template<template<typename> typename Predicate, typename... Types>
        constexpr bool any_satisfy_v = (Predicate<Types>::value || ...);

        // C++23: Check if no type in a pack satisfies a condition
        template<template<typename> typename Predicate, typename... Types>
        constexpr bool none_satisfy_v = !any_satisfy_v<Predicate, Types...>;

        // C++23: Find first type in a pack that satisfies a condition
        template<template<typename> typename Predicate, typename... Types>
        struct find_first;

        template<template<typename> typename Predicate, typename First, typename... Rest>
        struct find_first<Predicate, First, Rest...> {
            using type = std::conditional_t<Predicate<First>::value, First, typename find_first<Predicate, Rest...>::type>;
        };

        template<template<typename> typename Predicate>
        struct find_first<Predicate> {
            using type = void;
        };

        template<template<typename> typename Predicate, typename... Types>
        using find_first_t = typename find_first<Predicate, Types...>::type;

        // C++23: Check if a type is in a type list
        template<typename T, typename... Types>
        constexpr bool is_in_pack_v = (std::is_same_v<T, Types> || ...);

        // C++23: Count types in a pack that satisfy a condition
        template<template<typename> typename Predicate, typename... Types>
        constexpr std::size_t count_satisfying_v = (std::size_t(0) + ... + std::size_t(Predicate<Types>::value));

        // C++23: Index of a type in a pack
        template<typename T, typename... Types>
        struct index_in_pack;

        template<typename T, typename First, typename... Rest>
        struct index_in_pack<T, First, Rest...> {
            static constexpr std::size_t value = std::is_same_v<T, First> ? 0 : 1 + index_in_pack<T, Rest...>::value;
        };

        template<typename T>
        struct index_in_pack<T> {
            static constexpr std::size_t value = std::size_t(-1); // Not found
        };

        template<typename T, typename... Types>
        constexpr std::size_t index_in_pack_v = index_in_pack<T, Types...>::value;

        // C++23: Check if index is valid for a pack
        template<std::size_t Index, typename... Types>
        constexpr bool is_valid_index_v = Index < sizeof...(Types);

        // C++23: Get type at index in a pack
        template<std::size_t Index, typename... Types>
        struct type_at_index;

        template<std::size_t Index, typename First, typename... Rest>
        struct type_at_index<Index, First, Rest...> {
            using type = std::conditional_t<Index == 0, First, typename type_at_index<Index - 1, Rest...>::type>;
        };

        template<typename First>
        struct type_at_index<0, First> {
            using type = First;
        };

        template<std::size_t Index, typename... Types>
        using type_at_index_t = typename type_at_index<Index, Types...>::type;

    }

}

#endif // __GA_CORE_TYPE_TRAITS_EXTENSION_HPP__ 