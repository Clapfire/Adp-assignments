/*
Exercise 3.
Make a program, which inputs 3 numbers. Make a void function called rotate with 3 reference
parameters. It rotates the values to the right. If we have a = 2, b = 4, c = 6 then after the call
rotate(a,b,c) we have a = 6, b = 2, c = 4
*/

#include <iostream>
using namespace std;

void rotate(int& a, int& b, int& c);

int main(void) {
	int a, b, c;

	cout << "Please enter a value for a: \n";
	cin >> a;

	cout << "Please enter a value for b: \n";
	cin >> b;

	cout << "Please enter a value for c: \n";
	cin >> c;

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;

	rotate(a, b, c);

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;

	rotate(a, b, c);

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;

	rotate(a, b, c);

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;

	return 0;
}

void rotate(int& a, int& b, int& c) {
	int a1 = a, b1 = b, c1 = c;

	a = c1;
	b = a1;
	c = b1;
}