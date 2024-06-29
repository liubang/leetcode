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

#include "tree.h"

namespace {
class Solution {
public:
    using TreeNode = leetcode::tree::TreeNode;
    int findSecondMinimumValue(TreeNode* root) { return dfs(root, root->val); }

private:
    int dfs(TreeNode* root, int val) {
        if (!root) {
            return -1;
        }
        if (root->val > val) {
            return root->val;
        }
        int left = dfs(root->left, val);
        int right = dfs(root->right, val);
        if (left < 0) {
            return right;
        }
        if (right < 0) {
            return left;
        }
        return std::min(left, right);
    }
};
} // namespace

TEST(Leetcode, second_minimum_node_in_a_binary_tree) {
    Solution s;
    auto root = leetcode::tree::create({"2", "2", "5", "null", "null", "5", "7"});
    EXPECT_EQ(5, s.findSecondMinimumValue(root));
    leetcode::tree::destroy(root);
}
