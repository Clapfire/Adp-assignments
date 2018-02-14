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

a)
By using only the 3 pointer variables a_ptr, b_ptr and c_ptr calculate the sum of a, b and c and assign
it to the variable sum.
b)
Use the built-in function new to make an integer location in memory and let the pointer variable int_ptr
point at it. Give it the value 5.
c)
Make a reference to the variable a called aa. Set aa to 7 and watch what happens to the value of a in
your table.
e)
Declare two pointers to int and let z_ptr point at a and y_ptr at aa. What can you say about the
addresses they contain?
f)
Make a pointer to pointer to int: int_ptr_ptr. Let it point to a_ptr. Use it to assign 9 to a.
Bonus round: Dynamic arrays
Make a program, which asks the user about how many numbers to input. Then use the built-in function
new to allocate the necessary number of members in a dynamic array ( int *dynarr = int[n];). Input the
numbers to the dynamic array and then output them in reverse order. Delete the array with the function
delete (delete dynarr[];) and let the program start all over again.
*/

#include<iostream>
#include<iomanip>
using namespace std;

void main(void) {
	int a = 2, b = 3, c = 4, sum;
	int *a_ptr = &a, *b_ptr = &b, *c_ptr = &c;

	sum = (*a_ptr + *b_ptr + *c_ptr);
	
	int *int_ptr = new int[5];

	int& aa = a;

	aa = 7;

	cout << setw(10) << " name " << setw(10) << " address " << setw(10) << " content " << endl;
	cout << setw(10) << " a " << setw(10) << &a << setw(10) << a << endl;
	cout << setw(10) << " b " << setw(10) << &b << setw(10) << b << endl;
	cout << setw(10) << " c " << setw(10) << &c << setw(10) << c << endl;
	cout << setw(10) << " sum " << setw(10) << &sum << setw(10) << sum << endl;
	cout << setw(10) << " a_ptr " << setw(10) << &a_ptr << setw(10) << a_ptr << endl;
	cout << setw(10) << " b_ptr " << setw(10) << &b_ptr << setw(10) << b_ptr << endl;
	cout << setw(10) << " c_ptr " << setw(10) << &c_ptr << setw(10) << c_ptr << endl;
	cout << setw(10) << " int_ptr " << setw(10) << &int_ptr << setw(10) << int_ptr << endl;

	std:getchar();
}

