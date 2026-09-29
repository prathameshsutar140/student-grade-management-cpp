# EduGrade - C++ Student Grade & Attendance Management System

A file-handling based C++ console application that allows authenticated users to manage student academic records, calculate unit test averages, and track attendance performance.

## Features

* **User Authentication System:** User signup and login functionality stored in a binary file (`USERS.DAT`).
* **User-Specific Records:** Ensures each logged-in user can only view, edit, or delete student records they created (`owner` tag).
* **Academic & Attendance Metrics:** Calculates unit test averages and attendance percentage with automated status tags (e.g., DEFAULTER / SATISFACTORY).
* **Full CRUD Operations:** Support for adding, viewing, editing, and deleting records dynamically using binary stream operations (`STUDENT.DAT`).

## Included File

* **`EDU.cpp`** — Complete source code containing `User` authentication struct, `Stud` management class, and interactive menu routines.

---

## Technical Note
This code relies on legacy C++ headers (`<iostream.h>`, `<fstream.h>`, `<conio.h>`). To compile on modern GCC or Clang compilers:
* Replace `<iostream.h>` and `<fstream.h>` with standard `<iostream>` and `<fstream>`
* Add `using namespace std;`
* Replace `void main()` with `int main()` and remove `clrscr()` / `getch()`
