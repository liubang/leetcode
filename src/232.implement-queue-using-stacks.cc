#include <gtest/gtest.h>

#include <stack>

namespace {
class MyQueue {
public:
    MyQueue() = default;

    void push(int x) {
        while (!output_.empty()) {
            input_.push(output_.top());
            output_.pop();
        }
        input_.push(x);
    }

    int top() {
        while (!input_.empty()) {
            output_.push(input_.top());
            input_.pop();
        }
        return output_.top();
    }

    int pop() {
        while (!input_.empty()) {
            output_.push(input_.top());
            input_.pop();
        }
        int ret = output_.top();
        output_.pop();
        return ret;
    }

    bool empty() { return input_.empty() && output_.empty(); }

private:
    std::stack<int> input_;
    std::stack<int> output_;
};
} // namespace

TEST(Leetcode, implement_queue_using_stacks) {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    EXPECT_EQ(1, queue.top());
    EXPECT_EQ(1, queue.pop());
    EXPECT_FALSE(queue.empty());
}
