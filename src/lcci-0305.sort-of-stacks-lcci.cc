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
class SortedStack {
public:
    SortedStack() = default;
    virtual ~SortedStack() = default;

    void push(int x) {
        if (st_.empty() || st_.top() >= x) {
            st_.push(x);
        } else {
            std::stack<int> temp;
            while (!st_.empty() && st_.top() < x) {
                temp.push(st_.top());
                st_.pop();
            }
            st_.push(x);
            while (!temp.empty()) {
                st_.push(temp.top());
                temp.pop();
            }
        }
    }

    void pop() {
        if (!st_.empty()) {
            st_.pop();
        }
    }

    int peek() { return st_.empty() ? -1 : st_.top(); }

    bool empty() { return st_.empty(); }

private:
    std::stack<int> st_;
};
} // namespace

TEST(Leetcode, sort_of_stack_lcci) {
    SortedStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(1, stack.peek());
    stack.pop();
    EXPECT_EQ(2, stack.peek());
    stack.pop();
    EXPECT_EQ(3, stack.peek());
    EXPECT_FALSE(stack.empty());
    stack.pop();
    EXPECT_TRUE(stack.empty());
}
