/*
Exercise 2.
Make a program with 3 void functions:
input_box_sides, with 3 reference parameters ( 3 sides ). The function asks the user to input values.
calculate_box_data, with 3 input parameters ( the sides ) and 2 reference parameters surface, volume.
Show_box_data, with 5 input parameters ( the 3 sides , surface and volume ) . The function makes a
pretty print-out of the data to the screen.
Your main-function must only have 4 lines: a line of declarations and one call of each function. What
happens if your actual parameter names are the same as the formal parameter names?
*/

#include<iostream>
#include<iomanip>
using namespace std;

void input_box_sides(int& side1, int& side2, int& side3);
void calculate_box_data(int side1, int side2, int side3, int& surface, int& volume);
void show_box_data(int side1, int side2, int side3, int surface, int volume);

int main(void) {
	int side1, side2, side3, surface, volume;
	input_box_sides();
	calculate_box_data();
	show_box_data();

	return 0;
}

void input_box_sides(int& side1, int& side2, int& side3) {

}

void calculate_box_data(int side1, int side2, int side3, int& surface, int& volume) {

}

void show_box_data(int side1, int side2, int side3, int surface, int volume) {

}