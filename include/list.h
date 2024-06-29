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

#pragma once

#include <vector>

namespace leetcode::list {
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x, ListNode* next = nullptr) : val(x), next(next) {}
};

ListNode* create(const std::vector<int>& vecs) {
    if (vecs.empty()) {
        return nullptr;
    }
    auto* root = new ListNode(vecs[0]);
    ListNode* cur = root;
    for (int i = 1; i < vecs.size(); ++i) {
        cur->next = new ListNode(vecs[i]);
        cur = cur->next;
    }
    return root;
}

// 释放无环连表
void destroy(ListNode* node) {
    ListNode* cur = node;
    while (cur) {
        ListNode* next = cur->next;
        delete cur;
        cur = next;
    }
}

bool equals(ListNode* lhs, ListNode* rhs) {
    if (lhs && rhs) {
        return lhs->val == rhs->val && equals(lhs->next, rhs->next);
    }
    return lhs == rhs;
}

} // namespace leetcode::list
