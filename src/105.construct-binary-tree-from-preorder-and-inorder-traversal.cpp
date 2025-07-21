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

#include "tree.h"

#include <memory>
#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    using TreeNode = leetcode::tree::TreeNode;

    TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
        int psize = preorder.size();
        int isize = inorder.size();
        if (psize == 0 || isize == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int i = 0;
        for (; i < isize; ++i) {
            if (inorder[i] == preorder[0]) {
                break;
            }
        }
        // 存在left
        if (i > 0) {
            std::vector<int> subpreorder(preorder.begin() + 1, preorder.begin() + 1 + i);
            std::vector<int> subinorder(inorder.begin(), inorder.begin() + i);
            root->left = buildTree(subpreorder, subinorder);
        }

        // 存在right
        if (psize > i + 1) {
            std::vector<int> subpreorder(preorder.begin() + 1 + i, preorder.end());
            std::vector<int> subinorder(inorder.begin() + 1 + i, inorder.end());
            root->right = buildTree(subpreorder, subinorder);
        }
        return root;
    }
};
} // namespace

TEST(Leetcode, construct_binary_tree_from_preorder_and_inorder_traversal) {
    using TreeNode = leetcode::tree::TreeNode;
    using leetcode::tree::destroy;

    Solution s;
    std::vector<std::string> nodes = {"3", "9", "20", "null", "null", "15", "7"};
    TreeNode* exp = leetcode::tree::create(nodes);
    std::unique_ptr<TreeNode, decltype(&destroy)> exp_ptr(exp, destroy);
    TreeNode* ret = s.buildTree({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7});
    std::unique_ptr<TreeNode, decltype(&destroy)> ret_ptr(ret, destroy);
    EXPECT_TRUE(leetcode::tree::equals(exp, ret));
}
