//=====================================================================
//
// 322.coin-change.cc -
//
// Created by liubang on 2023/04/17 21:01
// Last Modified: 2023/04/17 21:01
//
//=====================================================================
#include <climits>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
 public:
  /**
   * 这也是一道典型的完全背包问题，整体解法跟279类似
   * 令dp[i]表示，凑够i元，最少需要的硬币数量，由题可知，当提供的硬币不满足条件的时候返回-1
   * 而最小的硬币面值为1，所以这里用到了一个小技巧，凑够amount在满足条件的情况下，最多需要
   * amount个硬币，所以令dp中所有的值默认为amount + 1表示无法满足的情况;
   *
   * 则dp = std::min(d[i], dp[i - coins[0]] + 1, ..., dp[i - coins[coins.size()
   * - 1]] + 1)
   *
   * 最后判断dp[amount]如果大于amount则表示不符合要求，否则返回值即可。
   *
   */
  int coinChange(const std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (auto coin : coins) {
        if (coin <= i) {
          dp[i] = std::min(dp[i], dp[i - coin] + 1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }

  /**
   * 这个解法跟上面的基本思想一样，只不过这个更容易理解一下，上面的更巧妙
   */
  int coinChange2(const std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, 0);
    for (int i = 1; i <= amount; ++i) {
      int min = INT_MAX;
      for (int coin : coins) {
        if (coin > i || dp[i - coin] < 0)
          continue;
        else
          min = std::min(min, dp[i - coin]);
      }
      if (min == INT_MAX)
        dp[i] = -1;
      else
        dp[i] = min + 1;
    }
    return dp[amount];
  }
};
}  // namespace

TEST(Leetcode, coin_change) {
  Solution s;
  EXPECT_EQ(3, s.coinChange({1, 2, 5}, 11));
  EXPECT_EQ(-1, s.coinChange({2}, 3));
  EXPECT_EQ(1, s.coinChange({1}, 1));

  EXPECT_EQ(3, s.coinChange2({1, 2, 5}, 11));
  EXPECT_EQ(-1, s.coinChange2({2}, 3));
  EXPECT_EQ(1, s.coinChange2({1}, 1));
}
