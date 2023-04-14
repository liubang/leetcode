#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
 public:
  std::vector<bool> camelMatch(const std::vector<std::string>& queries,
                               const std::string& pattern) {
    std::vector<bool> result;
    for (const auto& query : queries) {
      int idx = 0;
      bool ret = true;
      for (char c : query) {
        if (idx < pattern.size() && pattern[idx] == c) {
          idx++;
        } else if (std::isupper(c)) {
          ret = false;
          break;
        }
      }
      if (idx < pattern.size())
        ret = false;
      result.push_back(ret);
    }
    return result;
  }
};
}  // namespace

TEST(Leetcode, camelcase_matching) {
  Solution s;
  {
    std::vector<bool> exp = {true, false, true, true, false};
    EXPECT_EQ(exp, s.camelMatch({"FooBar", "FooBarTest", "FootBall",
                                 "FrameBuffer", "ForceFeedBack"},
                                "FB"));
  }

  {
    std::vector<bool> exp = {true, false, true, false, false};
    EXPECT_EQ(exp, s.camelMatch({"FooBar", "FooBarTest", "FootBall",
                                 "FrameBuffer", "ForceFeedBack"},
                                "FoBa"));
  }

  {
    std::vector<bool> exp = {false, true, false, false, false};
    EXPECT_EQ(exp, s.camelMatch({"FooBar", "FooBarTest", "FootBall",
                                 "FrameBuffer", "ForceFeedBack"},
                                "FoBaT"));
  }
}
