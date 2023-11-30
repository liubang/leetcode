//=====================================================================
//
// 198.house-robber.cc -
//
// Created by liubang on 2023/04/24 23:38
// Last Modified: 2023/04/24 23:38
//
//=====================================================================
#include <gtest/gtest.h>
#include <vector>

// 这道题目太经典了，所以值得经常拿出来反复练习
namespace {
class Solution {
public:
    int rob(const std::vector<int>& nums) {
        int size = static_cast<int>(nums.size());
        if (size == 1)
            return nums[0];
        // dp[i]表示偷前i个房子，在不触发报警的情况下最大的收益
        // 由于不能连续偷相邻的房子，所以：
        // dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i])
        std::vector<int> dp(size);
        // 初始状态
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[size - 1];
    }
};
} // namespace

TEST(Leetcode, house_robber) {
    Solution s;
    EXPECT_EQ(1, s.rob({1}));
    EXPECT_EQ(2, s.rob({1, 2}));
    EXPECT_EQ(4, s.rob({1, 2, 3, 1}));
    EXPECT_EQ(12, s.rob({2, 7, 9, 3, 1}));
}
