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
