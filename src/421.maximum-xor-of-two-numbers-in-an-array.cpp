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

#include <vector>

namespace {
struct TrieNode {
    TrieNode* left;
    TrieNode* right;
    TrieNode() : left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Solution() : root_(new TrieNode()) {}
    ~Solution() { destroy(root_); }
    void reset() {
        destroy(root_);
        root_ = new TrieNode();
    }

    int findMaximumXOR(const std::vector<int>& nums) {
        for (auto num : nums) {
            add(num);
        }
        int ret = 0;
        for (auto num : nums) {
            TrieNode* cur = root_;
            int tmp = 0;
            for (int i = 30; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (bit == 0) {
                    if (cur->left) {
                        tmp = tmp | (1 << i);
                        cur = cur->left;
                    } else {
                        cur = cur->right;
                    }
                } else {
                    if (cur->right) {
                        tmp = tmp | (1 << i);
                        cur = cur->right;
                    } else {
                        cur = cur->left;
                    }
                }
            }
            ret = std::max(ret, tmp);
        }
        return ret;
    }

private:
    void destroy(TrieNode* node) {
        if (!node)
            return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    void add(int num) {
        TrieNode* cur = root_;
        for (int i = 30; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (bit == 1) {
                if (!cur->left) {
                    cur->left = new TrieNode();
                }
                cur = cur->left;
            } else {
                if (!cur->right) {
                    cur->right = new TrieNode();
                }
                cur = cur->right;
            }
        }
    }

private:
    TrieNode* root_;
};
} // namespace

TEST(Leetcode, maximum_xor_of_two_numbers_in_an_array) {
    Solution s;
    EXPECT_EQ(28, s.findMaximumXOR({3, 10, 5, 25, 2, 8}));
    s.reset();
    EXPECT_EQ(0, s.findMaximumXOR({0}));
    s.reset();
    EXPECT_EQ(6, s.findMaximumXOR({2, 4}));
    s.reset();
    EXPECT_EQ(10, s.findMaximumXOR({8, 10, 2}));
    s.reset();
    EXPECT_EQ(127, s.findMaximumXOR({14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70}));
}
