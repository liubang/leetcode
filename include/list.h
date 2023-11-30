//=====================================================================
//
// list.h -
//
// Created by liubang on 2023/11/30 23:18
// Last Modified: 2023/11/30 23:18
//
//=====================================================================
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
