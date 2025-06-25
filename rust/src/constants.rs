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
 * Mathematical constants module providing tau-based constants for modern geometric algebra.
 */

use std::f64::consts;

/// Mathematical constants using τ (tau) as the fundamental circle constant.
/// 
/// τ = 2π is the fundamental circle constant, making many mathematical
/// expressions more natural and reducing the number of factors of 2.
pub mod constants {
    use super::*;

    /// τ = 2π (tau is the fundamental circle constant)
    pub fn tau<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        T::from(2.0 * consts::PI)
    }

    /// τ/2 = π (half tau)
    pub fn tau_over_2<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        T::from(consts::PI)
    }

    /// τ/4 = π/2 (quarter tau)
    pub fn tau_over_4<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        T::from(consts::FRAC_PI_2)
    }

    /// τ/6 = π/3 (one-sixth tau)
    pub fn tau_over_6<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        T::from(consts::FRAC_PI_3)
    }

    /// τ/8 = π/4 (one-eighth tau)
    pub fn tau_over_8<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        T::from(consts::FRAC_PI_4)
    }

    /// τ/12 = π/6 (one-twelfth tau)
    pub fn tau_over_12<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        T::from(consts::FRAC_PI_6)
    }

    /// Common angle constants
    pub fn full_rotation<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        tau::<T>() // 360° = τ
    }

    pub fn half_rotation<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        tau_over_2::<T>() // 180° = τ/2
    }

    pub fn quarter_rotation<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        tau_over_4::<T>() // 90° = τ/4
    }

    pub fn third_rotation<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        tau_over_6::<T>() // 60° = τ/6
    }

    pub fn sixth_rotation<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        tau_over_12::<T>() // 30° = τ/12
    }

    // Legacy π constants for backward compatibility
    pub fn pi<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        tau_over_2::<T>()
    }

    pub fn pi_over_2<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        tau_over_4::<T>()
    }

    pub fn pi_over_4<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        tau_over_8::<T>()
    }

    pub fn pi_over_6<T>() -> T 
    where 
        T: From<f64> + Copy,
    {
        tau_over_12::<T>()
    }
}

// Re-export all constants for convenience
pub use constants::*; 