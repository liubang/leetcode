//=====================================================================
//
// 1042.flower-planting-with-no-adjacent.cc -
//
// Created by liubang on 2023/11/30 23:08
// Last Modified: 2023/11/30 23:08
//
//=====================================================================
#include <gtest/gtest.h>
#include <vector>

namespace {
class Solution {
public:
    std::vector<int> gardenNoAdj(int n, const std::vector<std::vector<int>>& paths) {
        std::vector<std::vector<int>> graph(n);
        for (const auto& path : paths) {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }
        std::vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            // 记录第i个花园的相邻花园种植了哪种种颜色的花了
            std::vector<bool> c(5, false);
            for (int g : graph[i]) {
                // 当i=0的时候，这里只有c[0] = true
                // 后面默认为1号花园种植颜色为1的花
                c[result[g]] = true;
            }
            // 为当前花园挑出一个没有种的花
            for (int j = 1; j <= 4; ++j) {
                if (!c[j]) {
                    result[i] = j;
                    break;
                }
            }
        }
        return result;
    }
};
} // namespace

TEST(Leetcode, flower_planting_with_no_adjacent) {
    Solution s;
    {
        std::vector<int> exp = {1, 2, 3};
        s.gardenNoAdj(3, {{1, 2}, {2, 3}, {1, 3}});
    }

    {
        std::vector<int> exp = {1, 2, 1, 2};
        s.gardenNoAdj(4, {{1, 2}, {3, 4}});
    }

    {
        std::vector<int> exp = {1, 2, 3, 4};
        s.gardenNoAdj(4, {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}, {2, 4}});
    }
}
