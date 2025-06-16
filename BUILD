#======================================================================
#
# BUILD -
#
# Created by liubang on 2023/04/17 15:51
# Last Modified: 2023/04/17 15:51
#
#======================================================================
# vim: ft=bzl

cc_library(
    name = "common",
    hdrs = glob(["include/*.h"]),
    includes = ["include"],
    visibility = ["//visibility:private"],
)

[
    cc_test(
        name = "%s" % f[4:f.rfind(".")],
        srcs = [
            "%s" % f,
        ],
        copts = [
            "-std=c++17",
            "-fno-omit-frame-pointer",
            "-fsanitize=address",
        ],
        linkopts = [
            "-fsanitize=address",
        ],
        deps = [
            ":common",
            "@googletest//:gtest_main",
        ],
    )
    for f in glob(["src/*.cc"])
]
