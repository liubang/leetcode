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

#include <queue>
#include <vector>

namespace {
class Solution {
public:
    int findKthLargest(const std::vector<int>& nums, int k) {
        // 小顶堆
        std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k) {
                queue.push(nums[i]);
            } else {
                if (nums[i] > queue.top()) {
                    queue.pop();
                    queue.push(nums[i]);
                }
            }
        }
        return queue.top();
    }
};
} // namespace

TEST(Leetcode, kth_largest_element_in_an_array) {
    Solution s;
    EXPECT_EQ(5, s.findKthLargest({3, 2, 1, 5, 6, 4}, 2));
    EXPECT_EQ(4, s.findKthLargest({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4));
}
