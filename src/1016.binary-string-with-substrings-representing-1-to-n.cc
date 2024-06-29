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


#include <bitset>
#include <string>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    bool queryString(const std::string& s, int n) {
        for (int i = 1; i <= n; ++i) {
            std::bitset<32> bits(i);
            std::string str = bits.to_string();
            str = str.substr(str.find_first_not_of('0'));
            if (s.find(str) == std::string::npos)
                return false;
        }
        return true;
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_TRUE(s.queryString("0110", 3));
    EXPECT_FALSE(s.queryString("0110", 4));
    EXPECT_FALSE(s.queryString("01101110001", 129));
}
