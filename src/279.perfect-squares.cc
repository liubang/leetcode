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

#include <climits>
#include <vector>

#include <gtest/gtest.h>

namespace {
/**
 * 这是一道典型的完全背包的问题，完全背包跟01背包的区别在于，完全背包中元素可重复
 * 因此在选择元素的时候，需要遍历寻找最优值
 *
 * 设dp[i]表示和为i的完全平方数的最少个数，那么dp[i]的递推公式为 dp[i] =
 * min(dp[i - 1*1], dp[i - 2 * 2], dp[i - j * j]) + 1; for(j = 1; j*j <= i; ++j)
 * 其中 j >= 1, j*j <= i;
 *
 * 清楚了递推公式，代码就非常简单了。
 */
class Solution {
public:
    int numSquares(int n) {
        std::vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int min = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                min = std::min(min, dp[i - j * j]);
            }
            dp[i] = min + 1;
        }
        return dp[n];
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_EQ(3, s.numSquares(12));
    EXPECT_EQ(2, s.numSquares(13));
    EXPECT_EQ(3, s.numSquares(14));
    EXPECT_EQ(4, s.numSquares(15));
}
