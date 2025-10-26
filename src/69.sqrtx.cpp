// Copyright (c) 2025 The Authors. All rights reserved.
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
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int s = 0;
        int e = x;
        while (s < e) {
            uint64_t mid = s + (e - s) / 2;
            uint64_t y = mid * mid;
            if (y == x) {
                return mid;
            } else if (y < x) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s - 1;
    }
};
} // namespace

TEST(Leetcode, sqrtx) {
    Solution s;
    EXPECT_EQ(2, s.mySqrt(4));
    EXPECT_EQ(2, s.mySqrt(8));
    EXPECT_EQ(46339, s.mySqrt(2147395599));
}
