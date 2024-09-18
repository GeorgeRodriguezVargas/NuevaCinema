#pragma once
using namespace std;
#include <iostream>


class Movie
{
private:
	string name;
	string country;
	string duration;
	string review;
	int year;

public:
	Movie();
	Movie(string name, string country, string duration, string review, int year);

	void setName(string name);
	void setCountry(string country);
	void setDuration(string duration);
	void setReview(string review);
	void setYear(int year);

	string getName();
	string getCountry();
	string getDuration();
	string getReview();
	int getYear();

	void showMovieInformation();
	~Movie();
};

