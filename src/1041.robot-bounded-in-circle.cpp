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
    bool isRobotBounded(const std::string& instructions) {
        std::pair<int, int> pos = {0, 0};
        // 北 -> 东 -> 南 -> 西
        std::vector<std::vector<int>> dires = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direidx = 0;
        for (char c : instructions) {
            if (c == 'G') {
                pos.first += dires[direidx][0];
                pos.second += dires[direidx][1];
            } else if (c == 'L') {
                direidx = direidx == 0 ? 3 : direidx - 1;
            } else if (c == 'R') {
                direidx = direidx == 3 ? 0 : direidx + 1;
            }
        }
        return (pos.first == 0 && pos.second == 0) || direidx != 0;
    }
};
} // namespace

TEST(Leetcode, robot_bounded_in_circle) {
    Solution s;
    EXPECT_TRUE(s.isRobotBounded("GGLLGG"));
    EXPECT_TRUE(s.isRobotBounded("GL"));
    EXPECT_FALSE(s.isRobotBounded("GG"));
}
