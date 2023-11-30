#! /bin/bash
#======================================================================
#
# format.sh -
#
# Created by liubang on 2023/09/21 23:27
# Last Modified: 2023/09/21 23:27
#
#======================================================================

CLANG_FORMAT='clang-format -i'

dirs=('include' 'src')

for dir in "${dirs[@]}"; do
    find "${dir}" -regex '.*\(\.cc\|\.h|\.cpp\)$' | while read file; do
        cmd="${CLANG_FORMAT} ${file}"
        echo ${cmd}
        eval ${cmd}
    done
done
