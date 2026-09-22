# Bank Management — Level 8 (Final Version)

The **final version** of the level-8 course project: a single-file bank
management program with a login system.

## Features

* **Login / logout** — password-protected entry.
* **Main menu**:
  1. Show client list
  2. Add new client
  3. Delete client
  4. Update client info
  5. Find client
  6. Transactions
  7. Manage users
  8. Logout
* **Transactions** — deposit / withdraw / transfer.
* **Manage users** — list users with their **permissions** (the app checks a
  user's permission bits before allowing access to transaction and
  user-management screens).
* **File persistence** — clients and users saved to `member.txt` /
  `myfile.txt` (kept as samples).

## How to run

Open `Bank_Management_Level8_v2.sln` in Visual Studio 2022, build for
**x64 / Debug**, and run. Log in with an existing user (see the user data in
`myfile.txt`).

## Note

This is the improved successor of
[`Bank_Management_Level8_v1`](../Bank_Management_Level8_v1/) — both were kept
to show the development progression.