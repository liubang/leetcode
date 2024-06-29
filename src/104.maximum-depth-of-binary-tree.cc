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

#include "tree.h"

namespace {
class Solution {
public:
    using TreeNode = leetcode::tree::TreeNode;
    int maxDepth(TreeNode* root) {
        return root == nullptr ? 0 : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
} // namespace

TEST(Leetcode, maximum_depth_of_binary_tree) {
    using TreeNode = leetcode::tree::TreeNode;
    Solution s;
    TreeNode* root =
        new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    EXPECT_EQ(3, s.maxDepth(root));
    leetcode::tree::destroy(root);
}
