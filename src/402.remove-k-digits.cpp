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

#include <map>
#include <string>
#include <vector>

namespace {
class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        if (num.length() == k)
            return "0";
        for (int i = 0; i < k; ++i) {
            int idx = 0;
            while (idx < num.length() - 1 && num[idx] <= num[idx + 1])
                idx++;
            num.erase(idx, 1);
            while (!num.empty() && num[0] == '0')
                num.erase(0, 1);
            if (num.empty())
                return "0";
        }
        return num;
    }
};
} // namespace

TEST(Leetcode, remove_k_digits) {
    Solution s;
    // num -> exp, k = vector.idx + 1
    std::vector<std::pair<std::string, std::string>> cases = {
        {"1432219", "132219"}, {"1432219", "12219"}, {"1432219", "1219"}, {"1432219", "119"},
        {"1432219", "11"},     {"1432219", "1"},     {"1432219", "0"},
    };
    int i = 1;
    for (const auto& [num, exp] : cases) {
        EXPECT_EQ(exp, s.removeKdigits(num, i++));
    }
}
