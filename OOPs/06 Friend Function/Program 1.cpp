#include<iostream>
#include<string.h>

using namespace std;

class Saturn;	//forward declaration

class Earth
{
	private:
		char satellite[20];
		double rpy;
	public:
		Earth();
		void getDetails();
		void printDetails();
		friend isGreater(Earth,Saturn);		//friend function prototype
};

Earth::Earth()
{
	strcpy(satellite,"");
	rpy=0;
}

void Earth::getDetails()
{
	cout<<"\n\n\tDetails for Earth";
	cout<<"\n\tSatellite : ";
	cin>>satellite;
	cout<<"\tRotation Per Year : ";
	cin>>rpy;
}

void Earth::printDetails()
{
	cout<<"\n\n\tDetails for Earth";
	cout<<"\n\tSatellite : "<<satellite<<"\n\tRotation Per Year : "<<rpy;
}

class Saturn
{
	private:
		char satellite[20];
		double rpy;
	public:
		Saturn();
		void getDetails();
		void printDetails();
		friend isGreater(Earth,Saturn);		//friend function prototype
};

Saturn::Saturn()
{
	strcpy(satellite,"");
	rpy=0;
}

void Saturn::getDetails()
{
	cout<<"\n\n\tDetails for Saturn";
	cout<<"\n\tSatellite : ";
	cin>>satellite;
	cout<<"\tRotation Per Year : ";
	cin>>rpy;
}

void Saturn::printDetails()
{
	cout<<"\n\n\tDetails for Saturn";
	cout<<"\n\tSatellite : "<<satellite<<"\n\tRotation Per Year : "<<rpy;
}

int main()
{
	Earth E;
	E.getDetails();
	E.printDetails();
	Saturn S;
	S.getDetails();
	S.printDetails();
	if(isGreater(E,S)==1)
	{
		cout<<"\n\n\tSatellite's RPY of Earth is greater than Satellite's RPY of Saturn";
	}
	else
	{
		cout<<"\n\n\tSatellite's RPY of Saturn is greater than Satellite's RPY of Earth";
	}
	return 0;
}

int isGreater(Earth e,Saturn s)
{
	if(e.rpy>s.rpy)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
