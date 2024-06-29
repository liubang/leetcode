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
#include <stack>
#include <string>

namespace {
class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> st;
        for (const char& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // clang-format off
        if (st.empty()) return false;
        if (c == ')' && st.top() != '(') return false;
        if (c == ']' && st.top() != '[') return false;
        if (c == '}' && st.top() != '{') return false;
                // clang-format on
                st.pop();
            }
        }
        return st.empty();
    }
};
} // namespace

TEST(Leetcode, valid_parentheses) {
    Solution s;
    EXPECT_TRUE(s.isValid("()"));
    EXPECT_TRUE(s.isValid("()[]{}"));
    EXPECT_FALSE(s.isValid("(]"));
    EXPECT_FALSE(s.isValid("()}"));
}
