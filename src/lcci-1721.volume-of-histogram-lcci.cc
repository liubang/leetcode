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
    int trap(const std::vector<int>& height) {
        int size = height.size();
        int r = 0;
        std::vector<int> max(size, 0);
        for (int i = size - 1; i >= 0; --i) {
            max[i] = r;
            r = std::max(r, height[i]);
        }
        int l = 0, ret = 0;
        for (int i = 0; i < size; ++i) {
            int add = std::min(l, max[i]) - height[i];
            ret += add > 0 ? add : 0;
            l = std::max(l, height[i]);
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, volume_of_histogram_lcci) {
    Solution s;
    EXPECT_EQ(6, s.trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}));
}
