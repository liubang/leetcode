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
    std::string longestPalindrome(const std::string& s) {
        auto len = s.length();
        if (len == 1 || (len == 2 && s[0] == s[1]))
            return s;
        int left = 0, right = 0;
        // 直接暴力求解
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (isPalindrome(s, i, j) && (j - i) > (right - left)) {
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left, right - left + 1);
    }

private:
    bool isPalindrome(const std::string& s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
} // namespace

TEST(Leetcode, longest_palindromic_substring) {
    Solution s;
    EXPECT_EQ("bab", s.longestPalindrome("babad"));
    EXPECT_EQ("bb", s.longestPalindrome("cbbd"));
    EXPECT_EQ("a", s.longestPalindrome("abcdt"));
    EXPECT_EQ("aa", s.longestPalindrome("aa"));
}
