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
#include <unordered_set>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    std::vector<int> vowelStrings(const std::vector<std::string>& words,
                                  const std::vector<std::vector<int>>& queries) {
        int size = words.size();
        // dp[i]表示[0， i]中，符合要求的字符串个数
        // dp[i] = dp[i - 1] + current ?
        std::vector<int> dp(size, 0);
        dp[0] = isVowelString(words[0]) ? 1 : 0;
        for (int i = 1; i < size; ++i) {
            dp[i] = dp[i - 1] + (isVowelString(words[i]) ? 1 : 0);
        }

        int qs = queries.size();
        std::vector<int> result(qs, 0);
        for (int i = 0; i < qs; ++i) {
            auto query = queries[i];
            if (query[0] == 0)
                result[i] = dp[query[1]];
            else
                result[i] = dp[query[1]] - dp[query[0] - 1];
        }
        return result;
    }

private:
    std::unordered_set<char> w{'a', 'e', 'i', 'o', 'u'};

    bool isVowelString(const std::string& s) {
        return w.count(s[0]) > 0 && w.count(s[s.size() - 1]) > 0;
    }
};

} // namespace

TEST(Leetcode, count_vowel_strings_in_ranges) {
    Solution s;
    {
        std::vector<int> exp = {2, 3, 0};
        EXPECT_EQ(exp, s.vowelStrings({"aba", "bcb", "ece", "aa", "e"}, {{0, 2}, {1, 4}, {1, 1}}));
    }
    {
        std::vector<int> exp = {3, 2, 1};
        EXPECT_EQ(exp, s.vowelStrings({"a", "e", "i"}, {{0, 2}, {0, 1}, {2, 2}}));
    }
}
