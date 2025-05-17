#ifndef USERMANAGER_HPP
#define USERMANAGER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
#include "DataBase.hpp"
#include "Screens.hpp"
#include "BookInfo.hpp"
#include "BorrowRecord.hpp"

using string = std::string;

class User
{

protected:
	string name;
	int ID;
	int code;
	bool validUser = 0;

	User();
	User(string name, int ID, int c);
	virtual ~User();

public:
	virtual void displayMenu() = 0;
};

class Librarian : public User
{
public:
	Librarian();
	Librarian(string name, int ID);
	~Librarian();
	void addNewBook();
	void removeBookByISBN();
	void viewAllBooks();
	void viewALLBorrowingRecords();
	bool isAvailableBook(string ISBN);
	void displayMenu();
	void LibrarianMenu(char in_key);
};

class Member : public User
{
public:
	std::vector<std::shared_ptr<Book>> currentBorrowedBooks;
	Member();
	Member(string name, int ID);
	~Member();
	void borrowBook(string ISBN, string borrowingDate, string dueDate);
	void returnBorrowedBooks(string ISBN);
	void viewCurrentBorrowedBooks();
	bool isAvailableBook(string ISBN);
	void addReview(string ISBN, float rate);
	void displayMenu();
	void MemberMenu(char in_key);
};

#endif // !UserManager.hpp
