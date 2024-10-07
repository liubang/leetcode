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
    // 方法一: 暴力法
    int maxArea1(const std::vector<int>& height) {
        int s = height.size();
        int ret = 0;
        for (int i = 0; i < s - 1; ++i) {
            for (int j = i + 1; j < s; ++j) {
                ret = std::max(ret, (j - i) * std::min(height[i], height[j]));
            }
        }
        return ret;
    }

    // 方法二：双指针
    int maxArea2(const std::vector<int>& height) {
        int ret = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            ret = std::max(ret, (r - l) * std::min(height[l], height[r]));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, container_with_mose_water) {
    Solution s;
    EXPECT_EQ(49, s.maxArea1({1, 8, 6, 2, 5, 4, 8, 3, 7}));
    EXPECT_EQ(49, s.maxArea2({1, 8, 6, 2, 5, 4, 8, 3, 7}));

    EXPECT_EQ(1, s.maxArea1({1, 1}));
    EXPECT_EQ(1, s.maxArea2({1, 1}));
}
