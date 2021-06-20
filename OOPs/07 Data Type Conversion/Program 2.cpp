#include<iostream>
#include<string.h>

using namespace std;

class Time24;	//forward declaration

class Time12
{
	private:
		int hour,minute,second;
		char ampm[3];
	public:
		Time12(int,int,int,char *);
		Time12(Time24);
		int getHour();
		int getMinute();
		int getSecond();
		char* getAMPM();
		void printTime();
};

class Time24
{
	private:
		int hour,minute,second;
	public:
		Time24(int,int,int);
		Time24(Time12);
		int getHour();
		int getMinute();
		int getSecond();
		void printTime();
};

Time12::Time12(int h=0,int m=0,int s=0,char *ap="PM")
{
	hour=h;
	minute=m;
	second=s;
	strcpy(ampm,ap);
	//strcpy is a string function used to
	//copy content of variable in 2nd parameter to variable in 1st parameter
}

Time24::Time24(int h=0,int m=0,int s=0)
{
	hour=h;
	minute=m;
	second=s;
}

Time12::Time12(Time24 obj)
{
	hour=obj.getHour();
	minute=obj.getMinute();
	second=obj.getSecond();
	if(hour==12)
	{
		strcpy(ampm,"PM");
	}
	else if(hour>12)
	{
		hour=hour-12;
		strcpy(ampm,"PM");
	}
	else
	{
		strcpy(ampm,"AM");
	}
}

Time24::Time24(Time12 obj)
{
	hour=obj.getHour();
	minute=obj.getMinute();
	second=obj.getSecond();
	if(strcmp("PM",obj.getAMPM())==0 && hour<12)
	{
		hour=hour+12;
	}
}

int Time12::getHour()
{
	return hour;
}

int Time24::getHour()
{
	return hour;
}

int Time12::getMinute()
{
	return minute;
}

int Time24::getMinute()
{
	return minute;
}

int Time12::getSecond()
{
	return second;
}

int Time24::getSecond()
{
	return second;
}

char* Time12::getAMPM()
{
	return ampm;
}

void Time12::printTime()
{
	cout<<"\n\t"<<hour<<":"<<minute<<":"<<second<<" "<<ampm;
}

void Time24::printTime()
{
	cout<<"\n\t"<<hour<<":"<<minute<<":"<<second;
}

int main()
{
	Time24 T1(18,20,30);
	
	Time12 T2=T1;		//user defined data type to user defined data type, Time24 to Time12
	cout<<"\n\n\t";
	T1.printTime();
	cout<<"\n\tis same as ";
	T2.printTime();
	
	Time12 T3(7,16,10,"PM");
	Time24 T4=T3;		//user defined data type to user defined data type, Time12 to Time24
	cout<<"\n\n\t";
	T3.printTime();
	cout<<"\n\tis same as ";
	T4.printTime();
	
	return 0;
}
