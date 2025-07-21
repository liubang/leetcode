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
#include <set>
#include <vector>

namespace {
class Solution {
public:
    bool isStraight(const std::vector<int>& nums) {
        if (nums.size() != 5) {
            return true;
        }
        std::set<int> ss;
        int min = 14;
        int max = 0;
        for (auto num : nums) {
            if (num == 0) {
                continue;
            }
            if (ss.find(num) != ss.end()) {
                return false;
            }
            ss.insert(num);
            max = std::max(max, num);
            min = std::min(min, num);
        }
        return max - min < 5;
    }
};
} // namespace

TEST(Leetcode, bu_ke_pai_zhong_de_shu_zi_lcof) {
    Solution s;
    EXPECT_TRUE(s.isStraight({1, 2, 3, 4, 5}));
    EXPECT_TRUE(s.isStraight({0, 0, 1, 2, 5}));
    EXPECT_FALSE(s.isStraight({1, 2, 3, 7, 4}));
}
