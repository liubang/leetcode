//=====================================================================
//
// lcci-0403.list-of-depth-lcci.cc -
//
// Created by liubang on 2023/04/15 17:48
// Last Modified: 2023/04/15 17:48
//
//=====================================================================
#include "list.h"
#include "tree.h"
#include <memory>
#include <vector>

#include <gtest/gtest.h>

using leetcode::list::ListNode;
using leetcode::tree::TreeNode;

namespace {
class Solution {
public:
    std::vector<ListNode*> listOfDepth(TreeNode* tree) {
        std::vector<ListNode*> ret;
        visit(&ret, tree, 0);
        return ret;
    }

private:
    void visit(std::vector<ListNode*>* ret, TreeNode* node, int dep) {
        if (node == nullptr) {
            return;
        }
        if (ret->size() >= (dep + 1)) {
            ListNode* cur = (*ret)[dep];
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = new ListNode(node->val);
        } else {
            ret->push_back(new ListNode(node->val));
        }
        visit(ret, node->left, dep + 1);
        visit(ret, node->right, dep + 1);
    }
};
} // namespace

TEST(Leetcode, list_of_depth_lcci) {
    using leetcode::tree::destroy;

    Solution s;
    TreeNode* tree = leetcode::tree::create({"1", "2", "3", "4", "5", "null", "7", "8"});
    std::unique_ptr<TreeNode, decltype(&destroy)> tree_ptr(tree, destroy);

    auto ret = s.listOfDepth(tree);
    std::vector<std::vector<int>> exp = {{1}, {2, 3}, {4, 5, 7}, {8}};
    EXPECT_EQ(ret.size(), exp.size());
    for (int i = 0; i < ret.size(); ++i) {
        int c = 0;
        ListNode* cur = ret[i];
        while (cur != nullptr || c < exp[i].size()) {
            EXPECT_EQ(cur->val, exp[i][c]);
            cur = cur->next;
            c++;
        }
    }

    for (auto* list : ret) {
        leetcode::list::destroy(list);
    }
}
