# C++ Learning & Problem Solving

A structured collection of C++ programs written while learning to program — a
record of my progression from fundamentals through object-oriented programming
and larger projects. It contains over 100 exercises and four complete programs.

## Repository Structure

```
Problems/   Individual exercises, grouped by topic (01_Basics → 12_OOP)
Projects/   Complete, runnable programs
```

## Learning Progression

1. **Basics** — variables, types, console I/O, conversions, simple formulas
2. **Control Flow & Loops** — conditionals and `for` / `while` / `do-while`
3. **Functions** — decomposition, parameters, return values
4. **Structs & Enums** — modeling small entities
5. **Arrays** — filling, searching, copying, shuffling
6. **Matrices** — the `#3` problem set (problems 1–20)
7. **Strings** — text processing (`#3` problems 23–35)
8. **Recursion** — Fibonacci, first iterative, then recursive
9. **Date & Time** — date/period utilities and libraries
10. **File I/O** — reading and writing files
11. **Data Structures** — a custom doubly linked list
12. **OOP** — classes, class-based string/date libraries, templates

## Projects

| Project | What it does |
|---|---|
| `Projects/Bank_System_OOP` | Multi-file OOP bank system — login, client and user management, permissions, deposits/withdrawals/transfers, and currency data |
| `Projects/Bank_Management_Level8_v2` | Bank management (final version) — login, client CRUD, transactions, and user management with permissions; file-based |
| `Projects/Bank_Management_Level8_v1` | Bank management (first version) — client CRUD and transactions, file-based |
| `Projects/Client_Management_Level_7` | Client management — list, add, delete, update, find, persisted to a text file |

Each project has its own README with run instructions.

## How to Run

* **Individual problems** are standalone `.cpp` files — compile with any C++
  compiler (e.g. `g++ file.cpp`) or open them in Visual Studio.
* **Projects** are full Visual Studio solutions — open the `.sln` file (or the
  `.vcxproj` for the OOP bank system) in Visual Studio 2022 and build for
  **x64 / Debug**.

## Notes

* This is my actual learning work, kept as originally written.
* Visual Studio build output is git-ignored so the repository stays
  source-only.