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
    // 基本思路是先找到第一个元素，然后就非常简单了
    std::vector<int> decode(const std::vector<int>& encoded) {
        int size = encoded.size();
        int a = 0;
        for (int i = 1; i <= size + 1; ++i) {
            a ^= i;
        }
        for (int i = 1; i < size; i += 2) {
            a ^= encoded[i];
        }
        std::vector<int> ret;
        ret.push_back(a);
        for (int i = 0; i < size; ++i) {
            a ^= encoded[i];
            ret.push_back(a);
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, decode_xored_permutation) {
    Solution s;
    {
        std::vector<int> exp = {1, 2, 3};
        EXPECT_EQ(exp, s.decode({3, 1}));
    }

    {
        std::vector<int> exp = {2, 4, 1, 5, 3};
        EXPECT_EQ(exp, s.decode({6, 5, 4, 6}));
    }
}
