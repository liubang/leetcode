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
    bool canJump(const std::vector<int>& nums) {
        int pre = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > pre) {
                return false;
            }
            pre = std::max(pre, i + nums[i]);
        }
        return true;
    }
};
} // namespace

TEST(Leetcode, jump_game) {
    Solution s;
    EXPECT_TRUE(s.canJump({1, 2, 3, 4}));
    EXPECT_FALSE(s.canJump({3, 2, 1, 0, 4}));
}
