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
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> ret(n, std::vector<int>(m, 0));
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                ret[i][j] = matrix[j][i];
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, transpose_matrix) {
    Solution s;
    {
        std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        std::vector<std::vector<int>> exp = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
        auto ret = s.transpose(matrix);
        EXPECT_EQ(exp, ret);
    }

    {
        std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}};
        std::vector<std::vector<int>> exp = {{1, 4}, {2, 5}, {3, 6}};
        auto ret = s.transpose(matrix);
        EXPECT_EQ(exp, ret);
    }
}
