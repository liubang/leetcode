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

#include <cstring>
#include <string>

namespace {
class Trie {
public:
    Trie() { head_ = new Node(); }

    ~Trie() { destroy(head_); }

    void insert(const std::string& word) {
        auto cur = head_;
        for (auto& c : word) {
            int idx = c - 'a';
            if (!cur->nodes[idx]) {
                cur->nodes[idx] = new Node(c);
            }
            cur = cur->nodes[idx];
        }
        cur->is_word = true;
    }

    bool search(const std::string& word) {
        auto cur = head_;
        for (auto& c : word) {
            int idx = c - 'a';
            if (!cur->nodes[idx]) {
                return false;
            }
            cur = cur->nodes[idx];
        }
        return cur->is_word;
    }

    bool prefix(const std::string& prefix) {
        auto cur = head_;
        for (auto& c : prefix) {
            int idx = c - 'a';
            if (!cur->nodes[idx]) {
                return false;
            }
            cur = cur->nodes[idx];
        }
        return true;
    }

private:
    struct Node {
        char c;
        bool is_word;
        Node* nodes[26];
        Node(char c = '0', bool is_word = false) : c(c), is_word(is_word) {
            std::memset(nodes, 0, sizeof(nodes));
        }
    };
    Node* head_;

private:
    void destroy(Node* node) {
        if (!node)
            return;
        for (Node* n : node->nodes) {
            destroy(n);
        }
        delete node;
    }
};
} // namespace

TEST(Leetcode, implement_trie_prefix_tree) {
    Trie trie;
    trie.insert("apple");
    EXPECT_TRUE(trie.search("apple"));
    EXPECT_FALSE(trie.search("app"));
    EXPECT_TRUE(trie.prefix("app"));
    trie.insert("app");
    EXPECT_TRUE(trie.search("apple"));
    EXPECT_TRUE(trie.search("app"));
    EXPECT_TRUE(trie.prefix("app"));
}
