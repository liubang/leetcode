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

// @leet imports start
#include <climits>
#include <gtest/gtest.h>
#include <numeric>
#include <unordered_set>
#include <vector>
// @leet imports end

namespace {

// @leet start
class Solution {
public:
    int maxSum(const std::vector<int>& nums) {
        std::unordered_set<int> positive;
        int maxEle = INT_MIN;
        for (auto& num : nums) {
            if (num > 0) {
                positive.insert(num);
            }
            maxEle = std::max(maxEle, num);
        }
        if (positive.empty()) {
            return maxEle;
        }
        return std::accumulate(positive.begin(), positive.end(), 0);
    }
};
// @leet end

} // namespace
TEST(Leetcode, maximum_unique_subarray_sum_after_deletion) {
    Solution s;
    EXPECT_EQ(15, s.maxSum({1, 2, 3, 4, 5}));
    EXPECT_EQ(1, s.maxSum({1, 1, 0, 1, 1}));
    EXPECT_EQ(3, s.maxSum({1, 2, -1, -2, 1, 0, -1}));
}
