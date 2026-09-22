# Bank System (OOP)

The largest project in this repository — a complete **Bank Management System**
built with Object-Oriented Programming. It is split across a main entry point
and ~35 reusable class headers (`cls*`).

## Features

* **Login screen** (`clsLoginScreen`) — the app only starts after a valid
  login.
* **Clients** — list, add, update, delete, find; persisted to `Clients.txt`.
* **Users & permissions** — manage system users and control which screens each
  user can access (`clsMangeUsers`, `clsUser`).
* **Transactions** — deposit, withdraw, and transfer balances between clients.
* **Currencies** — list exchange rates and convert amounts
  (`clsCurrency`, `clsCalculatorCurrency`), data in `Currencies.txt`.
* **Logs** — register-log (`UserLog.txt`) and transfer-log
  (`TransferLog.txt`) files.

## Structure

* `Bank_System_OOP.cpp` — entry point (login loop then main menu).
* `clsPerson.h` / `clsBankClient.h` / `clsUser.h` — domain model (inheritance).
* `cls*Screen.h` — one header per screen/menu.
* `clsString.h`, `clsdate.h`, `clsInputValidate.h`, `clsUtil.h` — reusable
  utilities used across the app.
* `Clients.txt`, `Currencies.txt`, `Users.txt` — data files read/written by
  the app (kept as samples).

## How to run

Open `Bank_System_OOP.vcxproj` in Visual Studio 2022 and build for
**x64 / Debug**. Log in with one of the users stored in `Users.txt`.

> Note: `clsShowUbdateCurrencyScreen.cpp` is a leftover helper file kept
> unchanged; it is not part of the main build.