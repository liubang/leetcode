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

class CQueue {
public:
    CQueue() = default;
    virtual ~CQueue() = default;

    void appendTail(int value) { st1_.push(value); }

    int deleteHead() {
        if (st2_.empty()) {
            if (st1_.empty()) {
                return -1;
            }
            while (!st1_.empty()) {
                st2_.push(st1_.top());
                st1_.pop();
            }
        }
        auto ret = st2_.top();
        st2_.pop();
        return ret;
    }

private:
    std::stack<int> st1_;
    std::stack<int> st2_;
};
} // namespace

TEST(Leetcode, yong_liang_ge_zhan_shi_xian_dui_lie_lcof) {
    CQueue q;
    q.appendTail(3);
    q.appendTail(4);
    q.appendTail(5);
    EXPECT_EQ(3, q.deleteHead());
    EXPECT_EQ(4, q.deleteHead());
    EXPECT_EQ(5, q.deleteHead());
    EXPECT_EQ(-1, q.deleteHead());
}
