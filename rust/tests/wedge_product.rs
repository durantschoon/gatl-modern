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
