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
    int calculateMinHP(const std::vector<std::vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        for (int i = (m - 1); i >= 0; --i) {
            for (int j = (n - 1); j >= 0; --j) {
                if (i == (m - 1) && j == (n - 1)) {
                    dp[i][j] = std::max(1, 1 - dungeon[i][j]);
                } else if (i == (m - 1)) {
                    dp[i][j] = std::max(1, dp[i][j + 1] - dungeon[i][j]);
                } else if (j == (n - 1)) {
                    dp[i][j] = std::max(1, dp[i + 1][j] - dungeon[i][j]);
                } else {
                    dp[i][j] = std::max(1, std::min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};
} // namespace

TEST(Leetcode, dungeon_game) {
    Solution s;
    EXPECT_EQ(7, s.calculateMinHP({{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}}));
    EXPECT_EQ(3, s.calculateMinHP({{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}}));
    EXPECT_EQ(1, s.calculateMinHP({{0}}));
}
