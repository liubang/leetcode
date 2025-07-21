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
    bool hasAlternatingBits(int n) {
        int pre = 1 & n;
        while (n > 0) {
            n = n >> 1;
            if (pre == (1 & n)) {
                return false;
            }
            pre = 1 & n;
        }
        return true;
    }
};
} // namespace

TEST(Leetcode, binary_number_with_alternating_bits) {
    Solution s;
    EXPECT_TRUE(s.hasAlternatingBits(5));
    EXPECT_FALSE(s.hasAlternatingBits(8));
}
