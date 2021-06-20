#include<iostream>

using namespace std;

int main()
{
	char ch;
	int num;
	do
	{
		cout<<"\n\n\tEnter a number : ";
		cin>>num;
		if(num>=1 && num<=9)
		{
			for(int i=1;i<=10;++i)
			{
				cout<<"\n\t"<<num<<" x "<<i<<" = "<<num*i;
			}
		}
		else
		{
			cout<<"\n\t"<<num<<" not in range 1-9!";
		}
		cout<<"\n\n\tDo you want to continue? (y/n) : ";
		cin>>ch;
	}while(ch=='y');
	return 0;
}
