#include "SalesTransaction.h"

SalesTransaction::SalesTransaction() {
	ID_number = " ";
	cardNumber = " ";
	transactionCode = 0;
	totalAmount = 0;
}
SalesTransaction::SalesTransaction(string ID_number, string cardNumber) {
	this->ID_number = ID_number;
	this->cardNumber = cardNumber;
	transactionCode = 0;
	totalAmount = 0;
}

void SalesTransaction::setId_number(string id_number) { this->ID_number = ID_number; }
void SalesTransaction::setCard_number(string card_number) { this->cardNumber = cardNumber; }
void SalesTransaction::setTotalAmount(double amount) { this->totalAmount += amount; }//Total amount adds up the ticket price each time a seat is selected.
void SalesTransaction::setTransactionCode(){
	srand(time(0));//Reset the seed
	this->transactionCode = 1000 + rand() % (9999 - 1000 + 1);//The code is generated between 1000 and 9999.
}

string SalesTransaction::getId_number() { return ID_number; }
string SalesTransaction::getCard_number() { return cardNumber; }
double SalesTransaction::getTotalAmount() { return totalAmount; }
int SalesTransaction::getTransactionCode() { return transactionCode; }

SalesTransaction::~SalesTransaction() {};