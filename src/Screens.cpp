#include "Screens.hpp"

using string = std::string;

void screen::MainMenu()
{
	char in_key;
	std::cout << "================================================================================================================================================="
			  << std::endl;
	std::cout << "						Welcome in Library Manegement System						" << std::endl;
	std::cout << "================================================================================================================================================="
			  << std::endl
			  << std::endl;
	std::cout << "	- Librarian Page " << "  " << "--> Press L + Enter" << std::endl;
	std::cout << "	- Member Page      " << "  " << "--> Press M + Enter" << std::endl;
	std::cout << " 	- Search Page  	   " << "  " << "--> Press S + Enter" << std::endl
			  << std::endl;
	std::cout << "Choose: ";
	std::cin >> in_key;
	while ((in_key != 'L') && (in_key != 'l') && (in_key != 'M') && (in_key != 'm') && (in_key != 'S') && (in_key != 's'))
	{
		std::cout << "Invalid input please enter char. from menu !!!!!!!" << std::endl;
		std::cout << "Choose: ";
		std::cin >> in_key;
	}
	if ((in_key == 'L') || (in_key == 'l'))
	{
		LibrarianPage();
	}
	else if ((in_key == 'M') || (in_key == 'm'))
	{
		MemberPage();
	}
	else if ((in_key == 'S') || (in_key == 's'))
	{
		SearchPage();
	}
}

void screen::LibrarianPage()
{
	char in_key;
	std::cout << "=========================================================================================================" << std::endl;
	std::cout << "						Librarian Page				" << std::endl;
	std::cout << "=========================================================================================================" << std::endl
			  << std::endl;
	std::cout << "	- Add New Librarian " << "  " << "--> Press N + Enter" << std::endl;
	std::cout << " 	- Librarian Login   " << "  " << "--> Press L + Enter" << std::endl;
	std::cout << " 	- Back to Main Menu  " << "  " << "--> Press B + Enter" << std::endl
			  << std::endl;
	std::cout << "Choose: ";
	std::cin >> in_key;
	while ((in_key != 'L') && (in_key != 'l') && (in_key != 'N') && (in_key != 'n') && (in_key != 'B') && (in_key != 'b'))
	{
		std::cout << "Invalid input please enter char. from menu!!!!!!!" << std::endl;
		std::cout << "Choose: ";
		std::cin >> in_key;
	}
	if ((in_key == 'N') || (in_key == 'n'))
	{
		string in_sysID;
		string in_name;
		int in_ID;
		std::cout << "=========================================================================================================" << std::endl;
		std::cout << "					Add New Librarian Page				" << std::endl;
		std::cout << "=========================================================================================================" << std::endl
				  << std::endl;
		std::cout << " 	- Back to Librarian Page --> Press B + Enter" << std::endl;
		std::cout << "Enter System ID: ";
		std::cin >> in_sysID;
		while ((in_sysID != DataBase::sysID) && (in_sysID != "B" && in_sysID != "b"))
		{
			std::cout << "Incorrect System ID, Renter ID !!! " << std::endl;
			std::cout << "Enter System ID: ";
			std::cin >> in_sysID;
		}
		if (in_sysID == "B" || in_sysID == "b")
			LibrarianPage();
		std::cout << "Enter Librarian Name: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, in_name);
		std::cout << "Enter Librarian ID: ";
		std::cin >> in_ID;
		DataBase::addLibrarianUser(in_name, in_ID);
		LibrarianPage();
	}
	else if ((in_key == 'L') || (in_key == 'l'))
	{
		std::cout << "=========================================================================================================" << std::endl;
		std::cout << "						Librarian Login Page				" << std::endl;
		std::cout << "=========================================================================================================" << std::endl
				  << std::endl;
		std::cout << " 	- Back to Librarian Page --> Press B + Enter" << std::endl;
		std::cout << "Enter Librarian Name: ";
		string in_name;
		int in_ID;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, in_name);
		if (in_name == "B" || in_name == "b")
			LibrarianPage();
		std::cout << "Enter Librarian ID: ";
		std::cin >> in_ID;
		Librarian logLibrarian(in_name, in_ID);
	}
	else if ((in_key == 'B') || (in_key == 'b'))
	{
		MainMenu();
	}
}

