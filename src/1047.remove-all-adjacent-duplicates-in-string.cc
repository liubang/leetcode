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

#include <string>

namespace {
class Solution {
public:
    std::string removeDuplicates(const std::string& S) {
        std::string ret;
        for (auto& ch : S) {
            if (!ret.empty() && ret.back() == ch) {
                ret.pop_back();
            } else {
                ret.push_back(ch);
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, remove_all_adjacent_duplicates_in_string) {
    Solution s;
    {
        auto ret = s.removeDuplicates("abbaca");
        EXPECT_EQ("ca", ret);
    }
    {
        auto ret = s.removeDuplicates("abcddcbabcddcbabc");
        EXPECT_EQ("abc", ret);
    }
}
