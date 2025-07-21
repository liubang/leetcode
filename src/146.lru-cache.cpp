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

#include <list>
#include <unordered_map>

namespace {
template <typename Key, typename Value> class LRUCache {
    using List = std::list<std::pair<Key, Value>>;
    using ListIterator = typename std::list<std::pair<Key, Value>>::iterator;
    using Map = std::unordered_map<Key, ListIterator>;

public:
    LRUCache(int capacity) : capacity_(capacity) {}

    void put(const Key& key, const Value& val) {
        if (map_.find(key) == map_.end()) {
            if (cache_.size() == capacity_) {
                map_.erase(cache_.back().first);
                cache_.pop_back();
            }
        } else {
            cache_.erase(map_[key]);
        }
        cache_.push_front({key, val});
        map_[key] = cache_.begin();
    }

    int get(const Key& key) {
        if (map_.find(key) == map_.end()) {
            return -1;
        }
        std::pair<int, int> kv = *map_[key];
        cache_.erase(map_[key]);
        cache_.push_front(kv);
        map_[key] = cache_.begin();
        return kv.second;
    }

private:
    int capacity_;
    List cache_;
    Map map_;
};
} // namespace

TEST(Leetcode, lru_cache) {
    LRUCache<int, int> cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(1, cache.get(1));
    cache.put(3, 3);
    EXPECT_EQ(-1, cache.get(2));
    cache.put(4, 4);
    EXPECT_EQ(-1, cache.get(1));
    EXPECT_EQ(3, cache.get(3));
    EXPECT_EQ(4, cache.get(4));
}
