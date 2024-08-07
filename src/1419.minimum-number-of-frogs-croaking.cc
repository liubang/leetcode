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
    int minNumberOfFrogs(const std::string& croakOfFrogs) {
        // clang-format off
    std::size_t len = croakOfFrogs.length();
    if ((len % 5) > 0) return -1;

    std::unordered_map<char, int> c_idx = {
        {'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};

    std::vector<int> cc(5, 0);

    int ret = 0, tmp = 0;
    for (char c : croakOfFrogs) {
      int idx = c_idx[c];
      if (idx == 0) {
        cc[0]++;
        tmp++;
        ret = std::max(ret, tmp);
      } else {
        if (cc[idx - 1] == 0) return -1;
        cc[idx - 1]--;
        cc[idx]++;
        if (idx == 4) tmp--;
      }
    }
        // clang-format on

        return tmp > 0 ? -1 : ret;
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_EQ(1, s.minNumberOfFrogs("croakcroak"));
    EXPECT_EQ(2, s.minNumberOfFrogs("crcoakroak"));
    EXPECT_EQ(-1, s.minNumberOfFrogs("croakcrook"));
    EXPECT_EQ(4, s.minNumberOfFrogs("cccrrocarkooraakkoak"));
}
