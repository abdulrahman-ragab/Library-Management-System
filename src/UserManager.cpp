#include "UserManager.hpp"

using string = std::string;

User::User() : name(" "), ID(0), code(0)
{
	this->validUser = 0;
}

User::User(string name, int ID, int c) : name(name), ID(ID), code(c)
{
	if (this->code == 1)
		this->validUser = DataBase::checkLibrarianUsers(name, ID);
	else if (this->code == 2)
		this->validUser = DataBase::checkMemberUsers(name, ID);
}

User::~User()
{
}

/////////////////////////////////////////////////////////////////////////////////////////

Librarian::Librarian() : User()
{
}
Librarian::Librarian(string name, int ID) : User(name, ID, 1)
{
	if (this->validUser)
	{
		std::cout << "Librarian User found .." << std::endl;
		displayMenu();
	}
	else
	{
		std::cout << "Librarian Name or ID is incorrect " << std::endl;
		screen::LibrarianPage();
	}
}
Librarian::~Librarian() {}
void Librarian::addNewBook()
{
	string title;
	string author;
	string genre;
	string ISBN;
	int numCopies;
	std::cout << " Enter Book Title: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, title);
	std::cout << " Enter Book Author: ";
	std::getline(std::cin, author);
	std::cout << " Enter Book Genre: ";
	std::getline(std::cin, genre);
	std::cout << " Enter Book ISBN (13 digits): ";
	std::cin >> ISBN;
	std::cout << " Enter Book Copies Number: ";
	std::cin >> numCopies;
	DataBase::addBook(title, author, genre, ISBN, numCopies);
}
void Librarian::removeBookByISBN()
{
	string ISBN;
	std::cout << " Enter Book ISBN to remove (13 digits): ";
	std::cin >> ISBN;
	while (!isAvailableBook(ISBN))
	{
		std::cout << " Entered Book NOT Available, please Enter valid one: " << std::endl;
		std::cout << " Enter Book ISBN (13 digits): ";
		std::cin >> ISBN;
	}
	DataBase::removeBook(ISBN);
}
void Librarian::viewAllBooks()
{
	DataBase::viewAllBooks();
}
void Librarian::viewALLBorrowingRecords()
{
	DataBase::viewALLBorrowingRecords();
}
bool Librarian::isAvailableBook(string ISBN)
{
	for (auto &book : DataBase::bookList)
	{
		if ((book->ISBN == ISBN) && (book->isAvailable()))
		{
			return 1;
		}
	}
	return 0;
}
void Librarian::displayMenu()
{
	char in_key;
	std::cout << "=========================================================================================================" << std::endl;
	std::cout << "                        Librarian: " << this->name << " Profile" << std::endl;
	std::cout << "=========================================================================================================" << std::endl
			  << std::endl;
	std::cout << "    - Add New Book                " << " " << "--> Press A + Enter" << std::endl;
	std::cout << "    - Remove Book By ISBN         " << " " << "--> Press X + Enter" << std::endl;
	std::cout << "    - View All Books              " << " " << "--> Press V + Enter" << std::endl;
	std::cout << "    - View ALL Borrowing Records  " << " " << "--> Press R + Enter" << std::endl;
	std::cout << "    - Logout                      " << " " << "--> Press B + Enter" << std::endl
			  << std::endl;
	std::cout << "Choose: ";
	std::cin >> in_key;

	while ((in_key != 'A') && (in_key != 'a') && (in_key != 'X') && (in_key != 'x') &&
		   (in_key != 'B') && (in_key != 'b') && (in_key != 'V') && (in_key != 'v') &&
		   (in_key != 'R') && (in_key != 'r'))
	{
		std::cout << "Invalid input please enter char. from Menu!!!!!!!" << std::endl;
		std::cout << "Choose: ";
		std::cin >> in_key;
	}
	return LibrarianMenu(in_key);
}
void Librarian::LibrarianMenu(char in_key)
{
	if (in_key == 'A' || in_key == 'a')
	{
		std::cout << "=========================================================================================================" << std::endl;
		std::cout << "    * Add New Book: " << std::endl;
		addNewBook();
		std::cout << " New Book is added Successfully.. " << std::endl;
		return displayMenu();
	}
	else if (in_key == 'X' || in_key == 'x')
	{
		std::cout << "=========================================================================================================" << std::endl;
		std::cout << "    * Remove Book By ISBN: " << std::endl;

		removeBookByISBN();
		std::cout << " Book is removed Successfully.. " << std::endl;
		return displayMenu();
	}
	else if (in_key == 'V' || in_key == 'v')
	{
		std::cout << "=========================================================================================================" << std::endl;
		std::cout << "    * View All Books: " << std::endl;
		viewAllBooks();
		std::cout << std::endl;
		std::cout << "    Back to Previous Menu  --> Press B + Enter" << std::endl;
		char in2_key;
		std::cin >> in2_key;
		while (in2_key != 'B' && in2_key != 'b')
		{
			std::cout << std::endl;
			std::cout << "Invalid input! Press B to go back." << std::endl;
			std::cin >> in2_key;
		}
		return displayMenu();
	}
	else if (in_key == 'R' || in_key == 'r')
	{
		std::cout << "=========================================================================================================" << std::endl;
		std::cout << "    * View ALL Borrowing Records: " << std::endl;
		viewALLBorrowingRecords();
		std::cout << std::endl;
		std::cout << "    Back to Previous Menu  --> Press B + Enter" << std::endl;
		char in2_key;
		std::cin >> in2_key;
		while (in2_key != 'B' && in2_key != 'b')
		{
			std::cout << "Invalid input! Press B to go back." << std::endl;
			std::cin >> in2_key;
		}
		return displayMenu();
	}
	else if (in_key == 'B' || in_key == 'b')
	{
		screen::MainMenu();
		return;
	}
}

