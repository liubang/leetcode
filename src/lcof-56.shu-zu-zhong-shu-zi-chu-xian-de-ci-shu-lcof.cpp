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
    std::vector<int> singleNumbers(const std::vector<int>& nums) {
        int ret = 0;
        for (auto num : nums) {
            ret ^= num;
        }
        int a = 0, b = 0;
        int mask = ret & (-ret);
        for (auto num : nums) {
            if (num & mask) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return {a, b};
    }
};
} // namespace

TEST(Leetcode, shu_zu_zhong_shu_zi_chu_xian_de_ci_shu_lcof) {
    Solution s;
    {
        auto ret = s.singleNumbers({1, 2, 10, 4, 1, 4, 3, 3});
        EXPECT_TRUE(ret[0] == 10 || ret[0] == 2);
        EXPECT_TRUE(ret[1] == 10 || ret[1] == 2);
    }
    {
        auto ret = s.singleNumbers({4, 1, 4, 6});
        EXPECT_TRUE(ret[0] == 1 || ret[0] == 6);
        EXPECT_TRUE(ret[1] == 1 || ret[1] == 6);
    }
}
