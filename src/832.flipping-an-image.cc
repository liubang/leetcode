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
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A) {
        int len = A.size();
        std::vector<std::vector<int>> ret;
        for (auto i = 0; i < len; ++i) {
            std::vector<int> row;
            for (auto j = len - 1; j >= 0; --j) {
                row.push_back(A[i][j] ^ 1);
            }
            ret.emplace_back(std::move(row));
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, flipping_an_image) {
    Solution s;
    {
        std::vector<std::vector<int>> A = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
        std::vector<std::vector<int>> exp = {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
        auto ret = s.flipAndInvertImage(A);
        EXPECT_EQ(exp, ret);
    }

    {
        std::vector<std::vector<int>> A = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
        std::vector<std::vector<int>> exp = {
            {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 1, 0}};
        auto ret = s.flipAndInvertImage(A);
        EXPECT_EQ(exp, ret);
    }
}
