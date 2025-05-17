#ifndef SCREENS_HPP
#define SCREENS_HPP

#include <iostream>
#include <string>
#include <limits>
#include "UserManager.hpp"
#include "DataBase.hpp"

using string = std::string;

class screen
{
public:
	static void MainMenu();
	static void LibrarianPage();
	static void MemberPage();
	static void SearchPage();
};
#endif // !SCREENS_HPP
