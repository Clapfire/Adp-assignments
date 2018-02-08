// Exercise 4
//
// Make a class Box with length, width and height as private members. Make a constructor with
// 3 parameters for initializing these three member - variables. Make the public member - functions
// get_volume, get_surface. You can also make set - and get - member - functions for your 3
// member - variables. In your main - function make some boxes and try them out.


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

void main(void) {

}