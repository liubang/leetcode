#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * union-find
 */
namespace leetcode {
namespace uf {

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
  void unionn(int p, int q) {
    int pRoot = findRoot(p);
    int qRoot = findRoot(q);
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
    int pRoot = findRoot(p);
    int qRoot = findRoot(q);
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

 private:
  // 返回当前节点的根
  int findRoot(int p) {
    // 路径压缩
    if (p != parent_[p]) {
      parent_[p] = findRoot(parent_[p]);
    }

    return parent_[p];
  }

 private:
  int count_{0};
  std::vector<int> size_;
  std::vector<int> parent_;
};

}  // namespace uf
}  // namespace leetcode
