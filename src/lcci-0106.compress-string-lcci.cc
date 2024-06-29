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
    std::string compressString(const std::string& S) {
        int len = S.length();
        if (len <= 1) {
            return S;
        }
        std::string ret;
        char pre = S[0];
        int count = 1;
        for (int i = 1; i < len; ++i) {
            if (S[i] != pre) {
                ret.push_back(pre);
                ret.append(std::to_string(count));
                pre = S[i];
                count = 1;
            } else {
                count++;
            }
        }
        ret.push_back(pre);
        ret.append(std::to_string(count));
        return ret.length() < len ? ret : S;
    }
};
} // namespace

TEST(Leetcode, compress_string_lcci) {
    Solution s;
    EXPECT_EQ("a2b1c5a3", s.compressString("aabcccccaaa"));
    EXPECT_EQ("abbccd", s.compressString("abbccd"));
}
