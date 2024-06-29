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
    int minMoves(const std::vector<int>& nums) {
        auto po = std::min_element(nums.begin(), nums.end());
        int ret = 0;
        for (auto num : nums) {
            ret += num - *po;
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, minimum_moves_to_equal_array_elements) {
    Solution s;
    {
        std::vector<int> input = {1, 2, 3};
        auto ret = s.minMoves(input);
        EXPECT_EQ(3, ret);
    }
    {
        std::vector<int> input = {6, 2, 3, 10};
        auto ret = s.minMoves(input);
        EXPECT_EQ(13, ret);
    }
}
