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
    int numIslands(std::vector<std::vector<char>>& grid) {
        int nr = grid.size();
        if (nr == 0)
            return 0;
        int nc = grid[0].size();
        int ret = 0;
        for (int i = 0; i < nr; ++i) {
            for (int j = 0; j < nc; ++j) {
                if (grid[i][j] == '1') {
                    ret++;
                    dfs(grid, i, j);
                }
            }
        }
        return ret;
    }

private:
    void dfs(std::vector<std::vector<char>>& grid, int x, int y) {
        int nr = grid.size();
        int nc = grid[0].size();
        grid[x][y] = '0';
        // clang-format off
    if (x - 1 >= 0 && grid[x - 1][y] == '1') dfs(grid, x - 1, y);
    if (x + 1 < nr && grid[x + 1][y] == '1') dfs(grid, x + 1, y);
    if (y - 1 >= 0 && grid[x][y - 1] == '1') dfs(grid, x, y - 1);
    if (y + 1 < nc && grid[x][y + 1] == '1') dfs(grid, x, y + 1);
        // clang-format on
    }
};
} // namespace

TEST(Leetcode, number_of_islands) {
    Solution s;
    {
        std::vector<std::vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
        };
        EXPECT_EQ(1, s.numIslands(grid));
    }

    {
        std::vector<std::vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
        };
        EXPECT_EQ(3, s.numIslands(grid));
    }
}
