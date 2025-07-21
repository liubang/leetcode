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
#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace {
class Solution {
public:
    std::string largestNumber(const std::vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }
        std::vector<std::string> strs;
        for (auto num : nums) {
            strs.push_back(std::to_string(num));
        }
        std::sort(strs.begin(), strs.end(), [](auto& a, auto& b) {
            return (a + b) > (b + a);
        });
        std::string ret;
        for (auto& str : strs) {
            ret.append(str);
        }
        if (ret[0] == '0') {
            return "0";
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, largest_number) {
    Solution s;
    EXPECT_EQ("210", s.largestNumber({10, 2}));
    EXPECT_EQ("9534330", s.largestNumber({3, 30, 34, 5, 9}));
    EXPECT_EQ("343234323", s.largestNumber({34323, 3432}));
}
