#pragma once
#include <iostream>;
using namespace std;

class SalesTransaction
{
private:
	string id_number;
	string card_number;
	int  transaction_code;

public:
	SalesTransaction();
	SalesTransaction(string id_number, string card_number);

	void setId_number(string id_number);
	void setCard_number(string card_number);
	void setTransactionCode();

	string getId_number();
	string getCard_number();
};

