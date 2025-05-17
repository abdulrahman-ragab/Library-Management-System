#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>
#include <iomanip>
#include "BookInfo.hpp"
#include "BorrowRecord.hpp"

using string = std::string;

class DataBase
{
public:
	static std::vector<std::pair<string, int>> LibrarianUsers;
	static std::vector<std::pair<string, int>> MemberUsers;
	static std::vector<std::shared_ptr<Book>> bookList;
	static std::vector<std::shared_ptr<BorrowRecord>> borrowedList;
	static string sysID;
	DataBase();
	~DataBase();
	static bool checkLibrarianUsers(string name, int ID);
	static bool checkMemberUsers(string name, int ID);
	static void addLibrarianUser(string name, int ID);
	// static void removeLibrarianUser(string name, int ID);
	// static void editLibrarianUser(string name);
	// static void editLibrarianUser(int ID);
	static void addMemberUser(string name, int ID);
	// static void removeMemberUser(string name, int ID);
	// static void editMemberUser(string name);
	// static void editMemberUser(int ID);
	static void addBook(string title, string author, string genre, string ISBN, int numCopies);
	// static void reviewBook(float rate, int numReviewer);
	//  static void editBook(string title, string author, string genre, float rate, int numReviewer, string ISBN, bool isAvailable);
	static void removeBook(string ISBN);
	static void viewAllBooks();
	static void viewALLBorrowingRecords();
};

#endif // !DATABASE_HPP
