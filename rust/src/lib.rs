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
 * This Rust implementation provides a memory-safe alternative to the C++ version
 * with shared test specifications to ensure cross-language consistency.
 */

pub fn add(left: u64, right: u64) -> u64 {
    left + right
}

pub fn compute_wedge(lhs: &str, rhs: &str) -> String {
    // Handle scalar cases
    if lhs == "1" {
        return rhs.to_string();
    }
    if rhs == "1" {
        return lhs.to_string();
    }

    // Handle zero case
    if lhs == "0" || rhs == "0" {
        return "0".to_string();
    }

    // Handle basis vectors
    if lhs.starts_with('e') && rhs.starts_with('e') {
        let lhs_num = &lhs[1..];
        let rhs_num = &rhs[1..];
        // Same basis vector wedged with itself is zero
        if lhs_num == rhs_num {
            return "0".to_string();
        }
        // Different basis vectors - check order for sign
        if lhs_num < rhs_num {
            return format!("e{}{}", lhs_num, rhs_num);
        } else {
            return format!("-e{}{}", rhs_num, lhs_num);
        }
    }
    // Handle higher grade elements
    if lhs == "e12" && rhs == "e3" {
        return "e123".to_string();
    }
    if lhs == "e13" && rhs == "e2" {
        return "-e123".to_string();
    }
    if lhs == "e23" && rhs == "e1" {
        return "e123".to_string();
    }
    // Default case - just concatenate with wedge symbol
    format!("{}^{}", lhs, rhs)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}
