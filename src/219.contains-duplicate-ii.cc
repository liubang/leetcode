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
