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
    int findLength(const std::vector<int>& A, const std::vector<int>& B) {
        int m = A.size();
        int n = B.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        int ret = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
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

TEST(Leetcode, maximum_length_of_repeated_subarray) {
    Solution s;
    EXPECT_EQ(3, s.findLength({1, 2, 3, 2, 1}, {3, 2, 1, 4, 7}));
}
