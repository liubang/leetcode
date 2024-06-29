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

namespace {
class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while (n >= 5) {
            ret += n / 5;
            n /= 5;
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, factorial_trailing_zeros) {
    Solution s;
    EXPECT_EQ(2, s.trailingZeroes(11));
    EXPECT_EQ(0, s.trailingZeroes(3));
    EXPECT_EQ(33, s.trailingZeroes(135));
}
