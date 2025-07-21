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
#include <gtest/gtest.h>

#include <climits>
#include <vector>

namespace {
class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return;
        }
        int i = size - 2;
        for (; i >= 0; --i) {
            int idx = -1, max = INT_MAX;
            for (int j = i + 1; j < size; ++j) {
                if (nums[j] > nums[i]) {
                    if (max > nums[j]) {
                        idx = j;
                        max = nums[j];
                    }
                }
            }
            if (idx != -1) {
                std::swap(nums[i], nums[idx]);
                break;
            }
        }
        std::sort(nums.begin() + i + 1, nums.end());
    }
};
} // namespace

TEST(Leetcode, next_permutation) {
    Solution s;
    {
        std::vector<int> inputs = {1, 2, 3};
        std::vector<int> exps = {1, 3, 2};
        s.nextPermutation(inputs);
        EXPECT_EQ(exps, inputs);
    }

    {
        std::vector<int> inputs = {2, 5, 4, 3, 1};
        std::vector<int> exps = {3, 1, 2, 4, 5};
        s.nextPermutation(inputs);
        EXPECT_EQ(exps, inputs);
    }
}
