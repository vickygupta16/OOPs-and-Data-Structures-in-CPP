#include<iostream>

using namespace std;

template<class T>
void sort(T *ar,int s)
{
	if(s>-1)
	{
		T temp;
		//selection sort
		for(int i=0;i<s;++i)
		{
			for(int j=i+1;j<s;++j)
			{
				if(ar[i]>ar[j])
				{
					temp=ar[i];
					ar[i]=ar[j];
					ar[j]=temp;
				}
			}
		}
	}
	else
	{
		cout<<"\n\tArray Empty!";
	}
}

template<class T>
void printArray(T *ar,int s)
{
	if(s>-1)
	{
		for(int i=0;i<s;++i)
		{
			cout<<"\t"<<ar[i];
		}
	}
	else
	{
		cout<<"\n\tArray Empty!";
	}
}

template<class T>
void printArray(T *ar,int s,int low,int high)
{
	if(s>-1)
	{
		if(low<s && high<=s && low<=high)
		{
			for(int i=low;i<=high;++i)
			{
				cout<<"\t"<<ar[i];
			}
		}
	}
	else
	{
		cout<<"\n\tArray Empty!";
	}
}

int main()
{
	int size=5;
	
	int intArr[size];
	cout<<"\n\n\tEnter elements in integer array\n";
	for(int i=0;i<size;++i)
	{
		cout<<"\tEnter element at "<<i<<" : ";
		cin>>intArr[i];
	}
	cout<<"\n\n\tInteger Array : ";
	printArray(intArr,size);
	cout<<"\n\tPart of Integer Array : ";
	printArray(intArr,size,0,3);
	sort(intArr,size);
	cout<<"\n\n\tInteger Array after Sorting : ";
	printArray(intArr,size);
	
	double doubleArr[size];
	cout<<"\n\n\tEnter elements in double array\n";
	for(int i=0;i<size;++i)
	{
		cout<<"\tEnter element at "<<i<<" : ";
		cin>>doubleArr[i];
	}
	cout<<"\n\n\tDouble Array : ";
	printArray(doubleArr,size);
	cout<<"\n\tPart of Double Array : ";
	printArray(doubleArr,size,2,4);
	sort(doubleArr,size);
	cout<<"\n\n\tDouble Array after Sorting : ";
	printArray(doubleArr,size);
	
	return 0;
}
