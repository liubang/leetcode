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
#include <string>

namespace {
class Solution {
public:
    int myAtoi(const std::string& s) {
        if (s.empty()) {
            return 0;
        }
        int ret = 0, sign = 1;
        int boundary = INT_MAX / 10;
        int len = s.length(), i = 0;
        // 跳过开头的空格
        while (s[i] == ' ' && i < len) {
            i++;
        }
        // 符号位
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        // 数字位
        while (std::isdigit(s[i]) && i < len) {
            if (ret > boundary || (ret == boundary && s[i] > '7')) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ret = ret * 10 + (s[i] - '0');
            i++;
        }
        return ret * sign;
    }
};
} // namespace

TEST(Leetcode, string_to_integer_atoi) {
    Solution s;
    EXPECT_EQ(42, s.myAtoi("42"));
    EXPECT_EQ(42, s.myAtoi("  42"));
    EXPECT_EQ(-42, s.myAtoi(" -42"));
    EXPECT_EQ(4193, s.myAtoi("4193 with words"));
    EXPECT_EQ(0, s.myAtoi("words and 987"));
    EXPECT_EQ(-2147483648, s.myAtoi("-91283472332"));
}
