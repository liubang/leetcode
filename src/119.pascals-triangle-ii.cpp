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
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> cur;
        for (int i = 0; i <= rowIndex; ++i) {
            std::vector<int> tmp;
            for (int j = 0; j <= i; ++j) {
                if (i == 0 || j == 0 || i == j) {
                    tmp.push_back(1);
                } else {
                    tmp.push_back(cur[j] + cur[j - 1]);
                }
            }
            cur = tmp;
        }
        return cur;
    }
};
} // namespace

TEST(Leetcode, pascals_triangle_ii) {
    Solution s;
    EXPECT_EQ(std::vector<int>({1}), s.getRow(0));
    EXPECT_EQ(std::vector<int>({1, 1}), s.getRow(1));
    EXPECT_EQ(std::vector<int>({1, 2, 1}), s.getRow(2));
    EXPECT_EQ(std::vector<int>({1, 3, 3, 1}), s.getRow(3));
}
