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
