#include<iostream>

using namespace std;

const double PI=3.141592654;

class Shape
{
	public:
		virtual void print()=0;
		virtual double area()=0;
};

class Circle:public Shape
{
	private:
		double radius;
	public:
		Circle();
		void get();
		void print();
		double area();
		~Circle();
};

Circle::Circle()
{
	radius=0;
}

void Circle::get()
{
	cout<<"\n\n\tEnter radius : ";
	cin>>radius;
}

void Circle::print()
{
	cout<<"\n\n\tArea of Circle having Radius "<<radius<<" is "<<area();
}

double Circle::area()
{
	return PI*(radius*radius);
}

Circle::~Circle()
{
	cout<<"\n\n\tCircle Destructor";
}

class Square:public Shape
{
	private:
		int side;
	public:
		Square();
		void get();
		void print();
		double area();
		~Square();
};

Square::Square()
{
	side=0;
}

void Square::get()
{
	cout<<"\n\n\tEnter side for Square : ";
	cin>>side;
}

void Square::print()
{
	cout<<"\n\n\tArea of Square having side "<<side<<" units is "<<area();
}

double Square::area()
{
	return side*side;
}

Square::~Square()
{
	cout<<"\n\n\tSquare Destructor";
}

class Triangle:public Shape
{
	private:
		int base,height;
	public:
		Triangle();
		void get();
		void print();
		double area();
		~Triangle();
};

Triangle::Triangle()
{
	base=height=0;
}

void Triangle::get()
{
	cout<<"\n\n\tEnter base : ";
	cin>>base;
	cout<<"\tEnter height : ";
	cin>>height;
}

void Triangle::print()
{
	cout<<"\n\n\tArea of Triangle with base "<<base<<" & height "<<height<<" is "<<area();
}

double Triangle::area()
{
	return 0.5*base*height;
}

Triangle::~Triangle()
{
	cout<<"\n\n\tTriangle Destructor";
}

int main()
{
	Circle c;
	c.get();
	c.print();
	
	Square s;
	s.get();
	s.print();
	
	Triangle t;
	t.get();
	t.print();
	
	return 0;
}
