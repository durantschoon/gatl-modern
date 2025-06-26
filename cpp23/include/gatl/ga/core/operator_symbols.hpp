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

#ifndef __GA_CORE_OPERATOR_SYMBOLS_HPP__
#define __GA_CORE_OPERATOR_SYMBOLS_HPP__

#include <string_view>

namespace ga {

    // C++23: Conventional operator symbols for geometric algebra operations
    // 
    // This file defines the standard operator symbols used across GA libraries:
    // - ^ (caret) for wedge/outer product
    // - * (asterisk) for geometric product  
    // - | (pipe) for inner product
    // - < > (angle brackets) for contractions
    // - ~ (tilde) for reversion
    // - etc.
    //
    // These operators provide intuitive mathematical notation for GA operations.

    namespace operators {

        // C++23: Operator symbol constants for documentation and debugging
        struct symbols {
            // Core products
            static constexpr char geometric_product = '*';
            static constexpr char outer_product = '^';
            static constexpr char inner_product = '|';
            static constexpr char scalar_product = '.';
            static constexpr char commutator_product = 'x';
            
            // Contractions
            static constexpr char left_contraction = '<';
            static constexpr char right_contraction = '>';
            
            // Sign operations
            static constexpr char reversion = '~';
            static constexpr char conjugation = '!';
            static constexpr char involution = '@';
            static constexpr char grade_involution = '*';
            
            // Special operations
            static constexpr char dual = '*';
            static constexpr char meet = '&';
            static constexpr char join = '|';
            static constexpr char plunge = '#';
            
            // Arithmetic
            static constexpr char addition = '+';
            static constexpr char subtraction = '-';
            static constexpr char negation = '-';
            static constexpr char division = '/';
            
            // Comparison
            static constexpr char equality = '=';
            static constexpr char inequality = '!';
            static constexpr char less_than = '<';
            static constexpr char greater_than = '>';
            static constexpr char less_equal = '<';
            static constexpr char greater_equal = '>';
            
            // Assignment
            static constexpr char assignment = '=';
            static constexpr char add_assign = '+';
            static constexpr char sub_assign = '-';
            static constexpr char mul_assign = '*';
            static constexpr char div_assign = '/';
            
            // Other
            static constexpr char power = '^';
            static constexpr char square_root = 'r';
            static constexpr char absolute_value = '|';
            static constexpr char norm = 'n';
        };

        // C++23: Operator precedence levels (higher number = higher precedence)
        struct precedence {
            // Unary operators (highest precedence)
            static constexpr int unary_plus = 15;
            static constexpr int unary_minus = 15;
            static constexpr int reversion = 15;
            static constexpr int conjugation = 15;
            static constexpr int involution = 15;
            static constexpr int dual = 15;
            
            // Power and function calls
            static constexpr int power = 14;
            static constexpr int function_call = 14;
            
            // Multiplicative operators
            static constexpr int geometric_product = 13;
            static constexpr int outer_product = 13;
            static constexpr int inner_product = 13;
            static constexpr int scalar_product = 13;
            static constexpr int left_contraction = 13;
            static constexpr int right_contraction = 13;
            static constexpr int commutator_product = 13;
            static constexpr int division = 13;
            
            // Additive operators
            static constexpr int addition = 12;
            static constexpr int subtraction = 12;
            
            // Comparison operators
            static constexpr int equality = 10;
            static constexpr int inequality = 10;
            static constexpr int less_than = 9;
            static constexpr int greater_than = 9;
            static constexpr int less_equal = 9;
            static constexpr int greater_equal = 9;
            
            // Logical operators
            static constexpr int logical_and = 5;
            static constexpr int logical_or = 4;
            
            // Assignment operators (lowest precedence)
            static constexpr int assignment = 2;
            static constexpr int compound_assignment = 2;
        };

        // C++23: Operator associativity
        struct associativity {
            static constexpr bool left = true;
            static constexpr bool right = false;
        };

        // C++23: Operator properties
        struct properties {
            // Commutative operators
            static constexpr bool commutative_geometric_product = false;
            static constexpr bool commutative_outer_product = false;
            static constexpr bool commutative_inner_product = false;
            static constexpr bool commutative_scalar_product = true;
            static constexpr bool commutative_addition = true;
            static constexpr bool commutative_multiplication = true;
            
            // Associative operators
            static constexpr bool associative_geometric_product = true;
            static constexpr bool associative_outer_product = true;
            static constexpr bool associative_inner_product = false;
            static constexpr bool associative_addition = true;
            static constexpr bool associative_multiplication = true;
            
