#include<iostream>
#include<ctime>
#include<algorithm>

using namespace std;

class Array
{
	private:
		int *arr,size;
	public:
		Array();
		Array(int);
		void printArray();
		friend void operator ++ (Array,int);	//overload post increment operator as friend function
		friend void operator -- (Array,int);	//overload post decrement operator as friend function
		friend void operator ++ (Array);		//overload pre increment operator as friend function
		friend void operator -- (Array);		//overload pre decrement operator as friend function
};

Array::Array()
{
	cout<<"\n\n\tEnter size of array : ";
	cin>>size;
	arr=new int[size];
	for(int i=0;i<size;++i)
	{
		arr[i]=rand()%10+1;
	}
}

Array::Array(int s)
{
	size=s;
	arr=new int[size];
	for(int i=0;i<size;++i)
	{
		arr[i]=rand()%10+1;
	}
}

void Array::printArray()
{
	cout<<"\n\n\tArray : ";
	for(int i=0;i<size;++i)
	{
		cout<<"\t"<<arr[i];
	}
}

void operator ++ (Array obj,int dummy)	//called by a++
{
	for(int i=0;i<obj.size;++i)
	{
		obj.arr[i]++;
	}
}

void operator -- (Array obj,int dummy)	//called by a--
{
	for(int i=0;i<obj.size;++i)
	{
		obj.arr[i]--;
	}
}

void operator ++ (Array obj)	//called by ++a
{
	for(int i=0;i<obj.size;++i)
	{
		++obj.arr[i];
	}
}

void operator -- (Array obj)	//called by --a
{
	for(int i=0;i<obj.size;++i)
	{
		--obj.arr[i];
	}
}

int main()
{
	Array a;
	a.printArray();
	a++;
	a.printArray();
	a--;
	a.printArray();
	++a;
	a.printArray();
	--a;
	a.printArray();
	return 0;
}
