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
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty() || target < matrix[0][0] ||
            target > matrix[matrix.size() - 1][matrix[0].size() - 1]) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                i--;
            } else {
                j++;
            }
        }
        return false;
    }
};
} // namespace

TEST(Leetcode, search_a_2d_matrix_ii) {
    Solution s;
    {
        std::vector<std::vector<int>> input = {{1, 4, 7, 11, 15},
                                               {2, 5, 8, 12, 19},
                                               {3, 6, 9, 16, 22},
                                               {10, 13, 14, 17, 24},
                                               {18, 21, 23, 26, 30}};
        EXPECT_TRUE(s.searchMatrix(input, 5));
        EXPECT_FALSE(s.searchMatrix(input, 33));
    }

    {
        std::vector<std::vector<int>> input = {{1, 4, 7, 11, 15},
                                               {2, 5, 8, 12, 19},
                                               {3, 6, 9, 16, 22},
                                               {10, 13, 14, 17, 24},
                                               {18, 21, 23, 26, 30}};
        EXPECT_FALSE(s.searchMatrix(input, 20));
    }
}
