#include <iostream>
#include <cstdlib> 
#include "Movie.h"
#include "Auditorium.h"
using namespace std;

bool closeMenu = false;
bool successfulReserve = false;

void cleanWindow() {
    cout << "Presiona Enter para continuar...";
    cin.ignore();
    cin.get();
    system("cls");
}

void archiveMenu(int button) {
    do{
        cout << " Acerca de: 1\n";
        cout << " Salir: 2\n";
        cout << " Regresar: 3\n";
        cin >> button;

        if (button == 1) {
            system("cls");  
            cout << "Estudiante: George Rodriguez Vargas\n \n \n";
        }
        else if (button == 2) {
            closeMenu = true;
        }
    } while (button == 1 || button == 0);
    cleanWindow();
}

void maintenanceMenu(Movie movies[], Auditorium& roomOne, Auditorium& roomTwo) {
    int option = 0;
    do {
        
        cout << "Mostrar peliculas disponibles: 1\n";
        cout << "Mostrar Salas: 2\n";
        cout << "Mostrar horarios: 3\n";
        cout << "Regresar: 4\n";
        cout << "\nSeleccione la opcion que desea realizar:";
        cin >> option;

        cout << endl;
        switch (option) {
        case 1: {
            for (int i = 0; i < 3; i++) {
                movies[i].showMovieInformation();
            }
            break;
        }
        case 2: {
            roomOne.showAuditoriumInformation();
            roomTwo.showAuditoriumInformation();
            break;
        }
        case 3: {
            roomOne.showAuditoriumSchedules();
            roomTwo.showAuditoriumSchedules();
            break;
        }
        case 4: {
            break;
        }
        default:
            cout << "Opcion invalida\n";
            break;
        }
        cleanWindow();
    } while (option != 4);
}

void reserveMenu(Movie movies[], Auditorium& roomOne, Auditorium& roomTwo) {
    int movieSelect = -1; int option;
    
    for (int i = 0; i < 3; i++) {
        movies[i].showMovieInformation();
    }
    cout << " Seleccione la pelicula:";
    cin >> movieSelect;

    cout << endl;
    roomOne.showMovieSchedules(movies[movieSelect - 1], roomTwo);
    cout << " Elige un horario:";
    cin >> option;
    cout << endl;
    roomOne.selectSchedule(option);
    cout << " **Metodos aun no disponibles**\n \n";
    //successfulReserve = true; Para validar el botón de venta.
    cleanWindow();
}

void saleMenu() {
    if (!successfulReserve) {
        cout << " Necesitas reservar\n";
        cout << " **Metodos aun no disponibles**\n \n";
    }
    cleanWindow();
}


int main()
{
    //Objetos de la clase película
    Movie movieOne("Batman", "USA", "2h59m", " 7", 2022);
    Movie movieTwo("Joker", "USA", "2h02m", "8.4", 2019);
    Movie movieThree("Deadpool", "AUS", "2h07m", " 8", 2024);
    Movie movieList[3] = { movieOne, movieTwo, movieThree };

    //Objetos de la clase sala
    Auditorium roomOne(1, 3, "3,000", "4 sept");
    roomOne.setMovieList(movieOne, "14:00", "17:30", "4 sept");
    roomOne.setMovieList(movieTwo, "18:00", "20:00", "4 sept");
    roomOne.setMovieList(movieTwo, "20:00", "22:30", "4 sept");
    Auditorium roomTwo(2, 3, "4,000", "4 sept");
    roomTwo.setMovieList(movieThree, "14:00", "16:30", "4 sept");
    roomTwo.setMovieList(movieOne, "17:00", "20:30", "4 sept");
    roomTwo.setMovieList(movieTwo, "21:00", "23:30", "4 sept");

    int button = 0;
    int selectOption;

    do{
        cout << " Archivo: 1\n";
        cout << " Mantenimiento: 2\n";
        cout << " Reservar: 3\n";
        cout << " Venta: 4\n";
        cout << " Seleccione una opcion:";
        cin >> selectOption;

        cin.ignore();
        system("cls");

        switch (selectOption){
        case 1: {
            archiveMenu(button);
            break;
        }
        case 2: {
            maintenanceMenu(movieList, roomOne, roomTwo);
            break;
        }
        case 3: {
            reserveMenu(movieList, roomOne, roomTwo);
            break;
        }
        case 4: {
            saleMenu();
            break;
        }
        default:
            cout << "Opcion invalida. Intentalo nuevamente." << endl;
        }
        button = 0;
    }while (!closeMenu );
}

