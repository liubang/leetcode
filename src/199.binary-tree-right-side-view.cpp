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
#include <vector>

#include "tree.h"

namespace {
class Solution {
public:
    using TreeNode = leetcode::tree::TreeNode;

    std::vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        std::queue<TreeNode*> queue;
        std::vector<int> ret;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* front = queue.front();
                if (i == size - 1) {
                    ret.push_back(front->val);
                }
                queue.pop();
                if (front->left) {
                    queue.push(front->left);
                }
                if (front->right) {
                    queue.push(front->right);
                }
            }
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, binary_tree_right_side_view) {
    using TreeNode = leetcode::tree::TreeNode;
    Solution s;
    {
        TreeNode* root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)),
                                      new TreeNode(3, nullptr, new TreeNode(4)));

        std::vector<int> exp = {1, 3, 4};
        EXPECT_EQ(exp, s.rightSideView(root));
        leetcode::tree::destroy(root);
    }
}
