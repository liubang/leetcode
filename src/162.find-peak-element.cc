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
    int findPeakElement(const std::vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        while (s < e) {
            int m = (s + e) / 2;
            if (nums[m] > nums[m + 1]) {
                e = m;
            } else {
                s = m + 1;
            }
        }
        return s;
    }
};
} // namespace

TEST(Leetcode, find_peak_element) {
    Solution s;
    EXPECT_EQ(2, s.findPeakElement({1, 2, 3, 1}));
    EXPECT_EQ(1, s.findPeakElement({1, 2, 1}));
    EXPECT_EQ(0, s.findPeakElement({1}));
    EXPECT_EQ(1, s.findPeakElement({1, 2}));
}
