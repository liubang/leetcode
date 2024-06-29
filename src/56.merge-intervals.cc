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

#include <vector>

namespace {
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end(), [](auto& lhs, auto& rhs) {
            return (lhs[0] < rhs[0]) || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
        });

        std::vector<std::vector<int>> ret;
        int st = intervals[0][0], ed = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (ed >= intervals[i][0]) {
                ed = std::max(ed, intervals[i][1]);
            } else {
                ret.push_back({st, ed});
                st = intervals[i][0];
                ed = intervals[i][1];
            }
        }
        ret.push_back({st, ed});
        return ret;
    }
};
} // namespace

TEST(Leetcode, merge_intervals) {
    Solution s;

    {
        std::vector<std::vector<int>> inputs = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        std::vector<std::vector<int>> exp = {{1, 6}, {8, 10}, {15, 18}};
        EXPECT_EQ(exp, s.merge(inputs));
    }

    {
        std::vector<std::vector<int>> inputs = {{1, 4}, {4, 5}};
        std::vector<std::vector<int>> exp = {{1, 5}};
        EXPECT_EQ(exp, s.merge(inputs));
    }
}
