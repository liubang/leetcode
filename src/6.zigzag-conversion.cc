#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
 public:
  std::string convert(const std::string& s, int numRows) {
    if (numRows < 2)
      return s;
    std::vector<std::string> vecs(numRows, "");
    int row = 0;
    int flag = -1;
    for (char i : s) {
      if (row == 0 || row == numRows - 1)
        flag = -flag;
      vecs[row].append(1, i);
      row += flag;
    }
    std::string ret;
    for (const auto& str : vecs) {
      ret += str;
    }
    return ret;
  }
};
}  // namespace

TEST(Leetcode, zigzag_conversion) {
  Solution s;
  EXPECT_EQ("PAYPALISHIRING", s.convert("PAYPALISHIRING", 1));
  EXPECT_EQ("PAHNAPLSIIGYIR", s.convert("PAYPALISHIRING", 3));
  EXPECT_EQ("PINALSIGYAHRPI", s.convert("PAYPALISHIRING", 4));
}
