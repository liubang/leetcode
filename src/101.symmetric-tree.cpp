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

using TreeNode = leetcode::tree::TreeNode;

namespace {
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return false;
        return ismirror(root->left, root->right);
    }

private:
    bool ismirror(TreeNode* l, TreeNode* r) {
        if (!l && !r)
            return true;
        if ((!l || !r) || (l->val != r->val))
            return false;
        return ismirror(l->left, r->right) && ismirror(l->right, r->left);
    }
};
} // namespace

TEST(Leetcode, symmetric_tree) {
    using leetcode::tree::destroy;

    Solution s;
    {
        std::vector<std::string> nodes = {"1", "2", "2", "3", "4", "4", "3"};
        auto root = leetcode::tree::create(nodes);
        std::unique_ptr<TreeNode, decltype(&destroy)> root_ptr(root, destroy);

        EXPECT_TRUE(s.isSymmetric(root));
    }

    {
        std::vector<std::string> nodes = {"1", "2", "2", "null", "3", "null", "3"};
        auto root = leetcode::tree::create(nodes);
        std::unique_ptr<TreeNode, decltype(&destroy)> root_ptr(root, destroy);

        EXPECT_FALSE(s.isSymmetric(root));
    }
}
