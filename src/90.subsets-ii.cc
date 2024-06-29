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
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        // 先排序
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ret;
        dfs(&ret, nums, 0);
        return ret;
    }

private:
    void dfs(std::vector<std::vector<int>>* ret, const std::vector<int>& nums, int s) {
        ret->push_back(row_);
        for (int i = s; i < nums.size(); ++i) {
            // 去重
            if (i != s && nums[i] == nums[i - 1]) {
                continue;
            }
            row_.push_back(nums[i]);
            // 从i继续往下搜索
            dfs(ret, nums, i + 1);
            // 回溯
            row_.pop_back();
        }
    }

private:
    std::vector<int> row_;
};
} // namespace

TEST(Leetcode, subsets_ii) {
    Solution s;
    {
        std::vector<std::vector<int>> exp = {{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}};
        std::vector<int> input = {1, 2, 2};
        EXPECT_EQ(exp, s.subsetsWithDup(input));
    }
    {
        std::vector<std::vector<int>> exp = {{}, {0}};
        std::vector<int> input = {0};
        EXPECT_EQ(exp, s.subsetsWithDup(input));
    }
}
