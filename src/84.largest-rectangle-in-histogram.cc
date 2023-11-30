#include <gtest/gtest.h>

#include <climits>
#include <stack>
#include <vector>

namespace {
class Solution {
public:
    // 暴力求解 O(n^2)
    int largestRectangleInHistogram1(const std::vector<int>& inputs) {
        std::size_t n = inputs.size();
        int max_area = 0;
        for (int i = 0; i < n; ++i) {
            int min_height = INT_MAX;
            for (int j = i; j < n; ++j) {
                min_height = std::min(min_height, inputs[j]);
                max_area = std::max(max_area, min_height * (j - i + 1));
            }
        }
        return max_area;
    }

    // stack: O(n)
    int largestRectangleInHistogram2(const std::vector<int>& inputs) {
        int n = inputs.size();
        std::stack<int> stk;
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && inputs[stk.top()] > inputs[i]) {
                int w = i;
                int h = inputs[stk.top()];
                stk.pop();
                if (!stk.empty()) {
                    w = i - stk.top() - 1;
                }
                ret = std::max(ret, w * h);
            }
            stk.push(i);
        }

        while (!stk.empty()) {
            int w = n;
            int h = inputs[stk.top()];
            stk.pop();
            if (!stk.empty()) {
                w = n - stk.top() - 1;
            }
            ret = std::max(ret, w * h);
        }

        return ret;
    }
};
} // namespace

TEST(Leetcode, largest_rectangle_in_histogram) {
    Solution s;
    EXPECT_EQ(10, s.largestRectangleInHistogram1({2, 1, 5, 6, 2, 3}));
    EXPECT_EQ(10, s.largestRectangleInHistogram2({2, 1, 5, 6, 2, 3}));

    EXPECT_EQ(4, s.largestRectangleInHistogram1({2, 4}));
    EXPECT_EQ(4, s.largestRectangleInHistogram2({2, 4}));

    EXPECT_EQ(50, s.largestRectangleInHistogram1({2, 1, 5, 6, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
    EXPECT_EQ(50, s.largestRectangleInHistogram2({2, 1, 5, 6, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
}
