#ifndef BORROWEDRECORD_HPP
#define BORROWEDRECORD_HPP

#include <memory>
#include "BookInfo.hpp"

using string = std::string;

class BorrowRecord
{
public:
	std::shared_ptr<Book> book;
	string memberName;
	int memberID;
	string borrowingDate;
	string dueDate;

	BorrowRecord();
	BorrowRecord(std::shared_ptr<Book> book, string memberName, int memberID, string borrowingDate, string dueDate);
	~BorrowRecord();
};
#endif // !BORROWEDRECORD_HPP