            // Distributive properties
            static constexpr bool distributive_over_addition = true;
            static constexpr bool distributive_over_subtraction = true;
        };

        // C++23: Operator names for debugging and error messages
        struct names {
            static constexpr std::string_view geometric_product = "geometric product";
            static constexpr std::string_view outer_product = "outer product";
            static constexpr std::string_view inner_product = "inner product";
            static constexpr std::string_view scalar_product = "scalar product";
            static constexpr std::string_view left_contraction = "left contraction";
            static constexpr std::string_view right_contraction = "right contraction";
            static constexpr std::string_view commutator_product = "commutator product";
            static constexpr std::string_view reversion = "reversion";
            static constexpr std::string_view conjugation = "conjugation";
            static constexpr std::string_view involution = "involution";
            static constexpr std::string_view dual = "dual";
            static constexpr std::string_view meet = "meet";
            static constexpr std::string_view join = "join";
            static constexpr std::string_view plunge = "plunge";
        };

        // C++23: Operator symbols used by different GA libraries
        struct library_conventions {
            // GATL (original)
            struct gatl {
                static constexpr char geometric_product = '*';
                static constexpr char outer_product = '^';
                static constexpr char inner_product = '|';
                static constexpr char left_contraction = '<';
                static constexpr char right_contraction = '>';
                static constexpr char reversion = '~';
            };
            
            // GAALOP (Geometric Algebra ALgorithms Optimizer)
            struct gaalop {
                static constexpr char geometric_product = '*';
                static constexpr char outer_product = '^';
                static constexpr char inner_product = '|';
                static constexpr char left_contraction = '<';
                static constexpr char right_contraction = '>';
                static constexpr char reversion = '~';
            };
            
            // GAALOPweb
            struct gaalopweb {
                static constexpr char geometric_product = '*';
                static constexpr char outer_product = '^';
                static constexpr char inner_product = '|';
                static constexpr char left_contraction = '<';
                static constexpr char right_contraction = '>';
                static constexpr char reversion = '~';
            };
            
            // CLUCalc
            struct clucalc {
                static constexpr char geometric_product = '*';
                static constexpr char outer_product = '^';
                static constexpr char inner_product = '|';
                static constexpr char left_contraction = '<';
                static constexpr char right_contraction = '>';
                static constexpr char reversion = '~';
            };
            
            // GAViewer
            struct gaviewer {
                static constexpr char geometric_product = '*';
                static constexpr char outer_product = '^';
                static constexpr char inner_product = '|';
                static constexpr char left_contraction = '<';
                static constexpr char right_contraction = '>';
                static constexpr char reversion = '~';
            };
            
            // Mathematica
            struct mathematica {
                static constexpr std::string_view geometric_product = "**";
                static constexpr char outer_product = '^';
                static constexpr char inner_product = '|';
                static constexpr std::string_view left_contraction = "<<";
                static constexpr std::string_view right_contraction = ">>";
                static constexpr char reversion = '~';
            };
            
            // Maple
            struct maple {
                static constexpr std::string_view geometric_product = "&*";
                static constexpr std::string_view outer_product = "&^";
                static constexpr std::string_view inner_product = "&|";
                static constexpr std::string_view left_contraction = "&<";
                static constexpr std::string_view right_contraction = "&>";
                static constexpr char reversion = '~';
            };
            
            // Python (clifford library)
            struct python_clifford {
                static constexpr char geometric_product = '*';
                static constexpr char outer_product = '^';
                static constexpr char inner_product = '|';
                static constexpr char left_contraction = '<';
                static constexpr char right_contraction = '>';
                static constexpr char reversion = '~';
            };
            
            // Julia (GeometricAlgebra.jl)
            struct julia_geometricalgebra {
                static constexpr char geometric_product = '*';
                static constexpr char outer_product = '^';
                static constexpr char inner_product = '|';
                static constexpr char left_contraction = '<';
                static constexpr char right_contraction = '>';
                static constexpr char reversion = '~';
            };
        };

        // C++23: Default convention (GATL-style)
        using default_convention = library_conventions::gatl;

    } // namespace operators

    // C++23: Operator overload templates for different conventions
    namespace operator_overloads {

        // Template for creating operator overloads with different conventions
        template<typename Convention = operators::default_convention>
        struct operator_symbols {
            // Use char for single-character operators, string_view for multi-character
            static constexpr auto geometric_product = 
                std::is_same_v<decltype(Convention::geometric_product), char> ? 
                Convention::geometric_product : char('*');
            static constexpr char outer_product = Convention::outer_product;
            static constexpr char inner_product = Convention::inner_product;
            static constexpr auto left_contraction = 
                std::is_same_v<decltype(Convention::left_contraction), char> ? 
                Convention::left_contraction : char('<');
            static constexpr auto right_contraction = 
                std::is_same_v<decltype(Convention::right_contraction), char> ? 
                Convention::right_contraction : char('>');
            static constexpr char reversion = Convention::reversion;
        };

