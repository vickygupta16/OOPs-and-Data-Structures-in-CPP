#include<iostream>

using namespace std;

class Fahrenheit;	//forward declaration

class Centigrade
{
	private:
		int cen;
	public:
		Centigrade();
		Centigrade(int);
		int getCentigrade();
		operator int();
		Centigrade(Fahrenheit);
		void printCentigrade();
};

class Fahrenheit
{
	private:
		int fah;
	public:
		Fahrenheit();
		Fahrenheit(int);
		int getFahrenheit();
		operator int();
		Fahrenheit(Centigrade);
		void printFahrenheit();
};

Centigrade::Centigrade()
{
	cen=0;
}

Fahrenheit::Fahrenheit()
{
	fah=0;
}

Centigrade::Centigrade(int c)
{
	cen=c;
}

Fahrenheit::Fahrenheit(int f)
{
	fah=f;
}

int Centigrade::getCentigrade()
{
	return cen;
}

int Fahrenheit::getFahrenheit()
{
	return fah;
}

void Centigrade::printCentigrade()
{
	cout<<"\n\tCentigrade : "<<cen;
}

void Fahrenheit::printFahrenheit()
{
	cout<<"\n\tFahrenheit : "<<fah;
}

Centigrade::operator int()
{
	return cen;
}

Fahrenheit::operator int()
{
	return fah;
}

Centigrade::Centigrade(Fahrenheit f)
{
	//cout<<"\n\t\tfrom centi f : "<<f;
	cen=((f-32)/180)*100;
}

Fahrenheit::Fahrenheit(Centigrade c)
{
	//cout<<"\n\t\tfrom fahren c : "<<c;
	fah=((180*c)/100)+32;
}

int main()
{
	int x=38;
	Centigrade C1=x;	//basic data type to user defined data type, int to Centigrade
	C1.printCentigrade();
	
	Fahrenheit F1=215;	//basic data type to user defined data type, int to Fahrenheit
	F1.printFahrenheit();
		
	x=F1;				//user defined data type to basic data type, Fahrenheit to int;
	cout<<"\n\tx : "<<x;
	
	Centigrade C2=F1;	//user defined data type to user defined data type, Fahrenheit to Centigrade
	cout<<"\n\t"<<F1.getFahrenheit()<<" degress Fahrenheit = "<<C2.getCentigrade()<<" degress Centigrade";
	
	Fahrenheit F2=C1;	//user defined data type to user defined data type, Centigrade to Fahrenheit
	cout<<"\n\t"<<C1.getCentigrade()<<" degrees Centigrade = "<<F2.getFahrenheit()<<" degrees Fahrenheit";
	return 0;
}
