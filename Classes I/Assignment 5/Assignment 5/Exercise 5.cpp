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
		cout << nominator << "/" << denominator;
	}

	void increase_with(Fraction i) {


		if (denominator == i.denominator)
		{
			nominator += i.nominator;
		}
		else
		{
			int ini_den1 = denominator; //temporary storage of initial value
			int ini_den2 = i.denominator;
			int mul1 = 1; //multiple counters
			int mul2 = 1;

			while (denominator != i.denominator)
			{

				if (denominator < i.denominator)
				{
					denominator += ini_den1;
					mul1++;
				}

				if (denominator > i.denominator)
				{
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

	void decrease_with(Fraction i) {
		if (denominator == i.denominator)
		{
			nominator -= i.nominator;
		}
		else
		{
			int ini_den1 = denominator; //temporary storage of initial value
			int ini_den2 = i.denominator;
			int mul1 = 1; //multiple counters
			int mul2 = 1;

			while (denominator != i.denominator)
			{

				if (denominator < i.denominator)
				{
					denominator += ini_den1;
					mul1++;
				}

				if (denominator > i.denominator)
				{
					i.denominator += ini_den2;
					mul2++;
				}

			}

			nominator = mul1 * nominator;
			i.nominator = mul2 * i.nominator;

			nominator -= i.nominator;

		}

		reduce();

	}

	void multiply_with(Fraction i) {
		nominator *= i.nominator;
		denominator *= i.denominator;

		reduce();
	}

	void divide_with(Fraction i) {
		nominator *= i.denominator;
		denominator *= i.nominator;

		reduce();
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


Fraction sum(Fraction x, Fraction y) {
	x.increase_with(y);

	return x;
}

Fraction difference(Fraction x, Fraction y) {
	x.decrease_with(y);

	return x;
}

Fraction mul(Fraction x, Fraction y) {
	x.multiply_with(y);

	return x;
}

Fraction div(Fraction x, Fraction y) {
	x.divide_with(y);

	return x;
}


Fraction a(5, 10), b(3, 11);

int main(void) {
	
	//testing member functions
	cout << "a: ";
	a.print();
	cout << "\nb: ";
	b.print();
	cout << "\n\n";

	cout << "MEMBER FUNCTIONS: \n\n";

	a.print();
	cout << " + ";
	b.print();

	a.increase_with(b);
	cout << "\n=\n";
	a.print();
	cout << "\n\n";

	a.print();
	cout << " - ";
	b.print();

	a.decrease_with(b);
	cout << "\n=\n";
	a.print();
	cout << "\n\n";

	a.print();
	cout << " * ";
	b.print();

	a.multiply_with(b);
	cout << "\n=\n";
	a.print();
	cout << "\n\n";

	a.print();
	cout << " / ";
	b.print();

	a.divide_with(b);
	cout << "\n=\n";
	a.print();
	cout << "\n\n";

	//testing non-member functions
	cout << "NON-MEMBER FUNCTIONS: \n\n";

	a.print();
	cout << " + ";
	b.print();

	cout << "\n=\n";
	sum(a, b).print();
	cout << "\n\n";

	a.print();
	cout << " - ";
	b.print();

	cout << "\n=\n";
	difference(a, b).print();
	cout << "\n\n";

	a.print();
	cout << " * ";
	b.print();

	cout << "\n=\n";
	mul(a, b).print();
	cout << "\n\n";

	a.print();
	cout << " / ";
	b.print();

	cout << "\n=\n";
	div(a, b).print();
	cout << "\n\n";

	std::getchar();

	return 0;
}