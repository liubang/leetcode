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

#include <string>
#include <unordered_map>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    bool checkDistances(const std::string& s, const std::vector<int>& distance) {
        std::unordered_map<char, int> rindex;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (rindex.find(c) != rindex.end()) {
                if (distance[c - 'a'] != (i - rindex[c] - 1)) {
                    return false;
                }
            } else {
                rindex[c] = i;
            }
        }
        return true;
    }
};
} // namespace

TEST(Leetcode, check_distances_between_same_letters) {
    Solution s;
    EXPECT_TRUE(s.checkDistances(
        "abaccb", {1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    EXPECT_FALSE(s.checkDistances(
        "aa", {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
}
