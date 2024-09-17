#pragma once
#include "Movie.h"
#include "Schedule.h"
#include <iostream>;
using namespace std;

class Auditorium
{
private:
	int id_auditorium;
	int projections;
	string price;
	int** asientos;

	Movie** movieList;
	Schedule* schedulesList;
	Auditorium** selectedRoom;
	int* selectedIndex;
	
	int index;
	int optionCount;

public:
	Auditorium();
	Auditorium(int number, int projections, string price, string date);

	void setNumber(int number);
	void setProjections(int projections);
	void setPrice(int price);
	void setMovieList(Movie& movie, string movieStart, string movieEnd, string date);

	int getNumber();
	int getProjections();
	string getPrice();

	void showAuditoriumSchedules();
	void showMovieSchedules(Movie& movie, Auditorium& room);
	void selectSchedule(int option);
	void showAuditoriumInformation();
	~Auditorium();
};

