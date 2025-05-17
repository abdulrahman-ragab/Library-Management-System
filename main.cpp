#include <iostream>
#include <string>
#include <vector>
#include "UserManager.hpp"
#include "Screens.hpp"
#include "BookInfo.hpp"
#include "DataBase.hpp"

using string = std::string;

int main()
{
	// Example: Data entry:
	DataBase::LibrarianUsers.emplace_back("admin1", 123456);

	DataBase::MemberUsers.emplace_back("client1", 123456);

	DataBase::addBook("To Kill a Mockingbird", "Harper Lee", "Classic", "9780446310789", 5);
	DataBase::addBook("The Life", "Harper Lee", "Romance", "9780446355789", 5);
	DataBase::addBook("Dune", "Frank Herbert", "Sci-Fi", "9780441172719", 3);
	DataBase::addBook("The Hobbit", "J.R.R. Tolkien", "Fantasy", "9780547928227", 4);
	DataBase::addBook("The Girl", "Stieg Larsson", "Mystery", "9780307269751", 2);
	DataBase::addBook("Steve Jobs", "Walter Isaacson", "Biography", "9781451648539", 3);

	screen::MainMenu();

	return 0;
}
