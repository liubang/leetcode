//=====================================================================
//
// 416.partition-equal-subset-sum.cc -
//
// Created by liubang on 2023/04/16 17:19
// Last Modified: 2023/04/16 17:19
//
//=====================================================================
#include <numeric>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    bool canPartition(const std::vector<int>& nums) {
        auto size = static_cast<int64_t>(nums.size());
        // 只有一个元素的话，无法分成两个非空子集，所以不成立
        if (size < 2)
            return false;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        // 元素和为奇数，无法分成两个正整数之和
        if ((sum & 1) == 1)
            return false;
        int target = sum / 2;
        // dp[i][j] 表示nums前i个元素中，是否能构成和为j的子集
        std::vector<std::vector<bool>> dp(size + 1, std::vector<bool>(target + 1, false));
        for (int i = 1; i <= size; ++i) {
            for (int j = 1; j <= target; ++j) {
                // 当前元素
                int num = nums[i - 1];
                if (num == j)
                    dp[i][j] = true;
                else if (num > j)
                    // 当前元素比target还大，所以当前元素不能加入到集合中
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
            }
        }
        return dp[size][target];
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_TRUE(s.canPartition({1, 5, 11, 5}));
    EXPECT_TRUE(s.canPartition({2, 2, 1, 1}));
    EXPECT_FALSE(s.canPartition({1, 2, 5}));
    EXPECT_FALSE(s.canPartition({1, 2, 3, 5}));
}
