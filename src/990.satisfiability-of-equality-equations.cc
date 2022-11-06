#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "uf.h"

namespace {
class Solution {
 public:
  bool equationsPossible(const std::vector<std::string>& equations) {
    leetcode::uf::UnionFind uf(26);
    for (const auto& e : equations) {
      if (e[1] == '!') {
        continue;
      }
      uf.unite(e[0] - 'a', e[3] - 'a');
    }
    for (const auto& e : equations) {
      if (e[1] == '=') {
        continue;
      }
      if (uf.find(e[0] - 'a') == uf.find(e[3] - 'a')) {
        return false;
      }
    }
    return true;
  }
};
}  // namespace

TEST(Leetcode, satisfiability_of_equality_equations) {
  Solution s;
  EXPECT_TRUE(s.equationsPossible({"b==a", "a==b"}));
  EXPECT_FALSE(s.equationsPossible({"a==b", "b!=a"}));
  EXPECT_TRUE(s.equationsPossible({"a==b", "b==c", "a==c"}));
  EXPECT_FALSE(s.equationsPossible({"a==b", "b!=c", "c==a"}));
  EXPECT_TRUE(s.equationsPossible({"c==c", "b==d", "x!=z"}));
}
