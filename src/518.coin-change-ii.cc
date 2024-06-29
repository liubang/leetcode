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

#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    int change(int amount, const std::vector<int>& coins) {
        std::vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;

    EXPECT_EQ(4, s.change(5, {1, 2, 5}));
    EXPECT_EQ(0, s.change(3, {2}));
    EXPECT_EQ(1, s.change(10, {10}));
}
