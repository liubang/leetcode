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
    // 个人感觉这道题有点像两数之和
    int numPairsDivisibleBy60(const std::vector<int>& time) {
        int ret = 0;
        std::unordered_map<int, int> m;
        for (int t : time) {
            t = t % 60;
            int tmp = 60 - t;
            if (m.find(tmp) != m.end())
                ret += m[tmp];

            if (t == 0)
                m[60]++;
            else
                m[t]++;
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;

    EXPECT_EQ(3, s.numPairsDivisibleBy60({30, 20, 150, 100, 40}));
    EXPECT_EQ(3, s.numPairsDivisibleBy60({60, 60, 60}));
    EXPECT_EQ(105,
              s.numPairsDivisibleBy60(
                  {269, 230, 318, 468, 171, 158, 350, 60,  287, 27,  11,  384, 332, 267, 412, 478,
                   280, 303, 242, 378, 129, 131, 164, 467, 345, 146, 264, 332, 276, 479, 284, 433,
                   117, 197, 430, 203, 100, 280, 145, 287, 91,  157, 5,   475, 288, 146, 370, 199,
                   81,  428, 278, 2,   400, 23,  470, 242, 411, 470, 330, 144, 189, 204, 62,  318,
                   475, 24,  457, 83,  204, 322, 250, 478, 186, 467, 350, 171, 119, 245, 399, 112,
                   252, 201, 324, 317, 293, 44,  295, 14,  379, 382, 137, 280, 265, 78,  38,  323,
                   347, 499, 238, 110, 18,  224, 473, 289, 198, 106, 256, 279, 275, 349, 210, 498,
                   201, 175, 472, 461, 116, 144, 9,   221, 473}));
}
