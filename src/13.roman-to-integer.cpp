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

#include <map>
#include <string>

namespace {
class Solution {
public:
    int romanToInt(const std::string& s) {
        std::pair<std::string, int> pairs[] = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50},
            {"XL", 40},  {"X", 10},   {"IX", 9},  {"V", 5},    {"IV", 4},  {"I", 1},
        };
        int ret = 0, idx = 0;
        for (const auto& [symbol, num] : pairs) {
            while (idx < s.length() && s.find(symbol, idx) == idx) {
                ret += num;
                idx += symbol.length();
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, roman_to_integer) {
    Solution s;
    EXPECT_EQ(2994, s.romanToInt("MMCMXCIV"));
    EXPECT_EQ(1994, s.romanToInt("MCMXCIV"));
    EXPECT_EQ(58, s.romanToInt("LVIII"));
}
