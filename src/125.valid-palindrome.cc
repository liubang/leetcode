#include <gtest/gtest.h>

#include <string>

namespace {
class Solution {
 public:
  bool isPalindrome(const std::string& s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
      while (i < j && !std::isalnum(s[i])) {
        i++;
      }
      while (i < j && !std::isalnum(s[j])) {
        j--;
      }
      if (i < j && !equals(s[i++], s[j--])) {
        return false;
      }
    }
    return true;
  }

 private:
  bool equals(char a, char b) {
    return (a == b) || (std::isalpha(a) && std::isalpha(b) &&
                        std::toupper(a) == std::toupper(b));
  }
};

// this solution is slow
class Solution2 {
 public:
  bool isPalindrome(const std::string& s) {
    std::string ns = filterOutNumberAndChar(s);
    return ns == std::string(ns.rbegin(), ns.rend());
  }

 private:
  std::string filterOutNumberAndChar(const std::string& s) {
    std::string ns;
    for (char i : s) {
      if (std::isalnum(i)) {
        ns.push_back(static_cast<char>(std::toupper(i)));
      }
    }
    return ns;
  }
};
}  // namespace

TEST(Leetcode, valid_palindrome) {
  {
    Solution s;
    EXPECT_TRUE(s.isPalindrome("A man, a plan, a canal: Panama"));
    EXPECT_FALSE(s.isPalindrome("race a car"));
  }

  {
    Solution2 s;
    EXPECT_TRUE(s.isPalindrome("A man, a plan, a canal: Panama"));
    EXPECT_FALSE(s.isPalindrome("race a car"));
  }
}
