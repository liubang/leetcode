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

#include <cmath>

namespace {
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }
        int s = std::sqrt(n);
        for (int i = 2; i <= s; ++i) {
            while (n % i == 0) {
                if (i != 2 && i != 3 && i != 5) {
                    return false;
                }
                n /= i;
            }
        }
        if (n != 1) {
            if (n != 2 && n != 3 && n != 5) {
                return false;
            }
        }
        return true;
    }
};
} // namespace

TEST(Leetcode, ugly_number) {
    Solution s;
    EXPECT_TRUE(s.isUgly(1));
    EXPECT_TRUE(s.isUgly(6));
    EXPECT_FALSE(s.isUgly(14));
    EXPECT_FALSE(s.isUgly(-1));
}
