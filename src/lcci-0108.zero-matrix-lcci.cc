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
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> copy = matrix;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (copy[i][j] == 0) {
                    for (int x = 0; x < m; ++x) {
                        matrix[x][j] = 0;
                    }
                    for (int y = 0; y < n; ++y) {
                        matrix[i][y] = 0;
                    }
                }
            }
        }
    }
};
} // namespace

TEST(Leetcode, zero_matrix_lcci) {
    Solution s;
    {
        std::vector<std::vector<int>> input = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
        std::vector<std::vector<int>> exp = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
        s.setZeroes(input);
        EXPECT_EQ(exp, input);
    }

    {
        std::vector<std::vector<int>> input = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
        std::vector<std::vector<int>> exp = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
        s.setZeroes(input);
        EXPECT_EQ(exp, input);
    }
}
