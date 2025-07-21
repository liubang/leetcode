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

#include <unordered_map>

namespace {
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) {
            return n;
        }
        int pp = 2, p = 3, ret = 0;
        for (int i = 4; i <= n; ++i) {
            ret = pp + p;
            pp = p;
            p = ret;
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, climbing_stairs) {
    Solution s;
    std::unordered_map<int, int> cases = {
        {1, 1}, {2, 2}, {3, 3}, {4, 5}, {5, 8}, {6, 13}, {7, 21}, {8, 34}, {9, 55}, {10, 89},
    };

    for (auto& [i, j] : cases) {
        EXPECT_EQ(j, s.climbStairs(i));
    }
}
