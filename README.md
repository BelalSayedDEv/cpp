# C++ Learning Repository

A structured collection of **C++ programs** written while learning to program.
It contains over 100 practice problems grouped by topic and a set of larger
projects, including a full OOP bank system.

> This repository was renamed from `C-Coding` to `cpp`.
> (Note: the exact name `c++` is not allowed by GitHub — repository names may
> only contain letters, digits, `.`, `-` and `_`.)

## Repository layout

```
.

├── Problems/                 Individual exercises, grouped by topic
│   ├── 01_Basics/            Variables, types, console I/O, geometry formulas
│   ├── 02_Control_Flow_Loops/ if/else, switch, for/while/do-while, patterns
│   ├── 03_Functions/         Functions, parameters, return values
│   ├── 04_Structs_Enums/     Structs, enums, small typed programs
│   ├── 05_Arrays/            Filling, searching, copying, shuffling arrays
│   ├── 06_Matrices/          2D matrices (problem set #3: 1..20)
│   ├── 07_Strings/           String manipulation (problems #3: 23..35)
│   ├── 08_Recursion/         Fibonacci: iterative and recursive
│   ├── 09_Date_Time/         Date/period utilities and libraries
│   ├── 10_File_IO/           File read/write learning steps (level 7 prep)
│   ├── 11_Data_Structures/   Doubly linked list
│   └── 12_OOP/               Classes: calculator, address, person, string
│                             classes, date/string class demo, templates
└── Projects/                 Complete, runnable programs
    ├── Bank_System_OOP/               Multi-file OOP bank system
    ├── Bank_Management_Level8_v1/     Level-8 final project (first version)
    ├── Bank_Management_Level8_v2/     Level-8 final project (final version)
    └── Client_Management_Level_7/     Level-7 final project
```

## The learning progression

The problems follow the classic learning path:

1. **Basics** — variables, input/output, conversions, simple formulas.
2. **Control flow and loops** — conditionals and the three loop forms.
3. **Functions** — decomposition, parameters, returning values.
4. **Structs and enums** — modeling small entities.
5. **Arrays and search** — aggregate data and simple algorithms.
6. **Matrices** — the `#3` problem set (problems 1–20).
7. **Strings** — text processing (`#3` problems 23–35).
8. **Recursion** — Fibonacci (iterative then recursive).
9. **Date and time** — date/period utilities and libraries.
10. **File I/O** — reading and writing files (prepares the level-7 project).
11. **Data structures** — a custom doubly linked list.
12. **OOP** — classes, `__declspec(property)`, class-based libraries.

Large multi-feature programs live in `Projects/` (see below).

## How to run

* **Individual problems** are standalone `.cpp` files — open one in any C++
  compiler. In Visual Studio you can create a new empty Console project and
  replace `main.cpp`, or just build with `g++ file.cpp`.
* **Projects** are full Visual Studio solutions. Open the `.sln` file in
  Visual Studio 2022 and build for **x64 / Debug**. The OOP bank system also
  has a `.vcxproj` (no solution file) — open it directly.

## Notes

* All source code is kept exactly as originally written (no refactoring).
  File names were cleaned up; the original name-to-file mapping is in
  [`CHANGES.md`](CHANGES.md).
* Visual Studio build output is git-ignored, and the C# (.NET) practice
  folders that were on disk are intentionally kept out of this C++ repository.