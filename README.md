# 📚 Library Management System (C++)

A simple console-based C++ Library Management System demonstrating Object-Oriented Programming principles. The system supports two types of users: **Librarians** and **Members**, each with specific capabilities like borrowing, returning, reviewing books, and managing the database.

---

## 📁 Project Structure

LibraryManagementSystem/
├── main.cpp # Entry point
├── README.md
├── hpp/ # Header files
│ ├── BookInfo.hpp
│ ├── BorrowRecord.hpp
│ ├── DataBase.hpp
│ ├── Screens.hpp
│ └── UserManager.hpp
├── src/ # Source files
│ ├── BookInfo.cpp
│ ├── BorrowRecord.cpp
│ ├── DataBase.cpp
│ ├── Screens.cpp
│ └── UserManager.cpp


---

## ⚙️ Features

### 👨‍💼 Librarian
- Add, remove, and update books
- View all available books
- View all borrowing records

### 👤 Member
- Borrow books
- Return books and add reviews
- View borrowing history

### 👤 Visitor
- Search for books by Title or Author

---

## 🛠 Requirements

- C++11 or later
- g++ or any modern C++ compiler

---

## 🚀 Build & Run

Open a terminal in the project directory and run:

```bash
g++ -std=c++14 main.cpp src/*.cpp -Ihpp -o LibrarySystem
./LibrarySystemm

```/bash

## 🚀 Build & Run

