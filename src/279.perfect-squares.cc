//=====================================================================
//
// 279.perfect-squares.cc -
//
// Created by liubang on 2023/04/17 13:45
// Last Modified: 2023/04/17 13:45
//
//=====================================================================
#include <climits>
#include <vector>

#include <gtest/gtest.h>

namespace {
/**
 * 这是一道典型的完全背包的问题，完全背包跟01背包的区别在于，完全背包中元素可重复
 * 因此在选择元素的时候，需要遍历寻找最优值
 *
 * 设dp[i]表示和为i的完全平方数的最少个数，那么dp[i]的递推公式为 dp[i] =
 * min(dp[i - 1*1], dp[i - 2 * 2], dp[i - j * j]) + 1; for(j = 1; j*j <= i; ++j)
 * 其中 j >= 1, j*j <= i;
 *
 * 清楚了递推公式，代码就非常简单了。
 */
class Solution {
public:
    int numSquares(int n) {
        std::vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int min = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                min = std::min(min, dp[i - j * j]);
            }
            dp[i] = min + 1;
        }
        return dp[n];
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_EQ(3, s.numSquares(12));
    EXPECT_EQ(2, s.numSquares(13));
    EXPECT_EQ(3, s.numSquares(14));
    EXPECT_EQ(4, s.numSquares(15));
}
