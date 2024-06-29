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

namespace {
class Solution {
public:
    int add(int a, int b) { return b == 0 ? a : add(a ^ b, (unsigned int)(a & b) << 1); }
};
} // namespace

TEST(Leetcode, bu_yong_jia_jian_cheng_chu_zuo_jia_fa_lcof) {
    Solution s;
    EXPECT_EQ(3, s.add(1, 2));
    EXPECT_EQ(10, s.add(5, 5));
}
