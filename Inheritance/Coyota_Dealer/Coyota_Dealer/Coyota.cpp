/*
The Coyota car dealer part 1
Use the template with the class definitions given. Make the member functions of class Person (you can
write them inline). It contains name, address and age. String from the template library is used to store text
in the class. Besides the constructor, the person class also has a print member function printing out all the
data.
Make the member functions of class Employee. It has a pointer to a person (which is hired to do the job). It
has an employee number. It also has a print member function for printing out all the data. Finally it has a
static member employee_number_init used for initializing employee_number.
Make the member functions of class Customer. It has a pointer to a person (the customer in question). It
has a customer number. It also has a print member function for printing out all the data. Furthermore it has
an account. Finally it has a static member customer_number_init used for initializing customer_number.
Make the member functions of class Mechanic, which is a subclass of Employee. It has as member data
hourly_salary(consider making it static) and hours It also has a print member function for printing out
“mechanic “ and all the data.
Make the member functions of class Secretary, which is a subclass of Employee. It has as member data
monthly_salary It also has a print member function for printing “secretary “ out and all the data.
Make the member functions of class Salesman, which is a subclass of Employee. It has as member data
provision and sale It also has a print member function for printing “salesman” out and all the data.
Make the member functions of class Director as a subclass of Employee. It has as member data
monthly_salary . It also has a print member function for printing “director” out and all the data.
Make the member functions of the Coyota-dealer class. It contains address, owner (a pointer to class
Person), employee list and customer list. The lists are implemented using vector from the standard
template library. Put pointers to the employees in the employee-vector, and pointers to customers in the
customer-vector. The Coyota-dealer class has:
- member function hire, which takes an employee object as parameter.
- member function fire, which takes an employee object as parameter.
- member function register_customer, which takes a customer object as parameter.
- member function print.
In the main function some employees and customers are defined. Do stepwise testing incrementally.
Comment out what you have not yet implemented in the main function.
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Person
{
public:
	Person(string n, string adr, int a) : name(n), address(adr), age(a) {}
	void print(void) const
	{
		cout << "Name: " << name << " Address: " << address << " Age: " << age << endl;
	};

private:
	string name, address;
	int age;
};

class Customer
{
public:
	Customer(const Person &p, double ac) : person_ptr(&p), account(ac), customer_number(customer_number_init++) {}
	void print(void)
	{
		person_ptr->print();
		cout << "Account: " << account << " Customer number: " << customer_number << endl;
	};

private:
	const Person *person_ptr;
	int customer_number;
	static int customer_number_init;
	double account;
};

int Customer::customer_number_init = 1;

class Employee
{
public:
	Employee(const Person *p_ptr) : person_ptr(p_ptr), employee_number(employee_number_init++) {}
	void print(void) {
		person_ptr->print();
		cout << "Employee Number: " << employee_number << endl;
	}
private:
	const Person *person_ptr;
	int employee_number;
	static int employee_number_init;
};

int Employee::employee_number_init = 1;

class Mechanic : public Employee
{
public:
	Mechanic(const Person &p) : Employee(&p) {}
	void set_hourly_salary(double s) {
		hourly_salary = s;
	};
	void set_hours(int h) {
		hours = h;
	};
	void print(void) {
		Employee::print();
		cout << "Mechanic" << endl;
	};
private:
	int hours;
	double hourly_salary;
};

class Secretary : public Employee
{
public:
	Secretary(const Person &p) : Employee(&p) {}
	void set_monthly_salary(double s) {
		monthly_salary = s;
	};
	void print(void) {
		Employee::print();
		cout << "Secretary" << endl;
	};
private:
	double monthly_salary;
};

class Salesman : public Employee
{
public:
	Salesman(const Person &p) : Employee(&p) {}
	void set_provision(double p) {
		provision = p;
	}
	void set_sale(double s) {
		sale = s;
	}
	void print(void) {
				Employee::print();
		cout << "Salesman" << endl;
	}
private:
	double sale, provision;
};

class Director : public Employee
{
public:
	Director(const Person &p) : Employee(&p) {}
	void set_monthly_salary(double s) {
		monthly_salary = s;
	};
	void print(void) {
		Employee::print();
		cout << "Director" << endl;
	};
private:
	double monthly_salary;
};
//  to be used in part 2 of the couyota dealer exercise
/*
class Coyota_employee
{
  public:
	  Coyota_employee(const Person &p),
	  void set_monthly_salary(double s);
	  void print();
  private:
	const Person *person_ptr;
	double monthly_salary;
};
*/

class Coyota_dealer
{
public:
	Coyota_dealer(Person &o, string adr) : owner_ptr(&o), address(adr) {}
	void hire(Employee &e) {
		employees.push_back(&e);
	};
	void fire(Employee &e) {
		vector<Employee*>::iterator ii;
		int found = 0;
		for (auto i = employees.begin(); i < employees.end(); i++)
		{
			if ((*i) == &e) {
				ii = i;
				found = 1;
			}
		}
		if (found) {
			employees.erase(ii);
		}
	};
	void register_customer(Customer &c) {
		customers.push_back(&c);
	};
	void print(void) {
		owner_ptr->print();
		cout << "Employees:" << endl << endl;

		for (auto i = employees.begin(); i < employees.end(); i++)
		{
			(*i)->print();
		}
	};
private:
	Person * owner_ptr;
	string address;
	vector<Employee*> employees;
	vector<Customer*> customers;
};

int main(void)
{
	Person p1("Jens", "Odense", 20);
	Mechanic m1(p1);
	m1.set_hourly_salary(100.5);
	m1.set_hours(10);
	m1.print();
	
	cout << endl;

	Person p2("Ole","Fynshav",22);
	Secretary s1(p2);
	s1.set_monthly_salary(20000.7);
	s1.print();

	cout << endl;

	Person p3("Ib","Skovby",42);
	Salesman sm1(p3);
	sm1.set_provision(0.1);
	sm1.set_sale(1000);
	sm1.print();

	cout << endl;

	Person p4("Ole","Fynshav",22);
	Director d1(p4);
	d1.set_monthly_salary(200000.8);
	d1.print();

	cout << endl;
	/*
	Person p7("Ito","Tokyo",30);
	Foreign_worker f1(p7);
	f1.set_monthly_salary(10000);
	f1.set_hourly_salary(100.5);
	f1.set_hours(10);
	f1.print();
	cout << endl;
	
	Person p5("Rudolf","Augustenborg",25);
	Customer c1(p5,100);
	c1.print();
	cout << endl;

	Customer c2(p7,0);
	c2.print();
	cout << endl;
	*/
	Person p6("Wolf","Broager",35);
	Coyota_dealer Broager_coyota(p6," Broager");

	Broager_coyota.hire(d1);
	Broager_coyota.hire(sm1);
	Broager_coyota.hire(s1);
	Broager_coyota.hire(m1);
	//Broager_coyota.hire(f1);

	//Broager_coyota.register_customer(c1);
	//Broager_coyota.register_customer(c2);

	cout << endl;
	Broager_coyota.print();
	Broager_coyota.fire(s1);
	cout << endl <<" after firing of the secretary: " << endl;
	Broager_coyota.print();
	// to be used in part 2 of the couyota dealer exercise
	//cout << endl << " total salary: "<< Broager_coyota.calculate_total_salary();

	// Broager_coyota.write_letter_to_employees(" labor party on Friday ");
   // Broager_coyota.write_letter_to_customers(" come and try the new Coyota yaugo ");
   // Broager_coyota.write_letter_to_affiliates(" We have a speeder problem ");
   
	int kk; cin >> kk;
	return 0;
}