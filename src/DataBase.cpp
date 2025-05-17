#include "DataBase.hpp"

using string = std::string;

string DataBase::sysID = "AA123456";

std::vector<std::pair<string, int>> DataBase::LibrarianUsers;
std::vector<std::pair<string, int>> DataBase::MemberUsers;
std::vector<std::shared_ptr<Book>> DataBase::bookList;
std::vector<std::shared_ptr<BorrowRecord>> DataBase::borrowedList;

DataBase::DataBase() {}
DataBase::~DataBase() {}

bool DataBase::checkLibrarianUsers(string name, int ID)
{
	for (auto &users : LibrarianUsers)
	{
		if ((users.first == name) && (users.second == ID))
			return 1;
	}
	return 0;
}
bool DataBase::checkMemberUsers(string name, int ID)
{
	for (auto &users : MemberUsers)
	{
		if ((users.first == name) && (users.second == ID))
			return 1;
	}
	return 0;
}
void DataBase::addLibrarianUser(string name, int ID)
{
	while (checkLibrarianUsers(name, ID))
	{
		std::cout << "The name or ID is taken, please enter uniqe one" << std::endl;
		std::cout << "Enter Librarian Name: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, name);
		std::cout << "Enter Librarian ID: ";
		std::cin >> ID;
	}
	LibrarianUsers.emplace_back(name, ID);
	std::cout << " New Librarian User Added Successfully .." << std::endl;
}
// void DataBase::removeLibrarianUser(string name, int ID) {}
// void DataBase::editLibrarianUser(string name) {}
// void DataBase::editLibrarianUser(int ID) {}
void DataBase::addMemberUser(string name, int ID)
{
	while (checkMemberUsers(name, ID))
	{
		std::cout << "The name or ID is taken, please enter uniqe one" << std::endl;
		std::cout << "Enter Member Name: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, name);
		std::cout << "Enter Member ID: ";
		std::cin >> ID;
	}
	MemberUsers.emplace_back(name, ID);
	std::cout << " New Member User Added Successfully .." << std::endl;
}
// void DataBase::removeMemberUser(string name, int ID) {}
// void DataBase::editMemberUser(string name) {}
// void DataBase::editMemberUser(int ID) {}
void DataBase::addBook(string title, string author, string genre, string ISBN, int numCopies)
{
	auto newBook = std::make_shared<Book>(title, author, genre, ISBN, numCopies);
	bookList.push_back(newBook);
}
// void DataBase::reviewBook(float rate, int numReviewer) {}
// void DataBase::editBook(string title, string author, string genre, float rate, int numReviewer, string ISBN, bool isAvailable) {}
void DataBase::removeBook(string ISBN)
{
	for (auto it = bookList.begin(); it != bookList.end();)
	{
		if ((*it)->ISBN == ISBN)
			it = bookList.erase(it);
		else
			it++;
	}
}

void DataBase::viewAllBooks()
{
	// Header
	std::cout << "-----------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::left
			  << std::setw(35) << "  Titles"
			  << std::setw(35) << "Author"
			  << std::setw(15) << "Genre"
			  << std::setw(15) << "ISBN"
			  << std::setw(10) << "Rating"
			  << std::setw(15) << "Reviewers"
			  << std::setw(15) << "Available"
			  << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------------------" << std::endl;

	// Data rows
	for (auto &book : bookList)
	{
		std::cout << std::left
				  << std::setw(35) << ("  " + book->title)
				  << std::setw(35) << book->author
				  << std::setw(15) << book->genre
				  << std::setw(15) << book->ISBN
				  << std::setw(10) << std::fixed << std::setprecision(1) << book->rate // Format rating to 1 decimal place
				  << std::setw(15) << book->numReviewer
				  << std::setw(1) << (book->isAvailable() ? "YES" : "NO") << " (" << book->numCopies << ") "
				  << std::endl;
	}
}

void DataBase::viewALLBorrowingRecords()
{
	// Header
	std::cout << "-----------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::left
			  << std::setw(35) << "  Titles"
			  << std::setw(35) << "Author"
			  << std::setw(15) << "ISBN"
			  << std::setw(20) << "Borrower Name"
			  << std::setw(15) << "Borrower ID"
			  << std::setw(20) << "Borrowing Date"
			  << std::setw(15) << "Due Date"
			  << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------------------" << std::endl;

	// Data rows
	for (auto &record : borrowedList)
	{
		std::cout << std::left
				  << std::setw(35) << ("  " + record->book->title)
				  << std::setw(35) << record->book->author
				  << std::setw(15) << record->book->ISBN
				  << std::setw(20) << record->memberName
				  << std::setw(15) << record->memberID
				  << std::setw(20) << record->borrowingDate
				  << std::setw(15) << record->dueDate
				  << std::endl;
	}
}