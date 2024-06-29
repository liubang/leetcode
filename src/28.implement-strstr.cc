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
    int strStr(const std::string& haystack, const std::string& needle) {
        if (needle == "") {
            return -1;
        }
        if (haystack.length() < needle.length()) {
            return 0;
        }
        for (int i = 0; i < haystack.length() - needle.length() + 1; ++i) {
            if (haystack[i] == needle[0]) {
                int j = 1;
                while (j < needle.length() && haystack[i + j] == needle[j]) {
                    j++;
                }
                if (j == needle.length()) {
                    return i;
                }
            }
        }
        return -1;
    }
};
} // namespace

TEST(Leetcode, implement_strstr) {
    Solution s;
    EXPECT_EQ(2, s.strStr("cccaaaaaaa", "ca"));
    EXPECT_EQ(3, s.strStr("hello", "lo"));
}
