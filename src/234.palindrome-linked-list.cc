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

#include <stack>

#include "list.h"

namespace {
class Solution {
public:
    using ListNode = leetcode::list::ListNode;
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        std::stack<ListNode*> stack;
        while (fast && fast->next) {
            stack.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) {
            slow = slow->next;
        }
        while (slow) {
            if (stack.top()->val != slow->val) {
                return false;
            } else {
                stack.pop();
                slow = slow->next;
            }
        }
        return stack.empty();
    }
};
} // namespace

TEST(Leetcode, palindrome_linked_list) {
    using ListNode = leetcode::list::ListNode;
    Solution s;
    {
        ListNode* list = leetcode::list::create({1, 2, 2, 3, 2, 2, 1});
        EXPECT_TRUE(s.isPalindrome(list));
        leetcode::list::destroy(list);
    }

    {
        ListNode* list = leetcode::list::create({1, 2, 3, 4, 5});
        EXPECT_FALSE(s.isPalindrome(list));
        leetcode::list::destroy(list);
    }
}
