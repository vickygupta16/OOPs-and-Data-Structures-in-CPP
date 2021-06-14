#include<iostream>

using namespace std;

class Sort
{
	private :
		int *arr;
		int last;
	public :
		Sort(int);
		void fillArray();
		void printArray();
		void insertionSort();
};

Sort::Sort(int s)
{
	arr=new int[s];
	for(int i=0;i<s;i++)
	{
		arr[i]=0;
	}
	last=s-1;
}

void Sort::fillArray()
{
	cout<<"\n\tEnter elements : \n";
	for(int i=0;i<=last;i++)
	{
		cout<<"\tElement "<<i<<" : ";
		cin>>arr[i];
	}
}

void Sort::printArray()
{
	for(int i=0;i<=last;i++)
	{
		cout<<"\t"<<arr[i];
	}
}

void Sort::insertionSort()
{
	int hold,current,walker;
	current=1;
	while(current<=last)
	{
		hold=arr[current];
		walker=current-1;
		while(walker>=0 && hold<arr[walker])
		{
			arr[walker+1]=arr[walker];
			walker--;
		}
		arr[walker+1]=hold;
		cout<<"\n\tAfter Pass "<<current<<" : ";
		printArray();
		current++;
	}
}

int main()
{
	int n;
	//Insertion Sort 
	//size	12
	//input 	71, 84, 1, 86, 2, 7, 85, 18, 48, 41, 65, 5
	cout<<"\n\n\n\t-------------------------INSERTION SORT-------------------------";
	cout<<"\n\tEnter Array size for Insertion Sort : ";
	cin>>n;
	Sort Insertion(n);
	Insertion.fillArray();
	cout<<"\n\tArray : ";
	Insertion.printArray();
	Insertion.insertionSort();
	cout<<"\n\n\tInsertion Sorting : ";
	Insertion.printArray();
	cout<<"\n\t-------------------------INSERTION SORT-------------------------";
	//Insertion Sort
	
	return 0;
}
