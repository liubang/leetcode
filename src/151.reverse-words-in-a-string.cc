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
    std::string reverseWords(const std::string& s) {
        int len = s.length();
        if (len == 0 || len == 1) {
            return s;
        }
        std::string ret;
        int i = 0;
        while (s[i] == ' ' && i < len) {
            i++;
        }
        for (; i < len; ++i) {
            std::string tmp;
            while (s[i] != ' ' && i < len) {
                tmp.push_back(s[i++]);
            }
            if (!tmp.empty()) {
                tmp.push_back(' ');
                ret.insert(0, tmp);
            }
        }
        return ret.erase(ret.find_last_not_of(' ') + 1);
    }
};
} // namespace

TEST(Leetcode, reverse_words_in_a_string) {
    Solution s;
    {
        std::string input = "  hello world!  ";
        std::string exp = "world! hello";
        EXPECT_EQ(exp, s.reverseWords(input));
    }

    {
        std::string input = "a good   example";
        std::string exp = "example good a";
        EXPECT_EQ(exp, s.reverseWords(input));
    }
}
