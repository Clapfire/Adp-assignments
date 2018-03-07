#include <iostream>
using namespace std;

class Date
{
public:
	Date(int d, int m) :day(d), month(m){}
	void set_date(int d, int m){ day = d; month = m; }
	void print(void){ cout << day << '/' << month; }
private:
	int day, month;
};

class Period
{
public:
	Period(Date s, Date e) : start(s), end(e){}
	void print(void){ start.print(); cout << "-"; end.print(); }
private:
	Date start, end;

};

int main(void)
{
	Period easterHoliday(Date(26, 3), Date(2, 4));
	easterHoliday.print();
	return 0;

}