#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

namespace {
class Solution {
public:
    int findMinDifference(std::vector<std::string>& timePoints) {
        std::sort(timePoints.begin(), timePoints.end());
        int ret = diffTime(timePoints[timePoints.size() - 1], timePoints[0]);
        for (int i = 0; i < timePoints.size() - 1; ++i) {
            ret = std::min(diffTime(timePoints[i + 1], timePoints[i]), ret);
        }
        return ret;
    }

private:
    static constexpr int HOURS_12 = 12 * 60;

    static constexpr int HOURS_24 = 24 * 60;

    int diffTime(const std::string& lhs, const std::string& rhs) {
        int ret = 0;
        int hour1 = (lhs[0] - '0') * 10 + (lhs[1] - '0');
        int hour2 = (rhs[0] - '0') * 10 + (rhs[1] - '0');
        int minute1 = (lhs[3] - '0') * 10 + (lhs[4] - '0');
        int minute2 = (rhs[3] - '0') * 10 + (rhs[4] - '0');
        ret = (hour1 - hour2) * 60 + minute1 - minute2;
        return ret > HOURS_12 ? (HOURS_24 - ret) : ret;
    }
};
} // namespace

TEST(Leetcode, minimum_time_diffrence) {
    Solution s;
    {
        std::vector<std::string> vecs = {"23:59", "00:00"};
        int ret = s.findMinDifference(vecs);
        EXPECT_EQ(ret, 1);
    }
    {
        std::vector<std::string> vecs = {"00:00", "23:59", "00:00"};
        int ret = s.findMinDifference(vecs);
        EXPECT_EQ(ret, 0);
    }
    {
        std::vector<std::string> vecs = {"00:00", "23:00", "11:50", "13:20", "12:30"};
        int ret = s.findMinDifference(vecs);
        EXPECT_EQ(ret, 40);
    }
    {
        std::vector<std::string> vecs = {"05:31", "22:08", "00:35"};
        int ret = s.findMinDifference(vecs);
        EXPECT_EQ(ret, 147);
    }
    {
        std::vector<std::string> vecs = {"12:12", "00:13"};
        int ret = s.findMinDifference(vecs);
        EXPECT_EQ(ret, 719);
    }
}
