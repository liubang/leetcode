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
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        dfs(&ret, nums, 0, nums.size() - 1);
        return ret;
    }

private:
    void dfs(std::vector<std::vector<int>>* ret, std::vector<int>& nums, int start, int end) {
        if (start == end) {
            ret->emplace_back(nums.begin(), nums.end());
        } else {
            for (int i = start; i <= end; ++i) {
                std::swap(nums[start], nums[i]);
                dfs(ret, nums, start + 1, end);
                std::swap(nums[start], nums[i]);
            }
        }
    }
};
} // namespace

TEST(Leetcode, permutations) {
    Solution s;
    std::vector<int> input = {1, 2, 3};
    std::vector<std::vector<int>> exp = {
        {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 2, 1}, {3, 1, 2},
    };
    EXPECT_EQ(exp, s.permute(input));
}
