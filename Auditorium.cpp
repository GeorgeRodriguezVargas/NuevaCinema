#include "Auditorium.h"
Auditorium::Auditorium() {
	ID_auditorium = 0;
	price = 0;
	projections = 0;
	rows = 6;
	cols = 5;
	initializeSeats(rows, cols);//Uses a method to save us from declaring the matrix twice.
	index = 0;
	movieList = new Movie*[projections];
	schedulList = new Schedule[projections];

	selectedRoom = new Auditorium*[projections * 2];//Stores references to the auditoriums where the selected movie is located.
	selectedIndex = new int[projections * 2];//Stores index references to access the movie and schedule.
	optionCount = 0;//Handles SelectedMATRIX limits.
}

Auditorium::Auditorium(int number, int projections, double price) {
	this->ID_auditorium = number;
	this->price = price;
	this->projections = projections;
	rows = 6;
	cols = 6;
	initializeSeats(rows, cols);
	index = 0;
	movieList = new Movie*[projections];
	schedulList = new Schedule[projections];

	selectedRoom = new Auditorium * [projections * 2];
	selectedIndex = new int[projections * 2];
	optionCount = 0;
}

void Auditorium::setNumber(int number) { this->ID_auditorium = number; }
void Auditorium::setProjections(int projections) { this->projections = projections; }
void Auditorium::setPrice(double price) { this->price = price; }

//initializes the matrix for the constructors.
void Auditorium::initializeSeats(int rows, int cols) {
	SeatsMatrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		SeatsMatrix[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			SeatsMatrix[i][j] = 0;
		}
	}
}

//Fill in the list of films being shown in the Auditoriums.
void Auditorium::setMovieList(Movie& movie, string start, string end, string date) {
	if (index < projections) {
		movieList[index] = &movie;
		schedulList[index].setTimetable(start, end, date);//Assign the schedule.
		index++;
	}
}

int Auditorium::getNumber() { return ID_auditorium; }
int Auditorium::getProjections() { return projections; }
double Auditorium::getPrice() { return price; }
int Auditorium::getSeatsAvailable() { return rows * cols; }

void Auditorium::showAuditoriumInformation() {
	cout << "| Numero: " << getNumber() << " | Precio: " << getPrice() << " | Asientos: " << getSeatsAvailable() << endl;
}


//Displays all the schedules in the Cinema.
void Auditorium::showAuditoriumSchedules() {
	for (int i = 0; i < index; i++) {
			cout << "| " << movieList[i]->getName() << " |" << " | Inicio: " << schedulList[i].getInitialHour() << " |" << " | Final: " 
				<< schedulList[i].getEndHour() << " |" << " | Fecha: " << schedulList[i].getDate() << " |" << endl;
	}
}


//Displays the necessary information about the selected movie in both rooms.
void Auditorium::showMovieProjections(Movie& movie, Auditorium& room) {
	for (int i = 0; i < index; i++) {
		if (movie.getName() == movieList[i]->getName()) {
			cout << optionCount+1 <<": | " << movieList[i]->getName() << " | Inicio: " << schedulList[i].getInitialHour() << " | Final: " 
				<< schedulList[i].getEndHour() << " | Fecha: " << schedulList[i].getDate() << " |" << endl;

			selectedRoom[optionCount] = this;//Auditorium1 
			selectedIndex[optionCount] = i;
			optionCount++;
		}
	}
	for (int j = 0; j < room.index; j++) {
		if (movie.getName() == room.movieList[j]->getName()) {
			cout << optionCount+1 << ": | " << room.movieList[j]->getName() << " | Inicio: " << room.schedulList[j].getInitialHour() 
				<< " | Final: " << room.schedulList[j].getEndHour() << " | Fecha: " << room.schedulList[j].getDate() << " |" << endl;

			selectedRoom[optionCount] = &room;//Auditorium2
			selectedIndex[optionCount] = j;
			optionCount++;
		}
	}
}



void Auditorium::printMatriz() {
	cout << endl;
	for (int i = 0; i < rows; i++) {
		cout <<"   " << i + 1 << " ";//Seats numbers.
	}
	cout << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (j == 0) {
				cout <<  i+1 << " [" << SeatsMatrix[i][j] << "] ";//Rows numbers;
			}
			else {
				cout << " [" << SeatsMatrix[i][j] << "] ";
			}
		}
		cout << endl;
	}
}


//Displays the necessary information about the reserved movie.
void Auditorium::selectSchedule(int option) {	
	if (option >= 0 && option <= optionCount) {
		cout << "| " << selectedRoom[option]->movieList[selectedIndex[option]]->getName() << " | Sala: " << selectedRoom[option]->getNumber() 
			<< " | Inicio: " << selectedRoom[option]->schedulList[selectedIndex[option]].getInitialHour() << " | Final: " << selectedRoom[option]->schedulList[selectedIndex[option]].getEndHour() << " |" << endl;
		selectedRoom[option]->printMatriz();
	}
}


//Allows select the seat.
void Auditorium::selectSeats(int row, int col, int option, SalesTransaction& client) {
	if (row >= 0 && row < rows && col >= 0 && col < cols) {
		if (selectedRoom[option]->SeatsMatrix[row][col] == 0) {
			selectedRoom[option]->SeatsMatrix[row][col] = 1;//seat taken
			client.setTotalAmount(selectedRoom[option]->getPrice());//Add the price to be paid.
		}
		else {
			cout << " * * * * Espacio ocupado! * * * *\n";
		}
	}
	else {
		cout << " Opcion invalida\n";
	}
}



Auditorium::~Auditorium() {
	delete[] movieList;
	delete[] schedulList;
	delete[] selectedRoom;
	delete[] selectedIndex;
	for (int i = 0; i < rows; i++) {
		delete[] SeatsMatrix[i];
	}
	delete[] SeatsMatrix;
}
