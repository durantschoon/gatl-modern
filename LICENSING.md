<!--
  LICENSING.md - Licensing Guide for GATL
  Copyright (c) 2024 Durant Schoon
  This documentation is provided under the terms of the Mozilla Public License 2.0.
-->
# GATL Dual License Structure

## 📋 **Overview**

This project uses a **dual-license structure** to provide users with choice and flexibility while respecting the original work and enabling new development.

## 🏗️ **License Structure**

### **Original GATL System (GPL v3.0)**
- **License**: GNU General Public License v3.0
- **Files**: `cpp/`, `cpp23/include/gatl/ga/` (derivative works)
- **Copyright**: Leandro A. F. Fernandes (2021)
- **Requirements**: Copyleft - derivative works must also be GPL v3.0

### **Modern Implementation (MPL 2.0)**
- **License**: Mozilla Public License 2.0
- **Files**: `cpp23/include/gatl/modern/`, `rust/`
- **Copyright**: Durant Schoon (2024)
- **Requirements**: Permissive - can be used in proprietary software

## 📁 **Directory Structure with Licensing**

```
gatl/
├── LICENSE-GPL-v3.0        # Original GPL v3.0 license
├── LICENSE-MPL-2.0         # Modern MPL 2.0 license
├── LICENSING.md            # This file - licensing guide
├── cpp/                    # GPL v3.0 - Original template metaprogramming
│   └── include/gatl/ga/    # GPL v3.0 - Original system
├── cpp23/
│   └── include/gatl/
│       ├── ga/             # GPL v3.0 - Derivative of original
│       └── modern/         # MPL 2.0 - New modern implementation
├── rust/                   # MPL 2.0 - New Rust implementation
└── shared_tests/           # MPL 2.0 - New test infrastructure
```

## 🎯 **How to Use Each System**

### **Using Only the Modern System (MPL 2.0)**

**C++23 Modern Types:**
```cpp
#include <gatl/modern/types.hpp>
using namespace gatl::modern;

// Create modern algebraic types
auto scalar_term = scalar(3.14);
auto vector_term = vector({{1, 1.0}, {2, 2.0}});
auto bivector_term = bivector({{1, 2, 1.0}});

// Use grade-indexed types for safety
GradeIndexed<double, 0> safe_scalar(3.14);
GradeIndexed<std::vector<std::pair<Index, Scalar>>, 1> safe_vector({{1, 1.0}});
```

**Rust Modern Types:**
```rust
use gatl::modern::types::*;

// Create modern algebraic types
let scalar_term = scalar(3.14);
let vector_term = vector(vec![(1, 1.0), (2, 2.0)]);
let bivector_term = bivector(vec![(1, 2, 1.0)]);

// Use grade-indexed types for safety
let safe_scalar: GradeIndexed<f64, 0> = GradeIndexed::new(3.14);
let safe_vector: GradeIndexed<Vec<(Index, Scalar)>, 1> = GradeIndexed::new(vec![(1, 1.0)]);
```

**Benefits:**
- ✅ **No GPL restrictions** - can use in proprietary software
- ✅ **Modern type safety** - compile-time grade checking
- ✅ **Clean API** - simpler than original template system
- ✅ **Cross-language** - identical results in C++ and Rust

### **Using Only the Legacy System (GPL v3.0)**

**C++17 Template Metaprogramming:**
```cpp
#include <gatl/ga3e.hpp>
using namespace ga3e;

// Use original template metaprogramming system
auto v1 = vector(space, 1.0, 2.0, 3.0);
auto v2 = vector(space, 4.0, 5.0, 6.0);
auto result = v1 * v2;  // Geometric product
```

**Benefits:**
- ✅ **Sophisticated optimizations** - lazy evaluation, compile-time simplifications
- ✅ **Proven performance** - mature template metaprogramming
- ✅ **Full feature set** - all original GATL capabilities

### **Using Both Systems**

