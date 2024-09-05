#include "Schedule.h"

Schedule::Schedule() {
	date = " ";
	initialHour = " ";
	endHour = " ";
}

void Schedule::setTimetable(string& start, string& end, string& date) {
	this->date = date;
	initialHour = start;
	endHour = end;
}

string Schedule::getInitialHour() { return initialHour; }
string Schedule::getEndHour() { return endHour; }
string Schedule::getDate() { return date; }

void Schedule::showScheduleInformation() {
	cout << "| Fecha: " << getDate() << " |";
}