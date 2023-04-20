//=====================================================================
//
// 2413.smallest-even-multiple.cc -
//
// Created by liubang on 2023/04/21 01:00
// Last Modified: 2023/04/21 01:00
//
//=====================================================================
#include <gtest/gtest.h>

namespace {
class Solution {
 public:
  int smallestEvenMultiple(int n) {
    // 最小共倍数= a * b / 最大公约数
    return 2 * n / gcd(2, n);
  }

 private:
  // 最大公约数 greatest common divisor
  int gcd(int a, int b) {
    if (a % b == 0)
      return b;
    else
      return gcd(b, a % b);
  }
};
}  // namespace

TEST(Leetcode, leetcode) {
  Solution s;
  EXPECT_EQ(2, s.smallestEvenMultiple(1));
  EXPECT_EQ(2, s.smallestEvenMultiple(2));
  EXPECT_EQ(6, s.smallestEvenMultiple(3));
  EXPECT_EQ(4, s.smallestEvenMultiple(4));
  EXPECT_EQ(10, s.smallestEvenMultiple(5));
  EXPECT_EQ(6, s.smallestEvenMultiple(6));
}
