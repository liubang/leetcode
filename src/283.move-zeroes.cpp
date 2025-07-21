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
    void moveZeroes(std::vector<int>& nums) {
        int s = nums.size();
        for (int i = s - 1; i >= 0; --i) {
            if (nums[i] != 0) {
                continue;
            }
            for (int j = i; j < (s - 1) && nums[j + 1] != 0; ++j) {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
};
} // namespace

TEST(Leetcode, move_zeroes) {
    Solution s;
    {
        std::vector<int> input = {0, 1, 0, 3, 12};
        std::vector<int> output = {1, 3, 12, 0, 0};
        s.moveZeroes(input);
        EXPECT_EQ(output, input);
    }
    {
        std::vector<int> input = {0};
        std::vector<int> output = {0};
        s.moveZeroes(input);
        EXPECT_EQ(output, input);
    }
    {
        std::vector<int> input(100000, 0);
        std::vector<int> output(100000, 0);
        int j = 0;
        for (int i = 0; i < 100000; ++i) {
            if ((i & 1) == 0) {
                input[i] = i;
                if (i != 0) {
                    output[j++] = i;
                }
            }
        }
        s.moveZeroes(input);
        EXPECT_EQ(output, input);
    }
}
