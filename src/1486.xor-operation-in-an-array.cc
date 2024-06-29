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
    int xorOperation(int n, int start) {
        int ret = start;
        for (int i = 1; i < n; ++i) {
            ret ^= (start + i * 2);
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, xor_operation_in_an_array) {
    Solution s;
    EXPECT_EQ(8, s.xorOperation(5, 0));
    EXPECT_EQ(8, s.xorOperation(4, 3));
    EXPECT_EQ(7, s.xorOperation(1, 7));
    EXPECT_EQ(2, s.xorOperation(10, 5));
}
