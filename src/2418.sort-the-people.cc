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


#include <algorithm>
#include <string>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    std::vector<std::string> sortPepple(const std::vector<std::string>& names,
                                        const std::vector<int>& heights) {
        int size = static_cast<int>(names.size());
        std::vector<std::pair<std::string, int>> pairs;
        pairs.reserve(size);
        for (int i = 0; i < size; ++i) {
            pairs.emplace_back(names[i], heights[i]);
        }

        std::sort(pairs.begin(), pairs.end(), [](const auto& p1, const auto& p2) {
            return p1.second > p2.second;
        });

        std::vector<std::string> result;
        result.reserve(size);
        for (int i = 0; i < size; ++i) {
            std::string s = pairs[i].first;
            result.push_back(std::move(s));
            // result[i] = pairs[i].first;
        }

        return result;
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;

    {
        const std::vector<std::string> exp = {"Mary", "Emma", "John"};
        EXPECT_EQ(exp, s.sortPepple({"Mary", "John", "Emma"}, {180, 165, 170}));
    }

    {
        const std::vector<std::string> exp = {"Bob", "Alice", "Bob"};
        EXPECT_EQ(exp, s.sortPepple({"Alice", "Bob", "Bob"}, {155, 185, 150}));
    }
}
