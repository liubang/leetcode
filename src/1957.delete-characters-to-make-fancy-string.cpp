// Copyright (c) 2025 The Authors. All rights reserved.
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

// @leet imports start
#include <gtest/gtest.h>
#include <string>
namespace {
// @leet imports end

// @leet start
class Solution {
public:
    std::string makeFancyString(const std::string& s) {
        std::string result;
        char c = s[0];
        int count = 1;
        result.append(1, c);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != c) {
                result.append(1, s[i]);
                c = s[i];
                count = 1;
            } else if (++count < 3) {
                result.append(1, s[i]);
            }
        }
        return result;
    }
};
// @leet end

} // namespace
TEST(Leetcode, aaa) {
    Solution s;
    EXPECT_EQ("leetcode", s.makeFancyString("leeetcode"));
    EXPECT_EQ("aabaa", s.makeFancyString("aaabaaaa"));
    EXPECT_EQ("aab", s.makeFancyString("aab"));
}
