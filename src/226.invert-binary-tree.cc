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

#include <queue>
#include <string>
#include <vector>

#include "tree.h"

namespace {
class Solution {
public:
    using TreeNode = leetcode::tree::TreeNode;
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* cur = queue.front();
            queue.pop();
            std::swap(cur->left, cur->right);
            if (cur->left)
                queue.push(cur->left);
            if (cur->right)
                queue.push(cur->right);
        }
        return root;
    }
};
} // namespace

TEST(Leetcode, invert_binary_tree) {
    Solution s;
    {
        std::vector<std::string> nodes = {"4", "2", "7", "1", "3", "6", "9"};
        std::vector<std::string> expnodes = {"4", "7", "2", "9", "6", "3", "1"};
        auto root = leetcode::tree::create(nodes);
        auto exp = leetcode::tree::create(expnodes);
        auto ret = s.invertTree(root);
        EXPECT_TRUE(leetcode::tree::equals(exp, ret));
        leetcode::tree::destroy(exp);
        leetcode::tree::destroy(ret);
    }
}
