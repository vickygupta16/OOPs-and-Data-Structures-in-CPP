#include<iostream>

using namespace std;

int main()
{
	int n,i=1,at=0,bt=0;
	while(i<=7)
	{
		cout<<"\n\n\tEnter temperature in celcius for city "<<i<<" : ";
		cin>>n;
		if(n<30)
		{
			++bt;	//accumulator
		}
		else
		{
			++at;	//accumulator
		}
		++i;
	}
	cout<<"\n\n\tTotal number of cities with temperature below 30 : "<<bt;
	cout<<"\n\tTotal number of cities with temperature 30 and above : "<<at;
}
