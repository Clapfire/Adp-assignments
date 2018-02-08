/*
	Make a class Fraction, which have the private member - variables nominator and denominator .
	We have 2 constructors : one with two parameters for initializing nominator and denominator,
	and one with only one parameter for initializing the nominator(denominator is initialized to
	1).
	Make the member - function print(the fraction ½ is outputted like this: (1 / 2))
	Make the member - functions increase_with, decrease_with, multiply_with and divide_with .
	All these member - functions have an object of fraction as parameter.If the fraction a is ½ and
	fraction b is ¼, then after the call of the member - function a.increase_with(b) we have the
	new value of a to be ¾ .
	Make the member - function reduce.It must be private.It will reduce the fraction – for instance
	(12 / 18) is reduced to(2 / 3).Use it in the end of all member - functions(remember the
	constructors), which changes the nominator or denominator. (Hint: find greatest common
	divisor like this : let i have the same value as the denominator.Test if i divides into the
	nominator and the nominator.If not, decrease i and try again and so forth, until i divides into
	the nominator and denominator.Divide the nominator and denominator with i.For instance : if
	the nominator is 12 and the nominator is 18, then the following values of i are tested 12 11 10
	9 8 7 6. 6 divides into both and the fraction becomes(2 / 3)).
	Make the following functions(not member - functions) sum, difference, mul, div.They all
	have two fractions as parameters and returns a fraction.You will need to add the member
	functions get - nominator() and get_denominator() to your Fraction class.
*/
#include <iostream>
using namespace std;

class Fraction
{
public:

	Fraction(int  n, int d) : nominator(n), denominator(d) {};
	Fraction(int n) : nominator(n), denominator(1) {};

	void print(void) {
		cout << nominator << " / " << denominator << "\n";
	}

	void increase_with(Fraction i) {

		i.print(); //testing

		if (denominator == i.denominator)
		{
			cout << "first if \n"; //testing
			nominator += i.nominator;
		}
		else
		{
			cout << "else \n"; //testing
			int ini_den1 = denominator; //temporary storage of initial value
			int ini_den2 = i.denominator;
			int mul1 = 0; //multiple counters
			int mul2 = 0;

			while (denominator != i.denominator)
			{
				cout << "a: " << denominator; //testing
				cout << "\n i: "; //testing
				i.print(); //testing
				cout << "while \n"; //testing

				if (denominator < i.denominator)
				{
					cout << "second if \n"; //testing
					denominator += ini_den1;
					mul1++;
				}

				if (denominator > i.denominator)
				{
					cout << "third if \n"; //testing
					i.denominator += ini_den2;
					mul2++;
				}

			}

			nominator = mul1 * nominator;
			i.nominator = mul2 * i.nominator;

			nominator += i.nominator;

		}

		reduce();

	}

	Fraction decrease_with(Fraction i) {

	}

	Fraction multiply_with(Fraction i) {

	}

	Fraction divide_with(Fraction i) {

	}

	int get_nominator(void) {
		return nominator;
	}

	int get_denominator(void) {
		return denominator;
	}

private:
	int nominator, denominator;

	void reduce(void) {
		for (size_t i = denominator; i > 0; i--)
		{
			if (!(nominator % i) && !(denominator % i))
			{
				nominator = nominator / i;
				denominator = denominator / i;
			}
		}
	}
};

/*
Fraction sum(Fraction x, Fraction y) {

}

Fraction difference(Fraction x, Fraction y) {

}

Fraction mul(Fraction x, Fraction y) {

}

Fraction div(Fraction x, Fraction y) {

}

*/
Fraction a(5, 10), b(3, 10);

int main(void) {

	a.print();
	b.print();

	a.increase_with(b);
	cout << "\n\n";
	a.print();

	std::getchar();

	return 0;
}