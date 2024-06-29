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
    bool isPalindrome(const std::string& s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !std::isalnum(s[i])) {
                i++;
            }
            while (i < j && !std::isalnum(s[j])) {
                j--;
            }
            if (i < j && !equals(s[i++], s[j--])) {
                return false;
            }
        }
        return true;
    }

private:
    bool equals(char a, char b) {
        return (a == b) ||
               (std::isalpha(a) && std::isalpha(b) && std::toupper(a) == std::toupper(b));
    }
};

// this solution is slow
class Solution2 {
public:
    bool isPalindrome(const std::string& s) {
        std::string ns = filterOutNumberAndChar(s);
        return ns == std::string(ns.rbegin(), ns.rend());
    }

private:
    std::string filterOutNumberAndChar(const std::string& s) {
        std::string ns;
        for (char i : s) {
            if (std::isalnum(i)) {
                ns.push_back(static_cast<char>(std::toupper(i)));
            }
        }
        return ns;
    }
};
} // namespace

TEST(Leetcode, valid_palindrome) {
    {
        Solution s;
        EXPECT_TRUE(s.isPalindrome("A man, a plan, a canal: Panama"));
        EXPECT_FALSE(s.isPalindrome("race a car"));
    }

    {
        Solution2 s;
        EXPECT_TRUE(s.isPalindrome("A man, a plan, a canal: Panama"));
        EXPECT_FALSE(s.isPalindrome("race a car"));
    }
}
