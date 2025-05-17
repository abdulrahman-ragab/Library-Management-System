#ifndef BookInfo_hpp
#define BookInfo_hpp

#include <iostream>
using string = std::string;
class Book
{
public:
	string title;
	string author;
	string genre;
	float rate = 0;
	float totalRates = 0;
	int numReviewer = 0;
	string ISBN;
	int numCopies = 0;

	Book(string title, string author, string genre, string ISBN, int numCopies);
	~Book();
	void addReview(float newrate);
	float getBookReview();
	bool isAvailable();
};

#endif // !BookInfo_hpp