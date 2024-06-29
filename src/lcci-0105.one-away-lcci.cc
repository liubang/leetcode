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

#include <string>

namespace {
class Solution {
public:
    bool oneEditAway(const std::string& first, const std::string& second) {
        int len1 = first.length();
        int len2 = second.length();
        if (std::abs(len1 - len2) > 1) {
            return false;
        }
        // 如果len1 == len2，只考虑替换
        if (len1 == len2) {
            int diff = 0;
            for (int i = 0; i < len1; ++i) {
                if (first[i] != second[i]) {
                    diff++;
                }
                if (diff > 1) {
                    return false;
                }
            }
            return true;
        }
        // 如果len1 < len2，只考虑插入
        if (len1 < len2) {
            int skip = 0;
            for (int i = 0, j = 0; i < len1 && j < len2;) {
                if (first[i] != second[j]) {
                    skip++;
                    j++;
                } else {
                    i++;
                    j++;
                }
                if (skip > 1) {
                    return false;
                }
            }
            return true;
        }

        // 如果len1 > len2，只考虑删除
        // 删除可以认为是second -> first的插入
        if (len1 > len2) {
            return oneEditAway(second, first);
        }
        return true;
    }
};
} // namespace

TEST(Leetcode, one_way_lcci) {
    Solution s;
    EXPECT_TRUE(s.oneEditAway("pale", "ple"));
    EXPECT_FALSE(s.oneEditAway("pales", "pal"));
    EXPECT_TRUE(s.oneEditAway("horse", "horae"));
}
