//=====================================================================
//
// 129.sum-root-to-leaf-numbers.cc -
//
// Created by liubang on 2023/04/23 11:15
// Last Modified: 2023/04/23 11:15
//
//=====================================================================
#include "tree.h"

#include <memory>
#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace {
class Solution {
public:
    using TreeNode = leetcode::tree::TreeNode;
    int sumNumbers(TreeNode* root) { return dfs(root, 0); }

private:
    int dfs(TreeNode* node, int sum) {
        if (!node) {
            return 0;
        }
        sum = sum * 10 + node->val;
        if (!node->left && !node->right) {
            return sum;
        }
        return dfs(node->left, sum) + dfs(node->right, sum);
    }
};
} // namespace

TEST(Leetcode, sum_root_to_leaf_numbers) {
    using leetcode::tree::destroy;
    Solution s;
    {
        std::vector<std::string> nodes = {"1", "2", "3"};
        auto* root = leetcode::tree::create(nodes);
        std::unique_ptr<leetcode::tree::TreeNode, decltype(&destroy)> root_ptr(root, destroy);
        EXPECT_EQ(25, s.sumNumbers(root));
    }

    {
        std::vector<std::string> nodes = {"4", "9", "0", "5", "1"};
        auto* root = leetcode::tree::create(nodes);
        std::unique_ptr<leetcode::tree::TreeNode, decltype(&destroy)> root_ptr(root, destroy);
        EXPECT_EQ(1026, s.sumNumbers(root));
    }
}
