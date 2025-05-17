#include "BorrowRecord.hpp"

BorrowRecord::BorrowRecord() {}
BorrowRecord::BorrowRecord(std::shared_ptr<Book> book, string memberName, int memberID, string borrowingDate, string dueDate) : book(book), memberName(memberName), memberID(memberID), borrowingDate(borrowingDate), dueDate(dueDate)
{
}
BorrowRecord::~BorrowRecord() {}
