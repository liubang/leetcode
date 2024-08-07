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
    int countTriplets(const std::vector<int>& nums) {
        std::vector<int> dp;
        int tmp = 0;
        for (auto num : nums) {
            tmp ^= num;
            dp.push_back(tmp);
        }
        int size = nums.size(), ret = 0;
        for (int i = 0; i < size - 1; ++i) {
            for (int k = i + 1; k < size; ++k) {
                for (int j = i + 1; j <= k; ++j) {
                    if (i == 0 && (dp[j - 1] == (dp[k] ^ dp[j - 1]))) {
                        ret++;
                    } else if (i > 0 && ((dp[j - 1] ^ dp[i - 1]) == (dp[k] ^ dp[j - 1]))) {
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, count_triplets_that_can_form_two_arrays_of_equal_xor) {
    Solution s;
    EXPECT_EQ(4, s.countTriplets({2, 3, 1, 6, 7}));
    EXPECT_EQ(10, s.countTriplets({1, 1, 1, 1, 1}));
    EXPECT_EQ(0, s.countTriplets({2, 3}));
    EXPECT_EQ(3, s.countTriplets({1, 3, 5, 7, 9}));
    EXPECT_EQ(8, s.countTriplets({7, 11, 12, 9, 5, 2, 7, 17, 22}));
}
