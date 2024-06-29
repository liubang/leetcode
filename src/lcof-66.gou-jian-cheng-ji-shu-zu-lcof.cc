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
    std::vector<int> constructArr(const std::vector<int>& a) {
        int len = a.size();
        if (len == 0) {
            return {};
        }
        std::vector<int> ret(len, 1);
        for (int i = 1; i < len; ++i) {
            ret[i] = ret[i - 1] * a[i - 1];
        }
        int tmp = 1;
        for (int i = len - 2; i >= 0; --i) {
            tmp *= a[i + 1];
            ret[i] *= tmp;
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, gou_jian_cheng_ji_shu_zu_ocof) {
    Solution s;
    {
        std::vector<int> exp = {120, 60, 40, 30, 24};
        EXPECT_EQ(exp, s.constructArr({1, 2, 3, 4, 5}));
    }
}
