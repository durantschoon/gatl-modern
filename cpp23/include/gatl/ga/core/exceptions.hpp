/* Copyright (C) Leandro Augusto Frata Fernandes
 * 
 * author     : Fernandes, Leandro A. F.
 * e-mail     : laffernandes@ic.uff.br
 * home page  : http://www.ic.uff.br/~laffernandes
 * repository : https://github.com/laffernandes/gatl.git
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
 */

#ifndef __GA_CORE_EXCEPTIONS_HPP__
#define __GA_CORE_EXCEPTIONS_HPP__

#include <stdexcept>
#include <string>
#include <string_view>

namespace ga {

    // Modern C++23 exception class for not implemented features
    class not_implemented_error : public std::logic_error {
    public:
        // C++23 constructor with string_view for better performance
        explicit not_implemented_error(std::string_view what_arg) 
            : std::logic_error(std::string(what_arg)) {
        }

        // Legacy constructor for backward compatibility
        explicit not_implemented_error(const std::string& what_arg) 
            : std::logic_error(what_arg) {
        }

        explicit not_implemented_error(const char* what_arg) 
            : std::logic_error(what_arg) {
        }

        // C++23: Add noexcept specifier for destructor
        ~not_implemented_error() noexcept override = default;

        // C++23: Add copy constructor and assignment operator
        not_implemented_error(const not_implemented_error&) = default;
        not_implemented_error& operator=(const not_implemented_error&) = default;

        // C++23: Add move constructor and assignment operator
        not_implemented_error(not_implemented_error&&) noexcept = default;
        not_implemented_error& operator=(not_implemented_error&&) noexcept = default;
    };

    // Additional exception types for C++23
    class invalid_argument_error : public std::invalid_argument {
    public:
        explicit invalid_argument_error(std::string_view what_arg) 
            : std::invalid_argument(std::string(what_arg)) {
        }

        explicit invalid_argument_error(const std::string& what_arg) 
            : std::invalid_argument(what_arg) {
        }

        explicit invalid_argument_error(const char* what_arg) 
            : std::invalid_argument(what_arg) {
        }

        ~invalid_argument_error() noexcept override = default;
        invalid_argument_error(const invalid_argument_error&) = default;
        invalid_argument_error& operator=(const invalid_argument_error&) = default;
        invalid_argument_error(invalid_argument_error&&) noexcept = default;
        invalid_argument_error& operator=(invalid_argument_error&&) noexcept = default;
    };

    class domain_error : public std::domain_error {
    public:
        explicit domain_error(std::string_view what_arg) 
            : std::domain_error(std::string(what_arg)) {
        }

        explicit domain_error(const std::string& what_arg) 
            : std::domain_error(what_arg) {
        }

        explicit domain_error(const char* what_arg) 
            : std::domain_error(what_arg) {
        }

        ~domain_error() noexcept override = default;
        domain_error(const domain_error&) = default;
        domain_error& operator=(const domain_error&) = default;
        domain_error(domain_error&&) noexcept = default;
        domain_error& operator=(domain_error&&) noexcept = default;
    };

}

#endif // __GA_CORE_EXCEPTIONS_HPP__ 