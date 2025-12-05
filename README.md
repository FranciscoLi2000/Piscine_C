# Piscine_C — 轻量版 C 练习库 & 进阶路线图 😎

一个把 42 Barcelona 的 Piscine（C00–C13）练习整理成可复习、可扩展的 GitHub 仓库的模板。
既可以当刷题集复习基础，也能逐步扩展成面向工程的小型 C 工具箱。

⸻

## 为什么要有这个 repo？（TL;DR）

现在手里有一堆经典的 C 练习函数。把它们组织成项目能让你：
•	快速复盘基础（指针、字符串、链表、树、递归、算法）。
•	用测试/CI 验证实现，避免遗忘和回归。
•	逐步把练习升级成工程库（添加容器、线程、网络、内存管理等），把“刷题”变成“能拿到工作里用”的工具箱。

好处：面试、项目、写小工具、写崩溃少的 C 代码都更顺手。

⸻

## 主要内容

✅ 特性
•	收录 C00–C13 常见函数与类型（c_piscine.h）用于快速回顾。
•	推荐目录结构和 Makefile 示例（即刻可编译、测试）。
•	测试框架示例（Criterion 或自制测试 harness）。
•	CI（GitHub Actions）示例工作流（编译 + 单元测试 + ASAN）。
•	学习路径与进阶任务清单（一步步把练习库变成“能在工作中用”的库）。

⸻

## 快速开始

git clone https://github.com/...
cd c_piscine

### 编译
make

### 运行测试
make test

### 编译单个示例（手动）：
cc -Wall -Wextra -Werror -Iinclude examples/example.c src/*.c -o bin/example
./bin/example

### 建议常用编译选项（开发时）：
-g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer

⸻

## 推荐项目结构

c_piscine/
├─ include/
│  └─ c_piscine.h
├─ src/
│  └─ (模块实现 .c)
├─ tests/
│  └─ (unit tests, e.g. Criterion)
├─ examples/
│  └─ small demos
├─ tools/
│  └─ scripts (run_tests.sh, norm_check.sh, format.sh)
├─ .github/workflows/
│  └─ ci.yml
├─ Makefile
├─ README.md
└─ LICENSE

⸻

## 如何把这个仓库从“练习”升级到“工程级”——实操清单

下面按优先级给你能直接上手做的任务：

必做（马上做）
•	README.md, LICENSE（MIT/Apache2）。
•	Makefile（build / clean / test / format）。
•	include/ + src/ 明确分离。
•	tests/（Criterion） + make test。
•	GitHub Actions：compile + test + asan。
•	clang-format 配置并在 CI 中检查。

强烈建议（很加分）
•	添加 safe_alloc（失败处理的 malloc 封装）。
•	实现 vector、hashmap、string_builder。
•	增加 examples/：小型 HTTP client、CSV parser、CLI 工具。
•	性能/内存测试（benchmarks + valgrind / asan）。
•	写每个函数的 contract（参数、返回值、复杂度、错误行为）在 docs/ 或头注释里。

⸻

## 学习路线（复习 -> 进阶 -> 工程化）

### Level 1 — 复习基础（1–2 天/模块）
•	字符串/数组/指针操作函数（ft_strlen, ft_strcpy, ft_split 等）。
•	基本算法（排序、查找、递归、斐波那契、阶乘）。
•	手写链表/树基本操作（create, insert, traverse）。

### Level 2 — 系统编程入门（2–4 周）
•	malloc/free 熟练，错误处理风格：返回值检查 + 统一失败处理。
•	文件 IO（低级 read/write + stdio）。
•	进程/线程基础：fork、exec、pthread 入门示例。
•	简单 socket：TCP client/server demo。

### Level 3 — 工程实践（4–8 周）
•	数据结构库：vector/hashmap/queue/priority_queue。
•	内存池/arena allocator，避免频繁 small alloc 导致碎片。
•	安全与调试：ASAN/UBSAN、valgrind、perf 基准。
•	CI/CD：GH Actions，release 流程，测试覆盖率。
•	文档（Doxygen）、examples、语义版本控制（SemVer）。

⸻

## 示例：如何在项目里使用 c_piscine.h

```
	examples/print_list.c

	#include "c_piscine.h"
	#include <stdio.h>

	int	main(void)
	{
		t_list	*l = ft_create_elem("hello");

		ft_list_push_back(&l, "world");
		ft_list_foreach(l, &puts);
		return (0);
	}
```

编译：
gcc -Iinclude examples/print_list.c src/list/*.c -o bin/print_list
./bin/print_list


⸻

## CI 示例（GitHub Actions — 片段）

把下面放 .github/workflows/ci.yml（示例）

name: CI

on: [push, pull_request]

jobs:
	build-and-test:
		runs-on: ubuntu-latest
		steps:
			- uses: actions/checkout@v4
			- name: Install deps
				run: sudo apt-get update && sudo apt-get install -y libcriterion-dev
			- name: Build
				run: make
			- name: Run tests
				run: make test

（根据你用的测试框架/包管理器微调）

⸻

## 测试与质量保障建议
•	单元测试：Criterion（简单，上手快）或自制 harness。
•	在 CI 中运行：-fsanitize=address,undefined。
•	静态分析：clang-tidy + cppcheck（C 代码也有用处）。
•	格式化：clang-format 自动化格式检查。

⸻

## 贡献 & 代码风格
•	分支策略：main（稳定），dev（日常开发），feature-xxx（新功能）。
•	PR 模板：简要描述、如何复现、测试用例、影响范围。
•	代码风格：启用 -Wall -Wextra -Werror，尽量写清楚函数 contract。
•	每个 public header 下写清楚：线程安全？可重入？依赖啥？

⸻

## 常见问题（FAQ）

Q: 这个仓库能直接用于生产吗？
A: 不能直接当作生产级库使用，但可以作为练习和进阶的基石。要用于生产，需要 add 网络/线程/内存池/测试覆盖等工程化工作。

Q: 我该怎么开始把练习变成工具箱？
A: 先从 safe_alloc + vector 开始，再把常用字符串和容器稳定后，把示例项目（CLI、simple HTTP client/server）补上，在 CI 里保证测试通过。

⸻

参考工具 & 学习资料（推荐）
•	Criterion（单元测试）
•	AddressSanitizer / UndefinedBehaviorSanitizer
•	valgrind（内存分析）
•	clang-format / clang-tidy（代码风格 & 静态检查）
•	GNU Make / CMake（构建）

⸻

## License

MIT（简单开源许可，适合练习仓库）。
LICENSE 文件里写上选择的许可证文本。

