/*
Exercise 1.
Make a void function called increase. It has 2 parameters. First parameter is a reference parameter
called number and the second parameter is a value parameter called delta. The prototype looks like this:
void increase( int& number, int delta);
The function increases the value of the variable given as parameter with delta.
*/

#include <iostream>
using namespace std;

void increase(int&, int);

int main(void) {
	int num = 7;

	cout << num << endl;

	increase(num, 5);

	cout << num << endl;

	std::getchar();

	return 0;
}

void increase(int& number, int delta) {
	number += delta;
}