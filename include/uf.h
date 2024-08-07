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

#pragma once

#include <vector>

/*
 * union-find
 */
namespace leetcode::uf {

class UnionFind {
public:
    UnionFind(int n) : count_(n) {
        for (int i = 0; i < n; ++i) {
            // 最初每个节点都是独立的
            parent_.push_back(i);
            // 最初每个连通分量均为1
            size_.push_back(1);
        }
    }

    // 将 p 和 q  连接
    void unite(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) {
            return;
        }

        // 将少的连接到多的分量上
        // 平衡性优化
        if (size_[pRoot] < size_[qRoot]) {
            parent_[pRoot] = qRoot;
            size_[qRoot] += size_[pRoot];
        } else {
            parent_[qRoot] = pRoot;
            size_[pRoot] += size_[qRoot];
        }
        count_--;
    }

    // 判断 p 和 q  是否连通
    bool connected(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        return pRoot == qRoot;
    }

    // 返回途中有多少个连通的分量
    int count() { return count_; }

    int getMaxConnectSize() {
        int ret = 0;
        for (int i = 0; i < parent_.size(); ++i) {
            if (i == parent_[i]) {
                ret = std::max(ret, size_[i]);
            }
        }
        return ret;
    }

    // 返回当前节点的根
    int find(int p) {
        // 路径压缩
        if (p != parent_[p]) {
            parent_[p] = find(parent_[p]);
        }

        return parent_[p];
    }

private:
    int count_{0};
    std::vector<int> size_;
    std::vector<int> parent_;
};

} // namespace leetcode::uf
