#include<iostream>
#include<ctime>
#include<algorithm>

using namespace std;

void modify(int *arr,int subscript,int value)
{
	arr[subscript]=value;
}

int main()
{
	srand(time(0));
	int size=5;
	int arr[size];
	for(int i=0;i<size;++i)
	{
		arr[i]=rand()%100+1;
	}
	char ch;
	int sub,value;
	do
	{
		cout<<"\n\n\tArray : ";
		for(int i=0;i<size;++i)
		{
			cout<<"\t"<<arr[i];
		}
		try
		{
			cout<<"\n\n\tEnter subscript between 0 and 4, (including 0 and 4) : ";
			cin>>sub;
			if(sub>=0 && sub<=4)
			{
				cout<<"\n\n\tEnter value to substitute at "<<sub<<" : ";
				cin>>value;
				modify(arr,sub,value);
				continue;
			}
			else
			{
				throw sub;
			}
		}
		catch(int subscript)
		{
			cout<<"\n\n\t"<<subscript<<" not in range of 0-4!";
		}
		cout<<"\n\n\tDo you want to continue? (y/n) : ";
		cin>>ch;
	}while(ch=='y');
	return 0;
}
