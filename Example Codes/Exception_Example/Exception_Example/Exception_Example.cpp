// Exception_Example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <exception>
#include <iostream>
using namespace std;


int main()

{
	try {
		regulate_temperature();

		int a, b = 0, c = 2;

		if (c == 0) throw runtime_error("C is zero");

		a = b / c;
		return 0;
	}
	catch (Temperature_out_of_range &toor) {
		cout << toor.what() << toor.get();
	}
	catch (runtime_error &re) {
		cout << re.what() << endl;
	}
}


class Temperature_out_of_range : public runtime_error {
public:
	Temperature_out_of_range(string s, int t) : temp(t), runtime_error(s.c_str()) {}

	int get() {
		return temp;
	}
private:
	int temp;
};


void regulate_temperature(void) {
	int temperature;

	temperature = 115;

	if (temperature > 100) throw Temperature_out_of_range("Boiling, temp: ", temperature);
}

