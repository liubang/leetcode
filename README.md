<h1 align="center">Leetcode</h1>

<div align="center"><p>
    <a href="https://github.com/liubang/leetcode/actions">
        <img src="https://img.shields.io/github/actions/workflow/status/liubang/leetcode/integrate.yml?style=flat-square&branch=main" alt="Build"/>
    </a>
    <a href="https://github.com/liubang/leetcode/blob/main/LICENSE">
        <img src="https://img.shields.io/github/license/liubang/leetcode?style=flat-square&logo=MIT&label=License" alt="License"/>
    </a>
    <a href="https://github.com/liubang/leetcode/pulse">
        <img src="https://img.shields.io/github/last-commit/liubang/leetcode?style=flat-square" alt="Last commit"/>
    </a>
    <a href="#">
        <img src="https://img.shields.io/github/languages/top/liubang/leetcode?style=flat-square"
alt="" />
    </a>
</p></div>

## build and run

```bash
bazel test //...
```

## coverage report

```bash
bazel coverage -s \
    --instrument_test_targets \
    --combined_report=lcov \
    //...

genhtml --output report "$(bazel info output_path)/_coverage/_coverage_report.dat"
```

[There is the code coverage report](https://liubang.github.io/leetcode/src/index.html)