        // Convenience aliases for different library conventions
        using gatl_symbols = operator_symbols<operators::library_conventions::gatl>;
        using gaalop_symbols = operator_symbols<operators::library_conventions::gaalop>;
        using mathematica_symbols = operator_symbols<operators::library_conventions::mathematica>;
        using python_symbols = operator_symbols<operators::library_conventions::python_clifford>;
        using julia_symbols = operator_symbols<operators::library_conventions::julia_geometricalgebra>;

    } // namespace operator_overloads

    // C++23: Utility functions for operator symbols
    namespace operator_utils {

        // Get operator name from symbol
        template<char Symbol>
        constexpr std::string_view get_operator_name() {
            if constexpr (Symbol == operators::symbols::geometric_product) return operators::names::geometric_product;
            else if constexpr (Symbol == operators::symbols::outer_product) return operators::names::outer_product;
            else if constexpr (Symbol == operators::symbols::inner_product) return operators::names::inner_product;
            else if constexpr (Symbol == operators::symbols::left_contraction) return operators::names::left_contraction;
            else if constexpr (Symbol == operators::symbols::right_contraction) return operators::names::right_contraction;
            else if constexpr (Symbol == operators::symbols::reversion) return operators::names::reversion;
            else return "unknown operator";
        }

        // Check if operator is commutative
        template<char Symbol>
        constexpr bool is_commutative() {
            if constexpr (Symbol == operators::symbols::geometric_product) return operators::properties::commutative_geometric_product;
            else if constexpr (Symbol == operators::symbols::outer_product) return operators::properties::commutative_outer_product;
            else if constexpr (Symbol == operators::symbols::inner_product) return operators::properties::commutative_inner_product;
            else if constexpr (Symbol == operators::symbols::scalar_product) return operators::properties::commutative_scalar_product;
            else if constexpr (Symbol == operators::symbols::addition) return operators::properties::commutative_addition;
            else return false;
        }

        // Check if operator is associative
        template<char Symbol>
        constexpr bool is_associative() {
            if constexpr (Symbol == operators::symbols::geometric_product) return operators::properties::associative_geometric_product;
            else if constexpr (Symbol == operators::symbols::outer_product) return operators::properties::associative_outer_product;
            else if constexpr (Symbol == operators::symbols::inner_product) return operators::properties::associative_inner_product;
            else if constexpr (Symbol == operators::symbols::addition) return operators::properties::associative_addition;
            else return false;
        }

        // Get operator precedence
        template<char Symbol>
        constexpr int get_precedence() {
            if constexpr (Symbol == operators::symbols::geometric_product) return operators::precedence::geometric_product;
            else if constexpr (Symbol == operators::symbols::outer_product) return operators::precedence::outer_product;
            else if constexpr (Symbol == operators::symbols::inner_product) return operators::precedence::inner_product;
            else if constexpr (Symbol == operators::symbols::left_contraction) return operators::precedence::left_contraction;
            else if constexpr (Symbol == operators::symbols::right_contraction) return operators::precedence::right_contraction;
            else if constexpr (Symbol == operators::symbols::reversion) return operators::precedence::reversion;
            else if constexpr (Symbol == operators::symbols::addition) return operators::precedence::addition;
            else if constexpr (Symbol == operators::symbols::subtraction) return operators::precedence::subtraction;
            else return 0;
        }

        // Get operator associativity
        template<char Symbol>
        constexpr bool get_associativity() {
            if constexpr (Symbol == operators::symbols::geometric_product) return operators::associativity::left;
            else if constexpr (Symbol == operators::symbols::outer_product) return operators::associativity::left;
            else if constexpr (Symbol == operators::symbols::inner_product) return operators::associativity::left;
            else if constexpr (Symbol == operators::symbols::left_contraction) return operators::associativity::left;
            else if constexpr (Symbol == operators::symbols::right_contraction) return operators::associativity::left;
            else if constexpr (Symbol == operators::symbols::addition) return operators::associativity::left;
            else if constexpr (Symbol == operators::symbols::subtraction) return operators::associativity::left;
            else return operators::associativity::left; // Default to left associative
        }

    } // namespace operator_utils

} // namespace ga

#endif // __GA_CORE_OPERATOR_SYMBOLS_HPP__ 