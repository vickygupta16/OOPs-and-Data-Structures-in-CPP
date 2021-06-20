#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int n1,n2,n3;
	float avg;
	char name[10];
	cout<<"\n\n\tEnter cricketer's name : ";
	cin>>name;
	cout<<"\n\tEnter runs of "<<name<<" in last 3 ODI : ";
	cin>>n1>>n2>>n3;
	avg=(n1+n2+n3)/3.0;
	if(avg<50)
	{
		cout<<"\n\n\t"<<name<<" ,you scored an average of ";
		cout<<right<<setw(10)<<setprecision(2)<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<<avg<<"\n\tWork harder!";
	}
	else if(avg>=50 && avg<=59)
	{
		cout<<"\n\n\t"<<name<<" ,you scored an average of ";
		cout<<right<<setw(10)<<setprecision(2)<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<<avg<<"\n\tGood!";
	}
	else if(avg>=60 && avg<=69)
	{
		cout<<"\n\n\t"<<name<<" ,you scored an average of ";
		cout<<right<<setw(10)<<setprecision(2)<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<<avg<<"\n\tExcellent!";
	}
	else
	{
		cout<<"\n\n\t"<<name<<" ,you scored an average of ";
		cout<<right<<setw(10)<<setprecision(2)<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<<avg<<"\n\tWelcome to the Bradman's club'!";
	}
}
