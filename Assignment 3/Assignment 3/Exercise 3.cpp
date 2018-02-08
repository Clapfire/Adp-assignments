//Exercise 3
//
//Make a class Account with saldo and interest_rate as private members.Make constructors and
//the member - functions deposit, withdraw, add_interest and get_saldo.

#include <iostream>
using namespace std;

class Account 
{
public:
	
	Account(int n) : saldo(0), interest_rate(n) {};

	void deposit(int n) {

	}

	void withdraw(int n) {

	}

	void add_interest(void) {

	}

	int get_saldo(void) {

	}

private:
	
	int saldo;
	int interest_rate;
};