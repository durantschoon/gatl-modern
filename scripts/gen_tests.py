#!/usr/bin/env python

import toml
from pathlib import Path

# Paths
manifest_path = Path("shared_tests/test_manifest.toml")
cpp_test_dir = Path("cpp/tools/test")
rust_test_dir = Path("rust/tests")

# Templates
def cpp_stub(name, file):
    return f'''#define DOCTEST_CONFIG_IMPLEMENT_WITHOUT_MAIN
#include "external/doctest.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

TEST_CASE("{name} from {file}") {{
    std::ifstream f("shared_tests/{file}");
    json tests = json::parse(f);
    for (const auto& test : tests) {{
        // TODO: implement test logic
    }}
}}
'''

def rust_stub(name, file):
    return f'''use serde::Deserialize;
use std::fs;

#[derive(Deserialize)]
struct TestCase {{
    lhs: String,
    rhs: String,
    expected: String,
}}

#[test]
fn test_{name}() {{
    let data = fs::read_to_string("shared_tests/{file}").unwrap();
    let tests: Vec<TestCase> = serde_json::from_str(&data).unwrap();
    for test in tests {{
        // TODO: implement test logic
    }}
}}
'''

def main():
    # Load manifest
    manifest = toml.load(manifest_path)

    for test in manifest.get("tests", []):
        name = test["name"]
        file = test["file"]

        cpp_file = cpp_test_dir / f"{name}_tests.cpp"
        rust_file = rust_test_dir / f"{name}.rs"

        if not cpp_file.exists():
            cpp_file.write_text(cpp_stub(name, file))
            print(f"✓ Created C++:   {cpp_file}")

        if not rust_file.exists():
            rust_file.write_text(rust_stub(name, file))
            print(f"✓ Created Rust:  {rust_file}")

if __name__ == "__main__":
    main()
