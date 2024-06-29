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

using leetcode::tree::TreeNode;

namespace {
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) {
            return false;
        }
        // 找到相等的节点，然后判断以此节点为根的子树是否相等
        // 若相等，则直接返回true
        // 否则找下一个相等的节点
        if (A->val == B->val) {
            return isEqual(A, B);
        }
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

private:
    bool isEqual(TreeNode* a, TreeNode* b) {
        // b已经遍历完了，不管a是否遍历完，a都包含了b
        if (!b) {
            return true;
        }
        if (a && b && a->val == b->val) {
            return isEqual(a->left, b->left) && isEqual(a->right, b->right);
        }
        return false;
    }
};
} // namespace

TEST(Leetcode, shu_de_zi_jie_gou_lcof) {
    Solution s;
    using leetcode::tree::destroy;

    /*
     *     3
     *    / \
     *   4   5
     *  / \
     * 1   2
     *
     */
    auto* root =
        new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2)), new TreeNode(5));

    auto* sub = new TreeNode(3, new TreeNode(4), nullptr);
    auto* notsub = new TreeNode(3, new TreeNode(1), nullptr);

    EXPECT_TRUE(s.isSubStructure(root, sub));
    EXPECT_FALSE(s.isSubStructure(root, notsub));

    destroy(root);
    destroy(sub);
    destroy(notsub);
}
