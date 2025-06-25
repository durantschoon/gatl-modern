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
 * Exception types for geometric algebra operations.
 */

use std::error::Error;
use std::fmt;

/// Error type for not implemented features in geometric algebra operations.
#[derive(Debug, Clone)]
pub struct NotImplementedError {
    message: String,
}

impl NotImplementedError {
    /// Create a new NotImplementedError with the given message.
    pub fn new<S: Into<String>>(message: S) -> Self {
        Self {
            message: message.into(),
        }
    }

    /// Get the error message.
    pub fn message(&self) -> &str {
        &self.message
    }
}

impl fmt::Display for NotImplementedError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "Not implemented: {}", self.message)
    }
}

impl Error for NotImplementedError {}

/// Error type for invalid arguments in geometric algebra operations.
#[derive(Debug, Clone)]
pub struct InvalidArgumentError {
    message: String,
}

impl InvalidArgumentError {
    /// Create a new InvalidArgumentError with the given message.
    pub fn new<S: Into<String>>(message: S) -> Self {
        Self {
            message: message.into(),
        }
    }

    /// Get the error message.
    pub fn message(&self) -> &str {
        &self.message
    }
}

impl fmt::Display for InvalidArgumentError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "Invalid argument: {}", self.message)
    }
}

impl Error for InvalidArgumentError {}

/// Error type for domain errors in geometric algebra operations.
#[derive(Debug, Clone)]
pub struct DomainError {
    message: String,
}

impl DomainError {
    /// Create a new DomainError with the given message.
    pub fn new<S: Into<String>>(message: S) -> Self {
        Self {
            message: message.into(),
        }
    }

    /// Get the error message.
    pub fn message(&self) -> &str {
        &self.message
    }
}

impl fmt::Display for DomainError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "Domain error: {}", self.message)
    }
}

impl Error for DomainError {}

/// Error type for tolerance-related errors in geometric algebra operations.
#[derive(Debug, Clone)]
pub struct ToleranceError {
    message: String,
}

impl ToleranceError {
    /// Create a new ToleranceError with the given message.
    pub fn new<S: Into<String>>(message: S) -> Self {
        Self {
            message: message.into(),
        }
    }

    /// Get the error message.
    pub fn message(&self) -> &str {
        &self.message
    }
}

impl fmt::Display for ToleranceError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "Tolerance error: {}", self.message)
    }
}

impl Error for ToleranceError {}

/// Convenience function to create a NotImplementedError.
pub fn not_implemented<S: Into<String>>(message: S) -> NotImplementedError {
    NotImplementedError::new(message)
}

/// Convenience function to create an InvalidArgumentError.
pub fn invalid_argument<S: Into<String>>(message: S) -> InvalidArgumentError {
    InvalidArgumentError::new(message)
}

/// Convenience function to create a DomainError.
pub fn domain_error<S: Into<String>>(message: S) -> DomainError {
    DomainError::new(message)
}

/// Convenience function to create a ToleranceError.
pub fn tolerance_error<S: Into<String>>(message: S) -> ToleranceError {
    ToleranceError::new(message)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_not_implemented_error() {
        let error = NotImplementedError::new("test feature");
        assert_eq!(error.message(), "test feature");
        assert_eq!(error.to_string(), "Not implemented: test feature");
    }

    #[test]
    fn test_invalid_argument_error() {
        let error = InvalidArgumentError::new("invalid value");
        assert_eq!(error.message(), "invalid value");
        assert_eq!(error.to_string(), "Invalid argument: invalid value");
    }

    #[test]
    fn test_domain_error() {
        let error = DomainError::new("out of domain");
        assert_eq!(error.message(), "out of domain");
        assert_eq!(error.to_string(), "Domain error: out of domain");
    }

    #[test]
    fn test_tolerance_error() {
        let error = ToleranceError::new("tolerance exceeded");
        assert_eq!(error.message(), "tolerance exceeded");
        assert_eq!(error.to_string(), "Tolerance error: tolerance exceeded");
    }

    #[test]
    fn test_convenience_functions() {
        let _error1 = not_implemented("test");
        let _error2 = invalid_argument("test");
        let _error3 = domain_error("test");
        let _error4 = tolerance_error("test");
    }
} 