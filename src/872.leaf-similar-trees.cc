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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> vecs1;
        std::vector<int> vecs2;
        dfs(vecs1, root1);
        dfs(vecs2, root2);
        return vecs1 == vecs2;
    }

private:
    void dfs(std::vector<int>& vecs, TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(vecs, node->left);
        if (!node->left && !node->right) {
            vecs.push_back(node->val);
        }
        dfs(vecs, node->right);
    }
};
} // namespace

TEST(Leetcode, leaf_similar_trees) {
    Solution s;
    {
        auto root1 = leetcode::tree::create({"1", "2"});
        auto root2 = leetcode::tree::create({"2", "2"});
        EXPECT_TRUE(s.leafSimilar(root1, root2));

        leetcode::tree::destroy(root1);
        leetcode::tree::destroy(root2);
    }

    {
        auto root1 = leetcode::tree::create({"1", "2", "3"});
        auto root2 = leetcode::tree::create({"1", "3", "2"});
        EXPECT_FALSE(s.leafSimilar(root1, root2));
        leetcode::tree::destroy(root1);
        leetcode::tree::destroy(root2);
    }

    {
        auto root1 =
            leetcode::tree::create({"3", "5", "1", "6", "2", "9", "8", "null", "null", "7", "4"});
        auto root2 = leetcode::tree::create({"3", "5", "1", "6", "7", "4", "2", "null", "null",
                                             "null", "null", "null", "null", "9", "8"});
        EXPECT_TRUE(s.leafSimilar(root1, root2));
        leetcode::tree::destroy(root1);
        leetcode::tree::destroy(root2);
    }
}
