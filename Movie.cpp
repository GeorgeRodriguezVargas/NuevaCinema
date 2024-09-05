#include "Movie.h"
Movie::Movie() {
	name = " ";
	country = " ";
	duration = " ";
	review = " ";
	year = 0;
}

Movie::Movie(string name, string country, string duration, string review, int year) {
	this->name = name;
	this->country = country;
	this->duration = duration;
	this->review = review;
	this->year = year;
}

void Movie::setName(string name) {
	this->name = name;
}
void Movie::setCountry(string country) {
	this->country = country;
}
void Movie::setDuration(string duration) {
	this->duration = duration;
}
void Movie::setReview(string review) {
	this->review = review;
}
void Movie::setYear(int year) {
	this->year = year;
}

string Movie::getName() {
	return name;
}
string Movie::getCountry() {
	return country;
}
string Movie::getDuration() {
	return duration;
}
string Movie::getReview() {
	return review;
}
int Movie::getYear() {
	return year;
}

void Movie::showMovieInformation() {
	cout << "| Nombre: " << getName()
		<< " | anio: " << getYear()
		<< " | Duracion: " << getDuration()
		<< " | Pais: " << getCountry()
		<< " | Resenia: " << getReview() << " |"
		<< endl;
}