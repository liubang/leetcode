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

using leetcode::tree::TreeNode;

namespace {
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        std::queue<TreeNode*> queue;
        queue.push(root);
        std::vector<std::vector<int>> ret;
        int i = 0;
        while (!queue.empty()) {
            int size = queue.size();
            std::vector<int> row;
            for (int m = 0; m < size; ++m) {
                TreeNode* front = queue.front();
                queue.pop();
                if ((i & 1) == 0) {
                    row.push_back(front->val);
                } else {
                    row.insert(row.begin(), front->val);
                }
                if (front->left) {
                    queue.push(front->left);
                }
                if (front->right) {
                    queue.push(front->right);
                }
            }
            ret.emplace_back(std::move(row));
            i++;
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, cong_shang_dao_xia_da_yin_er_cha_shu_iii_lcof) {
    Solution s;
    auto* root =
        new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    std::vector<std::vector<int>> exp = {{3}, {20, 9}, {15, 7}};
    EXPECT_EQ(exp, s.levelOrder(root));

    leetcode::tree::destroy(root);
}
