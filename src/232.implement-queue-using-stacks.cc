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
