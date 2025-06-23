#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest.h"
#include <gatl/ga.hpp>>
#include <numbers>

TEST_CASE("example: multivector default constructs") {
    // Replace with real test logic once you're familiar with the API
    gatl::multivector<> mv;
    CHECK(mv.size() == 0);  // placeholder example, may need real API inspection
}

TEST_CASE("2D plane-based geometric algebra basics") {
    using namespace ga2p;

    // e1 and e2 are the two basis vectors of the 2D plane
    // e1 typically represents the x-axis direction
    // e2 typically represents the y-axis direction
    // They form an orthonormal basis: e1² = e2² = 1, e1·e2 = 0

    // Test basis vectors
    CHECK(e1 * e1 == 1);  // e1 squared should be 1
    CHECK(e2 * e2 == 1);  // e2 squared should be 1
    CHECK(e1 * e2 == -e2 * e1);  // Anti-commutativity

    // Test bivector
    auto e12 = e1 ^ e2;  // Wedge product creates the bivector representing the plane
    CHECK(e12 * e12 == -1);  // e12 squared should be -1

    // Test scalar multiplication
    auto v = 2.0 * e1 + 3.0 * e2;  // Vector in the plane
    CHECK(v * v == 13.0);  // (2e1 + 3e2)² = 4 + 9 = 13
}

TEST_CASE("2D rotations and reflections") {
    using namespace ga2p;

    // Test rotation using rotor
    auto angle = std::numbers::tau / 8.0;  // 45 degrees (tau/8 = 2π/8 = π/4)
    auto rotor = std::cos(angle/2) + std::sin(angle/2) * e12;
    auto vector = e1;  // Start with vector along x-axis

    // Rotate vector by 45 degrees
    auto rotated = rotor * vector * ~rotor;  // ~rotor is reverse
    CHECK(std::abs(rotated[e1] - std::cos(angle)) < 1e-10);
    CHECK(std::abs(rotated[e2] - std::sin(angle)) < 1e-10);

    // Test reflection
    auto normal = e1;  // Reflect across x-axis
    auto to_reflect = e1 + e2;
    auto reflected = normal * to_reflect * normal;
    CHECK(std::abs(reflected[e1] - 1.0) < 1e-10);
    CHECK(std::abs(reflected[e2] + 1.0) < 1e-10);
}

TEST_CASE("2D geometric operations") {
    using namespace ga2p;

    // Test vector projection
    auto a = 2.0 * e1 + e2;
    auto b = e1;
    auto proj = (a | b) * b;  // Project a onto b
    CHECK(std::abs(proj[e1] - 2.0) < 1e-10);
    CHECK(std::abs(proj[e2]) < 1e-10);

    // Test area calculation
    auto v1 = 2.0 * e1;
    auto v2 = 3.0 * e2;
    auto area = (v1 ^ v2).norm();  // Area of parallelogram
    CHECK(std::abs(area - 6.0) < 1e-10);

    // Test dual operation
    auto line = e1 + e2;  // Line through origin
    auto dual = line * e12;  // Dual of line is point
    CHECK(std::abs(dual[e1] + 1.0) < 1e-10);
    CHECK(std::abs(dual[e2] - 1.0) < 1e-10);
}

// Add more test cases with common angles using tau
TEST_CASE("Common rotation angles using tau") {
    using namespace ga2p;

    // Test common angles
    auto full_turn = std::numbers::tau;      // 360 degrees
    auto half_turn = std::numbers::tau/2.0;  // 180 degrees
    auto quarter_turn = std::numbers::tau/4.0;  // 90 degrees
    auto eighth_turn = std::numbers::tau/8.0;   // 45 degrees
    auto sixteenth_turn = std::numbers::tau/16.0;  // 22.5 degrees

    // Test that a full turn brings us back to the start
    auto vector = e1;
    auto rotor = std::cos(full_turn/2) + std::sin(full_turn/2) * e12;
    auto rotated = rotor * vector * ~rotor;
    CHECK(std::abs(rotated[e1] - 1.0) < 1e-10);
    CHECK(std::abs(rotated[e2]) < 1e-10);
}
