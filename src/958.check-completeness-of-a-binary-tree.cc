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
    bool isCompleteTree(TreeNode* root) {
        // 二叉树层次遍历
        std::queue<TreeNode*> queue;
        queue.push(root);
        int h = 1;
        while (!queue.empty()) {
            int size = queue.size();
            // 有中断
            int flag = true;
            for (int i = 0; i < size; ++i) {
                TreeNode* front = queue.front();
                queue.pop();
                if (front->left) {
                    if (!flag)
                        return false;
                    queue.push(front->left);
                } else {
                    flag = false;
                }

                if (front->right) {
                    if (!flag)
                        return false;
                    queue.push(front->right);
                } else {
                    flag = false;
                }
            }
            if (!queue.empty() && size != (1 << (h - 1))) {
                return false;
            }
            h++;
        }
        return true;
    }
};
} // namespace

TEST(Leetcode, check_completeness_of_a_binary_tree) {
    Solution s;
    {
        std::vector<std::string> nodes = {"1", "2", "3", "4", "5", "6"};
        auto root = leetcode::tree::create(nodes);
        EXPECT_TRUE(s.isCompleteTree(root));
        leetcode::tree::destroy(root);
    }

    {
        std::vector<std::string> nodes = {"1", "2", "3", "4", "5", "null", "7"};
        auto root = leetcode::tree::create(nodes);
        EXPECT_FALSE(s.isCompleteTree(root));
        leetcode::tree::destroy(root);
    }
}
