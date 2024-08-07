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
    int smallestEvenMultiple(int n) {
        // 最小共倍数= a * b / 最大公约数
        return 2 * n / gcd(2, n);
    }

private:
    // 最大公约数 greatest common divisor
    int gcd(int a, int b) {
        if (a % b == 0)
            return b;
        else
            return gcd(b, a % b);
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_EQ(2, s.smallestEvenMultiple(1));
    EXPECT_EQ(2, s.smallestEvenMultiple(2));
    EXPECT_EQ(6, s.smallestEvenMultiple(3));
    EXPECT_EQ(4, s.smallestEvenMultiple(4));
    EXPECT_EQ(10, s.smallestEvenMultiple(5));
    EXPECT_EQ(6, s.smallestEvenMultiple(6));
}
