# 📚 Library Management System (C++)

A simple console-based C++ Library Management System demonstrating Object-Oriented Programming principles. The system supports two types of users: **Librarians** and **Members**, each with specific capabilities like borrowing, returning, reviewing books, and managing the database.

---

## 📁 Project Structure

LibraryManagementSystem/
├── main.cpp # Entry point
├── README.md
├── hpp/ # Header files (declarations)
│ ├── BookInfo.hpp
│ ├── BorrowRecord.hpp
│ ├── DataBase.hpp
│ ├── Screens.hpp
│ └── UserManager.hpp
├── src/ # Source files (definitions)
│ ├── BookInfo.cpp
│ ├── BorrowRecord.cpp
│ ├── DataBase.cpp
│ ├── Screens.cpp
│ └── UserManager.cpp

yaml
Copy
Edit

---

## ⚙️ Features

### 👨‍💼 Librarian
- Add, remove, and update books
- View all available books

### 👤 Member
- Search and borrow books
- Return books and add reviews
- View borrowing history

---

## 🛠 Requirements

- C++11 or later
- g++ or any modern C++ compiler

---

## 🚀 Build & Run

Open a terminal in the project directory and run:

```bash
g++ -std=c++11 main.cpp src/*.cpp -Ihpp -o LibrarySystem
./LibrarySystem
🧠 Concepts Demonstrated
Object-Oriented Programming (OOP)

Class design and separation of concerns

Standard Template Library (STL): vectors, strings

Simple user management system

Book database simulation

📌 Future Improvements
File-based persistence for books and users

Password masking and authentication

Exception handling

Smart pointer usage (e.g., std::unique_ptr)

Test automation and unit testing

👤 Author
[Your Name Here]

Feel free to fork, use, and enhance this project!

📃 License
This project is open-source and available for educational and personal use.

vbnet
Copy
Edit

Let me know if you'd like me to generate badges (like build status, license
