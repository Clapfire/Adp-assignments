// Exercise 4
//
// Make a class Box with length, width and height as private members. Make a constructor with
// 3 parameters for initializing these three member - variables. Make the public member - functions
// get_volume, get_surface. You can also make set - and get - member - functions for your 3
// member - variables. In your main - function make some boxes and try them out.

#include <iostream>
using namespace std;

class Box 
{
public:

	Box(int l, int w, int h) : length(l), width(w), height(h) {};

	int get_volume(void) {
		return length * width * height;
	}

	int get_surface(void) {
		return (
			(2 * width * length)
			+ (2 * width * height)
			+ (2 * length * height)
			);
	}

	void set_length(int l) {
		length = l;
	}

	int get_length(void) {
		return length;
	}

	void set_width(int w) {
		width = w;
	}

	int get_width(void) {
		return width;
	}

	void set_height(int h) {
		height = h;
	}

	int get_height(void) {
		return height;
	}

private:

	int length, width, height;

};

Box box1(5, 7, 10);

int main(void) {

	cout << "Box dimensions: " 
		 << "length " << box1.get_length() 
		 << " width " << box1.get_width() 
		 << " height " << box1.get_height()
		 << "\n"
		 << "Box volume: " << box1.get_volume() << "\n"
		 << "Box surface area: " << box1.get_surface() << "\n";

	cout << "Changing length and width \n\n";

	box1.set_length(15);
	box1.set_width(2);

	cout << "Box dimensions: "
		<< "length " << box1.get_length()
		<< " width " << box1.get_width()
		<< " height " << box1.get_height()
		<< "\n"
		<< "Box volume: " << box1.get_volume() << "\n"
		<< "Box surface area: " << box1.get_surface() << "\n";

	std::getchar();

	return 0;
}