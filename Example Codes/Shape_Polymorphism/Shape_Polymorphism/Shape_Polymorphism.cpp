

#include <iostream>
using namespace std;

#define PI 3.14

class Shape
{
public:
	Shape(double x, double y) : anchor_x(x), anchor_y(y) {}

	void move(double dx, double dy) {
		anchor_x += dx;
		anchor_y += dy;
	}

	virtual void print(void) {
		cout << "Anchor Point: (" << anchor_x << " , " << anchor_y << ")";
	}

	virtual double get_area(void) = 0; //pure virtual, Shape is now Abstract

private:
	double anchor_x, anchor_y;

};

class Rectangle : public Shape
{
public:
	Rectangle(double x, double y, double l, double w) : Shape(x, y), length(l), width(w) {};

	virtual void print(void) {
		Shape::print();
		cout << "Lenght: " << length << " Width: " << width;
	}

	double get_area(void) {
		return length * width;
	}
private:
	double length, width;
};

class Square : public Shape
{
public:
	Square(double x, double y, double s) : Shape(x, y), side(s) {};

	virtual void print(void) {
		Shape::print();
		cout << "Side: " << side;
	}

	double get_area(void) {
		return side * side;
	}
private:
	double side;
};

class Circle : public Shape
{
public:
	Circle(double x, double y, double r) : Shape(x, y), radius(r) {};

	virtual void print(void) {
		Shape::print();
		cout << "Radius: " << radius;
	}

	double get_area(void) {
		return PI * radius * radius;
	}
private:
	double radius;
};

int main(void) {

	Rectangle r(1, 2, 3, 4);
	Circle c(5, 6, 3);
	Square s(7, 8, 9);

	//Shape A[] = { r, c, s }; //do not do this, should be done using addresses as below
	Shape* A[] = { &r, &c, &s };

	for (size_t i = 0; i < 3; i++)
	{
		A[i]->print();
		cout << " Area: " << A[i]->get_area() << endl;
	}

	return 0;
};