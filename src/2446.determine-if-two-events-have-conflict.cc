//=====================================================================
//
// 2446.determine-if-two-events-have-conflict.cc -
//
// Created by liubang on 2023/05/17 00:39
// Last Modified: 2023/05/17 00:39
//
//=====================================================================
#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    bool haveConflict(const std::vector<std::string>& event1,
                      const std::vector<std::string>& event2) {
        return compare(event1[1], event2[0]) >= 0 && compare(event1[0], event2[1]) <= 0;
    }

private:
    int compare(const std::string& t1, const std::string& t2) {
        for (int i = 0; i < 5; ++i) {
            if (t1[i] > t2[i])
                return 1;
            else if (t1[i] < t2[i])
                return -1;
        }
        return 0;
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_TRUE(s.haveConflict({"01:15", "02:00"}, {"02:00", "03:00"}));
    EXPECT_TRUE(s.haveConflict({"01:00", "02:00"}, {"01:20", "03:00"}));
    EXPECT_FALSE(s.haveConflict({"10:00", "11:00"}, {"14:00", "15:00"}));
}
