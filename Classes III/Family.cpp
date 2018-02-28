// The chief designer has given you the declarations below
// your job is to fill in the class member definitions below  
// for class Person and Marriagethe main function
// so that it can be executed. 

#include<iostream>
#include <vector>
#include <string>
using namespace std;

class Date
{
	friend class Period;	
public:
	Date(int d = 1, int m = 1, int y = 0) :  day(d), month(m), year(y) { count++; } // default arguments here is bad taste, but shorter
	Date(const Date &d) :  day(d.day), month(d.month), year(d.year) { count++; } 
	void print(void) const 
	{
		cout << this->day << "/" << this->month << "/" << this->year;
	}
	void set_date(const Date  * const d_ptr)
	{
		this->day = d_ptr->day; this->month = d_ptr->month; this->year = d_ptr->year;
	}
	Date& set_day(int d){ this->day = d; return *this; }
	Date& set_month(int m) { this->month = m; return *this; }
	Date& set_year(int y) { this->year = y; return *this; }
	static int get_count(void) { return count; }
private:
	int day, month, year;
	static int count; 
};
int Date::count = 0;

class Marriage;

class Person
{
	friend class Marriage;
public:
	Person(string n, Date b_d, Marriage  &f_m_ptr);
	Person(string n, Date b_d);
	void print(void) const;
	void print_children(void) const;
	void print_parents(void) const;
	bool no_parents(void) const;
private:
  void marry(const Marriage * const marriage_ptr);
  string name;
  const Date BIRTHDAY;
  vector< const Marriage * const > marriages;
  Marriage *from_marriage_ptr; 
};

class Marriage
{ 
public:
	Marriage(Person &male,Person &female);
	void print_children(void)const;
	void print_parents(void) const;
	void print(void) const;
	void get_child(const Person &c_ptr);
private:
	Person * const mother_ptr, * const father_ptr;
	vector< const Person * const > children;
};


int main(void)
{  
	Person joe("Joe", Date(1, 2, 1980)), heinz("Heinz", Date(3, 4, 1981)), eva("Eva", Date(5,6, 1973));
	
    joe.print();
	cout << endl;
    
    Marriage eva_joe(eva,joe);
	Person john("John", Date(1, 2, 2004), eva_joe), jill("Jill", Date(11, 2, 2006), eva_joe);
	Marriage eva_heinz(eva, heinz);
	Person fritz("Fritz", Date(1, 2, 2010), eva_heinz), gertrud("Gertrud", Date(1, 2, 2012), eva_heinz);
   
    cout << endl << " children of the marriage eva_joe: "<< endl;
	eva_joe.print_children();
	cout << endl << " parents in the marriage eva_joe: " << endl;;
	eva_joe.print_parents();
    cout << endl << " children of Eva: " << endl;;
	eva.print_children();
    cout << endl << " parents of John: " << endl;;
	john.print_parents();

	cout << endl << " children of the marriage eva_heinz: " << endl;
	eva_heinz.print_children();
	cout << endl << " parents in the marriage eva_heinz: " << endl;;
	eva_heinz.print_parents();
	cout << endl << " children of Heinz: " << endl;;
	heinz.print_children();
	cout << endl << " parents of Gertrud: " << endl;;
	gertrud.print_parents();
	
    return 0;
}

// your member function definitions here
// Person::Person(string n, Date b_d, Marriage  &f_m_ptr) ....