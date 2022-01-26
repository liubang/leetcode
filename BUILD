# vim: ft=bzl
package(default_visibility = ["//visibility:public"])

[
    cc_test(
        name = "%s" % f[0:f.rfind(".")],
        srcs = [
            "%s" % f,
        ] + glob([
            "include/*.h",
        ]),
        copts = [
            "-std=gnu++17",
            "-fno-omit-frame-pointer",
            "-fsanitize=address",
        ],
        linkopts = [
            "-fsanitize=address",
        ],
        deps = [
            "@com_google_googletest//:gtest_main",
        ],
    )
    for f in glob(["*.cc"])
]
