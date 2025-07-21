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

#include <climits>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    int maximumDifference(const std::vector<int>& nums) {
        int minidx = 0;
        int max = INT_MIN;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[minidx] > nums[i]) {
                minidx = i;
            }
            max = std::max(max, nums[i + 1] - nums[minidx]);
        }
        return max <= 0 ? -1 : max;
    }
};
} // namespace

TEST(Leetcode, maximum_difference_between_increasing_elements) {
    Solution s;
    EXPECT_EQ(4, s.maximumDifference({7, 1, 5, 4}));
    EXPECT_EQ(-1, s.maximumDifference({9, 4, 3, 2}));
    EXPECT_EQ(9, s.maximumDifference({1, 5, 2, 10}));
    EXPECT_EQ(-1, s.maximumDifference(
                      {999, 997, 980, 976, 948, 940, 938, 928, 924, 917, 907, 907, 881, 878, 864,
                       862, 859, 857, 848, 840, 824, 824, 824, 805, 802, 798, 788, 777, 775, 766,
                       755, 748, 735, 732, 727, 705, 700, 697, 693, 679, 676, 644, 634, 624, 599,
                       596, 588, 583, 562, 558, 553, 539, 537, 536, 509, 491, 485, 483, 454, 449,
                       438, 425, 403, 368, 345, 327, 287, 285, 270, 263, 255, 248, 235, 234, 224,
                       221, 201, 189, 187, 183, 179, 168, 155, 153, 150, 144, 107, 102, 102, 87,
                       80,  57,  55,  49,  48,  45,  26,  26,  23,  15}));
}
