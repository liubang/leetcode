// Copyright (c) 2025 The Authors. All rights reserved.
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

// @leet imports start
#include <algorithm>
#include <climits>
#include <functional>
#include <gtest/gtest.h>
#include <vector>
// @leet imports end

namespace {

// @leet start
class Solution {
public:
    int minimumScore(const std::vector<int>& nums, const std::vector<std::vector<int>>& edges) {
        int n = nums.size();
        int count = 0;
        std::vector<int> sum(n);
        std::vector<int> in(n);
        std::vector<int> out(n);
        std::vector<std::vector<int>> tree(n);

        for (auto edg : edges) {
            tree[edg[0]].push_back(edg[1]);
            tree[edg[1]].push_back(edg[0]);
        }

        std::function<void(int, int)> dfs = [&](int x, int fa) {
            in[x] = count++;
            sum[x] = nums[x];

            for (auto& y : tree[x]) {
                if (y == fa) {
                    continue;
                }
                dfs(y, x);
                sum[x] ^= sum[y];
            }
            out[x] = count;
        };

        dfs(0, -1);
        int ret = INT_MAX;
        for (int u = 1; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                if (in[v] > in[u] && in[v] < out[u]) {
                    // u是v的parent
                    ret = std::min(ret, calc(sum[0] ^ sum[u], sum[u] ^ sum[v], sum[v]));
                } else if (in[u] > in[v] && in[u] < out[v]) {
                    // v是u的parent
                    ret = std::min(ret, calc(sum[0] ^ sum[v], sum[v] ^ sum[u], sum[u]));
                } else {
                    // u v 互不为parent
                    ret = std::min(ret, calc(sum[0] ^ sum[u] ^ sum[v], sum[u], sum[v]));
                }
            }
        }
        return ret;
    }

private:
    int calc(int part1, int part2, int part3) {
        return std::max({part1, part2, part3}) - std::min({part1, part2, part3});
    }
};
// @leet end

} // namespace
TEST(Leetcode, minimum_score_after_removals_on_a_tree) {
    Solution s;
    int ret = s.minimumScore({1, 5, 5, 4, 11}, {{0, 1}, {1, 2}, {1, 3}, {3, 4}});
    EXPECT_EQ(9, ret);

    ret = s.minimumScore({5, 5, 2, 4, 4, 2}, {{0, 1}, {1, 2}, {5, 2}, {4, 3}, {1, 3}});
    EXPECT_EQ(0, ret);
}
