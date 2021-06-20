#include<iostream>

using namespace std;

int main()
{
	void swap(int *,int *);	//function prototype
	int a,b;
	cout<<"\n\n\tEnter numbers a : ";
	cin>>a;
	cout<<"\n\tEnter number b : ";
	cin>>b;
	cout<<"\n\n\t"<<&a<<"\t"<<&b;	//memory address of variable a & b
	swap(&a,&b);
	return 0;
}

void swap(int *x,int *y)
{
	cout<<"\n\n\t"<<x<<"\t"<<y;		//memory address of variable a & b
	cout<<"\n\n\t"<<*x<<"\t"<<*y;	//values stored at memory address of a & b resp.
	cout<<"\n\n\t"<<&x<<"\t"<<&y;	//memory address of parameterized variables x & y
	int temp;
	cout<<"\n\tBefore swapping : ";
	cout<<"\n\n\tx : "<<*x<<"\ty : "<<*y<<"\n";
	temp=*x;
	*x=*y;
	*y=temp;
	cout<<"\n\tAfter swapping : ";
	cout<<"\n\tx : "<<*x<<"\ty : "<<*y<<"\n";
}
