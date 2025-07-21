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
#include <vector>

namespace {
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (const auto& str : strs) {
            if (str.empty()) {
                map[str].push_back(str);
            } else {
                std::string copy = str;
                std::sort(copy.begin(), copy.end());
                map[copy].push_back(str);
            }
        }
        std::vector<std::vector<std::string>> result;
        result.reserve(map.size());
        for (const auto& [k, v] : map) {
            result.emplace_back(v);
        }
        return result;
    }
};
} // namespace

TEST(Leetcode, group_anagrams) {
    Solution s;
    {
        std::vector<std::vector<std::string>> exp = {
            {"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}};
        EXPECT_EQ(exp, s.groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"}));
    }
    {
        std::vector<std::vector<std::string>> exp = {{""}};
        EXPECT_EQ(exp, s.groupAnagrams({""}));
    }
    {
        std::vector<std::vector<std::string>> exp = {{"a"}};
        EXPECT_EQ(exp, s.groupAnagrams({"a"}));
    }
}
