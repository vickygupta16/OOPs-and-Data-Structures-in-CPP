#include<iostream>

using namespace std;

int main()
{
	//function prototype
	//need to be written before defining/calling a function
	void calculate(int *,float,float *,int *,int *);	
	float size=4.0;
	float avg=0.0;
	int l=0,h=0;
	int arr[(int)size];	//float to int conversion
	for(int i=0;i<(int)size;++i)
	{
		cout<<"\n\tEnter element at "<<i<<" : ";
		cin>>arr[i];
	}
	calculate(arr,size,&avg,&h,&l);	//passing memory address of variable avg, h & l
	cout<<"\n\n\tAverage : "<<avg;
	cout<<"\n\n\tHighest : "<<h;
	cout<<"\n\n\tLowest : "<<l;
	return 0;
}

void calculate(int *arr,float size,float *avg,int *h,int *l)
{
	int sum=0;
	for(int i=0;i<(int)size;++i)
	{
		sum=sum+arr[i];
	}
	*avg=sum/size;
	*h=*l=arr[0];
	for(int i=0;i<(int)size;++i)
	{
		if(*h<arr[i])
		{
			*h=arr[i];
		}
		if(*l>arr[i])
		{
			*l=arr[i];
		}
	}
}
