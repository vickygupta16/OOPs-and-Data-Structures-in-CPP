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
		void bubbleSort();
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

void Sort::bubbleSort()
{
	int current,walker,temp;
	bool sorted=false;
	current=0;
	while(current<=last && sorted==false)
	{
		walker=last;
		sorted=true;
		while(walker>current)
		{
			if(arr[walker]<arr[walker-1])
			{
				sorted=false;
				temp=arr[walker];
				arr[walker]=arr[walker-1];
				arr[walker-1]=temp;
			}
			walker=walker-1;
		}
		cout<<"\n\tAfter Pass "<<current+1<<" : ";
		printArray();
		current++;
	}
}

int main()
{
	int n;
		
	//Bubble Sort
	//size 6
	//input		23,78,45,8,56,32
	cout<<"\n\n\t-------------------------BUBBLE SORT-------------------------";
	cout<<"\n\tEnter Array size for Bubble Sort : ";
	cin>>n;
	Sort Bubble(n);
	Bubble.fillArray();
	cout<<"\n\tArray  : ";
	Bubble.printArray();
	Bubble.bubbleSort();
	cout<<"\n\n\tBubble Sorting : ";
	Bubble.printArray();
	cout<<"\n\t-------------------------BUBBLE SORT-------------------------";
	//Bubble Sort
	
	return 0;
}
