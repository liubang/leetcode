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
    using ListNode = leetcode::list::ListNode;
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->val == cur->next->val) {
                ListNode* n = cur->next;
                cur->next = cur->next->next;
                delete n;
            }
            cur = cur->next;
        }
        return head;
    }
};
} // namespace

TEST(Leetcode, remove_duplicates_form_sorted_list) {
    using ListNode = leetcode::list::ListNode;
    Solution s;
    {
        // 1, 1, 2
        ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2)));
        ListNode* ret = s.deleteDuplicates(head);
        EXPECT_EQ(1, ret->val);
        EXPECT_EQ(2, ret->next->val);
        leetcode::list::destroy(ret);
    }

    {
        ListNode* head = new ListNode(1);
        auto ret = s.deleteDuplicates(head);
        EXPECT_EQ(1, ret->val);
        leetcode::list::destroy(ret);
    }
}
