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

#include <queue>
#include <stack>
#include <string>

namespace {
class Solution {
public:
    std::string reverseParentheses(const std::string& s) {
        if (s.empty())
            return s;
        std::stack<char> stk;
        std::queue<char> queue;
        for (char c : s) {
            if (c != ')') {
                stk.push(c);
            } else {
                while (!stk.empty() && stk.top() != '(') {
                    queue.push(stk.top());
                    stk.pop();
                }
                // pop char '('
                if (!stk.empty())
                    stk.pop();
                while (!queue.empty()) {
                    stk.push(queue.front());
                    queue.pop();
                }
            }
        }
        std::string ret;
        while (!stk.empty()) {
            ret.insert(ret.begin(), stk.top());
            stk.pop();
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, reverse_substrings_between_each_pair_of_parentheses) {
    Solution s;
    EXPECT_EQ("dcba", s.reverseParentheses("(abcd)"));
    EXPECT_EQ("iloveu", s.reverseParentheses("(u(love)i)"));
    EXPECT_EQ("leetcode", s.reverseParentheses("(ed(et(oc))el)"));
    EXPECT_EQ("apmnolkjihgfedcbq", s.reverseParentheses("a(bcdefghijkl(mno)p)q"));
}
