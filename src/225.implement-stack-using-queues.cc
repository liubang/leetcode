#include <gtest/gtest.h>
#include <queue>

namespace {
class MyStack {
 public:
  MyStack() = default;

  void push(int x) {
    auto& q = q1_.empty() ? q2_ : q1_;
    q.push(x);
  }

  int pop() {
    auto& i = q1_.empty() ? q2_ : q1_;
    auto& o = q1_.empty() ? q1_ : q2_;

    while (i.size() > 1) {
      o.push(i.front());
      i.pop();
    }

    int ret = i.front();
    i.pop();
    return ret;
  }

  int top() {
    auto& i = q1_.empty() ? q2_ : q1_;
    auto& o = q1_.empty() ? q1_ : q2_;

    while (i.size() > 1) {
      o.push(i.front());
      i.pop();
    }
    int ret = i.front();
    i.pop();
    o.push(ret);
    return ret;
  }

  bool empty() { return q1_.empty() && q2_.empty(); }

 private:
  std::queue<int> q1_;
  std::queue<int> q2_;
};
}  // namespace

TEST(Leetcode, implement_stack_using_queues) {
  MyStack stack;
  stack.push(1);
  stack.push(2);
  EXPECT_EQ(2, stack.top());
  EXPECT_EQ(2, stack.pop());
  EXPECT_FALSE(stack.empty());
}
