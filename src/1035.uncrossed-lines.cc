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

namespace {
class Solution {
public:
    int maxUncrossedLines(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1));
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
} // namespace

TEST(Leetcode, uncrossed_lines) {
    Solution s;

    EXPECT_EQ(2, s.maxUncrossedLines({1, 4, 2}, {1, 2, 4}));
    EXPECT_EQ(3, s.maxUncrossedLines({2, 5, 1, 2, 5}, {10, 5, 2, 1, 5, 2}));
    EXPECT_EQ(2, s.maxUncrossedLines({1, 3, 7, 1, 7, 5}, {1, 9, 2, 5, 1}));
}
