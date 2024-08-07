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
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> ret;
        std::string cur;
        dfs(&ret, cur, root);
        return ret;
    }

private:
    void dfs(std::vector<std::string>* ret, std::string& cur, TreeNode* node) {
        cur.append(std::to_string(node->val));
        int size = static_cast<int>(cur.length());
        if (!node->left && !node->right) {
            ret->push_back(std::string(cur));
            return;
        }

        if (node->left) {
            cur.append("->");
            dfs(ret, cur, node->left);
            cur.erase(cur.begin() + size, cur.end());
        }
        if (node->right) {
            cur.append("->");
            dfs(ret, cur, node->right);
            cur.erase(cur.begin() + size, cur.end());
        }
    }
};
} // namespace

TEST(Leetcode, binary_tree_paths) {
    Solution s;
    {
        auto root = leetcode::tree::create({"11", "22", "23", "null", "59"});
        std::vector<std::string> exp = {"11->22->59", "11->23"};
        EXPECT_EQ(exp, s.binaryTreePaths(root));
        leetcode::tree::destroy(root);
    }
}
