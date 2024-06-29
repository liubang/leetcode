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
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        int tmp = n, one = 0, zero = 0;
        while (tmp > 0) {
            if (one >= 1)
                return false;
            if ((tmp & 1) == 0) {
                zero++;
            } else {
                one++;
            }
            tmp >>= 1;
        }
        return (zero & 1) == 0;
    }
};
} // namespace

TEST(Leetcode, power_of_four) {
    Solution s;
    EXPECT_FALSE(s.isPowerOfFour(0));
    EXPECT_TRUE(s.isPowerOfFour(1));
    EXPECT_FALSE(s.isPowerOfFour(2));
    EXPECT_TRUE(s.isPowerOfFour(4));
    EXPECT_FALSE(s.isPowerOfFour(8));
    EXPECT_TRUE(s.isPowerOfFour(16));
    EXPECT_FALSE(s.isPowerOfFour(32));
    EXPECT_TRUE(s.isPowerOfFour(64));
}
