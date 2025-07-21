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

namespace {
class Solution {
public:
    std::string intToRoman(int num) {
        std::pair<int, std::string> value_symbols[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"},
            {40, "XL"},  {10, "X"},   {9, "IX"},  {5, "V"},    {4, "IV"},  {1, "I"},
        };
        std::string ret;
        for (const auto& [value, symbol] : value_symbols) {
            while (num >= value) {
                num -= value;
                ret += symbol;
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, integer_to_roman) {
    Solution s;
    EXPECT_EQ("MXXIV", s.intToRoman(1024));
    EXPECT_EQ("MMCCXIII", s.intToRoman(2213));
    EXPECT_EQ("MCCXXXIV", s.intToRoman(1234));
}
