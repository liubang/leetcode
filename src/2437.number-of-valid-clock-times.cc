//=====================================================================
//
// 2437.number-of-valid-clock-times.cc -
//
// Created by liubang on 2023/05/09 00:35
// Last Modified: 2023/05/09 00:35
//
//=====================================================================
#include <string>

#include <gtest/gtest.h>

namespace {
class Solution {
 public:
  int countTime(const std::string& time) {
    int a = 1, b = 1;
    if (time[0] == '?') {
      if (time[1] == '?')
        a = 24;  // 00~24
      else if (time[1] > '3')
        a = 2;  // eg: 04, 14
      else
        a = 3;  // eg: 02, 12, 22
    } else if (time[1] == '?') {
      if (time[0] < '2')
        a = 10;
      else
        a = 4;
    }

    if (time[3] == '?') {
      if (time[4] == '?')
        b = 60;  // 00~59
      else
        b = 6;  // eg: 01~51
    } else if (time[4] == '?')
      b = 10;

    return a * b;
  }
};
}  // namespace

TEST(Leetcode, leetcode) {
  Solution s;
  EXPECT_EQ(2, s.countTime("?5:00"));
  EXPECT_EQ(3, s.countTime("?2:00"));
  EXPECT_EQ(12, s.countTime("?5:?0"));
  EXPECT_EQ(18, s.countTime("?2:?0"));
  EXPECT_EQ(100, s.countTime("0?:0?"));
  EXPECT_EQ(1440, s.countTime("??:??"));
}
