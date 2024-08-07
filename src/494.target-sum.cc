// Copyright (c) 2024 The Authors. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Authors: liubang (it.liubang@gmail.com)

#include <numeric>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    /**
     * 这题和416非常类似，也是典型的背包问题（或者NP完全问题）
     * 也是需要使用动态规划来解题。
     *
     * dp[i][j] 表示nums中前i个元素之和为j的组合数，那么状态转移方程为
     * 当nums[i] > j的时候，dp[i][j] = dp[i - 1][j]
     * 当nums[i] <= j的时候，dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]]
     */
    int findTargetSumWays(const std::vector<int>& nums, int target) {
        // 假设nums中需要添加-号的元素之和为x，那么(sum - x) - x = target
        // 则x = (sum - target) / 2
        // 由于nums都是正整数，所以(sum - target)必须为偶数
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int diff = sum - target;
        if (diff < 0 || (diff & 1) == 1)
            return 0;
        auto size = static_cast<int>(nums.size());
        int ntarget = diff / 2;
        std::vector<std::vector<int>> dp(size + 1, std::vector<int>(ntarget + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= size; ++i) {
            for (int j = 0; j <= ntarget; ++j) {
                int num = nums[i - 1];
                if (num > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num];
            }
        }
        return dp[size][ntarget];
    }
};
} // namespace

TEST(Leetcode, target_sum) {
    Solution s;
    EXPECT_EQ(5, s.findTargetSumWays({1, 1, 1, 1, 1}, 3));
    EXPECT_EQ(1, s.findTargetSumWays({1}, 1));
}
