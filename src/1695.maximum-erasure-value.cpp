// Copyright (c) 2025 The Authors. All rights reserved.
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

// @leet imports start
#include <gtest/gtest.h>
#include <unordered_set>
#include <vector>
using namespace std;
// @leet imports end

namespace {

// @leet start
class Solution {
public:
    int maximumUniqueSubarray(const std::vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int curr = 0;
        int ret = 0;
        std::unordered_set<int> seq;
        while (r < n) {
            // 如果右边界已经被包含了，则移动左边界
            while (seq.count(nums[r])) {
                seq.erase(nums[l]);
                curr -= nums[l];
                ++l;
            }
            seq.insert(nums[r]);
            curr += nums[r];
            ++r;
            ret = std::max(ret, curr);
        }
        return ret;
    }
};
// @leet end

} // namespace
TEST(Leetcode, maximum_erasure_value) {
    Solution s;
    EXPECT_EQ(17, s.maximumUniqueSubarray({4, 2, 4, 5, 6}));
    EXPECT_EQ(8, s.maximumUniqueSubarray({5, 2, 1, 2, 5, 2, 1, 2, 5}));
}
