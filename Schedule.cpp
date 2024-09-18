#include "Schedule.h"

Schedule::Schedule() {
	date = " ";
	initialHour = " ";
	endHour = " ";
}

void Schedule::setTimetable(string& initialHour, string& endHour, string& date) {
	this->date = date;
	this->initialHour = initialHour;
	this->endHour = endHour;
}

string Schedule::getInitialHour() { return initialHour; }
string Schedule::getEndHour() { return endHour; }
string Schedule::getDate() { return date; }

Schedule::~Schedule() {}