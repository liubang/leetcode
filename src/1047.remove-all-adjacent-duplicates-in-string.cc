//=====================================================================
//
// 1047.remove-all-adjacent-duplicates-in-string.cc -
//
// Created by liubang on 2023/11/30 23:08
// Last Modified: 2023/11/30 23:08
//
//=====================================================================
#include <gtest/gtest.h>

#include <string>

namespace {
class Solution {
public:
    std::string removeDuplicates(const std::string& S) {
        std::string ret;
        for (auto& ch : S) {
            if (!ret.empty() && ret.back() == ch) {
                ret.pop_back();
            } else {
                ret.push_back(ch);
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, remove_all_adjacent_duplicates_in_string) {
    Solution s;
    {
        auto ret = s.removeDuplicates("abbaca");
        EXPECT_EQ("ca", ret);
    }
    {
        auto ret = s.removeDuplicates("abcddcbabcddcbabc");
        EXPECT_EQ("abc", ret);
    }
}
