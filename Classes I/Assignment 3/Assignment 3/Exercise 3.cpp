//Exercise 3
//
//Make a class Account with saldo and interest_rate as private members.Make constructors and
//the member - functions deposit, withdraw, add_interest and get_saldo.

#include <iostream>
using namespace std;

class Account
{
public:

	Account(float n) : saldo(0), interest_rate(n) {};

	void deposit(float n) {
		saldo += n;
	}

	void withdraw(float n) {
		saldo -= n;
	}

	void add_interest(void) {
		if (saldo > 0) {
			saldo += (interest_rate / 100) * saldo;
		}
	}

	float get_saldo(void) {
		return saldo;
	}

private:

	float saldo;
	float interest_rate;
};

Account bob(5), george(10);

void main(void) {

	cout << "Bob Saldo: " << bob.get_saldo() << " George Saldo: " << george.get_saldo() << "\n";

	bob.deposit(500);

	cout << "Deposit 500 into Bob account \n";
	cout << "Bob Saldo: " << bob.get_saldo() << "\n";

	bob.add_interest();

	cout << "Calculate interest for Bob's account \n";
	cout << "Bob Saldo: " << bob.get_saldo() << "\n";

	bob.withdraw(200);

	cout << "Withdraw 200 from Bob's account \n";
	cout << "Bob Saldo: " << bob.get_saldo() << "\n";

	std::getchar();
}