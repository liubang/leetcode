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

#include <vector>

namespace {
class Solution {
public:
    int majorityElement(const std::vector<int>& nums) {
        int ret = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum == 0) {
                ret = nums[i];
                sum++;
            } else if (nums[i] == ret) {
                sum++;
            } else {
                sum--;
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, majority_element) {
    Solution s;

    EXPECT_EQ(3, s.majorityElement({3, 2, 3}));
    EXPECT_EQ(2, s.majorityElement({2, 2, 1, 1, 1, 2, 2}));
}
