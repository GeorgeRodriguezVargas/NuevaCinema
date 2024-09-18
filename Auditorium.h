#pragma once
using namespace std;
#include <iostream>
#include "Movie.h"
#include "Schedule.h"
#include "SalesTransaction.h"

class Auditorium
{
private:
	int ID_auditorium;
	int projections; //Number of sessions in each auditorium.
	double price;
	int rows;
	int cols;
	int** SeatsMatrix; 
	int index;
	Movie** movieList;
	Schedule* schedulList;//Stores the schedul of each Movie.

	//Information in Cpp.
	Auditorium** selectedRoom;
	int* selectedIndex;
	int optionCount;

public:
	Auditorium();
	Auditorium(int number, int projections, double price);

	void setNumber(int number);
	void setProjections(int projections);
	void setPrice(double price);
	void initializeSeats(int rows, int cols);
	void setMovieList(Movie& movie, string movieStart, string movieEnd, string date);

	int getNumber();
	int getProjections();
	double getPrice();
	int getSeatsAvailable();

	void showAuditoriumSchedules();
	void showMovieProjections(Movie& movie, Auditorium& room);
	void selectSchedule(int option);
	void showAuditoriumInformation();
	void printMatriz();
	void selectSeats(int row, int col, int option, SalesTransaction& client);
	~Auditorium();
};

