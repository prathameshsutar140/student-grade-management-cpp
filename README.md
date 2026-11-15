# 🎓 EduGrade – C++ Student Grade & Attendance Management System

<p align="center">

  **A File-Handling Based Student Academic & Attendance Management System**

  *Manage student records, calculate academic performance, and track attendance efficiently using C++.*

</p>

---

## 📌 About the Project

**EduGrade** is a console-based Student Grade and Attendance Management System developed using C++. It uses file handling and binary files to store and manage student academic records.

The application provides a secure user authentication system, allowing registered users to manage their own student records independently.

It automatically calculates unit test averages, attendance percentages, and student performance statuses.

This project demonstrates the practical implementation of C++ programming concepts such as classes, objects, structures, file handling, binary file operations, conditional statements, functions, and CRUD operations.

## ✨ Key Features

### 🔐 1. User Authentication System
- User registration (Sign Up).
- Secure login functionality.
- User credentials stored in `USERS.DAT`.
- Separate access to each user's student records.

### 👨‍🎓 2. Student Record Management
- Add new student records.
- Display student information.
- Search and manage existing records.
- Edit student details.
- Delete student records.
- Store records using binary file handling.

### 📊 3. Academic Performance Management
- Store student unit test marks.
- Automatically calculate unit test averages.
- Display academic performance.
- Organize student academic records.

### 📅 4. Attendance Management
- Record total working days.
- Track student attendance.
- Automatically calculate attendance percentage.
- Generate attendance status tags:
  - ⚠️ DEFAULTER
  - ✅ SATISFACTORY

### 🔒 5. User-Specific Data Management
- Each student record contains an owner identifier.
- Logged-in users can access only records associated with their account.
- Prevents ordinary users from managing another user's records through the application.

### 💾 6. Binary File Handling
- `USERS.DAT` – Stores user authentication records.
- `STUDENT.DAT` – Stores student academic and attendance records.
- Uses C++ file streams for persistent storage.

## 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| C++ | Core programming language |
| OOP | Classes and objects |
| File Handling | Persistent data storage |
| Binary Files | Record management |
| Structures | User data organization |
| Conditional Statements | Decision-making |
| Functions | Modular programming |
| CRUD Operations | Student record management |

## 📂 Project Structure

```text
EduGrade/
│
├── EDU.cpp          # Main C++ source code
├── USERS.DAT        # User account data (generated at runtime)
├── STUDENT.DAT      # Student records (generated at runtime)
└── README.md        # Project documentation
```

**Note:** `USERS.DAT` and `STUDENT.DAT` are generated when the application creates or saves records. They may not exist before the first execution.

## ⚙️ System Requirements

Before running EduGrade, ensure that you have:

| Requirement | Description |
|---|---|
| Operating System | Windows, Linux or macOS |
| Compiler | GCC, MinGW or Clang |
| C++ Standard | C++11 or later |
| RAM | 2 GB minimum |
| Storage | A few MB of free space |
| Code Editor | VS Code, Code::Blocks or Dev-C++ |

### 📥 Required Software

- [Visual Studio Code](https://code.visualstudio.com/)
- [MinGW-w64](https://www.mingw-w64.org/) or GCC
- [Code::Blocks](https://www.codeblocks.org/) (optional)

## 🚀 Installation & Execution

### Step 1: Clone the Repository

```bash
git clone YOUR_GITHUB_REPOSITORY_URL
```

Replace the placeholder with your actual repository URL.

### Step 2: Open the Project

```bash
cd EduGrade
```

### Step 3: Modernize Legacy C++ Headers

If your original source uses legacy headers, make these changes:

| Legacy Code | Modern C++ |
|---|---|
| `#include <iostream.h>` | `#include <iostream>` |
| `#include <fstream.h>` | `#include <fstream>` |
| `void main()` | `int main()` |
| `clrscr()` | Remove or use a portable alternative |
| `getch()` | Remove or use standard input |

Add:

```cpp
using namespace std;
```

Also include the standard headers required by your program, such as `<string>`, `<iomanip>`, and `<limits>` when applicable.

### Step 4: Compile the Program

Using GCC:

```bash
g++ -std=c++11 EDU.cpp -o EduGrade
```

### Step 5: Run the Application

**Windows:**

```bash
EduGrade.exe
```

**Linux / macOS:**

```bash
./EduGrade
```

## 🖥️ Application Workflow

```text
       START
         |
         v
    Main Menu
         |
    +----+----+
    |         |
  Sign Up    Login
    |         |
    v         v
  Create    Verify
  Account   Account
              |
              v
       Student Dashboard
              |
      +-------+-------+
      |       |       |
     Add     View    Manage
      |       |       |
      +-------+-------+
              |
              v
       Academic Records
              |
              v
       Attendance Report
              |
              v
             Exit
```

## 📊 Automatic Calculations

### 1. Unit Test Average

The system calculates the average of the recorded unit test marks.

```text
Average = Sum of Unit Test Marks / Number of Tests
```

### 2. Attendance Percentage

```text
Attendance Percentage =
(Present Days / Total Working Days) × 100
```

### 3. Attendance Status

- **DEFAULTER:** Attendance below the configured minimum threshold.
- **SATISFACTORY:** Attendance meets or exceeds the configured threshold.

The threshold should be checked in the source code and configured according to institutional requirements.

## 🔑 Main C++ Concepts Demonstrated

- Structures (`struct`)
- Classes and objects
- Constructors and member functions
- Encapsulation
- File input/output streams
- Binary file handling
- File pointers and stream operations
- CRUD operations
- Loops and conditional statements
- Functions and modular programming
- Basic authentication logic

## ⚠️ Important Technical Notes

1. This application uses local binary file storage, not a database server.
2. Binary files must be handled consistently with the structure definitions used to write them.
3. Avoid changing the structure layout without migrating existing data files.
4. The owner field provides application-level record separation, not strong operating-system-level security.
5. Plain-text passwords should not be used in a production authentication system. Use a secure password-hashing approach if extending this project.
6. Back up `USERS.DAT` and `STUDENT.DAT` before modifying or migrating stored records.
7. Legacy Turbo C++ functions and headers are not supported by modern GCC or Clang.

## 🔮 Future Improvements

Possible future enhancements:

- 🌐 Web-based student management dashboard.
- 🗄️ MySQL database integration.
- 📄 PDF report generation.
- 📈 Graphical performance analytics.
- 🔍 Advanced student search and filtering.
- 📊 Class-wise performance reports.
tc- 🔐 Improved password security.
- 👨‍🏫 Teacher and administrator roles.
- 📱 Mobile-friendly interface.

## 🎯 Project Objectives

The main objectives of EduGrade are:

- To understand practical C++ programming.
- To implement file handling using binary files.
- To demonstrate object-oriented programming.
- To develop CRUD-based record management.
- To automate student academic calculations.
- To understand user authentication and data ownership.

## 👨‍💻 Author

**Prathamesh Sutar**

🎓 Diploma in Computer Technology Student

💻 C++ | HTML | CSS | JavaScript | Programming

🔗 GitHub: [prathameshsutar140](https://github.com/prathameshsutar140)

---

## 📜 License

This project is available for educational and learning purposes.

You may modify and extend it with appropriate credit to the original author.

---

<p align="center">

  **⭐ If you find EduGrade useful, consider giving this repository a star!**

  *Built with ❤️ using C++*

</p>
