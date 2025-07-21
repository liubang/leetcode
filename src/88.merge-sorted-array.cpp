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

#include <algorithm>
#include <vector>

namespace {
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n) {
        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }
        std::sort(nums1.begin(), nums1.end());
    }
};
} // namespace

TEST(Leetcode, merge_sorted_array) {
    Solution s;
    std::vector<int> n1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> n2 = {2, 5, 6};
    std::vector<int> exp = {1, 2, 2, 3, 5, 6};
    s.merge(n1, 3, n2, 3);
    EXPECT_EQ(exp, n1);
}
