#include<iostream>

using namespace std;

int main()
{
	int num;
	cout<<"\n\tEnter a number : ";
	cin>>num;
	if(num%2==0)
	{
		cout<<"\n\t"<<num<<" is an even number";
	}
	else
	{
		cout<<"\n\t"<<num<<" is an odd number";
	}
	return 0;
}
