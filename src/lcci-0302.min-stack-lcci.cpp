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

#include <climits>
#include <stack>

namespace {
class MinStack {
public:
    MinStack() = default;
    virtual ~MinStack() = default;

    void push(int x) { st_.emplace(x, std::min(x, getMin())); }

    void pop() { st_.pop(); }

    int top() {
        if (!st_.empty()) {
            return st_.top().first;
        }
        return INT_MIN;
    }

    int getMin() {
        if (!st_.empty()) {
            return st_.top().second;
        }
        return INT_MAX;
    }

private:
    std::stack<std::pair<int, int>> st_;
};
} // namespace

TEST(Leetcode, min_stack_lcci) {
    MinStack min_stack;
    min_stack.push(-2);
    min_stack.push(0);
    min_stack.push(-3);

    EXPECT_EQ(-3, min_stack.getMin());
    EXPECT_EQ(-3, min_stack.top());

    min_stack.pop();
    EXPECT_EQ(-2, min_stack.getMin());
    EXPECT_EQ(0, min_stack.top());
}