void screen::MemberPage()
{
	char in_key;
	std::cout << "=========================================================================================================" << std::endl;
	std::cout << "						Member Page				" << std::endl;
	std::cout << "=========================================================================================================" << std::endl
			  << std::endl;
	std::cout << "	Add New Member 	  " << "   " << "--> Press N + Enter" << std::endl;
	std::cout << " 	Member Login   	  " << "   " << "--> Press L + Enter" << std::endl;
	std::cout << " 	Back to Main Menu" << "   " << "--> Press B + Enter" << std::endl
			  << std::endl;
	std::cout << "Choose: ";
	std::cin >> in_key;
	while ((in_key != 'L') && (in_key != 'l') && (in_key != 'N') && (in_key != 'n') && (in_key != 'B') && (in_key != 'b'))
	{
		std::cout << "Invalid input please enter char. from menu !!!!!!!" << std::endl;
		std::cout << "Choose: ";
		std::cin >> in_key;
	}
	if ((in_key == 'N') || (in_key == 'n'))
	{
		string in_name;
		int in_ID;
		std::cout << "=========================================================================================================" << std::endl;
		std::cout << "					Add New Member Page				" << std::endl;
		std::cout << "=========================================================================================================" << std::endl
				  << std::endl;
		std::cout << " 	- Back to Member Page --> Press B + Enter" << std::endl;
		std::cout << "Enter Member Name: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, in_name);
		if (in_name == "B" || in_name == "b")
			MemberPage();
		std::cout << "Enter Member ID: ";
		std::cin >> in_ID;
		DataBase::addMemberUser(in_name, in_ID);
		MemberPage();
	}
	else if ((in_key == 'L') || (in_key == 'l'))
	{
		std::cout << "=========================================================================================================" << std::endl;
		std::cout << "						Member Login Page				" << std::endl;
		std::cout << "=========================================================================================================" << std::endl
				  << std::endl;
		std::cout << " 	- Back to Member Page --> Press B + Enter" << std::endl;
		std::cout << "Enter Member Name: ";
		string in_name;
		int in_ID;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, in_name);
		if (in_name == "B" || in_name == "b")
			MemberPage();
		std::cout << "Enter Member ID: ";
		std::cin >> in_ID;
		Member logMember(in_name, in_ID);
	}
	else if ((in_key == 'B') || (in_key == 'b'))
	{
		MainMenu();
	}
}

void screen::SearchPage()
{
	string search;
	std::cout << "=========================================================================================================" << std::endl;
	std::cout << "						Search Page				" << std::endl;
	std::cout << "=========================================================================================================" << std::endl
			  << std::endl;

	std::cout << " Search for Books by Title or Author: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, search);

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

	int iter = 0;
	for (auto &book : DataBase::bookList)
	{
		if ((search == book->title) || (search == book->author))
		{
			// Data rows
			std::cout << std::left
					  << std::setw(35) << ("  " + book->title)
					  << std::setw(35) << book->author
					  << std::setw(15) << book->genre
					  << std::setw(15) << book->ISBN
					  << std::setw(10) << std::fixed << std::setprecision(1) << book->rate // Format rating to 1 decimal place
					  << std::setw(15) << book->numReviewer
					  << std::setw(1) << (book->isAvailable() ? "YES" : "NO") << " (" << book->numCopies << ") "
					  << std::endl;
			iter++;
		}
	}
	if (iter == 0)
	{
		std::cout << " Sorry, Entry NOT Found" << std::endl;
	}
	char in2_key;
	std::cout << std::endl;
	std::cout << "    Search again        --> Press S + Enter" << std::endl;
	std::cout << "    Back to Main Menu  --> Press B + Enter" << std::endl;
	std::cin >> in2_key;
	while (in2_key != 'B' && in2_key != 'b' && in2_key != 'S' && in2_key != 's')
	{
		std::cout << "Invalid input! Press B to go back." << std::endl;
		std::cin >> in2_key;
	}
	if (in2_key == 'B' || in2_key == 'b')
		return MainMenu();
	else
		return SearchPage();
}