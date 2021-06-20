#include<iostream>

using namespace std;

const double PI=3.141592654;

class Point
{
	private:
		float x,y;
	public:
		Point(float,float);
		void showPoint();
};

Point::Point(float a=0,float b=0)
{
	x=a;
	y=b;
}

void Point::showPoint()
{
	cout<<"\n\tPoints : \n\tx : "<<x<<"\ty : "<<y;
}

class Circle:public Point
{
	private:
		int radius;
	public:
		Circle(int,float,float);
		void showCircle();
		float areaOfCircle();
		int getRadius();
};

Circle::Circle(int r=0,float a=0,float b=0):Point(a,b)
{
	radius=r;
}

void Circle::showCircle()
{
	showPoint();
	cout<<"\n\tArea of Circle with Radius "<<radius<<" is "<<areaOfCircle();
}

float Circle::areaOfCircle()
{
	return PI*(radius^2);
}

int Circle::getRadius()
{
	return radius;
}

class Cylinder:public Circle
{
	private:
		int height;
	public:
		Cylinder(int,int,float,float);
		void showCylinder();
		double areaOfCylinder();
		double volumeOfCylinder();
};

Cylinder::Cylinder(int h=0,int r=0,float a=0,float b=0):Circle(r,a,b)
{
	height=h;
}

void Cylinder::showCylinder()
{
	showCircle();
	cout<<"\n\tArea of Cylinder with Height "<<height<<" and Radius "<<getRadius()<<" is "<<areaOfCylinder();
	cout<<"\n\tVolume of Cylinder with Height "<<height<<" and Radius "<<getRadius()<<" is "<<volumeOfCylinder();
}

double Cylinder::areaOfCylinder()
{
	return ((2*(PI*(getRadius()^2)))+(2*PI*getRadius()*height));
}

double Cylinder::volumeOfCylinder()
{
	return (PI*(getRadius()^2))*height;
}

int main()
{
	Cylinder C1(16,7,43,25);
	C1.showCylinder();
	return 0;
}
