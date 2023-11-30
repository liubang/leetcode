//=====================================================================
//
// 23.merge-k-sorted-lists.cc -
//
// Created by liubang on 2023/04/25 00:04
// Last Modified: 2023/04/25 00:04
//
//=====================================================================

#include "list.h"
#include <climits>
#include <memory>
#include <vector>

#include <gtest/gtest.h>

using leetcode::list::create;
using leetcode::list::destroy;
using leetcode::list::equals;
using leetcode::list::ListNode;

namespace {
class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*> lists) {
        int k = static_cast<int>(lists.size());
        if (k == 0)
            return nullptr;
        if (k == 1)
            return lists[0];
        ListNode* newHead = nullptr;
        ListNode* newCurr = nullptr;

        bool finished = false;
        do {
            int idx = -1;
            int min = INT_MAX;
            for (int i = 0; i < k; ++i) {
                if (lists[i] != nullptr && min > lists[i]->val) {
                    idx = i;
                    min = lists[i]->val;
                }
            }
            if (idx == -1)
                finished = true;
            else {
                if (newHead == nullptr) {
                    newHead = lists[idx];
                    newCurr = newHead;
                } else {
                    newCurr->next = lists[idx];
                    newCurr = newCurr->next;
                }
                lists[idx] = lists[idx]->next;
            }
        } while (!finished);

        return newHead;
    }
};
} // namespace

TEST(Leetcode, leetcode) {
    Solution s;
    EXPECT_TRUE(s.mergeKLists(std::vector<ListNode*>()) == nullptr);

    std::vector<ListNode*> inputs;
    inputs.push_back(nullptr);
    EXPECT_TRUE(s.mergeKLists(inputs) == nullptr);

    {
        ListNode* l1 = create({1, 4, 5});
        ListNode* l2 = create({1, 3, 4});
        ListNode* l3 = create({2, 6});

        std::vector<ListNode*> inputs;
        inputs.push_back(l1);
        inputs.push_back(l2);
        inputs.push_back(l3);

        ListNode* output = s.mergeKLists(inputs);
        ListNode* exp = create({1, 1, 2, 3, 4, 4, 5, 6});

        std::unique_ptr<ListNode, decltype(&destroy)> output_ptr(output, destroy);
        std::unique_ptr<ListNode, decltype(&destroy)> exp_ptr(exp, destroy);

        EXPECT_TRUE(equals(exp, output));
    }
}
