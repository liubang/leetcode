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

#include <numeric>
#include <string>
#include <vector>

namespace {
class Solution {
public:
    int calculate(const std::string& s) {
        int len = s.length(), num = 0;
        char sign = '+';
        std::vector<int> vec;
        for (int i = 0; i < len; ++i) {
            if (std::isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if ((!std::isdigit(s[i]) && s[i] != ' ') || i == len - 1) {
                switch (sign) {
                case '+':
                    vec.push_back(num);
                    break;
                case '-':
                    vec.push_back(-num);
                    break;
                case '*':
                    vec.back() *= num;
                    break;
                case '/':
                    vec.back() /= num;
                    break;
                }
                num = 0;
                sign = s[i];
            }
        }
        return std::accumulate(vec.begin(), vec.end(), 0);
    }
};
} // namespace

TEST(Leetcode, basic_calculator_ii) {
    Solution s;
    EXPECT_EQ(7, s.calculate("3+2*2"));
    EXPECT_EQ(1, s.calculate("3 / 2 "));
    EXPECT_EQ(5, s.calculate(" 3+5 / 2 "));
}
