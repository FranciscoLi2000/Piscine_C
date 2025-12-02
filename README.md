# 42 Piscine C 学习路径（中英双语）

本仓库整理了 42 学校 Piscine 的 C 语言与 Shell 学习路径，从 C00 到 C11 的练习与示例代码；C12（链表）与 C13（二叉树）暂未加入，计划后续复习时再补充。This repo collects the 42 School Piscine learning path for C and Shell, with exercises from C00 to C11. C12 (linked lists) and C13 (binary trees) are not yet included and will be added later during review.

仓库结构请参考根目录中的各模块文件夹，如 `C00/`、`C01/` 等。Refer to folders like `C00/`, `C01/` in the root for module contents.

— 更新日期 Updated: 2025-12-02

## 目标 Objectives
- 复习路径：快速回顾从基础到进阶的知识点。
- Debug 指南：统一编译与调试方法，提升定位问题效率。
- 他人阅读：为同学/同事提供清晰的代码入口与说明。
- Review path: fast recap of topics from basics to advanced.
- Debug guide: consistent compile/debug methods to speed up troubleshooting.
- For readers: clear entry points and explanations for your code.

## 环境与规范 Environment & Norms
- 编译器：`gcc`（或 `clang`），建议开启严格告警：`-Wall -Wextra -Werror`。
- 标准库使用：Piscine 多数题目禁止使用除 `write` 外的库函数，请遵循题面要求。
- 代码风格：遵循 42 Norminette 规范（函数长度、命名、缩进等）。
- 编码与换行：源文件使用 UTF-8，行尾 LF。
- Compiler: `gcc` (or `clang`), enable strict warnings: `-Wall -Wextra -Werror`.
- Lib usage: Many Piscine tasks restrict stdlib (often only `write` is allowed); follow each assignment's constraints.
- Style: 42 Norminette (function length, naming, indentation, etc.).
- Encoding & EOL: UTF-8, LF.

## 快速使用 Quick Start
- 单文件编译 Single file:
  ```bash
  gcc -Wall -Wextra -Werror -o bin/ft_print_alphabet C00/ft_print_alphabet.c
  ./bin/ft_print_alphabet
  ```
- 多文件编译 Multi-file:
  ```bash
  gcc -Wall -Wextra -Werror -I C08 -o bin/program \
      C04/ft_putnbr.c C04/ft_putstr.c C04/ft_strlen.c
  ./bin/program
  ```
- 运行 Makefile（若提供） Use `Makefile` when available:
  ```bash
  make -C C09
  ```

## 调试与排错 Debugging Tips
- 基础打印：在受限环境下优先用 `ft_putnbr`/`ft_putstr` 做简单日志。
- 断言思想：先验证输入与边界，再检查循环/递归不变量。
- 编译告警：将告警视为错误处理，逐条解决。
- GDB：
  ```bash
  gcc -g -Wall -Wextra -Werror -o bin/a.out C05/ft_recursive_power.c
  gdb bin/a.out
  ```
- Valgrind（如可用）：排查内存越界/泄漏。
- Unit 测试：为关键函数写最小可运行测试驱动（见下文模块示例）。
- Print logs: use `ft_putnbr`/`ft_putstr` for minimal logging under constraints.
- Assertions mindset: validate inputs, boundaries; check loop/recursion invariants.
- Treat warnings as errors, fix them one by one.
- GDB and Valgrind (if available) for runtime and memory issues.

## 学习路径概览 Path Overview (C00 → C13)

以下为每模块的核心主题与常见坑点。Module summaries and common pitfalls below.

### C00 — 基本输出与字符处理 Basics: output and chars
- 主题 Topics: `ft_putchar`, 字母与数字打印，组合输出。
- 技法 Skills: ASCII 操作、嵌套循环、格式控制。
- 坑点 Pitfalls: 边界字符处理，输出顺序与逗号/空格格式。

### C01 — 指针与数组 Pointers and arrays
- 主题: 指针传参、交换、整型数组、字符串长度。
- 技法: 传地址修改值、指针算术、原地反转与排序。
- 坑点: 越界访问、排序稳定性、`int` 溢出。

### C02 — 字符串与大小写转换 Strings and casing
- 主题: `strcpy`/`strncpy`/`strlcpy`、`is_alpha`/`is_numeric`、大小写转换、内存打印。
- 技法: 手写字符串函数、分类判断、位运算（`swap_bits`/`reverse_bits`）。
- 坑点: NUL 终止、缓冲区大小、非打印字符处理。

### C03 — 字符串拼接与查找 Concatenation and search
- 主题: `strcat`/`strncat`/`strlcat`、`strcmp`/`strncmp`、`strstr`/`strnstr`。
- 技法: 安全拼接与长度控制、朴素匹配算法。
- 坑点: 目标缓冲区大小、大小写与边界、部分匹配。

