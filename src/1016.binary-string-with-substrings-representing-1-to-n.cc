//=====================================================================
//
// 1016.binary-string-with-substrings-representing-1-to-n.cc -
//
// Created by liubang on 2023/05/11 01:12
// Last Modified: 2023/05/11 01:12
//
//=====================================================================

#include <bitset>
#include <string>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    bool queryString(const std::string& s, int n) {
        for (int i = 1; i <= n; ++i) {
            std::bitset<32> bits(i);
            std::string str = bits.to_string();
            str = str.substr(str.find_first_not_of('0'));
            if (s.find(str) == std::string::npos)
                return false;
        }
        return true;
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_TRUE(s.queryString("0110", 3));
    EXPECT_FALSE(s.queryString("0110", 4));
    EXPECT_FALSE(s.queryString("01101110001", 129));
}
