#include <gtest/gtest.h>
#include <stack>
#include <string>

namespace {
class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> st;
        for (const char& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // clang-format off
        if (st.empty()) return false;
        if (c == ')' && st.top() != '(') return false;
        if (c == ']' && st.top() != '[') return false;
        if (c == '}' && st.top() != '{') return false;
                // clang-format on
                st.pop();
            }
        }
        return st.empty();
    }
};
} // namespace

TEST(Leetcode, valid_parentheses) {
    Solution s;
    EXPECT_TRUE(s.isValid("()"));
    EXPECT_TRUE(s.isValid("()[]{}"));
    EXPECT_FALSE(s.isValid("(]"));
    EXPECT_FALSE(s.isValid("()}"));
}
