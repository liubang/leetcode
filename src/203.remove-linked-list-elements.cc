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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return head;
        while (head && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            if (cur->val == val) {
                ListNode* tmp = cur;
                cur = cur->next;
                pre->next = cur;
                delete tmp;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
} // namespace

TEST(Leetcode, remove_linked_list_elements) {
    Solution s;
    {
        auto* head = leetcode::list::create({1, 2, 6, 3, 4, 5, 6});
        auto* res = s.removeElements(head, 6);
        auto* exp = leetcode::list::create({1, 2, 3, 4, 5});
        EXPECT_TRUE(leetcode::list::equals(exp, res));

        leetcode::list::destroy(res);
        leetcode::list::destroy(exp);
    }
}
