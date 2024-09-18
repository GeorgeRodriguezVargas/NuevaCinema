#pragma once
using namespace std;
#include <iostream>


class Schedule
{
private:
	string date;
	string initialHour;
	string endHour;

public:
	Schedule();

	void setTimetable(string& start, string& end, string& date);

	string getInitialHour();
	string getEndHour();
	string getDate();

	~Schedule();
};