**Mixed Usage:**
```cpp
// Modern system (MPL 2.0)
#include <gatl/modern/types.hpp>
auto modern_vec = gatl::modern::vector({{1, 1.0}, {2, 2.0}});

// Legacy system (GPL v3.0)
#include <gatl/ga3e.hpp>
auto legacy_vec = ga3e::vector(ga3e::space, 1.0, 2.0, 3.0);

// Convert between systems (when bridge is implemented)
auto converted = convert_to_modern(legacy_vec);
```

## 📋 **License Requirements**

### **GPL v3.0 Requirements (Legacy System)**
- **Source Code**: Must provide source code when distributing
- **Copyleft**: Derivative works must also be GPL v3.0
- **Patent Protection**: Includes patent grants
- **Network Use**: Network use triggers source distribution requirement

### **MPL 2.0 Requirements (Modern System)**
- **Source Code**: Must provide source code when distributing
- **Permissive**: Can be used in proprietary software
- **Patent Protection**: Includes patent grants
- **File-Level**: License applies to individual files, not entire project

## 🔄 **Migration Path**

### **From Legacy to Modern**
```cpp
// Old way (GPL v3.0)
#include <gatl/ga3e.hpp>
auto v = ga3e::vector(ga3e::space, 1.0, 2.0, 3.0);

// New way (MPL 2.0)
#include <gatl/modern/types.hpp>
auto v = gatl::modern::vector({{1, 1.0}, {2, 2.0}, {3, 3.0}});
```

### **Gradual Migration**
1. **Start with modern types** for new code
2. **Keep legacy system** for existing code
3. **Use bridge functions** to convert between systems
4. **Migrate incrementally** as needed

## ⚖️ **Legal Considerations**

### **What You Can Do**
- ✅ Use modern system in proprietary software
- ✅ Use legacy system under GPL v3.0 terms
- ✅ Use both systems in the same project
- ✅ Contribute to either system under respective licenses

### **What You Must Avoid**
- ❌ Mixing licenses in the same file
- ❌ Claiming original work as your own
- ❌ Violating GPL terms for derivative works
- ❌ Unclear attribution of original authors

## 📊 **License Comparison**

| Aspect | GPL v3.0 (Legacy) | MPL 2.0 (Modern) |
|--------|-------------------|------------------|
| **Copyleft** | Strong | Weak (file-level) |
| **Proprietary Use** | ❌ No | ✅ Yes |
| **Patent Protection** | ✅ Yes | ✅ Yes |
| **Network Use** | Triggers source | No special requirement |
| **Commercial Friendly** | ❌ No | ✅ Yes |
| **Academic Use** | ✅ Yes | ✅ Yes |

## 🎯 **Recommendations**

### **For Commercial Users**
- **Use modern system** (MPL 2.0) for new development
- **Avoid legacy system** unless you can comply with GPL v3.0
- **Consider dual usage** if you need both systems

### **For Open Source Users**
- **Use either system** based on your license preferences
- **Legacy system** if you want strong copyleft
- **Modern system** if you want more permissive licensing

### **For Academic Users**
- **Modern system** for research and publications
- **No GPL restrictions** on your research code
- **Can share code** under your preferred license

## 📞 **Questions and Support**

If you have questions about licensing:

1. **Review this document** for common scenarios
2. **Check the license files** for full legal text
3. **Consult legal counsel** for specific use cases
4. **Contact the maintainers** for clarification

## 📝 **Attribution Requirements**

### **When Using Legacy System (GPL v3.0)**
```cpp
/*
 * Based on GATL: Geometric Algebra Template Library
 * Copyright (c) 2021 Leandro A. F. Fernandes
 * Licensed under the GNU General Public License v3.0
 */
```

### **When Using Modern System (MPL 2.0)**
```cpp
/*
 * Modern Algebraic Types for Geometric Algebra
 * Copyright (c) 2024 Durant Schoon
 * Licensed under the Mozilla Public License 2.0
 */
```

---

**Last Updated**: 2024
**For Legal Questions**: Consult with legal counsel for your specific use case 