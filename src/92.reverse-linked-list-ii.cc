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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int s = 1, e = 1;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (s < left && e < right && cur) {
            pre = cur;
            cur = cur->next;
            s++, e++;
        }
        ListNode* ss = pre;
        ListNode* se = cur;
        pre = nullptr;
        while (e <= right && cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            e++;
        }
        if (ss) {
            ss->next = pre;
        }
        se->next = cur;
        return ss ? head : pre;
    }
};
} // namespace

TEST(Leetcode, reverse_linked_list_ii) {
    Solution s;
    {
        auto head = leetcode::list::create({1, 2, 3, 4, 5});
        auto ret = s.reverseBetween(head, 2, 4);
        auto exp = leetcode::list::create({1, 4, 3, 2, 5});
        EXPECT_TRUE(leetcode::list::equals(exp, ret));

        leetcode::list::destroy(ret);
        leetcode::list::destroy(exp);
    }
}
