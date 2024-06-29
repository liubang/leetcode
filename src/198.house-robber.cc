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
