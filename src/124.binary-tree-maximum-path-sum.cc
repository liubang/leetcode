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
    int maxPathSum(leetcode::tree::TreeNode* root) {
        int ret = INT_MIN;
        std::function<int(leetcode::tree::TreeNode*)> getMax = [&](leetcode::tree::TreeNode* node) {
            if (!node) {
                return 0;
            }
            int left = std::max(0, getMax(node->left));
            int right = std::max(0, getMax(node->right));
            ret = std::max(ret, node->val + left + right);
            return std::max(left, right) + node->val;
        };
        getMax(root);
        return ret;
    }
};
} // namespace

TEST(Leetcode, binary_tree_maximun_path_sum) {
    Solution s;
    std::vector<std::string> nodes = {"-10", "9", "20", "null", "null", "15", "7"};
    leetcode::tree::TreeNode* root = leetcode::tree::create(nodes);
    EXPECT_EQ(42, s.maxPathSum(root));
    leetcode::tree::destroy(root);
}
