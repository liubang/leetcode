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
    bool haveConflict(const std::vector<std::string>& event1,
                      const std::vector<std::string>& event2) {
        return compare(event1[1], event2[0]) >= 0 && compare(event1[0], event2[1]) <= 0;
    }

private:
    int compare(const std::string& t1, const std::string& t2) {
        for (int i = 0; i < 5; ++i) {
            if (t1[i] > t2[i])
                return 1;
            else if (t1[i] < t2[i])
                return -1;
        }
        return 0;
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_TRUE(s.haveConflict({"01:15", "02:00"}, {"02:00", "03:00"}));
    EXPECT_TRUE(s.haveConflict({"01:00", "02:00"}, {"01:20", "03:00"}));
    EXPECT_FALSE(s.haveConflict({"10:00", "11:00"}, {"14:00", "15:00"}));
}
