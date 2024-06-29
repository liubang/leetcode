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

#include <climits>
#include <string>
#include <vector>

#include "tree.h"

namespace {
class Solution {
public:
    using TreeNode = leetcode::tree::TreeNode;
    int minDiffInBST(TreeNode* root) {
        int ret = INT_MAX, pre = -1;
        dfs(ret, pre, root);
        return ret;
    }

private:
    void dfs(int& ret, int& pre, TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(ret, pre, node->left);
        if (pre >= 0) {
            ret = std::min(ret, node->val - pre);
        }
        pre = node->val;
        dfs(ret, pre, node->right);
    }
};
} // namespace

TEST(Leetcode, minimum_distance_between_bst_nodes) {
    Solution s;
    {
        std::vector<std::string> nodes = {
            "27", "null", "34", "null", "58", "50", "null", "44",
        };
        auto root = leetcode::tree::create(nodes);
        int ret = s.minDiffInBST(root);
        EXPECT_EQ(6, ret);
        leetcode::tree::destroy(root);
    }
}
