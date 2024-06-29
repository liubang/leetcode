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

#include <string>
#include <vector>

namespace {
class Solution {
public:
    int longestCommonSubsequence(const std::string& text1, const std::string& text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));
        int ret = 0;
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (dp[i][j] > ret) {
                    ret = dp[i][j];
                }
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, longest_common_subsequence) {
    Solution s;
    EXPECT_EQ(3, s.longestCommonSubsequence("abcde", "ace"));
    EXPECT_EQ(3, s.longestCommonSubsequence("abc", "abc"));
    EXPECT_EQ(0, s.longestCommonSubsequence("abc", "def"));
}
