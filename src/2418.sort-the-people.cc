//=====================================================================
//
// 2418.sort-the-people.cc -
//
// Created by liubang on 2023/04/25 00:31
// Last Modified: 2023/04/25 00:31
//
//=====================================================================

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
 public:
  std::vector<std::string> sortPepple(const std::vector<std::string>& names,
                                      const std::vector<int>& heights) {
    int size = static_cast<int>(names.size());
    std::vector<std::pair<std::string, int>> pairs;
    pairs.reserve(size);
    for (int i = 0; i < size; ++i) {
      pairs.emplace_back(names[i], heights[i]);
    }

    std::sort(pairs.begin(), pairs.end(), [](const auto& p1, const auto& p2) {
      return p1.second > p2.second;
    });

    std::vector<std::string> result;
    result.reserve(size);
    for (int i = 0; i < size; ++i) {
      result.push_back(pairs[i].first);
    }

    return result;
  }
};
}  // namespace

TEST(Leetcode, leetcode) {
  Solution s;

  {
    const std::vector<std::string> exp = {"Mary", "Emma", "John"};
    EXPECT_EQ(exp, s.sortPepple({"Mary", "John", "Emma"}, {180, 165, 170}));
  }

  {
    const std::vector<std::string> exp = {"Bob", "Alice", "Bob"};
    EXPECT_EQ(exp, s.sortPepple({"Alice", "Bob", "Bob"}, {155, 185, 150}));
  }
}
