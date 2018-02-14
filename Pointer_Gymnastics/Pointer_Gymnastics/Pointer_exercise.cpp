/*
Make a program with these integer variables : sum, a =2, b=3, c=4, and declare 3 pointer to int
variables a_ptr, b_ptr, c_ptr; - a_ptr points at a etc.
Your program must at the end output your variables in a table ( an “excerpt” of the memory ) sketched
out below for the variables defined so far. Use the function setw from the iomanip library(add:
#include<iomanip> in the top of your program) to align the columns – for instance assigning 10 spaces
for each column like this for the headline
cout << setw(10) << “ name “ << setw(10) << “ address “ << setw(10) << “ content “ << endl;
and the entry in the table for a looks like this:
cout << setw(10) << “ a “ << setw(10) << &a << setw(10) << a << endl;
*/

#include<iostream>
#include<iomanip>
using namespace std;

void main(void) {
	int a = 2, b = 3, c = 4, sum;
	int *a_ptr = &a, *b_ptr = &b, *c_ptr = &c;

	sum = (*a_ptr + *b_ptr + *c_ptr);

	cout << setw(10) << " name " << setw(10) << " address " << setw(10) << " content " << endl;
	cout << setw(10) << " a " << setw(10) << &a << setw(10) << a << endl;
	cout << setw(10) << " b " << setw(10) << &b << setw(10) << b << endl;
	cout << setw(10) << " c " << setw(10) << &c << setw(10) << c << endl;
	cout << setw(10) << " sum " << setw(10) << &sum << setw(10) << sum << endl;
	cout << setw(10) << " a_ptr " << setw(10) << &a_ptr << setw(10) << a_ptr << endl;
	cout << setw(10) << " b_ptr " << setw(10) << &b_ptr << setw(10) << b_ptr << endl;
	cout << setw(10) << " c_ptr " << setw(10) << &c_ptr << setw(10) << c_ptr << endl;

	std:getchar();
}

