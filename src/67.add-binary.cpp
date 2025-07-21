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

#include <cstddef>
#include <string>

namespace {
class Solution {
public:
    std::string addBinary(const std::string& a, const std::string& b) {
        int i = a.length() - 1, j = b.length() - 1;
        std::string ret;
        int extra = 0;
        while (i >= 0 || j >= 0) {
            int tmp = extra;
            if (i >= 0) {
                tmp += a[i--] - '0';
            }
            if (j >= 0) {
                tmp += b[j--] - '0';
            }
            ret.insert(static_cast<size_t>(0), 1, (tmp % 2) + '0');
            extra = tmp / 2;
        }
        if (extra > 0) {
            ret.insert(static_cast<size_t>(0), 1, extra + '0');
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, add_binary) {
    Solution s;
    EXPECT_EQ("11110", s.addBinary("1111", "1111"));
}
