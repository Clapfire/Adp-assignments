//Exercise 2
//
//Make a class Adder. It has a private integer variable sum for holding the sum.
//It has 3 public member - functions. The member - function add(int n) increases the sum. The
//member - function reset_sum() sets sum to 0. The member - function get_sum() returns the sum.
//Declare some adder objects and try them out in your main - function.#include <iostream>using namespace std;class Adder{public:	Adder(int n) : sum(n) {};	void add(int n) {		sum += n;	}	void reset_sum(void) {		sum = 0;	}	int get_sum(void) {		return sum;	}private:	int sum;};Adder first(1), second(0);void main(void) {}