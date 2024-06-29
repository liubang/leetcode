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

using ListNode = leetcode::list::ListNode;

namespace {
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }
        int move = k % len;
        if (move == 0) {
            return head;
        }
        int i = 0;
        cur = head;
        while (i < (len - move - 1)) {
            cur = cur->next;
            i++;
        }
        ListNode* h = cur->next;
        cur->next = nullptr;
        cur = h;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = head;
        return h;
    }
};
} // namespace

TEST(Leetcode, rotate_list) {
    Solution s;
    ListNode* node = leetcode::list::create({1, 2, 3, 4, 5});
    ListNode* ret = s.rotateRight(node, 2);
    std::vector<int> exp = {4, 5, 1, 2, 3};
    ListNode* cur = ret;
    int i = 0;
    while (cur) {
        EXPECT_EQ(exp[i], cur->val);
        cur = cur->next;
        i++;
    }
    leetcode::list::destroy(ret);
}
