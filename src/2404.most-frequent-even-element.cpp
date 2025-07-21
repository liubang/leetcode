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

#include <unordered_map>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    int mostFrequentEvenElement(const std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        for (int num : nums) {
            if ((num & 1) == 0) {
                m[num]++;
            }
        }
        int ret = -1;
        int max = 0;
        for (auto& [num, count] : m) {
            if (max == count) {
                ret = std::min(ret, num);
            } else if (max < count) {
                ret = num;
                max = count;
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, most_frequent_even_element) {
    Solution s;
    EXPECT_EQ(2, s.mostFrequentEvenElement({0, 1, 2, 2, 4, 4, 1}));
    EXPECT_EQ(4, s.mostFrequentEvenElement({4, 4, 4, 9, 2, 4}));
    EXPECT_EQ(-1, s.mostFrequentEvenElement({29, 47, 21, 41, 13, 37, 25, 7}));
}
