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
    std::string removeTrailingZeros(const std::string& num) {
        return num.substr(0, num.find_last_not_of('0') + 1);
    }
};

} // namespace

TEST(Leetcode, remove_trailing_zeros_from_a_string) {
    Solution s;
    EXPECT_EQ("512301", s.removeTrailingZeros("51230100"));
    EXPECT_EQ("123", s.removeTrailingZeros("123"));
}
