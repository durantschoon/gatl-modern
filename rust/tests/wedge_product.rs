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
 * This test file validates the Rust implementation against shared test specifications
 * to ensure cross-language consistency with the C++ version.
 */

use serde::Deserialize;
use std::fs;
use rust::compute_wedge;

#[derive(Deserialize)]
struct WedgeTest {
    lhs: String,
    rhs: String,
    expected: String,
}

#[test]
fn wedge_tests_from_json() {
    let content = fs::read_to_string("../shared_tests/wedge_product.json").unwrap();
    let tests: Vec<WedgeTest> = serde_json::from_str(&content).unwrap();

    for test in tests {
        let result = compute_wedge(&test.lhs, &test.rhs);
        assert_eq!(result, test.expected, "lhs: {}, rhs: {}", test.lhs, test.rhs);
    }
}
