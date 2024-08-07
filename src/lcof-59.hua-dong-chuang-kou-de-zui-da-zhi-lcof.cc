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

#include <climits>
#include <vector>

namespace {
class Solution {
public:
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
        if (nums.empty()) {
            return {};
        }
        int pre = INT_MIN, i = 0;
        for (; i < k; ++i) {
            pre = std::max(pre, nums[i]);
        }
        std::vector<int> ret;
        ret.push_back(pre);
        for (; i < nums.size(); ++i) {
            if (nums[i] >= pre) {
                ret.push_back(nums[i]);
                pre = nums[i];
            } else if (nums[i - k] == pre) {
                int tmp = INT_MIN;
                for (int j = i - k + 1; j <= i; ++j) {
                    tmp = std::max(tmp, nums[j]);
                }
                ret.push_back(tmp);
                pre = tmp;
            } else {
                ret.push_back(pre);
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, hua_dong_chuang_kou_de_zui_da_zhi_lcof) {
    Solution s;
    auto ret = s.maxSlidingWindow({1, 3, -1, -3, 5, 3, 6, 7}, 3);
    std::vector<int> exp = {3, 3, 5, 5, 6, 7};
    EXPECT_EQ(exp, ret);
}
