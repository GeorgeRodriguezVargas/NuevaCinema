#include <iostream>
#include <cstdlib> 
#include "Movie.h"
#include "Auditorium.h"
#include "SalesTransaction.h"
using namespace std;

bool closeMenu = false;

void cleanWindow() {
    cout << "\n Presiona Enter para continuar...";
    cin.ignore();
    cin.get();
    system("cls");
}

void archiveMenu() {
    int option = 0;
    do{
        cout << endl;
        cout << " 1: Acerca de\n";
        cout << " 2: Salir\n";
        cout << " 3: Regresar\n";
        cout << " Seleccione una opcion:";
        cin >> option;

        system("cls");
        if (option == 1) {
            cout << "*** George Rodriguez Vargas ***\n";
        }
        else if (option == 2) {
            closeMenu = true;
        }
        else if (option == 3) { 
            break;
        }
        else {
            cout << " * * Opcion invalida * *\n";
        }
        
    } while (option == 1 || option == 0);
    cleanWindow();
}

void maintenanceMenu(Movie movies[], Auditorium& roomOne, Auditorium& roomTwo) {
    int option = 0;
    do {
        cout << endl;
        cout << " 1: Mostrar peliculas disponibles\n";
        cout << " 2: Mostrar Salas\n";
        cout << " 3: Mostrar horarios\n";
        cout << " 4: Regresar\n";
        cout << " Seleccione la opcion que desea realizar: ";
        cin >> option;
       
        system("cls");
        if (option == 1) {
            for (int i = 0; i < 3; i++) {
                movies[i].showMovieInformation();
            }
        }
        else if (option == 2) {
            roomOne.showAuditoriumInformation();
            roomTwo.showAuditoriumInformation();
        }
        else if (option == 3) {
            roomOne.showAuditoriumSchedules();
            roomTwo.showAuditoriumSchedules();
        }
    } while (option == 1 || option == 2 || option == 3 );
        cleanWindow();
}

void reserveMenu(Movie movies[], Auditorium& roomOne, Auditorium& roomTwo, SalesTransaction& client) {
    int rows, cols;
    int movieSelect = 0; 
    int option1, option2;
   
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ":"; movies[i].showMovieInformation();
    }
    cout << " \nSeleccione la pelicula:";
    cin >> movieSelect;

    system("cls");
    roomOne.showMovieProjections(movies[movieSelect - 1], roomTwo);
    cout << " \nSeleccione un horario:";
    cin >> option1;

   
    do {
        system("cls");
        roomOne.selectSchedule(option1 - 1);

        cout << " \n---- Seleccione los asientos que desea ----\n";
        cout << " Fila:";
        cin >> rows;
        cout << " Asiento:";
        cin >> cols;

        roomOne.selectSeats(rows - 1, cols - 1, option1 - 1, client);
       
        cout << " Total: " << client.getTotalAmount() << endl;
        cout << "\n 1: Finalizar reserva\n";
        cout << " 2: Agregar otro asiento\n";
        cout << " Seleccione una opcion:";
        cin >> option2;

    } while (option2 == 2);
    client.setTransactionCode();
    system("cls");

    cout << "* * * * * Importante * * * * *\n";
    cout << " Codigo de la transaccion: " << client.getTransactionCode();
    cleanWindow();
}

void saleMenu(SalesTransaction& client) {
    int code;
    string ID_number, card_number;
   
        cout << " Ingrese el codigo de la transaccion: ";
        cin >> code;

        if (code == client.getTransactionCode()) {
            cout << " Ingrese su numero de cedula\n";
            cin >> ID_number;
            cout << " Ingrese su tarjeta de credito\n";
            cin >> card_number;

            client.setId_number(ID_number);
            client.setCard_number(card_number);

            system("cls");
            cout << "* * *Compra realizado con exito!* * *\n";
            cout << "        Gracias por su compra\n";
        }
        else {
            cout << " Codigo incorrecto \n";
        }
    cleanWindow();
}

int main()
{
    SalesTransaction client;

    //Objetos de la clase película
    Movie movieOne(" Batman ", "USA", "2h59m", " 7% ", 2022);
    Movie movieTwo(" Joker  ", "USA", "2h02m", "8.4%", 2019);
    Movie movieThree("Deadpool", "AUS", "2h07m", " 8% ", 2024);
    Movie movieList[3] = { movieOne, movieTwo, movieThree };

    //Objetos de la clase sala
    Auditorium roomOne(1, 3, 3000);
    roomOne.setMovieList(movieOne, "14:00", "17:30", "4 sept");
    roomOne.setMovieList(movieTwo, "18:00", "20:00", "4 sept");
    roomOne.setMovieList(movieTwo, "20:00", "22:30", "4 sept");

    Auditorium roomTwo(2, 3, 4000);
    roomTwo.setMovieList(movieThree, "14:00", "16:30", "4 sept");
    roomTwo.setMovieList(movieOne, "17:00", "20:30", "4 sept");
    roomTwo.setMovieList(movieTwo, "21:00", "23:30", "4 sept");
  
    int optionSwitch;
    do{
        cout << "             Nueva Cinema S.A\n";
        cout << "------------------------------------------ \n";
        cout << " 1: Archivo \n";
        cout << " 2: Mantenimiento \n";
        cout << " 3: Reserva \n";
        cout << " 4: Venta \n";
        cout << " Seleccione una opcion:";
        cin >> optionSwitch;

        cin.ignore(); 
        system("cls");

        switch (optionSwitch){
        case 1: {
            archiveMenu();
            break;
        }
        case 2: {
            maintenanceMenu(movieList, roomOne, roomTwo);
            break;
        }
        case 3: {
            reserveMenu(movieList, roomOne, roomTwo, client);
            break;
        }
        case 4: {
            saleMenu(client);
            break;
        }
        default:
            cout << " Opcion invalida. Intentalo nuevamente.\n";
        }
        
    }while (!closeMenu );
}

