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
    int maxProfit(const std::vector<int>& prices) {
        int size = prices.size();
        int ret = 0;
        for (int i = 1; i < size; ++i) {
            if (prices[i] > prices[i - 1]) {
                ret += prices[i] - prices[i - 1];
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, best_time_to_buy_and_sell_stock_ii) {
    Solution s;
    EXPECT_EQ(7, s.maxProfit({7, 1, 5, 3, 6, 4}));
    EXPECT_EQ(4, s.maxProfit({1, 2, 3, 4, 5}));
    EXPECT_EQ(0, s.maxProfit({7, 6, 4, 3, 1}));
    EXPECT_EQ(0, s.maxProfit({3, 3}));
}
