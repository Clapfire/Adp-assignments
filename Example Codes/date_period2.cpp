#include <iostream>
using namespace std;

#define  PI  22/7  // old bad way

const int MONTH[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Period;// forward reference
class Date
{
	friend bool in_order(Date d1, Date d2);
	friend class Period;
public:
	Date(int d, int m) :day(d), month(m){ count++; }
	Date(void) :day(1), month(1){ count++; }
	Date(const Date &d) :day(d.day), month(d.month){ count++; }// our own  copy constructor
	Date( const Date * const d_ptr) :day((*d_ptr).day), month(d_ptr->month){  count++; }// our own  copy constructor
    ~Date(){ count--; }
	void set_date(int d, int m){ this->day = d; this->month = m; }
	void print(void) const { cout << this->day << '/' << this->month; }
	int get_day(void) const { return this->day; }
	int get_month(void) const { return this->month; }
	static int get_count(void) { return count; }
	Date& set_day(int d){ this->day = d; return *this; }// for cascading function calls
	Date& set_month(int m){ this->month = m; return *this; }
	Date& operator=(const Date& d){ if (!(this == &d)) { this->day = d.day; this->month = d.month; return *this; } }
private:	
	const int MAXDAY = 31;
	static int count; // common for all the objects
	int day, month;
};
int Date::count = 0; // here in old C++

bool in_order(Date d1, Date d2)
{   
	if ( d1.month < d2.month )
	{
		return true;
	}

	if (d1.month == d2.month)
	{
		return d1.day <= d2.day;
	}
	return false;
}

class Period
{ 
public:
	Period(Date s, Date e) : start(in_order(s, e) ? s : e), end(in_order(s, e) ? e : s){}
	void print(void){ start.print(); cout << "-"; end.print(); }
	int length(void)
	{
        if ( start.month == end.month )
         { 
			 return end.day - start.day; 	
		}
		else
		{ // homework
			return 0;
		}
	}
private:
	Date start, end;

};

int main(void)
{
	cout << " Date count : " << Date::get_count();

	Date christmas(24, 12), d(31,12), dd(d);
	d = christmas;
	d.operator=(christmas); // same thing as before
	Period easterHoliday(Date(26, 3), Date(31, 3));
	easterHoliday.print();
	cout << "holiday length = " << easterHoliday.length();

	cout << " Date count : " << Date::get_count(); 
	return 0;

}