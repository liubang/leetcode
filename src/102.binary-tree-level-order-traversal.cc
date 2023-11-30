//=====================================================================
//
// 102.binary-tree-level-order-traversal.cc -
//
// Created by liubang on 2023/04/15 17:45
// Last Modified: 2023/04/15 17:45
//
//=====================================================================
#include "tree.h"
#include <memory>
#include <queue>
#include <vector>

#include <gtest/gtest.h>

using leetcode::tree::TreeNode;

namespace {
class Solution {
public:
    // 这种常用算法就应该经常删了重写,加强理解和记忆
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        std::vector<std::vector<int>> ret;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto size = static_cast<int64_t>(q.size());
            std::vector<int> level;
            for (int i = 0; i < size; ++i) {
                auto* f = q.front();
                level.push_back(f->val);
                if (f->left != nullptr)
                    q.push(f->left);
                if (f->right != nullptr)
                    q.push(f->right);
                q.pop();
            }
            ret.push_back(level);
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, binary_tree_level_order_traversal) {
    using leetcode::tree::destroy;

    Solution s;
    auto* root =
        new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    std::unique_ptr<TreeNode, decltype(&destroy)> root_ptr(root, destroy);

    std::vector<std::vector<int>> exp = {{3}, {9, 20}, {15, 7}};
    auto ret = s.levelOrder(root);
    EXPECT_EQ(exp, ret);
}
