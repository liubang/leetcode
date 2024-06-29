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

#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    // 这道题目拿到就应该想到双指针
    int findMax(std::vector<int> nums) {
        std::sort(nums.begin(), nums.end());
        int size = static_cast<int>(nums.size());
        if (nums[0] >= 0 || nums[size - 1] <= 0)
            return -1;
        int lidx = 0, ridx = size - 1;
        while (lidx < ridx) {
            int r = nums[ridx];
            while (lidx < ridx && nums[lidx] + r < 0)
                ++lidx;
            if (nums[lidx] + r == 0)
                return r;
            --ridx;
        }
        return -1;
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    {
        std::vector<int> inputs = {-1, 2, -3, 3};
        EXPECT_EQ(3, s.findMax(inputs));
    }

    {
        std::vector<int> inputs = {-1, 10, 6, 7, -7, 1};
        EXPECT_EQ(7, s.findMax(inputs));
    }

    {
        std::vector<int> inputs = {-10, 8, 6, 7, -2, -3};
        EXPECT_EQ(-1, s.findMax(inputs));
    }

    {
        std::vector<int> inputs = {-956, -831, -707};
        EXPECT_EQ(-1, s.findMax(inputs));
    }

    {
        std::vector<int> inputs = {956, 831, 707};
        EXPECT_EQ(-1, s.findMax(inputs));
    }
}
