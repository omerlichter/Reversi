#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Point.h"

TEST(PointTest, RegularTest) {
    Point p(-1, 2);
    EXPECT_EQ(p.getRow(), -1);
    EXPECT_EQ(p.getColumn(), 2);
}

TEST(PointTest, ZeroTest) {
    Point p(0, 0);
    EXPECT_EQ(p.getRow(), 0);
    EXPECT_EQ(p.getColumn(), 0);
}


TEST(PointTest, CheckNotEqualPoints) {
    Point p(-1, 2);
    EXPECT_FALSE(p.getRow() == 5);
    EXPECT_FALSE(p.getColumn() == 5);
}

TEST(PointTest, BigNumbersTest) {
    Point p(-1111222, 2000012);
    EXPECT_EQ(p.getRow(), -1111222);
    EXPECT_EQ(p.getColumn(), 2000012);
}

TEST(PointTest, FromStringTest) {
    Point p1("3, 5");
    EXPECT_EQ(p1.getRow(), 3);
    EXPECT_EQ(p1.getColumn(), 5);
    Point p2("3, ");
    EXPECT_EQ(p2.getRow(), 0);
    EXPECT_EQ(p2.getColumn(), 0);
}