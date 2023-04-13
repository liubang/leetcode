#include <unordered_map>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
 public:
  int mostFrequentEvenElement(const std::vector<int>& nums) {
    std::unordered_map<int, int> m;
    for (int num : nums) {
      if ((num & 1) == 0) {
        m[num]++;
      }
    }
    int ret = -1;
    int max = 0;
    for (auto& [num, count] : m) {
      if (max == count) {
        ret = std::min(ret, num);
      } else if (max < count) {
        ret = num;
        max = count;
      }
    }
    return ret;
  }
};
}  // namespace

TEST(Leetcode, most_frequent_even_element) {
  Solution s;
  EXPECT_EQ(2, s.mostFrequentEvenElement({0, 1, 2, 2, 4, 4, 1}));
  EXPECT_EQ(4, s.mostFrequentEvenElement({4, 4, 4, 9, 2, 4}));
  EXPECT_EQ(-1, s.mostFrequentEvenElement({29, 47, 21, 41, 13, 37, 25, 7}));
}
