import os
import re

def replace_or_add_header(file_path, old_header_start, old_header_end, new_header):
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()

    # Check if the new header already exists
    if new_header in content:
        print(f"New header already exists in {file_path}, skipping.")
        return

    # Define the regex pattern for the old header
    pattern = re.compile(rf"{old_header_start}.*?{old_header_end}", re.DOTALL)

    # Check if the old header exists
    if pattern.search(content):
        # Replace the old header with the new header
        new_content = pattern.sub(new_header, content)
        print(f"Replaced old header in {file_path}")
    else:
        # Add the new header if no old header found
        new_content = new_header + '\n' + content
        print(f"Added new header to {file_path}")

    # Write the new content back to the file
    with open(file_path, 'w', encoding='utf-8') as f:
        f.write(new_content)

def add_or_replace_header_in_directory(directory_path, old_header_start, old_header_end, new_header, file_extensions=['.h', '.cc']):
    for root, _, files in os.walk(directory_path):
        for file_name in files:
            if any(file_name.endswith(ext) for ext in file_extensions):
                file_path = os.path.join(root, file_name)
                replace_or_add_header(file_path, old_header_start, old_header_end, new_header)

# Old header delimiters
old_header_start = "//====================================================================="
old_header_end = "//====================================================================="

# New header content
new_header = """\
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
"""

directory_path = './'

add_or_replace_header_in_directory(directory_path, old_header_start, old_header_end, new_header)
