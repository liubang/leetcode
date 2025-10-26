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
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0;
        int e = m * n;
        while (s < e) {
            int mid = s + (e - s) / 2;
            int r = mid / n;
            int c = mid % n;
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] < target) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return false;
    }
};
} // namespace

TEST(Leetcode, search_a_2d_matrix) {
    Solution s;
    std::vector<std::vector<int>> input = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input[0].size(); ++j) {
            EXPECT_TRUE(s.searchMatrix(input, input[i][j]));
        }
    }

    EXPECT_FALSE(s.searchMatrix(input, 2));
    EXPECT_FALSE(s.searchMatrix(input, 4));
    EXPECT_FALSE(s.searchMatrix(input, 6));
    EXPECT_FALSE(s.searchMatrix(input, 12));
    EXPECT_FALSE(s.searchMatrix(input, 13));
    EXPECT_FALSE(s.searchMatrix(input, 18));
    EXPECT_FALSE(s.searchMatrix(input, 70));
}
