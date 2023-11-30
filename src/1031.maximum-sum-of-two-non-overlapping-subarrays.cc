//=====================================================================
//
// 1031.maximum-sum-of-two-non-overlapping-subarrays.cc -
//
// Created by liubang on 2023/04/26 01:22
// Last Modified: 2023/04/26 01:22
//
//=====================================================================

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    int maxSumTwoNoOverlap(const std::vector<int>& nums, int firstLen, int secondLen) {
        // 先用暴力求解，但是即使是暴力求解，还是有优化空间的。
        // 后面有时间再优化
        int size = static_cast<int>(nums.size());
        int ret = 0;

        for (int i = 0; i < size - firstLen + 1; ++i) {
            int f = 0;
            for (int ii = 0; ii < firstLen; ++ii) {
                f += nums[i + ii];
            }

            for (int j = 0; i >= secondLen && j < i - secondLen + 1; ++j) {
                int s = 0;
                for (int jj = 0; jj < secondLen; ++jj) {
                    s += nums[j + jj];
                }
                ret = std::max(ret, f + s);
            }

            for (int j = i + firstLen; j < size - secondLen + 1; ++j) {
                int s = 0;
                for (int jj = 0; jj < secondLen; ++jj) {
                    s += nums[j + jj];
                }
                ret = std::max(ret, f + s);
            }
        }

        return ret;
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_EQ(20, s.maxSumTwoNoOverlap({0, 6, 5, 2, 2, 5, 1, 9, 4}, 1, 2));
    EXPECT_EQ(29, s.maxSumTwoNoOverlap({3, 8, 1, 3, 2, 1, 8, 9, 0}, 3, 2));
    EXPECT_EQ(31, s.maxSumTwoNoOverlap({2, 1, 5, 6, 0, 9, 5, 0, 3, 8}, 4, 3));
}
