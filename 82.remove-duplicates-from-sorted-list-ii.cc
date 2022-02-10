#include <gtest/gtest.h>

#include <vector>

#include "include/list.h"

using ListNode = leetcode::list::ListNode;

namespace {

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
      return head;
    }
    ListNode* dummy = new ListNode(0, head);
    ListNode* cur = dummy;
    while (cur->next != nullptr && cur->next->next != nullptr) {
      if (cur->next->val == cur->next->next->val) {
        int x = cur->next->val;
        while (cur->next != nullptr && cur->next->val == x) {
          cur->next = cur->next->next;
        }
      } else {
        cur = cur->next;
      }
    }
    ListNode* ret = dummy->next;
    delete dummy;
    return ret;
  }
};
}  // namespace

TEST(Leetcode, remove_duplicates_from_sorted_list_ii) {
  Solution s;
  {
    // 1,2,3,3,4,4,5
    std::vector<int> input = {1, 2, 3, 3, 4, 4, 5};
    ListNode* head = leetcode::list::create(input);
    std::vector<int> output = {1, 2, 5};
    ListNode* exp = leetcode::list::create(output);
    ListNode* ret = s.deleteDuplicates(head);
    ListNode* cur = ret;
    ListNode* cure = exp;
    while (cur != nullptr || cure != nullptr) {
      EXPECT_EQ(cur->val, cure->val);
      cur = cur->next;
      cure = cure->next;
    }

    leetcode::list::destroy(exp);
    leetcode::list::destroy(ret);
  }

  {
    // 1,1,1,2,3
    std::vector<int> input = {1, 1, 1, 2, 3};
    ListNode* head = leetcode::list::create(input);
    ListNode* exp = leetcode::list::create({2, 3});
    ListNode* ret = s.deleteDuplicates(head);

    ListNode* cur = ret;
    ListNode* cure = exp;
    while (cur != nullptr || cure != nullptr) {
      EXPECT_EQ(cur->val, cure->val);
      cur = cur->next;
      cure = cure->next;
    }

    leetcode::list::destroy(exp);
    leetcode::list::destroy(ret);
  }
}
