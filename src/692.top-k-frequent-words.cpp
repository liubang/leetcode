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

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

namespace {
class Solution {
public:
    std::vector<std::string> topKFrequent(const std::vector<std::string>& words, int k) {
        std::unordered_map<std::string, int> mmp;
        for (const auto& word : words) {
            mmp[word]++;
        }
        auto my_compare = [](const std::pair<std::string, int>& p1,
                             const std::pair<std::string, int>& p2) {
            if (p1.second == p2.second) {
                return p1.first < p2.first;
            }
            return p1.second > p2.second;
        };

        std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>,
                            decltype(my_compare)>
            queue(my_compare);

        for (auto& pair : mmp) {
            if (queue.size() < k) {
                queue.push(pair);
            } else {
                auto top = queue.top();
                if ((top.second == pair.second && top.first > pair.first) ||
                    (top.first < pair.first)) {
                    queue.pop();
                    queue.push(pair);
                }
            }
        }
        std::vector<std::string> ret;
        while (!queue.empty()) {
            ret.insert(ret.begin(), queue.top().first);
            queue.pop();
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, top_k_frequent_words) {
    Solution s;
    {
        std::vector<std::string> exp = {"i", "love"};
        EXPECT_EQ(exp, s.topKFrequent({"i", "love", "leetcode", "i", "love", "coding"}, 2));
    }

    {
        std::vector<std::string> exp = {"the", "is", "sunny", "day"};
        EXPECT_EQ(exp,
                  s.topKFrequent(
                      {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, 4));
    }
}
