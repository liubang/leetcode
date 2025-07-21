// Copyright (c) 2024 The Authors. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Authors: liubang (it.liubang@gmail.com)


#include <gtest/gtest.h>

namespace {
class Solution {
public:
    int maxSumTwoNoOverlap(const std::vector<int>& nums, int firstLen, int secondLen) {
        // 先用暴力求解，但是即使是暴力求解，还是有优化空间的。
        // 后面有时间再优化
        int size = static_cast<int>(nums.size());
        int ret = 0;

        for (int i = 0; i < size - firstLen + 1; ++i) {
            int f = 0;
            for (int ii = 0; ii < firstLen; ++ii) {
                f += nums[i + ii];
            }

            for (int j = 0; i >= secondLen && j < i - secondLen + 1; ++j) {
                int s = 0;
                for (int jj = 0; jj < secondLen; ++jj) {
                    s += nums[j + jj];
                }
                ret = std::max(ret, f + s);
            }

            for (int j = i + firstLen; j < size - secondLen + 1; ++j) {
                int s = 0;
                for (int jj = 0; jj < secondLen; ++jj) {
                    s += nums[j + jj];
                }
                ret = std::max(ret, f + s);
            }
        }

        return ret;
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_EQ(20, s.maxSumTwoNoOverlap({0, 6, 5, 2, 2, 5, 1, 9, 4}, 1, 2));
    EXPECT_EQ(29, s.maxSumTwoNoOverlap({3, 8, 1, 3, 2, 1, 8, 9, 0}, 3, 2));
    EXPECT_EQ(31, s.maxSumTwoNoOverlap({2, 1, 5, 6, 0, 9, 5, 0, 3, 8}, 4, 3));
}
