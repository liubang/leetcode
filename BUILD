# vim: ft=bzl
package(default_visibility = ["//visibility:public"])

[
    cc_test(
        name = "%s" % f[4:f.rfind(".")],
        srcs = [
            "%s" % f,
        ] + glob([
            "include/*.h",
        ]),
        copts = [
            "-std=c++17",
            "-fno-omit-frame-pointer",
            "-fsanitize=address",
            "-Iinclude",
        ],
        linkopts = [
            "-fsanitize=address",
        ],
        deps = [
            "@googletest//:gtest_main",
        ],
    )
    for f in glob(["src/*.cc"])
]
