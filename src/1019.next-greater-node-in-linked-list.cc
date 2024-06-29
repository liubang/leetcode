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

#include <stack>
#include <vector>

#include "list.h"

#include <gtest/gtest.h>

using leetcode::list::ListNode;

namespace {
class Solution {
public:
    std::vector<int> nextLargerNode(ListNode* head) {
        std::vector<int> vecs;
        ListNode* cur = head;
        while (cur != nullptr) {
            vecs.push_back(cur->val);
            cur = cur->next;
        }
        std::vector<int> ret(vecs.size(), 0);
        std::stack<int> st;
        for (int i = vecs.size() - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= vecs[i])
                st.pop();
            ret[i] = st.empty() ? 0 : st.top();
            st.push(vecs[i]);
        }
        return ret;
    }
};
} // namespace

TEST(Leetcode, next_greater_node_in_linked_list) {
    Solution s;
    {
        ListNode* head = leetcode::list::create({2, 1, 5});
        std::vector<int> exp = {5, 5, 0};
        EXPECT_EQ(exp, s.nextLargerNode(head));
        leetcode::list::destroy(head);
    }

    {
        ListNode* head = leetcode::list::create({2, 7, 4, 3, 5});
        std::vector<int> exp = {7, 0, 5, 5, 0};
        EXPECT_EQ(exp, s.nextLargerNode(head));
        leetcode::list::destroy(head);
    }

    {
        ListNode* head = leetcode::list::create({2});
        std::vector<int> exp = {0};
        EXPECT_EQ(exp, s.nextLargerNode(head));
        leetcode::list::destroy(head);
    }

    {
        ListNode* head = leetcode::list::create({3, 3});
        std::vector<int> exp = {0, 0};
        EXPECT_EQ(exp, s.nextLargerNode(head));
        leetcode::list::destroy(head);
    }

    {
        ListNode* head = leetcode::list::create({4, 3, 2, 5, 1, 8, 10});
        std::vector<int> exp = {5, 5, 5, 8, 8, 10, 0};
        EXPECT_EQ(exp, s.nextLargerNode(head));
        leetcode::list::destroy(head);
    }
}
