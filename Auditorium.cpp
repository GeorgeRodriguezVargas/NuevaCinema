#include "Auditorium.h"
Auditorium::Auditorium() {
	number = 0;
	price = " ";
	projections = 0;
	movieList = new Movie*[projections];
	schedules = new Schedule[projections];
	index = 0;
	selectedRoom = new Auditorium*[projections * 2];
	selectedIndex = new int[projections * 2];
	optionCount = 0;
}

Auditorium::Auditorium(int number, int projections, string price, string date) {
	this->number = number;
	this->price = price;
	this->projections = projections;
	movieList = new Movie*[projections];
	schedules = new Schedule[projections];
	index = 0;
	selectedRoom = new Auditorium * [projections * 2];
	selectedIndex = new int[projections * 2];
	optionCount = 0;
}

void Auditorium::setNumber(int number) { this->number = number; }
void Auditorium::setProjections(int projections) { this->projections = projections; }
void Auditorium::setPrice(int price) { this->price = price; }
void Auditorium::setMovieList(Movie& movie, string start, string end, string date) {
	if (index < projections) {
		movieList[index] = &movie;
		schedules[index].setTimetable(start, end, date);
		index++;
	}
}

int Auditorium::getNumber() { return number; }
int Auditorium::getProjections() { return projections; }
string Auditorium::getPrice() { return price; }

void Auditorium::showAuditoriumSchedules() {
	for (int i = 0; i < index; i++) {
			cout << "| " << movieList[i]->getName() << " |"
				<< " | Inicio: " << schedules[i].getInitialHour() << " |"
				<< " | Final: " << schedules[i].getEndHour() << " |"
				<< " | Fecha: " << schedules[i].getDate() << " |"
				<< endl <<endl;
	}
}

void Auditorium::showMovieSchedules(Movie& movie, Auditorium& room) {
	optionCount = 0;
	for (int i = 0; i < index; i++) {
		if (movie.getName() == movieList[i]->getName()) {
			cout << " Movie: " << movieList[i]->getName()
				<< " Inicio: " << schedules[i].getInitialHour()
				<< " Final: " << schedules[i].getEndHour()
				<< " | Fecha: " << schedules[i].getDate() << " |"
				<< endl;

			selectedRoom[optionCount] = this;
			selectedIndex[optionCount] = i;
			optionCount++;
		}
	}
	for (int j = 0; j < room.index; j++) {
		if (movie.getName() == room.movieList[j]->getName()) {
			cout << " Movie: " << room.movieList[j]->getName()
				<< " Inicio: " << room.schedules[j].getInitialHour()
				<< " Final: " << room.schedules[j].getEndHour()
				<< " | Fecha: " << schedules[j].getDate() << " |"
				<< endl;

			selectedRoom[optionCount] = &room;
			selectedIndex[optionCount] = j;
			optionCount++;
		}
	}
}

void Auditorium::selectSchedule(int option) {
	option -= 1;
	if (option >= 0 && option <= optionCount) {
		cout << endl;
		cout << " **Informacion sobre precio y demas para la venta** \n";
		cout << "|Nombre: " << selectedRoom[option]->movieList[selectedIndex[option]]->getName() 
		     << " | Inicio: " << selectedRoom[option]->schedules[selectedIndex[option]].getInitialHour() 
		     << " | Final: " << selectedRoom[option]->schedules[selectedIndex[option]].getEndHour() << endl;
	}
}

void Auditorium::showAuditoriumInformation() {
	cout << "| Numero: " << getNumber()
		<< " | Precio: " << getPrice()
		<< " | Asientos: *Metodo no habilitado* |" 
		<< endl;
}


Auditorium::~Auditorium() {
	delete[] movieList;
	delete[] schedules;
	delete[] selectedRoom;
	delete[] selectedIndex;
}