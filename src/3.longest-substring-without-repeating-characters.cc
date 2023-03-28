#include <gtest/gtest.h>

#include <string>
#include <unordered_map>
#include <unordered_set>

namespace {
class Solution {
 public:
  int lengthOfLongestSubstring(const std::string& s) {
    if (s.empty()) {
      return 0;
    }
    int pre = 1, ret = 1, len = s.length();
    std::unordered_map<char, int> map;
    map[s[0]] = 0;
    for (int i = 1; i < len; ++i) {
      if (map.find(s[i]) != map.end() && (i - pre) <= map[s[i]]) {
        pre = i - map[s[i]];
      } else {
        pre++;
      }
      ret = std::max(ret, pre);
      map[s[i]] = i;
    }
    return ret;
  }

  // 这种方法根上面的差不多，但是更简洁一些
  int lengthOfLongestSubstring2(const std::string& s) {
    int ret = 0;
    int left = 0;
    std::unordered_set<char> lookup;
    for (int i = 0; i < s.length(); ++i) {
      while (lookup.find(s[i]) != lookup.end()) {
        lookup.erase(s[left]);
        left++;
      }
      ret = std::max(ret, i - left + 1);
      lookup.insert(s[i]);
    }
    return ret;
  }
};
}  // namespace

TEST(Leetcode, longest_substring_without_repeating_characters) {
  Solution s;
  EXPECT_EQ(3, s.lengthOfLongestSubstring("abcabcbb"));
  EXPECT_EQ(1, s.lengthOfLongestSubstring("bbbbbbbb"));
  EXPECT_EQ(26,
            s.lengthOfLongestSubstring("abcdadbdqwertyuioplkjhgfdsazxcvbnm"));

  EXPECT_EQ(3, s.lengthOfLongestSubstring2("abcabcbb"));
  EXPECT_EQ(1, s.lengthOfLongestSubstring2("bbbbbbbb"));
  EXPECT_EQ(26,
            s.lengthOfLongestSubstring2("abcdadbdqwertyuioplkjhgfdsazxcvbnm"));
}
