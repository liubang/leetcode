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
    int titleToNumber(const std::string& columnTitle) {
        int ret = 0;
        for (auto& c : columnTitle) {
            ret = ret * 26 + (c - 'A' + 1);
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, execl_sheet_column_number) {
    Solution s;
    EXPECT_EQ(1, s.titleToNumber("A"));
    EXPECT_EQ(2321206, s.titleToNumber("EBASD"));
}
