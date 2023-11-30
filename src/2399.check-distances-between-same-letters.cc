#include <string>
#include <unordered_map>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    bool checkDistances(const std::string& s, const std::vector<int>& distance) {
        std::unordered_map<char, int> rindex;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (rindex.find(c) != rindex.end()) {
                if (distance[c - 'a'] != (i - rindex[c] - 1)) {
                    return false;
                }
            } else {
                rindex[c] = i;
            }
        }
        return true;
    }
};
} // namespace

TEST(Leetcode, check_distances_between_same_letters) {
    Solution s;
    EXPECT_TRUE(s.checkDistances(
        "abaccb", {1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    EXPECT_FALSE(s.checkDistances(
        "aa", {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
}
