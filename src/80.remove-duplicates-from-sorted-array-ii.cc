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
    int removeDuplicates(std::vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (len < 2 || nums[i] != nums[len - 2]) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};
} // namespace

TEST(Leetcode, remove_duplicates_from_sorted_array_ii) {
    Solution s;
    {
        std::vector<int> inputs = {1, 1, 1, 2, 2, 3};
        std::vector<int> exp = {1, 1, 2, 2, 3};
        int ret = s.removeDuplicates(inputs);
        EXPECT_EQ(5, ret);
        for (int i = 0; i < ret; ++i) {
            EXPECT_EQ(exp[i], inputs[i]);
        }
    }

    {
        std::vector<int> inputs = {0, 0, 1, 1, 1, 1, 2, 3, 3};
        std::vector<int> exp = {0, 0, 1, 1, 2, 3, 3};
        int ret = s.removeDuplicates(inputs);
        EXPECT_EQ(7, ret);
        for (int i = 0; i < ret; ++i) {
            EXPECT_EQ(exp[i], inputs[i]);
        }
    }
}
