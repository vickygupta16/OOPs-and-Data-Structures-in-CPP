#include<iostream>

using namespace std;

class Vehicle
{
	private:
		int num_wheels,range;
	public:
		Vehicle(int,int);
		void showVehicle();
};

Vehicle::Vehicle(int nw,int r)
{
	num_wheels=nw;
	range=r;
}

void Vehicle::showVehicle()
{
	cout<<"\n\n\tNumber of Wheels : "<<num_wheels;
	cout<<"\n\tRange : "<<range<<" km";
}

class Car:public Vehicle
{
	private:
		int num_passengers;
	public:
		Car(int,int,int);
		void showCar();
};

Car::Car(int np,int nw,int r):Vehicle(nw,r)
{
	num_passengers=np;
}

void Car::showCar()
{
	showVehicle();
	cout<<"\n\tNumber of Passengers : "<<num_passengers;
}

int main()
{
	Car C1(5,4,20);
	C1.showCar();
	return 0;
}
