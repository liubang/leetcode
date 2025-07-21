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
constexpr int MOD = 1E9 + 7;
class Solution {
public:
    int numWays(int arrLen, int steps) {
        // 能够到达的最大下标位置
        int maxcol = std::min(arrLen - 1, steps);
        // dp[i][j] 表示执行i步到达j位置的方案数
        // dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1] + dp[i - 1][j - 1];
        std::vector<std::vector<int>> dp(steps + 1, std::vector<int>(maxcol + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; ++i) {
            for (int j = 0; j <= maxcol; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
                if (j + 1 <= maxcol) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }
            }
        }
        return dp[steps][0];
    }
};
} // namespace

TEST(Leetcode, number_of_ways_to_stay_in_the_same_place_after_some_steps) {
    Solution s;
    EXPECT_EQ(4, s.numWays(2, 3));
    EXPECT_EQ(2, s.numWays(4, 2));
}
