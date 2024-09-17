#include "SalesTransaction.h"
SalesTransaction::SalesTransaction() {
	this->id_number = " ";
	this->card_number = " ";
	this->transaction_code = 0;
}
SalesTransaction::SalesTransaction(string id_number, string card_number) {
	this->id_number = id_number;
	this->card_number = card_number;
	this->transaction_code = 0;
}

void SalesTransaction::setId_number(string id_number) { this->id_number = id_number; }
void SalesTransaction::setCard_number(string card_number) { this->card_number = card_number; }
void SalesTransaction::setTransactionCode(){}

string SalesTransaction::getId_number() { return id_number; }
string SalesTransaction::getCard_number() { return card_number; }