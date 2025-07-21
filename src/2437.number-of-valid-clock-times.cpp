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

#include <string>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    int countTime(const std::string& time) {
        int a = 1, b = 1;
        if (time[0] == '?') {
            if (time[1] == '?')
                a = 24; // 00~24
            else if (time[1] > '3')
                a = 2; // eg: 04, 14
            else
                a = 3; // eg: 02, 12, 22
        } else if (time[1] == '?') {
            if (time[0] < '2')
                a = 10;
            else
                a = 4;
        }

        if (time[3] == '?') {
            if (time[4] == '?')
                b = 60; // 00~59
            else
                b = 6; // eg: 01~51
        } else if (time[4] == '?')
            b = 10;

        return a * b;
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_EQ(2, s.countTime("?5:00"));
    EXPECT_EQ(3, s.countTime("?2:00"));
    EXPECT_EQ(12, s.countTime("?5:?0"));
    EXPECT_EQ(18, s.countTime("?2:?0"));
    EXPECT_EQ(100, s.countTime("0?:0?"));
    EXPECT_EQ(1440, s.countTime("??:??"));
}
