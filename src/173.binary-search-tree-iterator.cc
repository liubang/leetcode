#include <gtest/gtest.h>

#include "tree.h"
#include <vector>

using leetcode::tree::TreeNode;

namespace {
class BSTIterator {
public:
    BSTIterator(TreeNode* node) { visit(node); }

    int next() {
        if (hasNext()) {
            return list_[idx_++];
        }
        return -1;
    }

    bool hasNext() { return idx_ < list_.size(); }

private:
    void visit(TreeNode* node) {
        if (!node) {
            return;
        }
        visit(node->left);
        list_.push_back(node->val);
        visit(node->right);
    }

private:
    std::vector<int> list_;
    int idx_{0};
};
} // namespace

TEST(Leetcode, binary_search_tree_iterator) {
    auto* root =
        new TreeNode(7, new TreeNode(3), new TreeNode(15, new TreeNode(9), new TreeNode(20)));
    BSTIterator it(root);

    EXPECT_EQ(3, it.next());
    EXPECT_EQ(7, it.next());
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(9, it.next());
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(15, it.next());
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(20, it.next());
    EXPECT_FALSE(it.hasNext());

    // destroy tree

    leetcode::tree::destroy(root);
}
