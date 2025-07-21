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
    std::vector<int> plusOne(std::vector<int>& digits) {
        int size = digits.size();
        int extra = 1;
        for (int i = size - 1; i >= 0; --i) {
            int tmp = digits[i] + extra;
            digits[i] = tmp % 10;
            extra = tmp / 10;
            if (extra == 0) {
                break;
            }
        }
        if (extra > 0) {
            digits.insert(digits.begin(), extra);
        }
        return digits;
    }
};
} // namespace

TEST(Leetcode, plus_one) {
    Solution s;
    {
        std::vector<int> inputs = {1, 2, 3};
        std::vector<int> exps = {1, 2, 4};
        EXPECT_EQ(exps, s.plusOne(inputs));
    }

    {
        std::vector<int> inputs = {9, 9, 9};
        std::vector<int> exps = {1, 0, 0, 0};
        EXPECT_EQ(exps, s.plusOne(inputs));
    }
}
