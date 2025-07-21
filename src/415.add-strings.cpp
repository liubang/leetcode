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

#include <cstddef>
#include <string>

namespace {
class Solution {
public:
    std::string addStrings(const std::string& num1, const std::string& num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int sum = 0;
        std::string ret;
        while (i >= 0 || j >= 0 || sum > 0) {
            if (i >= 0) {
                sum += num1[i--] - '0';
            }
            if (j >= 0) {
                sum += num2[j--] - '0';
            }
            ret = ret.insert(static_cast<size_t>(0), 1, sum % 10 + '0');
            sum /= 10;
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, add_strings) {
    Solution s;

    EXPECT_EQ("2", s.addStrings("1", "1"));
    EXPECT_EQ("1586", s.addStrings("999", "587"));
    EXPECT_EQ(
        "1587587587587587587587587587587586",
        s.addStrings("999999999999999999999999999999999", "587587587587587587587587587587587"));
}
