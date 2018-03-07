#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Dog
{
   public:
	   Dog(string n) : name(n){}
	   void print(void) const { cout << name << endl; }
	   void speak(void) const { cout << "vuf"; }
private:
	string name;
};

int main(void)
{
	Dog fido("Fido"), pluto("Pluto"), mikko("Mikko");

	vector<Dog*> dogs;

	dogs.push_back(&fido);
	dogs.push_back(&pluto);
	dogs.push_back(&mikko);
	//int i;

	for (int i = 0; i < dogs.size(); i++)
	{
		dogs.at(i)->print();// range check
	}
	cout << "without range check: ";
    for (int i = 0; i < dogs.size(); i++)
	{
		dogs[i]->print();
	}

	int A[] = { 1, 2, 3 };

	int *ptr;

	for (ptr = A; ptr <= &A[2]; ptr++)
	{
		cout << " " << *ptr;
	}

    // the STL way
	//vector<Dog*>::iterator dit;

	for (auto dit = dogs.begin(); dit < dogs.end(); dit++)
	{
		(*dit) ->print();
	}

    // C++11 loop
	for (int x : A)
	{
		cout << x << endl;
	}

    // and the lazy version
	for (auto x : A)
	{
		cout << x << endl;
	}

	dogs.erase(dogs.begin() + 1);

	for (auto d : dogs)
	{
		d->print();
	}
















	

	return 0;





}

