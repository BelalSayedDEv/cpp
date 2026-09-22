# CHANGES — Repository reorganization (mechanical only)

This file documents what was done when the repository was reorganized for a
clean, professional presentation. **No C++ source code was modified** —
only files were renamed and moved, and Visual Studio solution/project
references were updated to match the new names.

## What changed

### Moved
All ~100 individual exercises were extracted from their Visual Studio
project folders and grouped by topic under `Problems/` as single `.cpp`
files. Original VS scaffolding (`.sln`, `.vcxproj`, `.filters`, `x64/Debug`
build output) was removed for these small problems, as requested.

### Renamed
File names were cleaned to be GitHub-friendly (no spaces, `#`, or
duplicate numbering). The old names are listed below so any exercise can
still be found:

| Old (project folder) | New location (Problems/) |
|---|---|
| `1#3` | `06_Matrices/Problem_01_matrix_row_sums.cpp` |
| `2#3` | `06_Matrices/Problem_02_matrix_rows_to_array.cpp` |
| `2#3gain` | `06_Matrices/Problem_02b_matrix_rows_to_array_v2.cpp` |
| `4#3` | `06_Matrices/Problem_04_matrix_column_sums.cpp` |
| `5#3` | `06_Matrices/Problem_05_matrix_columns_to_array.cpp` |
| `6#3` | `06_Matrices/Problem_06_fill_matrix_1_to_9.cpp` |
| `7#3` | `06_Matrices/Problem_07_matrix_transpose.cpp` |
| `8#3` | `06_Matrices/Problem_08_sum_two_matrices.cpp` |
| `9#3` | `06_Matrices/Problem_09_middle_row_and_column.cpp` |
| `10#3` | `06_Matrices/Problem_10_matrix_total_sum.cpp` |
| `11#3` | `06_Matrices/Problem_11_matrices_equality.cpp` |
| `12#3` | `06_Matrices/Problem_12_matrices_equality_v2.cpp` |
| `13#3` | `06_Matrices/Problem_13_identity_matrix.cpp` |
| `14#3` | `06_Matrices/Problem_14_scalar_matrix.cpp` |
| `15#3` | `06_Matrices/Problem_15_count_number_in_matrix.cpp` |
| `16#3` | `06_Matrices/Problem_16_sparse_matrix.cpp` |
| `17#3` | `06_Matrices/Problem_17_number_exists_in_matrix.cpp` |
| `18#3` | `06_Matrices/Problem_18_intersected_numbers.cpp` |
| `19#3` | `06_Matrices/Problem_19_max_and_min_in_matrix.cpp` |
| `20#3` | `06_Matrices/Problem_20_palindrome_matrix.cpp` |
| `21#3` | `08_Recursion/Problem_21_fibonacci_sequence.cpp` |
| `22#3` | `08_Recursion/Problem_22_fibonacci_recursive.cpp` |
| `23#3` | `07_Strings/Problem_23_print_first_letters.cpp` |
| `24#3` | `07_Strings/Problem_24_capitalize_first_letters.cpp` |
| `25#3` | `07_Strings/Problem_25_lowercase_first_letters.cpp` |
| `26#3` | `07_Strings/Problem_26_string_to_uppercase.cpp` |
| `27#3` | `07_Strings/Problem_27_count_capital_and_small.cpp` |
| `29#2again` | `05_Arrays/copy_array_print_primes.cpp` |
| `30#3` | `07_Strings/Problem_30_count_char_occurrences.cpp` |
| `31#3` | `07_Strings/Problem_31_count_char_ignore_case.cpp` |
| `32#2` | `05_Arrays/reverse_copy_array.cpp` |
| `32#3` | `07_Strings/Problem_32_count_vowels.cpp` |
| `34#2` | `05_Arrays/search_array_return_index.cpp` |
| `35#3` | `07_Strings/Problem_35_split_string_into_words.cpp` |
| `54#3` | `09_Date_Time/Date_Periods_Library.cpp` |
| `ConsoleApplication1` | `01_Basics/circle_area_diameter.cpp` |
| `ConsoleApplication2` | `02_Control_Flow_Loops/leap_year_loop_practice.cpp` |
| `ConsoleApplication3` | `12_OOP/calculator_class.cpp` |
| `ConsoleApplication4` | `09_Date_Time/date_display_utils.cpp` |
| `ConsoleApplication5` | `09_Date_Time/Date_Library_MathLib.cpp` |
| `ConsoleApplication7` | `11_Data_Structures/doubly_linked_list.cpp` |
| `ConsoleApplication8` | `01_Basics/hello_world.cpp` |
| `oop #12` | `12_OOP/address_class.cpp` |
| `opp practising` | `12_OOP/person_class_msvc_property.cpp` |
| `problem again` | `04_Structs_Enums/random_character_enum_v2.cpp` |
| `proectoop` | `12_OOP/person_class.cpp` |
| `project 1` | `04_Structs_Enums/student_struct_pass_fail.cpp` |
| `project 21` | `01_Basics/circle_area_from_formula.cpp` |
| `project 24` | `02_Control_Flow_Loops/validate_age_in_range.cpp` |
| `project n 20` | `01_Basics/circle_area_diameter_v3.cpp` |
| `project newback` | `01_Basics/circle_area_diameter_v4.cpp` |
| `project one in oop` | `12_OOP/calculator_class_v2.cpp` |
| `project_2` | `01_Basics/basics_variables_arithmetic.cpp` |
| `project_3` | `04_Structs_Enums/structs_and_enums_basics.cpp` |
| `project_4` | `04_Structs_Enums/nested_structs.cpp` |
| `project_5` | `01_Basics/string_number_conversions.cpp` |
| `project_6` | `03_Functions/sum_two_numbers_function.cpp` |
| `project_8` | `03_Functions/swap_numbers_function.cpp` |
| `project_9` | `04_Structs_Enums/employee_info_struct.cpp` |
| `project_10` | `04_Structs_Enums/employee_yearly_salary_struct.cpp` |
| `project_11` | `05_Arrays/array_average_of_grades.cpp` |
| `project_12` | `05_Arrays/array_of_persons_struct.cpp` |
| `project_13` | `04_Structs_Enums/pin_code_balance_check.cpp` |
| `project_16` | `05_Arrays/array_sum_avg_one_based.cpp` |
| `project_17` | `05_Arrays/array_of_persons_v2.cpp` |
| `project_18` | `02_Control_Flow_Loops/loop_patterns.cpp` |
| `project_19` | `02_Control_Flow_Loops/read_number_in_range.cpp` |
| `project_20` | `02_Control_Flow_Loops/while_loop_odd_numbers.cpp` |
| `project_20#1` | `04_Structs_Enums/random_character_enum.cpp` |
| `project14` | `02_Control_Flow_Loops/simple_calculator.cpp` |
| `project15` | `04_Structs_Enums/weekday_enum_switch.cpp` |
| `project20` | `01_Basics/circle_area_diameter_v2.cpp` |
| `project21#2` | `04_Structs_Enums/random_keys_generator.cpp` |
| `project22` | `04_Structs_Enums/pass_fail_enum.cpp` |
| `project22#2` | `05_Arrays/count_number_in_array.cpp` |
| `project23#2` | `05_Arrays/fill_array_with_random.cpp` |
| `project23#2again` | `05_Arrays/max_of_array.cpp` |
| `project25` | `02_Control_Flow_Loops/age_validation_loop.cpp` |
| `project25#2` | `05_Arrays/min_of_array.cpp` |
| `project26` | `02_Control_Flow_Loops/print_numbers_for_while_do.cpp` |
| `project26#2` | `05_Arrays/sum_of_array.cpp` |
| `project27` | `02_Control_Flow_Loops/sum_odd_for_while_do.cpp` |
| `project27#2` | `05_Arrays/average_of_array.cpp` |
| `project28` | `02_Control_Flow_Loops/sum_even_for_while_do.cpp` |
| `project28#2` | `05_Arrays/copy_primes_to_array.cpp` |
| `project29` | `03_Functions/factorial_function.cpp` |
| `project30` | `02_Control_Flow_Loops/power_of_number_loop.cpp` |
| `project30#2again` | `05_Arrays/sum_two_arrays.cpp` |
| `project31` | `02_Control_Flow_Loops/base_to_power_loop.cpp` |
| `project32` | `03_Functions/power_function.cpp` |
| `project32#2` | `05_Arrays/shuffle_array.cpp` |
| `project33` | `03_Functions/grade_evaluation.cpp` |
| `project33#2` | `05_Arrays/generate_random_keys_array.cpp` |
| `project34` | `02_Control_Flow_Loops/sales_commission.cpp` |
| `project34#2` | `05_Arrays/search_array_for_index.cpp` |
| `project35` | `04_Structs_Enums/piggy_bank_coins.cpp` |
| `project35#2` | `05_Arrays/search_array_contains_number.cpp` |
| `project36` | `04_Structs_Enums/piggy_bank_struct.cpp` |
| `project37` | `02_Control_Flow_Loops/enum_calculator.cpp` |
| `project37.1` | `02_Control_Flow_Loops/enum_calculator_v2.cpp` |
| `project38` | `02_Control_Flow_Loops/sum_until_negative.cpp` |
| `project data class library` | `Problems/12_OOP/date_string_demo_class/` |
| `project oop string library` | `Problems/12_OOP/string_class_library/` |
| `Project_templateClass` | `Problems/12_OOP/template_class/` |
| `final project for level 7` (loose `.cxx`) | `Problems/10_File_IO/` |
| `Bank system using oop` | `Projects/Bank_System_OOP/` |
| `final project of level 8` | `Projects/Bank_Management_Level8_v1/` |
| `edit  final project of level 8` | `Projects/Bank_Management_Level8_v2/` |
| `final project for level7` | `Projects/Client_Management_Level_7/` |

### Removed / kept out of the repository
* `Project1`, `Project2` — empty Visual Studio projects with **no source code**
  (removed).
* `project30#2` — empty default "Hello World!" project (removed).
* `ConsoleApplication6` — duplicate default "Hello World!" template (kept on
  disk, excluded).
* All C# / .NET practice folders (`ConsoleApp2`–`7`, `practise*`/`pratice*`,
  `projectCollections`) — kept on disk but **excluded** from this C++
  repository (see `.gitignore`).
* Visual Studio build output (`x64/`, `Debug/`, `.vs/`, `*.obj`, `*.pdb`, ...)
  — git-ignored.
* `Bank system using oop\0` — stray console-capture file ("Press any key to
  continue . . ."), not source code (left out).

### Integrity check
Every source file (`.cpp`, `.cxx`, `.h`) was verified **byte-identical**
(SHA-256) between its original location and its new location before the
original scaffolding was removed.