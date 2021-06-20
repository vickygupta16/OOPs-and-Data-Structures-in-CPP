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

Vehicle::Vehicle(int nw=0,int r=0)
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

Car::Car(int np=0,int nw=0,int r=0):Vehicle(nw,r)
{
	num_passengers=np;
}

void Car::showCar()
{
	showVehicle();
	cout<<"\n\tNumber of Passengers : "<<num_passengers;
}

class Truck:public Vehicle
{
	private:
		int loadLimit;
	public:
		Truck(int,int,int);
		void showTruck();
};

Truck::Truck(int ll=0,int nw=0,int r=0):Vehicle(nw,r)
{
	loadLimit=ll;
}

void Truck::showTruck()
{
	showVehicle();
	cout<<"\n\tLoad Limit : "<<loadLimit<<" kg";
}

int main()
{
	Car C1(5,4,20);
	C1.showCar();
	
	Truck T1(500,6,10);
	T1.showTruck();
	return 0;
}
