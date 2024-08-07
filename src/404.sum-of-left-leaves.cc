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

#include <string>
#include <vector>

#include "tree.h"

namespace {
class Solution {
public:
    using TreeNode = leetcode::tree::TreeNode;
    int sumOfLeftLeaves(TreeNode* root) {
        int ret = 0;
        dfs(ret, root->left, true);
        dfs(ret, root->right, false);
        return ret;
    }

private:
    void dfs(int& ret, TreeNode* node, bool left) {
        if (!node) {
            return;
        }
        if (left && !node->left && !node->right) {
            ret += node->val;
            return;
        }
        dfs(ret, node->left, true);
        dfs(ret, node->right, false);
    }
};
} // namespace

TEST(Leetcode, sum_of_left_leaves) {
    Solution s;
    {
        auto root = leetcode::tree::create({"1", "2", "null", "3", "null", "4", "null", "5"});
        EXPECT_EQ(5, s.sumOfLeftLeaves(root));
        leetcode::tree::destroy(root);
    }
    {
        auto root = leetcode::tree::create({"1"});
        EXPECT_EQ(0, s.sumOfLeftLeaves(root));
        leetcode::tree::destroy(root);
    }
    {
        auto root = leetcode::tree::create({"3", "9", "20", "null", "null", "15", "7"});
        EXPECT_EQ(24, s.sumOfLeftLeaves(root));
        leetcode::tree::destroy(root);
    }
}
