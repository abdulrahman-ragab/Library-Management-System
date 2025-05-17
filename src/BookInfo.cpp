#include "BookInfo.hpp"

Book::Book(string title, string author, string genre, string ISBN, int numCopies) : title(title), author(author), genre(genre), ISBN(ISBN), numCopies(numCopies)
{
}
Book::~Book() {}
void Book::addReview(float newrate)
{
	Book::totalRates += newrate;
	Book::numReviewer++;
	Book::rate = totalRates / Book::numReviewer;
}
float Book::getBookReview()
{
	return Book::rate;
}

bool Book::isAvailable()
{
	if (this->numCopies > 0)
		return 1;
	else
		return 0;
}