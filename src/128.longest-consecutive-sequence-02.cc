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

#include <set>
#include <vector>

namespace {
class Solution {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        int ret = 0;
        int seq = 1;
        int pre = 0;
        bool first = true;
        for (int num : set) {
            if (first) {
                first = false;
            } else {
                if ((num - pre) == 1) {
                    ++seq;
                } else {
                    ret = std::max(ret, seq);
                    seq = 1;
                }
            }
            pre = num;
        }
        return std::max(ret, seq);
    }
};
} // namespace

TEST(Leetcode, longest_consecutive_sequence) {
    Solution s;
    EXPECT_EQ(4, s.longestConsecutive({100, 4, 200, 1, 3, 2}));
    EXPECT_EQ(9, s.longestConsecutive({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}));
    EXPECT_EQ(7, s.longestConsecutive({9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6}));
    EXPECT_EQ(0, s.longestConsecutive({}));
}
