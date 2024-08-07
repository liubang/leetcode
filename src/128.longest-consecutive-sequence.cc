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

#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "uf.h"

namespace {
class Solution1 {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        std::unordered_set<int> set;
        for (auto num : nums) {
            set.insert(num);
        }
        int ret = 0;
        for (auto it = set.begin(); it != set.end(); ++it) {
            int tmp = *it;
            if (set.count(tmp - 1)) {
                continue;
            }
            int cur = 1;
            while (set.count(tmp + cur)) {
                cur++;
            }
            ret = std::max(ret, cur);
        }
        return ret;
    }
};

class Solution2 {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        leetcode::uf::UnionFind uf(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) != map.end()) {
                continue;
            }

            if (map.find(nums[i] - 1) != map.end()) {
                uf.unite(i, map[nums[i] - 1]);
            }

            if (map.find(nums[i] + 1) != map.end()) {
                uf.unite(i, map[nums[i] + 1]);
            }

            map[nums[i]] = i;
        }

        return uf.getMaxConnectSize();
    }
};

} // namespace

TEST(Leetcode, longest_consecutive_sequence) {
    Solution1 s1;
    EXPECT_EQ(4, s1.longestConsecutive({100, 4, 200, 1, 3, 2}));
    EXPECT_EQ(9, s1.longestConsecutive({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}));
    EXPECT_EQ(0, s1.longestConsecutive({}));

    Solution2 s2;
    EXPECT_EQ(4, s2.longestConsecutive({100, 4, 200, 1, 3, 2}));
    EXPECT_EQ(9, s2.longestConsecutive({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}));
    EXPECT_EQ(0, s2.longestConsecutive({}));
}
