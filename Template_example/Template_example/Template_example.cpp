// Template_example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

const int QUEUE_SIZE = 4;

//template<class Queue, int size>

class IntQueue {
public:
	IntQueue() : queue_start(0), queue_end(-1), actual_size(0) {};

	void enqueue(int o) {
		actual_size++;
		queue_end++;
		if (queue_end == QUEUE_SIZE)
		{
			queue_end = 0;
		}
		queue[queue_end] = o;
		
	}

	int dequeue(void) {
		int q = queue[queue_start];
		queue_start++;
		if (queue_start == QUEUE_SIZE)
		{
			queue_start = 0;
		}

		actual_size--;
		if (actual_size < 0)
		{
			actual_size = 0;
		}

		return q;
	}
private:
	int queue[QUEUE_SIZE];
	int queue_start, queue_end, actual_size;
};

class FullQueueException : exception {

};

int main()
{
	IntQueue q;

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;


    return 0;
}

class Temperature_out_of_range : public exception {
	Temperature_out_of_range(string s, int t) : temp(t), exception(s.c_str()) {}

private:
	int temp;
};

void regulate_temperature(void) {
	int temperature;

	temperature = 115;

	if (temperature > 100) throw Temperature_out_of_range("Boiling, temp: ", temperature);
}