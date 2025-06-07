#include <gtest/gtest.h>
#include "../src/math.hpp" // Include the code to be tested

// Test case for the add function
TEST(MathTest, HandlesPositiveInput) {
    EXPECT_EQ(add(2, 2), 4);
    EXPECT_EQ(add(1, 5), 6);
}

TEST(MathTest, HandlesZeroInput) {
    EXPECT_EQ(add(0, 5), 5);
    EXPECT_EQ(add(5, 0), 5);
    EXPECT_EQ(add(0, 0), 0);
} 