/////////////////////////////////////////////////////////////////////////////////////

Member::Member() : User()
{
}
Member::Member(string name, int ID) : User(name, ID, 2)
{
	if (this->validUser)
	{
		std::cout << "Member User found .." << std::endl;
		displayMenu();
	}
	else
	{
		std::cout << "Member Name or ID is incorrect " << std::endl;
		screen::MemberPage();
	}
}
Member::~Member() {}
void Member::borrowBook(string ISBN, string borrowingDate, string dueDate)
{
	for (auto &book : DataBase::bookList)
	{
		if ((book->ISBN == ISBN) && (book->isAvailable()))
		{
			book->numCopies--;
			currentBorrowedBooks.push_back(book);
			auto addBorroweBook = std::make_shared<BorrowRecord>(book, this->name, this->ID, borrowingDate, dueDate);
			DataBase::borrowedList.push_back(addBorroweBook);
			return;
		}
	}
}
void Member::returnBorrowedBooks(string ISBN)
{
	for (auto it = DataBase::borrowedList.begin(); it != DataBase::borrowedList.end();)
	{
		if ((*it)->book->ISBN == ISBN)
		{
			(*it)->book->numCopies++;
			it = DataBase::borrowedList.erase(it);
		}
		else
			it++;
	}
	for (auto it = currentBorrowedBooks.begin(); it != currentBorrowedBooks.end();)
	{
		if ((*it)->ISBN == ISBN)
		{
			it = currentBorrowedBooks.erase(it);
		}
		else
			it++;
	}
}
void Member::viewCurrentBorrowedBooks()
{
	// Header
	std::cout << "-----------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::left
			  << std::setw(35) << "  Titles"
			  << std::setw(35) << "Author"
			  << std::setw(15) << "Genre"
			  << std::setw(15) << "ISBN"
			  << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------------------" << std::endl;

	// Data rows
	for (auto &book : currentBorrowedBooks)
	{
		std::cout << std::left
				  << std::setw(35) << ("  " + book->title)
				  << std::setw(35) << book->author
				  << std::setw(15) << book->genre
				  << std::setw(15) << book->ISBN
				  << std::endl;
	}
}
bool Member::isAvailableBook(string ISBN)
{
	for (auto &book : DataBase::bookList)
	{
		if ((book->ISBN == ISBN) && (book->isAvailable()))
		{
			return 1;
		}
	}
	return 0;
}
void Member::addReview(string ISBN, float rate)
{
	for (auto &book : DataBase::bookList)
	{
		if (book->ISBN == ISBN)
		{
			book->addReview(rate);
		}
	}
}
void Member::displayMenu()
{
	char in_key;
	std::cout << "=========================================================================================================" << std::endl;
	std::cout << "                        Member: " << this->name << " Profile" << std::endl;
	std::cout << "=========================================================================================================" << std::endl
			  << std::endl;
	std::cout << "    - Borrow a Book               " << "  " << "--> Press A + Enter" << std::endl;
	std::cout << "    - Return a Borrowed Book      " << "  " << "--> Press X + Enter" << std::endl;
	std::cout << "    - View Current Borrowed Books " << "  " << "--> Press V + Enter" << std::endl;
	std::cout << "    - Review a Book By ISBN       " << "  " << "--> Press R + Enter" << std::endl;
	std::cout << "    - Logout                      " << "  " << "--> Press B + Enter" << std::endl
			  << std::endl;
	std::cout << "Choose: ";
	std::cin >> in_key;

	while ((in_key != 'A') && (in_key != 'a') && (in_key != 'X') && (in_key != 'x') &&
		   (in_key != 'B') && (in_key != 'b') && (in_key != 'V') && (in_key != 'v') &&
		   (in_key != 'R') && (in_key != 'r'))
	{
		std::cout << "Invalid input! Please choose a valid option." << std::endl;
		std::cout << "Choose: ";
		std::cin >> in_key;
	}
	MemberMenu(in_key);
}
void Member::MemberMenu(char in_key)
{

	if (in_key == 'A' || in_key == 'a')
	{
		// Borrow a Book
		string in_ISBN;
		string in_borrowingDate, in_dueDate;
		std::cout << "=========================================================================================================" << std::endl;
		std::cout << "    * Borrow a Book: " << std::endl;
		std::cout << " Enter Book ISBN (13 digits): ";
		std::cin >> in_ISBN;
		while (!isAvailableBook(in_ISBN))
		{
			std::cout << " Entered Book NOT Available, please Enter valid one: " << std::endl;
			std::cout << " Enter Book ISBN (13 digits): ";
			std::cin >> in_ISBN;
		}
		std::cout << " Enter Borrowing Date (dd/mm/yy): ";
		std::cin >> in_borrowingDate;
		std::cout << " Enter Return Date (dd/mm/yy): ";
		std::cin >> in_dueDate;
		borrowBook(in_ISBN, in_borrowingDate, in_dueDate);
		std::cout << " Submitted..   Please Return Book before " << in_dueDate << std::endl;
		return displayMenu();
	}
	else if (in_key == 'X' || in_key == 'x')
	{
		string in_ISBN;
		float in_rate;
		std::cout << "=========================================================================================================" << std::endl;
		std::cout << "    * Return a Borrowed Book: " << std::endl;
		std::cout << " Enter Book ISBN (13 digits): ";
		std::cin >> in_ISBN;
		while (!isAvailableBook(in_ISBN))
		{
			std::cout << " Entered Book NOT Available, please Enter valid one: " << std::endl;
			std::cout << " Enter Book ISBN (13 digits): ";
			std::cin >> in_ISBN;
		}
		returnBorrowedBooks(in_ISBN);
		std::cout << " Book is Returned Successfully..  Thanks " << std::endl;
		std::cout << " Add Review for the Book (0:5) or skip B + Enter : ";
		std::cin >> in_rate;
		if (in_rate >= 0.0 && in_rate <= 5.0)
		{
			addReview(in_ISBN, in_rate);
			std::cout << " Thanks, Review added ..." << std::endl;
		}
		return displayMenu();
	}
	else if (in_key == 'V' || in_key == 'v')
	{
		std::cout << "=========================================================================================================" << std::endl;
		std::cout << "    * View Current Borrowed Books: " << std::endl;
		viewCurrentBorrowedBooks();
		std::cout << std::endl;
		std::cout << "    Back to Previous Menu  --> Press B + Enter" << std::endl;
		char in2_key;
		std::cin >> in2_key;
		while (in2_key != 'B' && in2_key != 'b')
		{
			std::cout << "Invalid input! Press B to go back." << std::endl;
			std::cin >> in2_key;
		}
		return displayMenu();
	}
	else if (in_key == 'R' || in_key == 'r')
	{
		string in_ISBN;
		float in_rate;
		std::cout << "=========================================================================================================" << std::endl;
		std::cout << "    * Review a Book By ISBN " << std::endl;
		std::cout << " Enter Book ISBN (13 digits): ";
		std::cin >> in_ISBN;
		while (!isAvailableBook(in_ISBN))
		{
			std::cout << " Entered Book NOT Available, please Enter valid one: " << std::endl;
			std::cout << " Enter Book ISBN (13 digits): ";
			std::cin >> in_ISBN;
		}
		std::cout << " Add Review for the Book (0:5) or skip B + Enter : ";
		std::cin >> in_rate;
		if (in_rate >= 0.0 && in_rate <= 5.0)
		{
			addReview(in_ISBN, in_rate);
			std::cout << " Thanks, Review added ..." << std::endl;
		}
		return displayMenu();
	}
	else if (in_key == 'B' || in_key == 'b')
	{
		screen::MainMenu();
		return;
	}
}
