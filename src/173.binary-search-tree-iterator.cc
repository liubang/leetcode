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

#include "tree.h"
#include <vector>

using leetcode::tree::TreeNode;

namespace {
class BSTIterator {
public:
    BSTIterator(TreeNode* node) { visit(node); }

    int next() {
        if (hasNext()) {
            return list_[idx_++];
        }
        return -1;
    }

    bool hasNext() { return idx_ < list_.size(); }

private:
    void visit(TreeNode* node) {
        if (!node) {
            return;
        }
        visit(node->left);
        list_.push_back(node->val);
        visit(node->right);
    }

private:
    std::vector<int> list_;
    int idx_{0};
};
} // namespace

TEST(Leetcode, binary_search_tree_iterator) {
    auto* root =
        new TreeNode(7, new TreeNode(3), new TreeNode(15, new TreeNode(9), new TreeNode(20)));
    BSTIterator it(root);

    EXPECT_EQ(3, it.next());
    EXPECT_EQ(7, it.next());
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(9, it.next());
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(15, it.next());
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(20, it.next());
    EXPECT_FALSE(it.hasNext());

    // destroy tree

    leetcode::tree::destroy(root);
}
