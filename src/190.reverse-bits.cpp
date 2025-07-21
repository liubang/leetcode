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
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = n;
        ret = ((ret & 0xffff0000) >> 16) | ((ret & 0x0000ffff) << 16);
        ret = ((ret & 0xff00ff00) >> 8) | ((ret & 0x00ff00ff) << 8);
        ret = ((ret & 0xf0f0f0f0) >> 4) | ((ret & 0x0f0f0f0f) << 4);
        ret = ((ret & 0xcccccccc) >> 2) | ((ret & 0x33333333) << 2);
        ret = ((ret & 0xaaaaaaaa) >> 1) | ((ret & 0x55555555) << 1);
        return ret;
    }
};
} // namespace

TEST(Leetcode, reverse_bits) {
    Solution s;
    {
        uint32_t exp = 0b00111001011110000010100101000000;
        uint32_t input = 0b00000010100101000001111010011100;
        EXPECT_EQ(exp, s.reverseBits(input));
    }

    {
        uint32_t exp = 0b11111111111111111111111111111101;
        uint32_t input = 0b10111111111111111111111111111111;
        EXPECT_EQ(exp, s.reverseBits(input));
    }
}
