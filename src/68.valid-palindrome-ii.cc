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
    bool validPalindrome(const std::string& str) { return valid(str, 0, str.length() - 1, true); }

private:
    bool valid(const std::string& str, int s, int e, bool canDelete) {
        while (s < e) {
            if (str[s] != str[e]) {
                if (!canDelete) {
                    return false;
                }
                return valid(str, s + 1, e, false) || valid(str, s, e - 1, false);
            }
            s++;
            e--;
        }
        return true;
    }
};
} // namespace

TEST(Leetcode, valid_palindrome_ii) {
    Solution s;
    EXPECT_TRUE(
        s.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymd"
                          "jgpfdhooxfuupuculmgmqfvnbgtapekouga"));
    EXPECT_FALSE(s.validPalindrome("abcda"));
}
