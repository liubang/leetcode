//=====================================================================
//
// 2441.largest-positive-integer-that-exists-with-its-negative.cc -
//
// Created by liubang on 2023/05/13 00:25
// Last Modified: 2023/05/13 00:25
//
//=====================================================================
#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
 public:
  // 这道题目拿到就应该想到双指针
  int findMax(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    int size = static_cast<int>(nums.size());
    if (nums[0] >= 0 || nums[size - 1] <= 0)
      return -1;
    int lidx = 0, ridx = size - 1;
    while (lidx < ridx) {
      int r = nums[ridx];
      while (lidx < ridx && nums[lidx] + r < 0)
        ++lidx;
      if (nums[lidx] + r == 0)
        return r;
      --ridx;
    }
    return -1;
  }
};
}  // namespace

TEST(Leetcode, leetcode) {
  Solution s;
  {
    std::vector<int> inputs = {-1, 2, -3, 3};
    EXPECT_EQ(3, s.findMax(inputs));
  }

  {
    std::vector<int> inputs = {-1, 10, 6, 7, -7, 1};
    EXPECT_EQ(7, s.findMax(inputs));
  }

  {
    std::vector<int> inputs = {-10, 8, 6, 7, -2, -3};
    EXPECT_EQ(-1, s.findMax(inputs));
  }

  {
    std::vector<int> inputs = {-956, -831, -707};
    EXPECT_EQ(-1, s.findMax(inputs));
  }

  {
    std::vector<int> inputs = {956, 831, 707};
    EXPECT_EQ(-1, s.findMax(inputs));
  }
}
