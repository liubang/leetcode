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
    virtual ~MyQueue() = default;

    void push(int x) { st1_.push(x); }

    int pop() {
        if (st2_.empty()) {
            while (!st1_.empty()) {
                st2_.push(st1_.top());
                st1_.pop();
            }
        }
        int ret = st2_.top();
        st2_.pop();
        return ret;
    }

    int peek() {
        if (st2_.empty()) {
            while (!st1_.empty()) {
                st2_.push(st1_.top());
                st1_.pop();
            }
        }
        return st2_.top();
    }

    bool empty() { return st1_.empty() && st2_.empty(); }

private:
    std::stack<int> st1_;
    std::stack<int> st2_;
};
} // namespace

TEST(Leetcode, implement_queue_using_stacks_lcci) {
    MyQueue my_queue;
    my_queue.push(1);
    my_queue.push(2);

    EXPECT_EQ(1, my_queue.peek());
    EXPECT_EQ(1, my_queue.pop());
    EXPECT_EQ(2, my_queue.peek());
    EXPECT_FALSE(my_queue.empty());
    EXPECT_EQ(2, my_queue.pop());
    EXPECT_TRUE(my_queue.empty());
}
