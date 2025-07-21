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

#include <algorithm>
#include <string>
#include <unordered_map>

namespace {
class Solution {
public:
    std::string frequencySort(const std::string& s) {
        std::unordered_map<char, int> charcount;
        for (auto& ch : s) {
            charcount[ch]++;
        }
        std::vector<std::pair<char, int>> v(charcount.begin(), charcount.end());
        std::sort(v.begin(), v.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.second > rhs.second;
        });
        std::string ret;
        for (auto& p : v) {
            ret.append(p.second, p.first);
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, sort_characters_by_frequency) {
    Solution s;
    {
        std::string input = "tree";
        auto ret = s.frequencySort(input);
        EXPECT_TRUE(ret == "eetr" || ret == "eert");
    }
    {
        std::string input = "cccaaa";
        auto ret = s.frequencySort(input);
        EXPECT_TRUE(ret == "cccaaa" || ret == "aaaccc");
    }
    {
        std::string input = "Aabb";
        auto ret = s.frequencySort(input);
        EXPECT_TRUE(ret == "bbaA" || ret == "bbAa");
    }
}
