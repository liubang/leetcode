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

#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    std::string convert(const std::string& s, int numRows) {
        if (numRows < 2)
            return s;
        std::vector<std::string> vecs(numRows, "");
        int row = 0;
        int flag = -1;
        for (char i : s) {
            if (row == 0 || row == numRows - 1)
                flag = -flag;
            vecs[row].append(1, i);
            row += flag;
        }
        std::string ret;
        for (const auto& str : vecs) {
            ret += str;
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, zigzag_conversion) {
    Solution s;
    EXPECT_EQ("PAYPALISHIRING", s.convert("PAYPALISHIRING", 1));
    EXPECT_EQ("PAHNAPLSIIGYIR", s.convert("PAYPALISHIRING", 3));
    EXPECT_EQ("PINALSIGYAHRPI", s.convert("PAYPALISHIRING", 4));
}
