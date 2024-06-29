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

#include <unordered_set>

#include "list.h"

namespace {
class Solution {
public:
    using ListNode = leetcode::list::ListNode;

    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }
        std::unordered_set<ListNode*> set;
        ListNode* cur = head;
        while (cur) {
            if (set.count(cur) > 0) {
                return cur;
            }
            set.insert(cur);
            cur = cur->next;
        }
        return nullptr;
    }
};
} // namespace

TEST(Leetcode, linked_list_cycle_ii) {
    using ListNode = leetcode::list::ListNode;
    Solution s;
    {
        ListNode* head = new ListNode(0);
        head->next = new ListNode(1, new ListNode(2, new ListNode(3, head)));
        EXPECT_EQ(head, s.detectCycle(head));

        delete head->next->next->next;
        delete head->next->next;
        delete head->next;
        delete head;
    }

    {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        EXPECT_EQ(nullptr, s.detectCycle(head));
        leetcode::list::destroy(head);
    }
}
