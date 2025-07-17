// Copyright (c) 2025 The Authors. All rights reserved.
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

#include <unordered_map>
#include <vector>

namespace {
class Solution {
public:
    /*
     * dp[i][mod] 表示以nums[i]结尾，模值为mod的最长子序列长度，那么：
     * 当 i < j 时, dp[j][mod] = dp[i][mod] + 1
     */
    int maximum_length(const std::vector<int>& nums, int k) {
        size_t size = nums.size();
        std::vector<std::unordered_map<int, int>> dp(size);
        int max_len = 1;
        for (int j = 0; j < size; ++j) {
            for (int i = 0; i < j; ++i) {
                int mod = (nums[i] + nums[j]) % k;
                // 如果不存在dp[i][mod]，则nums[i]和nums[j]构成长度为2的序列，使得模为mod
                // 否则，在dp[i][mod]的基础上+1
                dp[j][mod] = dp[i].count(mod) ? dp[i][mod] + 1 : 2;
                max_len = std::max(max_len, dp[j][mod]);
            }
        }
        return max_len;
    }
};
} // namespace

TEST(Leetcode, find_the_maximum_length_of_valid_subsequence_ii) {
    Solution s;
    EXPECT_EQ(5, s.maximum_length({1, 2, 3, 4, 5}, 2));
    EXPECT_EQ(4, s.maximum_length({1, 4, 2, 3, 1, 4}, 3));
}
