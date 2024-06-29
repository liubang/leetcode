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
    std::string countAndSay(int n) {
        std::string cur = "1";
        if (n == 1) {
            return cur;
        }
        for (int i = 2; i <= n; ++i) {
            std::string tmp;
            for (int j = 0; j < cur.length();) {
                int m = j;
                while (m < cur.length() && cur[m] == cur[j]) {
                    m++;
                }
                tmp.push_back((m - j) + '0');
                tmp.push_back(cur[m - 1]);
                j = m;
            }
            cur = tmp;
        }
        return cur;
    }
};
} // namespace

TEST(Leetcode, count_and_say) {
    Solution s;
    EXPECT_EQ("1", s.countAndSay(1));
    EXPECT_EQ("11", s.countAndSay(2));
    EXPECT_EQ("13211311123113112211", s.countAndSay(10));
}
