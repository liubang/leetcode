// Copyright (c) 2025 The Authors. All rights reserved.
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

#include <set>
#include <string>

namespace {
class Soluction {
public:
    bool isValid(const std::string& word) {
        static std::set<char> meta = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        if (word.size() < 3) {
            return false;
        }

        bool a = false;
        bool b = false;
        for (const char c : word) {
            if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                return false;
            }
            if (meta.count(c) > 0) {
                a = true;
            } else if (!(c >= '0' && c <= '9')) {
                b = true;
            }
        }
        return a && b;
    }
};
} // namespace

TEST(Leetcode, valid_word) {
    Soluction s;
    EXPECT_TRUE(s.isValid("234Adas"));
    EXPECT_FALSE(s.isValid("b3"));
    EXPECT_FALSE(s.isValid("a3$e"));
    EXPECT_FALSE(s.isValid("uUe9"));
}
