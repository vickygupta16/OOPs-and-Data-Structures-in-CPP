#include<iostream>
#include<string.h>

using namespace std;

class Student
{
	private:
		char university[30],degree[30];
	public:
		Student(char *,char *);
		void printStudent();
};

Student::Student(char *u,char *d)
{
	strcpy(university,u);
	strcpy(degree,d);
}

void Student::printStudent()
{
	cout<<"\n\tUniversity : "<<university;
	cout<<"\n\tDegree : "<<degree;
}

class Employee
{
	private:
		int empid;
		char name[20];
	public:
		Employee(int,char *);
		void printEmployee();
};

Employee::Employee(int eid,char *n)
{
	empid=eid;
	strcpy(name,n);
}

void Employee::printEmployee()
{
	cout<<"\n\tEmployee ID : "<<empid;
	cout<<"\n\tName : "<<name;
}

class Manager
{
	private:
		double salary;
		char title[20];
		Employee e;
		Student s;
	public:
		Manager(double,char *,char *,char *,int,char *);
		void printManager();
};

Manager::Manager(double s,char *t,char *u,char *d,int eid,char *n):s(u,d),e(eid,n)
{
	salary=s;
	strcpy(title,t);
}

void Manager::printManager()
{
	cout<<"\n\n\tManager Details";
	s.printStudent();
	e.printEmployee();
	cout<<"\n\tSalary : "<<salary;
	cout<<"\n\tTitle : "<<title;
}

int main()
{
	Manager M(70000,"Project Manager","MU","MCA",16,"Vicky");
	M.printManager();
	return 0;
}
