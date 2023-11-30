#include <gtest/gtest.h>
#include <vector>

namespace {
class Solution {
public:
    double findMedianSortedArray(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        auto size1 = nums1.size();
        auto size2 = nums2.size();
        auto total = size1 + size2;
        auto mid = (total & 1) == 0 ? total / 2 - 1 : total / 2;
        int i = 0;
        int j = 0;
        int n = 0;
        while (i < size1 || j < size2) {
            if (i == size1 || (j != size2 && nums1[i] > nums2[j]))
                n = nums2[j++];
            else
                n = nums1[i++];

            if ((i + j - 1) == mid) {
                if ((total & 1) == 0) {
                    if (i == size1 || (j != size2 && nums1[i] > nums2[j]))
                        return (n + nums2[j]) / 2.0;
                    else
                        return (n + nums1[i]) / 2.0;
                }
                return n;
            }
        }
        return 0;
    }
};
} // namespace

TEST(Leetcode, median_of_two_sorted_arrays) {
    Solution s;
    EXPECT_EQ(2.0, s.findMedianSortedArray({1, 3}, {2}));
    EXPECT_EQ(2.5, s.findMedianSortedArray({1, 3}, {2, 4}));
    EXPECT_EQ(3.5, s.findMedianSortedArray({3}, {1, 4, 5}));
    EXPECT_EQ(4.0, s.findMedianSortedArray({3}, {1, 4, 5, 6}));
    EXPECT_EQ(1.0, s.findMedianSortedArray({1}, {}));
    EXPECT_EQ(0.0, s.findMedianSortedArray({}, {}));
}
