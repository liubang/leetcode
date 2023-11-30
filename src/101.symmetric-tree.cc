//=====================================================================
//
// 101.symmetric-tree.cc -
//
// Created by liubang on 2023/04/15 17:45
// Last Modified: 2023/04/15 17:45
//
//=====================================================================
#include "tree.h"
#include <memory>
#include <string>
#include <vector>

#include <gtest/gtest.h>

using TreeNode = leetcode::tree::TreeNode;

namespace {
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return false;
        return ismirror(root->left, root->right);
    }

private:
    bool ismirror(TreeNode* l, TreeNode* r) {
        if (!l && !r)
            return true;
        if ((!l || !r) || (l->val != r->val))
            return false;
        return ismirror(l->left, r->right) && ismirror(l->right, r->left);
    }
};
} // namespace

TEST(Leetcode, symmetric_tree) {
    using leetcode::tree::destroy;

    Solution s;
    {
        std::vector<std::string> nodes = {"1", "2", "2", "3", "4", "4", "3"};
        auto root = leetcode::tree::create(nodes);
        std::unique_ptr<TreeNode, decltype(&destroy)> root_ptr(root, destroy);

        EXPECT_TRUE(s.isSymmetric(root));
    }

    {
        std::vector<std::string> nodes = {"1", "2", "2", "null", "3", "null", "3"};
        auto root = leetcode::tree::create(nodes);
        std::unique_ptr<TreeNode, decltype(&destroy)> root_ptr(root, destroy);

        EXPECT_FALSE(s.isSymmetric(root));
    }
}
