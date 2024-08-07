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
    int movingCount(int m, int n, int k) {
        std::vector<std::vector<int>> visted(m, std::vector<int>(n, 0));
        return dfs(visted, 0, 0, k);
    }

private:
    int bitsadd(int i) {
        int ret = 0;
        while (i > 0) {
            ret += i % 10;
            i /= 10;
        }
        return ret;
    }

    int dfs(std::vector<std::vector<int>>& visted, int i, int j, int k) {
        if (i < 0 || i >= visted.size() || j < 0 || j >= visted[0].size() || visted[i][j] == 1 ||
            bitsadd(i) + bitsadd(j) > k) {
            return 0;
        }
        visted[i][j] = 1;
        int ret = 1;
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        for (int m = 0; m < 4; ++m) {
            ret += dfs(visted, i + dx[m], j + dy[m], k);
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, ji_qi_ren_de_yun_dong_fan_wei_lcof) {
    Solution s;
    EXPECT_EQ(3, s.movingCount(2, 3, 1));
    EXPECT_EQ(1, s.movingCount(2, 3, 0));
    EXPECT_EQ(309, s.movingCount(100, 100, 10));
    EXPECT_EQ(5365, s.movingCount(100, 100, 19));
}
