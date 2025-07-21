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
    int longestValidParentheses(const std::string& s) {
        std::stack<int> stack;
        stack.push(-1);
        int ret = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    ret = std::max(ret, i - stack.top());
                }
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, longest_valid_parentheses) {
    Solution s;
    EXPECT_EQ(s.longestValidParentheses(")(()(()(((())(((((()()))((((()()(()()())())"
                                        "())()))()()()())(())()()(((()))))()((()))(("
                                        "(())()((()()())((())))(())))())((()())()()("
                                        "(()((())))))((()(((((()((()))(()()(())))((("
                                        ")))()))())"),
              132);
    EXPECT_EQ(4, s.longestValidParentheses(")()())"));
}
