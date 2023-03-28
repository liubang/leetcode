#include <gtest/gtest.h>

#include "tree.h"

using leetcode::tree::TreeNode;

namespace {
class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    if (!root) {
      // 空二叉树肯定是平衡的
      return true;
    }
    // 如果一棵树为平衡二叉树
    // 当且仅当该树的左右子树高度差不大于1，且该树的左右子树均为平衡二叉树
    return std::abs(height(root->left) - height(root->right)) <= 1 &&
           isBalanced(root->left) && isBalanced(root->right);
  }

 private:
  int height(TreeNode* node) {
    if (!node) {
      return 0;
    }
    // + 1为加上当前节点
    return std::max(height(node->left), height(node->right)) + 1;
  }
};
}  // namespace

TEST(Leetcode, balanced_binary_tree) {
  Solution s;
  {
    auto* root =
        new TreeNode(3, new TreeNode(9),
                     new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    EXPECT_TRUE(s.isBalanced(root));
    leetcode::tree::destroy(root);
  }

  {
    auto* root = new TreeNode(
        1,
        new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(4)),
                     new TreeNode(3)),
        new TreeNode(2));
    EXPECT_FALSE(s.isBalanced(root));
    leetcode::tree::destroy(root);
  }
}
