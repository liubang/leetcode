#include <gtest/gtest.h>

#include <unordered_set>
#include <vector>

namespace {
class Solution {
public:
    bool containsNearbyDuplicate(const std::vector<int>& nums, int k) {
        std::unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (set.size() > k) {
                set.erase(nums[i - k - 1]);
            }
            if (set.count(nums[i]) > 0) {
                return true;
            }
            set.emplace(nums[i]);
        }
        return false;
    }
};
} // namespace

TEST(Leetcode, contains_duplicate_ii) {
    Solution s;
    {
        std::vector<int> nums = {1, 2, 3, 1};
        EXPECT_TRUE(s.containsNearbyDuplicate(nums, 3));
    }
    {
        std::vector<int> nums = {1, 0, 1, 1};
        EXPECT_TRUE(s.containsNearbyDuplicate(nums, 1));
    }
    {
        std::vector<int> nums = {1, 2, 3, 1, 2, 3};
        EXPECT_FALSE(s.containsNearbyDuplicate(nums, 2));
    }
}
