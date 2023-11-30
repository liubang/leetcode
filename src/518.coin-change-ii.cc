//=====================================================================
//
// 518.coin-change-ii.cc -
//
// Created by liubang on 2023/04/17 23:39
// Last Modified: 2023/04/17 23:39
//
//=====================================================================
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    int change(int amount, const std::vector<int>& coins) {
        std::vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;

    EXPECT_EQ(4, s.change(5, {1, 2, 5}));
    EXPECT_EQ(0, s.change(3, {2}));
    EXPECT_EQ(1, s.change(10, {10}));
}
