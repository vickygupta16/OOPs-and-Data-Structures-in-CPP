#include<iostream>

using namespace std;

class Samay
{
	private:
		int hour,minute,second;
	public:
		Samay();
		void getSamay();
		void getSamay(int,int,int);
		void printSamay();
		int isGreaterThan(Samay);
		int isLessThan(Samay);
		int isNotEqualTo(Samay);
		void add2Samay(Samay,Samay);
};

Samay::Samay()
{
	hour=minute=second=0;
}

void Samay::getSamay()
{
	cout<<"\n\n\tEnter hour : ";
	cin>>hour;
	cout<<"\n\tEnter minute : ";
	cin>>minute;
	cout<<"\n\tEnter second : ";
	cin>>second;
}

void Samay::getSamay(int h,int m,int s)
{
	hour=h;
	minute=m;
	second=s;
}

void Samay::printSamay()
{
	cout<<"\n\t"<<hour<<":"<<minute<<":"<<second;
}

int Samay::isGreaterThan(Samay obj)
{
	if(hour>obj.hour)
	{
		return 1;
	}
	else if(hour==obj.hour && minute>obj.minute)
	{
		return 1;
	}
	else if(hour==obj.hour && minute==obj.minute && second>obj.second)
	{
		return 1;
	}
	return 0;
}

int Samay::isLessThan(Samay obj)
{
	if(hour<obj.hour)
	{
		return 1;
	}
	else if(hour==obj.hour && minute<obj.minute)
	{
		return 1;
	}
	else if(hour==obj.hour && minute==obj.minute && second<obj.second)
	{
		return 1;
	}
	return 0;
}

int Samay::isNotEqualTo(Samay obj)
{
	if(hour!=obj.hour && minute!=obj.minute && second!=obj.second)
	{
		return 1;
	}
	return 0;
}

void Samay::add2Samay(Samay a,Samay b)
{
	second=a.second+b.second;
	minute=a.minute+b.minute;
	hour=a.hour+b.hour;
	if(second>=60)
	{
		second=second-60;
		++minute;
	}
	if(minute>=60)
	{
		minute=minute-60;
		++hour;
	}
}

int main()
{
	Samay s1,s2;
	s1.getSamay(7,47,50);
	//s1.printSamay();
	s2.getSamay(5,30,56);
	//s2.printSamay();
	
	if(s1.isGreaterThan(s2))
	{
		s1.printSamay();
		cout<<"\n\tis greater than";
		s2.printSamay();
	}
	
	if(s1.isLessThan(s2))
	{
		s1.printSamay();
		cout<<"\n\tis less than";
		s2.printSamay();
	}
	
	if(s1.isNotEqualTo(s2))
	{
		s1.printSamay();
		cout<<"\n\tis not equal to";
		s2.printSamay();
	}
	
	
	cout<<"\n\n";
	Samay s3;
	s3.add2Samay(s1,s2);
	s3.printSamay();
	return 0;
}
