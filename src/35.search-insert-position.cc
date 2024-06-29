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
    int searchInsert(const std::vector<int>& nums, int target) {
        if (nums.empty() || nums[0] > target) {
            return 0;
        }
        int size = nums.size();
        if (nums[size - 1] < target) {
            return size;
        }
        int s = 0, e = size - 1;
        while (s < e) {
            int m = (s + e) / 2;
            if (nums[m] == target) {
                return m;
            } else if (target > nums[m]) {
                s = m + 1;
            } else {
                e = m;
            }
        }
        return s;
    }
};
} // namespace

TEST(Leetcode, search_insert_position) {
    Solution s;
    EXPECT_EQ(3, s.searchInsert({1, 3, 5, 8}, 7));
    EXPECT_EQ(0, s.searchInsert({1, 3, 5, 8}, 0));
    EXPECT_EQ(4, s.searchInsert({1, 3, 5, 8}, 10));
}
