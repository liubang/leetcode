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

#include <queue>
#include <vector>

namespace {
class Solution {
public:
    int kthLargestValue(const std::vector<std::vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int tmp = matrix[i][j];
                if (i > 0 && j == 0) {
                    tmp ^= dp[i - 1][j];
                } else if (i == 0 && j > 0) {
                    tmp ^= dp[i][j - 1];
                } else if (i > 0 && j > 0) {
                    tmp ^= dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1];
                }
                dp[i][j] = tmp;
                if (queue.size() < k) {
                    queue.push(tmp);
                } else {
                    if (queue.top() < tmp) {
                        queue.pop();
                        queue.push(tmp);
                    }
                }
            }
        }
        return queue.top();
    }
};
} // namespace

TEST(Leetcode, find_kth_largest_xor_coordinate_value) {
    Solution s;
    EXPECT_EQ(7, s.kthLargestValue({{5, 2}, {1, 6}}, 1));
    EXPECT_EQ(5, s.kthLargestValue({{5, 2}, {1, 6}}, 2));
    EXPECT_EQ(4, s.kthLargestValue({{5, 2}, {1, 6}}, 3));
    EXPECT_EQ(0, s.kthLargestValue({{5, 2}, {1, 6}}, 4));
    EXPECT_EQ(
        14, s.kthLargestValue({{8, 10, 5, 8, 5, 7, 6, 0, 1, 4, 10, 6, 4, 3, 6, 8, 7, 9, 4, 2}}, 2));
}
