#include<iostream>
#include<string.h>

using namespace std;

class StandardTime
{
	private:
		char ampm[2];
		int hours,minutes,seconds;
	public:
		StandardTime(int,int,int,char *);	//default and parameterized constructor together
		void printStandardTime() const;		//constant function
		//function overloading
		void getTime();						//function with no parameters
		void getTime(int,int,int,char *);	//function with same name but having parameters
		//function overloading comes under COMPILE TIME POLYMORPHISM
};

StandardTime::StandardTime(int h=12,int m=0,int s=0,char *ap="PM")
{
	hours=h;
	minutes=m;
	seconds=s;
	strcpy(ampm,ap);	
	//strcpy is a string function used to
	//copy content of variable in 2nd parameter to variable in 1st parameter
}

void StandardTime::getTime()
{
	cout<<"\n\n\tEnter hours : ";
	cin>>hours;
	cout<<"\n\tEnter minutes : ";
	cin>>minutes;
	cout<<"\n\tEnter seconds : ";
	cin>>seconds;
	cout<<"\n\tEnter AM / PM : ";
	cin>>ampm;
}

void StandardTime::getTime(int h,int m,int s,char *ap)
{
	hours=h;
	minutes=m;
	seconds=s;
	strcpy(ampm,ap);	//read as ampm=ap
}

void StandardTime::printStandardTime() const	
{
	//a constant function cannot alter the calling object's data
	//hours=4;
	cout<<"\t"<<hours<<":"<<minutes<<":"<<seconds<<" "<<ampm;
}

int main()
{
	StandardTime S1,S2(11,06,30,"AM"),S3,S4;
	S3.getTime();
	S4.getTime(4,40,23,"PM");
	
	cout<<"\n\n\tS1 Time : ";
	S1.printStandardTime();
	cout<<"\n\n\tS2 Time : ";
	S2.printStandardTime();
	cout<<"\n\n\tS3 Time : ";
	S3.printStandardTime();
	cout<<"\n\n\tS4 Time : ";
	S4.printStandardTime();
	return 0;
}
