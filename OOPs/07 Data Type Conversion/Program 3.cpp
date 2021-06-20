#include<iostream>

using namespace std;

const double PI=3.141592654;

class Radian;	//forward declaration

class Degree
{
	private:
		double deg;
	public:
		Degree(double);
		void printDegree();
		Degree(Radian);
		double getDegree();
};

class Radian
{
	private:
		double rad;
	public:
		Radian(double);
		void printRadian();
		Radian(Degree);
		double getRadian();
};

Degree::Degree(double d=0)
{
	deg=d;
}

Radian::Radian(double r=0)
{
	rad=r;
}

void Degree::printDegree()
{
	cout<<"\n\n\tDegree : "<<deg;
}

void Radian::printRadian()
{
	cout<<"\n\n\tRadian : "<<rad;
}

double Degree::getDegree()
{
	return deg;
}

double Radian::getRadian()
{
	return rad;
}

Degree::Degree(Radian r)		//invoked on line D2=R2, line number 84
{
	deg=(r.getRadian()*180.0)/PI;
}

Radian::Radian(Degree d)		//invoked on line R1=D1, line number 78
{
	rad=(d.getDegree()*PI)/180.0;
}

int main()
{
	Degree D1(100);
	Radian R1;
	D1.printDegree();
	R1=D1;			//user defined data type to user defined data type, Degree to Radian
	R1.printRadian();
	
	Radian R2(2.3);
	Degree D2;
	R2.printRadian();
	D2=R2;			//user defined data type to user defined data type, Radian to Degree
	D2.printDegree();
	return 0;
}
