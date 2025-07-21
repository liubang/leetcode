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
    int clumsy(int N) {
        if (N <= 2) {
            return N;
        }
        if (N == 3) {
            return 6;
        }

        int ret = N * (N - 1) / (N - 2) + N - 3;
        N -= 4;

        while (N >= 4) {
            ret += (-N * (N - 1) / (N - 2) + N - 3);
            N -= 4;
        }

        return ret - clumsy(N);
    }
};
} // namespace

TEST(Leetcode, clumsy_factorial) {
    Solution s;
    EXPECT_EQ(1, s.clumsy(1));
    EXPECT_EQ(2, s.clumsy(2));
    EXPECT_EQ(6, s.clumsy(3));
    EXPECT_EQ(7, s.clumsy(4));
    EXPECT_EQ(8, s.clumsy(6));
    EXPECT_EQ(12, s.clumsy(10));
    EXPECT_EQ(10001, s.clumsy(10000));
}
