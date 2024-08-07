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

#include "list.h"
#include <gtest/gtest.h>

using leetcode::list::ListNode;

namespace {
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = nullptr;
        ListNode* r;
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        int sup = 0;

        while (n1 != nullptr || n2 != nullptr) {
            int val = sup;
            if (n1 != nullptr) {
                val += n1->val;
                n1 = n1->next;
            }
            if (n2 != nullptr) {
                val += n2->val;
                n2 = n2->next;
            }
            sup = val / 10;
            if (ret == nullptr) {
                ret = new ListNode(val % 10);
                r = ret;
            } else {
                r->next = new ListNode(val % 10);
                r = r->next;
            }
        }
        if (sup > 0)
            r->next = new ListNode(sup);
        return ret;
    }
};
} // namespace

TEST(Leetcode, add_two_numbers) {
    Solution s;
    {
        ListNode* l1 = leetcode::list::create({2, 4, 3});
        ListNode* l2 = leetcode::list::create({5, 6, 4});
        ListNode* l3 = s.addTwoNumbers(l1, l2);
        ListNode* exp = leetcode::list::create({7, 0, 8});

        EXPECT_TRUE(equals(exp, l3));
        leetcode::list::destroy(l1);
        leetcode::list::destroy(l2);
        leetcode::list::destroy(l3);
        leetcode::list::destroy(exp);
    }

    {
        ListNode* l1 = leetcode::list::create({0});
        ListNode* l2 = leetcode::list::create({0});
        ListNode* l3 = s.addTwoNumbers(l1, l2);
        ListNode* exp = leetcode::list::create({0});

        EXPECT_TRUE(equals(exp, l3));
        leetcode::list::destroy(l1);
        leetcode::list::destroy(l2);
        leetcode::list::destroy(l3);
        leetcode::list::destroy(exp);
    }

    {
        ListNode* l1 = leetcode::list::create({9, 9, 9, 9, 9, 9, 9});
        ListNode* l2 = leetcode::list::create({9, 9, 9, 9});
        ListNode* l3 = s.addTwoNumbers(l1, l2);
        ListNode* exp = leetcode::list::create({8, 9, 9, 9, 0, 0, 0, 1});

        EXPECT_TRUE(equals(exp, l3));
        leetcode::list::destroy(l1);
        leetcode::list::destroy(l2);
        leetcode::list::destroy(l3);
        leetcode::list::destroy(exp);
    }
}
