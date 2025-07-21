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
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    std::vector<bool> camelMatch(const std::vector<std::string>& queries,
                                 const std::string& pattern) {
        std::vector<bool> result;
        for (const auto& query : queries) {
            int idx = 0;
            bool ret = true;
            for (char c : query) {
                if (idx < pattern.size() && pattern[idx] == c) {
                    idx++;
                } else if (std::isupper(c)) {
                    ret = false;
                    break;
                }
            }
            if (idx < pattern.size())
                ret = false;
            result.push_back(ret);
        }
        return result;
    }
};
} // namespace

TEST(Leetcode, camelcase_matching) {
    Solution s;
    {
        std::vector<bool> exp = {true, false, true, true, false};
        EXPECT_EQ(exp,
                  s.camelMatch({"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"},
                               "FB"));
    }

    {
        std::vector<bool> exp = {true, false, true, false, false};
        EXPECT_EQ(exp,
                  s.camelMatch({"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"},
                               "FoBa"));
    }

    {
        std::vector<bool> exp = {false, true, false, false, false};
        EXPECT_EQ(exp,
                  s.camelMatch({"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"},
                               "FoBaT"));
    }
}
