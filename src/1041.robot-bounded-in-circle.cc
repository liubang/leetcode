#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
 public:
  bool isRobotBounded(const std::string& instructions) {
    std::pair<int, int> pos = {0, 0};
    // 北 -> 东 -> 南 -> 西
    std::vector<std::vector<int>> dires = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int direidx = 0;
    for (char c : instructions) {
      if (c == 'G') {
        pos.first += dires[direidx][0];
        pos.second += dires[direidx][1];
      } else if (c == 'L') {
        direidx = direidx == 0 ? 3 : direidx - 1;
      } else if (c == 'R') {
        direidx = direidx == 3 ? 0 : direidx + 1;
      }
    }
    return (pos.first == 0 && pos.second == 0) || direidx != 0;
  }
};
}  // namespace

TEST(Leetcode, robot_bounded_in_circle) {
  Solution s;
  EXPECT_TRUE(s.isRobotBounded("GGLLGG"));
  EXPECT_TRUE(s.isRobotBounded("GL"));
  EXPECT_FALSE(s.isRobotBounded("GG"));
}