### C04 — 基础 I/O 与转换 I/O and number conversion
- 主题: `ft_putnbr`/`ft_putstr`/`ft_strlen`、`ft_atoi`、进制打印 `ft_putnbr_base`、`ft_atoi_base`。
- 技法: 溢出与符号处理、基数合法性校验。
- 坑点: 前导空白、`+-` 组合、非法字符与重复字符集。

### C05 — 递归与数学 Recursion and math
- 主题: 阶乘、幂、斐波那契、平方根、素数、下一个素数、八皇后。
- 技法: 递归边界、回溯、复杂度控制。
- 坑点: 深度爆炸、溢出与性能、剪枝策略。

### C06 — 程序参数与排序 Program args and sorting
- 主题: `argv` 处理、参数打印/反序、字符串排序。
- 技法: 比较器实现、稳定排序思想、输入健壮性。
- 坑点: 空参数、空字符串、比较函数返回值约定。

### C07 — 动态内存与字符串构造 Dynamic memory and string building
- 主题: `range`、`ultimate_range`、`strdup`、`strjoin`、`split`、进制转换 `convert_base`。
- 技法: `malloc`/`free`、双重指针返回长度、分隔符处理。
- 坑点: 内存泄漏、空输入/全分隔边界、返回值约定（NULL vs 长度）。

### C08 — 结构体与头文件 Structs and headers
- 主题: `ft_point`、`ft_boolean`、`ft_stock_str`、`ft_show_tab`、`ft_strs_to_tab`、统一头文件 `ft.h`。
- 技法: 结构体设计、头文件保护、类型与宏、接口组织。
- 坑点: 头文件重复包含、浅拷贝 vs 深拷贝、打印格式一致性。

### C09 — 库与构建 Scripts and library build
- 主题: `libft_creator.sh`、`Makefile` 基础。
- 技法: 批量编译归档、目标与依赖、可重用库思想。
- 坑点: 目标路径、清理规则、跨模块头文件路径。

### C10 — 文件 I/O File I/O
- 主题: `ft_display_file`，`open`/`read`/`close` 基础（在允许范围内）。
- 技法: 错误码处理、缓冲区循环读取、最小依赖实现。
- 坑点: 文件不存在/权限、部分读取、资源释放。

### C11 — 函数指针与高阶函数 Function pointers & higher-order fns
- 主题: `do_op`、`map`、`foreach`、`count_if`、`is_sort`、字符串表排序。
- 技法: 函数指针、回调、比较器、策略封装。
- 坑点: 函数原型一致性、指针传递、未定义行为。

### C12 — 链表 Linked Lists（未加入 Not included yet）
- 计划 Plan: 单链表创建、插入、删除、反转、排序，迭代与递归操作。
- 常见点 Topics: 节点管理、头尾处理、内存释放、稳定性。

### C13 — 二叉树 Binary Trees（未加入 Not included yet）
- 计划 Plan: 插入、遍历（前/中/后序）、查找、平衡性讨论（基础）。
- 常见点 Topics: 递归遍历、不变式维护、空子树处理。

## 模块运行与小型测试 Module run & mini tests
- 示例 Example: 测试 `C03/ft_strcmp.c`
  ```c
  // test_strcmp.c
  #include <stdio.h>
  int ft_strcmp(char *s1, char *s2);
  int main(void){
      printf("%d\n", ft_strcmp("abc","abc"));
      printf("%d\n", ft_strcmp("abc","abd"));
      printf("%d\n", ft_strcmp("","a"));
      return 0;
  }
  ```
  ```bash
  gcc -Wall -Wextra -Werror -o bin/t_cmp C03/ft_strcmp.c test_strcmp.c
  ./bin/t_cmp
  ```

## 常见调试清单 Debug Checklist
- 输入边界：空串、全空白、极端长度、负数/零。
- 内存安全：所有 `malloc` 都有对应 `free`；避免越界读写。
- 循环与递归：不变量成立；终止条件严谨；避免死循环/过深递归。
- 返回约定：题目要求的错误码/NULL/长度是否一致。
- I/O：输出格式完全匹配样例（空格、换行、逗号）。
- Edge cases, memory safety, invariants, return contracts, exact I/O formatting.

## 后续计划 Roadmap
- 补充 C12/C13 的代码与 README 章节。
- 增加更多最小测试驱动与脚本，统一编译入口。
- 完善 `Makefile` 与头文件组织，提升可复用性。
- Add C12/C13 implementations and docs.
- More mini test drivers and scripts; unified build entry.
- Improve Makefiles and header organization for reuse.

## 版权与致谢 License & Credits
- 本仓库仅用于个人学习与复习，不包含他人受版权保护的代码片段。遵循 42 学校的作业规范与学术诚信。
- This repo is for personal study/review; it avoids copyrighted content and follows 42 assignment norms and academic integrity.

——
如需我补充 C12/C13 的模板与测试驱动，告诉我你的偏好（函数原型、允许的库函数、目标接口），我可以直接在 `C12/`、`C13/` 下创建基础骨架文件与简单 `Makefile`。If you want starter scaffolds for C12/C13, share your preferences (prototypes, allowed libs, interfaces) and I can add skeletons and a simple Makefile.
