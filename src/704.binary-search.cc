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
    int search(const std::vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0 || target < nums[0] || target > nums[size - 1]) {
            return false;
        }
        int st = 0, ed = size - 1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return -1;
    }
};
} // namespace

TEST(Leetcode, binary_search) {
    Solution s;
    EXPECT_EQ(4, s.search({1, 0, 3, 5, 9, 12}, 9));
    EXPECT_EQ(-1, s.search({1, 0, 3, 5, 9, 12}, 2));
}
