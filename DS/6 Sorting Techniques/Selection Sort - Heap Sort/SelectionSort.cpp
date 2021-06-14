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
		void selectionSort();
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

void Sort::selectionSort()
{
	int temp;
	for(int i=0;i<last;i++)
	{
		for(int j=i+1;j<=last;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		cout<<"\n\tAfter Pass "<<i+1<<" : ";
		printArray();
	}
}

int main()
{
	int n;	
	//Selection Sort
	//size	12
	//input		71, 84, 1, 86, 2, 7, 85, 18, 48, 41, 65, 5
	cout<<"\n\n\n\t-------------------------SELECTION SORT-------------------------";
	cout<<"\n\tEnter Array size for Selection Sort : ";
	cin>>n;
	Sort Selection(n);
	Selection.fillArray();
	cout<<"\n\tArray : ";
	Selection.printArray();
	Selection.selectionSort();
	cout<<"\n\n\tSelection Sorting : ";
	Selection.printArray();
	cout<<"\n\t-------------------------SELECTION SORT-------------------------";
	//Selection Sort
	
	return 0;
}
