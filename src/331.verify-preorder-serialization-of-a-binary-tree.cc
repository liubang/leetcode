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
    bool isValidSerialization(const std::string& preorder) {
        if (preorder == "#")
            return false;
        int len = preorder.length(), inDegree = 0, outDegree = 0;
        for (int i = 0; i < len; ++i) {
            if (preorder[i] == ',')
                continue;
            if (i == 0) {
                if (preorder[i] == '#')
                    return false;
                outDegree += 2;
            } else {
                if (preorder[i] != '#') {
                    outDegree += 2;
                }
                inDegree++;
            }
            if (i != len - 1 && inDegree >= outDegree) {
                return false;
            }
            while ((i + 1 < len && preorder[i + 1] != ',') || (i + 1 == len)) {
                i++;
            }
        }
        return inDegree == outDegree;
    }
};
} // namespace

TEST(Leetcode, verify_preorder_serialization_of_a_binary_tree) {
    Solution s;

    EXPECT_TRUE(s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"));
    EXPECT_TRUE(s.isValidSerialization("9,#,92,#,#"));
    EXPECT_FALSE(s.isValidSerialization("1,#"));
    EXPECT_FALSE(s.isValidSerialization("9,#,#,1"));
}
