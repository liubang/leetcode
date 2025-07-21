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

#include "list.h"

namespace {
class Solution {
public:
    bool hasCycle(leetcode::list::ListNode* head) {
        if (!head || !head->next) {
            return false;
        }
        leetcode::list::ListNode* slow = head->next;
        leetcode::list::ListNode* fast = head->next->next;
        while (fast && slow) {
            if (fast == slow) {
                return true;
            }
            if (!fast->next) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
} // namespace

TEST(Leetcode, linked_list_cycle) {
    Solution s;
    using ListNode = leetcode::list::ListNode;

    {
        ListNode* head = new ListNode(3);
        head->next = new ListNode(2, new ListNode(0, new ListNode(-4, head)));
        EXPECT_TRUE(s.hasCycle(head));
        delete head->next->next->next;
        delete head->next->next;
        delete head->next;
        delete head;
    }

    {
        ListNode* head = new ListNode(3, new ListNode(2, new ListNode(1, new ListNode(0))));
        EXPECT_FALSE(s.hasCycle(head));
        leetcode::list::destroy(head);
    }
}
