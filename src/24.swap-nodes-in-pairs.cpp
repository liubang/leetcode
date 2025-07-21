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

#include "list.h"

namespace {
class Solution {
public:
    using ListNode = leetcode::list::ListNode;
    // 方法一
    ListNode* swapPairs1(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        std::vector<ListNode*> vecs;
        ListNode* cur = head;
        while (cur) {
            vecs.emplace_back(cur);
            cur = cur->next;
        }
        for (int i = 0; i < vecs.size() - 1; i += 2) {
            std::swap(vecs[i], vecs[i + 1]);
            vecs[i]->next = vecs[i + 1];
            if (i > 0) {
                vecs[i - 1]->next = vecs[i];
            }
            vecs[i + 1]->next = i == vecs.size() - 2 ? nullptr : vecs[i + 2];
        }
        return vecs[0];
    }

    ListNode* swapPairs2(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newhead = head->next;
        head->next = swapPairs2(newhead->next);
        newhead->next = head;
        return newhead;
    }
};
} // namespace

TEST(Leetcode, swap_nodes_in_pairs) {
    Solution s;
    {
        std::vector<int> nodes = {1, 2, 3, 4, 5};
        auto head = leetcode::list::create(nodes);
        auto ret = s.swapPairs1(head);
        std::vector<int> exps = {2, 1, 4, 3, 5};
        auto cur = ret;
        int i = 0;
        while (cur) {
            EXPECT_EQ(cur->val, exps[i++]);
            cur = cur->next;
        }
        leetcode::list::destroy(ret);
    }

    {
        std::vector<int> nodes = {1, 2, 3, 4, 5};
        auto head = leetcode::list::create(nodes);
        auto ret = s.swapPairs2(head);
        std::vector<int> exps = {2, 1, 4, 3, 5};
        auto cur = ret;
        int i = 0;
        while (cur) {
            EXPECT_EQ(cur->val, exps[i++]);
            cur = cur->next;
        }
        leetcode::list::destroy(ret);
    }
}
