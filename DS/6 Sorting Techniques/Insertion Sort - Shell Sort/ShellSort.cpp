#include<iostream>

using namespace std;

class Array
{
	private :
		int *arr;
		int last;
	public :
		Array(int);
		void fillArray();
		void printArray();
		void shellSort();
};

Array::Array(int s)
{
	arr=new int[s];
	for(int i=0;i<s;i++)
	{
		arr[i]=0;
	}
	last=s-1;
}

void Array::fillArray()
{
	cout<<"\n\tEnter elements : \n";
	for(int i=0;i<=last;i++)
	{
		cout<<"\tElement "<<i<<" : ";
		cin>>arr[i];
	}
}

void Array::printArray()
{
	for(int i=0;i<=last;i++)
	{
		cout<<"\t"<<arr[i];
	}
}

void Array::shellSort()
{
	int incre,current,hold,walker,i;
	incre=last/2;
	i=1;
	while(incre!=0)
	{
		current=incre;
		while(current<=last)
		{
			hold=arr[current];
			walker=current-incre;
			while(walker>=0 && hold<arr[walker])
			{
				arr[walker+incre]=arr[walker];
				walker=walker-incre;
			}
			arr[walker+incre]=hold;
			current=current+1;
		}
		cout<<"\n\tAfter Pass "<<i<<" : ";
		i++;
		printArray();
		incre=incre/2;
	}
}


int main()
{
	int n;
	cout<<"\n\n\t11-Vicky Gupta";
	
	//Shell Sort
	//size	12
	//input		71, 84, 1, 86, 2, 7, 85, 18, 48, 41, 65, 5
	cout<<"\n\n\n\t-------------------------SHELL SORT-------------------------";
	cout<<"\n\tEnter Array size for Shell Sort : ";
	cin>>n;
	Array Shell(n);
	Shell.fillArray();
	cout<<"\n\tArray : ";
	Shell.printArray();
	Shell.shellSort();
	cout<<"\n\n\tShell Sorting : ";
	Shell.printArray();
	cout<<"\n\t-------------------------SHELL SORT-------------------------";
	//Shell Sort
	
	return 0;
}
