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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return left && right ? root : left ? left : right;
    }
};
} // namespace

TEST(Leetcode, lowest_common_ancestor_of_a_binary_tree) {
    using TreeNode = leetcode::tree::TreeNode;
    Solution s;
    {
        TreeNode* root = new TreeNode(3);
        TreeNode* p = new TreeNode(5, new TreeNode(6), new TreeNode(2));
        TreeNode* q = new TreeNode(1, new TreeNode(0), new TreeNode(8));
        root->left = p;
        root->right = q;
        auto ret = s.lowestCommonAncestor(root, p, q);
        EXPECT_EQ(root, ret);
        leetcode::tree::destroy(root);
    }

    {
        TreeNode* root =
            new TreeNode(3, nullptr, new TreeNode(1, new TreeNode(0), new TreeNode(8)));
        TreeNode* node5 = new TreeNode(5, new TreeNode(6));
        TreeNode* node2 = new TreeNode(2, new TreeNode(7));
        TreeNode* node4 = new TreeNode(4);
        node2->right = node4;
        node5->right = node2;
        root->left = node5;
        auto ret = s.lowestCommonAncestor(root, node5, node4);
        EXPECT_EQ(node5, ret);
        leetcode::tree::destroy(root);
    }
}
