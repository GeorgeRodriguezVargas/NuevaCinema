#pragma once
using namespace std;
#include <iostream>
#include <cstdlib>   
#include <ctime> 

class SalesTransaction
{
private:
	string ID_number;
	string cardNumber;
	int  transactionCode;
	double totalAmount;
	
public:
	SalesTransaction();
	SalesTransaction(string ID_number, string cardNumber);

	void setId_number(string ID_number);
	void setCard_number(string cardNumber);
	void setTotalAmount(double amount);
	void setTransactionCode();

	string getId_number();
	string getCard_number();
	double getTotalAmount();
	int getTransactionCode();

	~SalesTransaction();
};

