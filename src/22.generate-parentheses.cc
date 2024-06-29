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
#include <vector>

namespace {
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ret;
        std::string str;
        gen(ret, str, 0, 0, n);
        return ret;
    }

private:
    void gen(std::vector<std::string>& ret, std::string& str, int open, int close, int n) {
        if (static_cast<int>(str.length()) == (n * 2)) {
            std::string s = str;
            ret.emplace_back(std::move(s));
            return;
        }

        if (open < n) {
            str.push_back('(');
            gen(ret, str, open + 1, close, n);
            str.pop_back();
        }

        if (close < open) {
            str.push_back(')');
            gen(ret, str, open, close + 1, n);
            str.pop_back();
        }
    }
};
} // namespace

TEST(Leetcode, generate_parentheses) {
    Solution s;
    {
        std::vector<std::string> exps = {
            "((()))", "(()())", "(())()", "()(())", "()()()",
        };
        EXPECT_EQ(exps, s.generateParenthesis(3));
    }

    {
        std::vector<std::string> exps = {"()"};
        EXPECT_EQ(exps, s.generateParenthesis(1));
    }
}
