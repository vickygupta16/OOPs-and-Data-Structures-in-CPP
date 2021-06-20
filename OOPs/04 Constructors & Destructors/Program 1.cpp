#include<iostream>

using namespace std;

class Distance
{
	private:
		int feet;
		float inches;
	public:
		Distance();				//Default Constructor
		Distance(int,float);	//Parameterized Constructor
		~Distance();			//Destructor
};

Distance::Distance()
{
	cout<<"\n\n\tDefault Constructor\n\tEnter feet : ";
	cin>>feet;
	cout<<"\n\tEnter inches : ";
	cin>>inches;
}

Distance::Distance(int f,float i)
{
	cout<<"\n\n\tParameterized Constructor";
	feet=f;
	inches=i;
}

Distance::~Distance()
{
	cout<<"\n\n\tDestructor";
	cout<<"\n\tFeet : "<<feet<<"\tInches : "<<inches;
}

int main()
{
	void process1(Distance);
	Distance d1,d2(6,85);
	process1(d2);
	return 0;
}

void process1(Distance d3)
{
	cout<<"\n\n\tPROCESS 1";
	void process2(Distance);
	process2(d3);
}

void process2(Distance d4)
{
	cout<<"\n\n\tPROCESS 2";
}
