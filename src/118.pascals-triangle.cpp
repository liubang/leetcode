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

#include <vector>

namespace {
class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ret;
        for (int i = 0; i < numRows; ++i) {
            std::vector<int> row;
            for (int j = 0; j <= i; ++j) {
                if (i == 0 || j == 0 || j == i) {
                    row.push_back(1);
                } else {
                    row.push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
                }
            }
            ret.emplace_back(std::move(row));
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, pascals_triangle) {
    Solution s;
    {
        std::vector<std::vector<int>> exps = {
            {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1},
        };
        EXPECT_EQ(exps, s.generate(5));
    }
}
