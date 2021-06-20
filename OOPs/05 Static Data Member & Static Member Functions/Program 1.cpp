#include<iostream>
#include<iomanip>

using namespace std;

class Cricket
{
	private:
		char name[10];
		char country[10];
		float avg;
	public:
		void getCricket();
		void printCricket();
		int static highest(Cricket *,int);
};

void Cricket::getCricket()
{
	cout<<"\n\n\tEnter name : ";
	cin>>name;
	cout<<"\n\tEnter country : ";
	cin>>country;
	cout<<"\n\tEnter average of ODI : ";
	cin>>avg;
}

void Cricket::printCricket()
{
	cout<<"\n\n\t"<<right<<setw(20)<<"Name : "<<left<<setw(10)<<name;
	cout<<"\n\t"<<right<<setw(20)<<"Country : "<<left<<setw(10)<<country;
	cout<<"\n\t"<<right<<setw(20)<<"Average runs : "<<left<<setw(10)<<avg;
}

int Cricket::highest(Cricket *arr,int s)
{
	float h=arr[0].avg;
	int index=0;
	for(int i=1;i<s;++i)
	{
		if(h<arr[i].avg)
		{
			index=i;
			//cout<<"\n\n\t\t\t\tindex "<<index;
		}
	}
	return index;
}

int main()
{
	int size=4;
	Cricket c[size];		//array of objects
	for(int i=0;i<size;++i)
	{
		c[i].getCricket();
		//c[i].printCricket();
	}
	cout<<"\n\n\n\tCricketer with highest score : ";
	int index=Cricket::highest(c,size);		//way to call a static function
	c[index].printCricket();
	return 0;
}
