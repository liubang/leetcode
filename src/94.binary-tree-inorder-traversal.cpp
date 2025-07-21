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

    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ret;
        visit(&ret, root);
        return ret;
    }

private:
    void visit(std::vector<int>* ret, TreeNode* node) {
        if (!node) {
            return;
        }
        visit(ret, node->left);
        ret->push_back(node->val);
        visit(ret, node->right);
    }
};
} // namespace

TEST(Leetcode, binary_tree_inordered_traversal) {
    Solution s;
    using TreeNode = leetcode::tree::TreeNode;
    {
        TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(5), new TreeNode(6)),
                                      new TreeNode(3, new TreeNode(4)));
        std::vector<int> exp = {5, 2, 6, 1, 4, 3};
        EXPECT_EQ(exp, s.inorderTraversal(root));
        leetcode::tree::destroy(root);
    }
}
