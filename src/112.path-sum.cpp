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
#include <vector>

#include "tree.h"

namespace {
class Solution {
public:
    using TreeNode = leetcode::tree::TreeNode;
    bool hasPathSum(TreeNode* root, int target) { return dfs(root, 0, target); }

private:
    bool dfs(TreeNode* node, int sum, int target) {
        if (!node) {
            return false;
        }
        sum += node->val;
        if (!node->left && !node->right) {
            return sum == target;
        }
        return dfs(node->left, sum, target) || dfs(node->right, sum, target);
    }
};
} // namespace

TEST(Leetcode, path_sum) {
    Solution s;
    {
        std::vector<std::string> nodes = {"5", "4", "8",    "11",   "null", "13", "4",
                                          "7", "2", "null", "null", "null", "1"};
        auto root = leetcode::tree::create(nodes);
        EXPECT_TRUE(s.hasPathSum(root, 22));
        EXPECT_FALSE(s.hasPathSum(root, 11));
        leetcode::tree::destroy(root);
    }
}
