// Exercise 1:
//
// Make a class Counter. It has a private integer variable counter_value for holding the ticks.
// It has 3 public member - functions.The member - function tick() increases the counter_value.
// The member - function reset() sets counter_value to 0. The member - function get() returns the
// counter_value. Declare some counter objects and try them out in your main - function.

#include <iostream>
using namespace std;

class Counter
{
public:

	Counter(int c) : counter_value(c) {};

	void tick(void) {
		counter_value++;
	}

	int get(void) {
		return counter_value;
	}

private:

	int counter_value;

};

Counter one(5), two(10);

int main()
{
	cout << one.get() << " " << two.get() << "\n";

	one.tick();
	two.tick();
	cout << one.get() << " " << two.get() << "\n";

	one.tick();
	one.tick();
	cout << one.get() << " " << two.get() << "\n";

	std::getchar();

	return 0;
}
