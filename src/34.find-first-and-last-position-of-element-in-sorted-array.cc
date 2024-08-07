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
    std::vector<int> searchRange(const std::vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0 || target < nums[0] || target > nums[len - 1]) {
            return {-1, -1};
        }
        int st = 0, ed = len - 1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (nums[mid] == target) {
                int i = mid;
                while (i >= 0 && nums[i] == target) {
                    i--;
                }
                int j = mid + 1;
                while (j < len && nums[j] == target) {
                    j++;
                }
                return {i + 1, j - 1};
            } else if (nums[mid] > target) {
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return {-1, -1};
    }
};
} // namespace

TEST(Leetcode, find_first_and_last_position_of_element_in_sorted_array) {
    Solution s;
    {
        std::vector<int> exp = {3, 4};
        EXPECT_EQ(exp, s.searchRange({5, 7, 7, 8, 8, 10}, 8));
    }
    {
        std::vector<int> exp = {-1, -1};
        EXPECT_EQ(exp, s.searchRange({5, 7, 7, 8, 8, 10}, 6));
    }
    {
        std::vector<int> exp = {0, 0};
        EXPECT_EQ(exp, s.searchRange({1}, 1));
    }
}
