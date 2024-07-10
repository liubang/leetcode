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
    int incremovableSubarrayCount(const std::vector<int>& nums) {
        std::size_t len = nums.size();
        if (len <= 1) {
            return 1;
        }
        int ret = 0;
        auto check = [&nums](int l, int r) -> bool {
            std::size_t len = nums.size();
            for (int i = 0; i < len - 1; ++i) {
                if (i >= l - 1 && i <= r) {
                    continue;
                }
                if (nums[i] >= nums[i + 1]) {
                    return false;
                }
            }
            if (l > 0 && r < len - 1 && nums[l - 1] >= nums[r + 1]) {
                return false;
            }
            return true;
        };
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                if (check(i, j)) {
                    ++ret;
                }
            }
        }
        return ret;
    }
};

TEST(Leetcode, count_the_number_of_incremovable_subarrays_i) {
    Solution s;
    EXPECT_EQ(10, s.incremovableSubarrayCount({1, 2, 3, 4}));
    EXPECT_EQ(7, s.incremovableSubarrayCount({6, 5, 7, 8}));
    EXPECT_EQ(3, s.incremovableSubarrayCount({8, 7, 6, 6}));
    EXPECT_EQ(1, s.incremovableSubarrayCount({8}));
    EXPECT_EQ(1, s.incremovableSubarrayCount({}));
}

} // namespace
