#include<iostream>
#include<ctime>
#include<algorithm>
#include<iomanip>

using namespace std;

int main()
{
	srand(time(0));
	int arr[10];
	for(int i=0;i<10;++i)
	{
		arr[i]=rand()%50+50;
	}
	
	cout<<"\n\n\tUSING CONVENTIONAL SQUARE BRACES AND THE & SIGN\n\t";
	cout<<left<<setw(10)<<"Element"<<left<<setw(10)<<"Address";
	for(int i=0;i<10;++i)
	{
		cout<<"\n\t";
		cout<<left<<setw(10)<<arr[i];
		cout<<left<<setw(10)<<&arr[i];
	}
	
	cout<<"\n\n\tUSING POINTER METHOD\n\t";
	cout<<left<<setw(10)<<"Element"<<left<<setw(10)<<"Address";
	int *p;
	int i=0;
	p=arr;
	while(i<10)
	{
		cout<<"\n\t";
		cout<<left<<setw(10)<<*p;
		cout<<left<<setw(10)<<p;
		++p;
		++i;
	}
	
	cout<<"\n\n\tUSING INDIRECTION METHOD\n\t";
	cout<<left<<setw(10)<<"Element"<<left<<setw(10)<<"Address";
	for(i=0;i<10;++i)
	{
		cout<<"\n\t";
		cout<<left<<setw(10)<<*(arr+i);
		cout<<left<<setw(10)<<(arr+i);
	}
	
	return 0;
}
