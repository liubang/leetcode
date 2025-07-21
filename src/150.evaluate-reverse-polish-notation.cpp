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
#include <unordered_set>
#include <vector>

namespace {
class Solution {
public:
    int evalRPN(const std::vector<std::string>& tokens) {
        std::stack<int> stk;
        const std::unordered_set<std::string> operators = {"+", "-", "*", "/"};
        for (auto& token : tokens) {
            if (operators.count(token) > 0) {
                if (stk.size() < 2) {
                    return 0;
                }
                int rhs = stk.top();
                stk.pop();
                int lhs = stk.top();
                stk.pop();
                if (token == "+") {
                    stk.push(lhs + rhs);
                } else if (token == "-") {
                    stk.push(lhs - rhs);
                } else if (token == "*") {
                    stk.push(lhs * rhs);
                } else if (token == "/") {
                    stk.push(lhs / rhs);
                }
            } else {
                stk.push(std::stoi(token));
            }
        }
        if (stk.size() != 1) {
            return 0;
        }
        return stk.top();
    }
};
} // namespace

TEST(Leetcode, evaluate_reverse_polish_notation) {
    Solution s;
    EXPECT_EQ(9, s.evalRPN({"2", "1", "+", "3", "*"}));
    EXPECT_EQ(6, s.evalRPN({"4", "13", "5", "/", "+"}));
    EXPECT_EQ(22, s.evalRPN({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}));
}
