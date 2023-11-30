//=====================================================================
//
// 2432.the-employee-that-worked-on-the-longest-task.cc -
//
// Created by liubang on 2023/05/05 00:51
// Last Modified: 2023/05/05 00:51
//
//=====================================================================

#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    int hardestWorker(int n, const std::vector<std::vector<int>>& logs) {
        int ret = logs[0][0];
        int max_time = logs[0][1];
        for (int i = 1; i < logs.size(); ++i) {
            int tmp = logs[i][1] - logs[i - 1][1];
            if (tmp == max_time)
                ret = std::min(ret, logs[i][0]);
            else if (tmp > max_time) {
                max_time = tmp;
                ret = logs[i][0];
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_EQ(1, s.hardestWorker(10, {{0, 3}, {2, 5}, {0, 9}, {1, 15}}));
    EXPECT_EQ(3, s.hardestWorker(26, {{1, 1}, {3, 7}, {2, 12}, {7, 17}}));
    EXPECT_EQ(0, s.hardestWorker(2, {{0, 10}, {1, 20}}));
    EXPECT_EQ(
        12, s.hardestWorker(70, {{36, 3}, {1, 5}, {12, 8}, {25, 9}, {53, 11}, {29, 12}, {52, 14}}));
}
