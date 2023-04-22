//=====================================================================
//
// 1027.longest-arithmetic-subsequence.cc -
//
// Created by liubang on 2023/04/23 00:28
// Last Modified: 2023/04/23 00:28
//
//=====================================================================
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
 public:
  int longestArithmeticSeqLength(const std::vector<int>& nums) {
    int size = static_cast<int>(nums.size());
    // 0 <= nums[i] <= 500
    std::vector<std::vector<int>> dp(size, std::vector<int>(10000 + 1));
    int ret = 1;
    for (int i = 1; i < size; ++i) {
      for (int j = 0; j < i; ++j) {
        // 由于0 <= nums[i] <= 500, 所以这里统一加上500, 确保公差一定为非负数
        // 所以0 <= diff <= 500 + 500，上面的二维数组声明为10000 + 1
        int diff = nums[i] - nums[j] + 500;
        // 因为nums[i]和nums[j]之间的差为diff，所以如果以nums[j]结尾，且公差为diff的子序列长度为0，
        // 那么nums[i]和nums[j]就可以组合成一个以nums[i]结尾，且公差为diff的新的子序列，所以长度为2，
        // 如果已经存在以nums[j]结尾，且公差为diff的子序列，那么就将nums[i]添加到这个序列中，构成以
        // nums[i]结尾，公差为diff的序列，所以长度+1即可
        dp[i][diff] = dp[j][diff] == 0 ? 2 : dp[j][diff] + 1;
        ret = std::max(ret, dp[i][diff]);
      }
    }
    return ret;
  }
};
}  // namespace

TEST(Leetcode, leetcode) {
  Solution s;
  EXPECT_EQ(4, s.longestArithmeticSeqLength({3, 6, 9, 12}));
  EXPECT_EQ(3, s.longestArithmeticSeqLength({9, 4, 7, 2, 10}));
  EXPECT_EQ(4, s.longestArithmeticSeqLength({20, 1, 15, 3, 10, 5, 8}));
}
