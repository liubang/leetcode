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
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        size_t m = grid.size();
        size_t n = grid[0].size();
        int ret = 0;
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (grid[i][j] == 0)
                    continue;

                // 上
                if (i == 0 || (i - 1 >= 0 && grid[i - 1][j] == 0))
                    ret++;
                // 下
                if (i == (m - 1) || (i + 1 < m && grid[i + 1][j] == 0))
                    ret++;
                // 左
                if (j == 0 || (j - 1 >= 0 && grid[i][j - 1] == 0))
                    ret++;
                // 右
                if (j == (n - 1) || (j + 1 < n && grid[i][j + 1] == 0))
                    ret++;
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, island_perimeter) {
    Solution s;
    {
        std::vector<std::vector<int>> grid = {
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0},
        };

        auto ret = s.islandPerimeter(grid);
        EXPECT_EQ(16, ret);
    }

    {
        std::vector<std::vector<int>> grid = {{1}};
        auto ret = s.islandPerimeter(grid);
        EXPECT_EQ(4, ret);
    }

    {
        std::vector<std::vector<int>> grid = {{1, 0}};
        auto ret = s.islandPerimeter(grid);
        EXPECT_EQ(4, ret);
    }
}
