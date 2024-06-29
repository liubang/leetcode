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
    int removeElement(std::vector<int>& nums, int target) {
        for (auto it = nums.begin(); it != nums.end();) {
            if (*it == target) {
                nums.erase(it);
            } else {
                it++;
            }
        }
        return nums.size();
    }
};
} // namespace

TEST(Leetcode, remove_element) {
    Solution s;

    {
        std::vector<int> inputs = {1, 2, 2, 3, 4};
        EXPECT_EQ(3, s.removeElement(inputs, 2));
        for (auto i : inputs) {
            EXPECT_NE(2, i);
        }
    }
}
