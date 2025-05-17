# 📚 Library Management System (C++)

A simple console-based C++ Library Management System demonstrating Object-Oriented Programming principles. The system supports two types of users: **Librarians** and **Members**, each with specific capabilities like borrowing, returning, reviewing books, and managing the database.

---

## 📁 Project Structure

<pre><code>LibraryManagementSystem/
├── main.cpp # Entry point 
├── README.md 
├── include/ # Header files 
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
│ └── UserManager.cpp </code></pre>


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

<pre><code>```bash
g++ -std=c++14 main.cpp src/*.cpp -Ihpp -o LibrarySystem
./LibrarySystemm

```</code></pre>

## 🧠 Concepts Demonstrated
- Object-Oriented Programming (OOP)
- Class design and separation of concerns
- Inheritance and polymorphism
- Abstract classes and interface-like design
- Standard Template Library (STL): vector, string, iterator
- Range-based for loops
- Smart pointers (std::shared_ptr)
- Type inference with auto
- Simple user authentication and role-based access
- Encapsulation and modular design

---

## 📦 To Do (Future Work)
- Add persistent storage using file I/O or SQLite
- Implement due dates and late return handling
- Improve CLI experience or add a GUI
- Add password protection for users
- Enhance search & filtering features

---

## 👤 Author
Abdulrahman Ragab | Mechatronics Engineer

---
## 📃 License
This project is open-source and available under the MIT License.
