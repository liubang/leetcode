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

#include <algorithm>
#include <vector>

namespace {
class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int ret = 1;
        for (auto num : nums) {
            if (num <= 0) {
                continue;
            }
            if (num == ret) {
                ret++;
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, first_missing_positive) {
    Solution s;

    {
        std::vector<int> inputs = {0, 2, 2, 1, 1};
        EXPECT_EQ(3, s.firstMissingPositive(inputs));
    }

    {
        std::vector<int> inputs = {3, 4, -1, 1};
        EXPECT_EQ(2, s.firstMissingPositive(inputs));
    }
}
