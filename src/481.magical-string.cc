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
    int magicalString(int n) {
        if (n == 0) {
            return 0;
        }
        if (n < 3) {
            return 1;
        }
        // i 是group指针，j是字符串尾部指针
        // 外层循环控制分组，内层循环构造当前字符串
        int i = 2, j = 3, ret = 1;
        std::string str = "122";
        while (j < n) {
            int times = str[i] - '0';
            while (j < n && times > 0) {
                if (i % 2 == 0) {
                    str.push_back('1');
                    ret++;
                } else {
                    str.push_back('2');
                }
                times--;
                j++;
            }
            i++;
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, magical_string) {
    Solution s;
    EXPECT_EQ(0, s.magicalString(0));
    EXPECT_EQ(3, s.magicalString(6));
    EXPECT_EQ(5, s.magicalString(10));
    EXPECT_EQ(49, s.magicalString(100));
}
