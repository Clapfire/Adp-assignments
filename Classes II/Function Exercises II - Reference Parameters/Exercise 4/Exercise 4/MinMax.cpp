/*
Exercise 4.
Make a program, which inputs 3 numbers.
Make a function called minMax. It has as parameters 5 numbers. First 3 parameters are the input
numbers call by value. Parameter 4 is a reference parameter called minimum. Parameter 5 is a
reference parameter called maximum. The function finds the minimum and maximum and returns the
values in the 2 last parameters.
*/

#include <iostream>
using namespace std;

void minMax(int a, int b, int c, int& minimum, int& maximum);

int main(void) {

	int a, b, c, minimum, maximum;

	cout << "Please input a value for a: \n";
	cin >> a;

	cout << "Please input a value for b: \n";
	cin >> b;

	cout << "Please input a value for c: \n";
	cin >> c;

	minMax(a, b, c, minimum, maximum);

	cout << "Minimum: " << minimum << endl;
	cout << "Maximum: " << maximum << endl;

	return 0;
}

void minMax(int a, int b, int c, int& minimum, int& maximum) {

	minimum = a;
	maximum = a;

	int ar[3];

	ar[0] = a;
	ar[1] = b;
	ar[2] = c;

	for (size_t i = 0; i < 3; i++)
	{
		if (ar[i] < minimum)
		{
			minimum = ar[i];
		}

		if (ar[i] > maximum)
		{
			maximum = ar[i];
		}
	}
}