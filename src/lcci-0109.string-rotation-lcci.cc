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
    bool isFlipedString(const std::string& s1, const std::string& s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        std::string s = s1 + s1;
        return s.find(s2) != std::string::npos;
    }
};
} // namespace

TEST(Leetcode, string_rotation_lcci) {
    Solution s;
    EXPECT_TRUE(s.isFlipedString("waterbottle", "erbottlewat"));
    EXPECT_FALSE(s.isFlipedString("aa", "abc"));
}
