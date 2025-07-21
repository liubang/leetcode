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
