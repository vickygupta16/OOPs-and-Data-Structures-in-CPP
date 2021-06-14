#include<iostream>

using namespace std;

class Sort
{
	private :
		int *arr;
		int last;
		void buildHeap();
		void reHeapUp(int);
		void reHeapDown(int,int);
	public :
		Sort(int);
		void fillArray();
		void printArray();
		void heapSort();
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

void Sort::heapSort()
{
	int sorted,holdData,i;
	i=1;
	buildHeap();
	sorted=last;
	while(sorted>0)
	{
		holdData=arr[0];
		arr[0]=arr[sorted];
		arr[sorted]=holdData;
		sorted--;
		reHeapDown(0,sorted);
		cout<<"\n\tAfter Pass "<<i<<" : ";
		printArray();
		i++;
	}
}

void Sort::buildHeap()
{
	for(int walker=1;walker<=last;walker++)
	{
		reHeapUp(walker);
	}
	cout<<"\n\n\tArray in Heap Format : ";
	printArray();
	cout<<"\n";
}

void Sort::reHeapUp(int newNode)
{
	if(newNode!=0)
	{
		int temp;
		int parent=(newNode-1)/2;
		if(arr[newNode]>arr[parent])
		{
			temp=arr[newNode];
			arr[newNode]=arr[parent];
			arr[parent]=temp;
			reHeapUp(parent);
		}
	}
}

void Sort::reHeapDown(int root,int lastIndex)
{
	int leftKey,rightKey,largeChildKey,largeChildIndex,lowKey;
	leftKey=rightKey=largeChildKey=largeChildIndex=lowKey=0;
	if((root*2)+1<=lastIndex)
	{
		leftKey=arr[(root*2)+1];
		if((root*2)+2<=lastIndex)
		{
			rightKey=arr[(root*2)+2];
		}
		else
		{
			rightKey=lowKey;
		}
		if(leftKey>rightKey)
		{
			largeChildKey=leftKey;
			largeChildIndex=(root*2)+1;
		}
		else
		{
			largeChildKey=rightKey;
			largeChildIndex=(root*2)+2;
		}
		if(arr[root]<arr[largeChildIndex])
		{
			int temp=arr[root];
			arr[root]=arr[largeChildIndex];
			arr[largeChildIndex]=temp;
			reHeapDown(largeChildIndex,lastIndex);
		}
	}
}

int main()
{
	int n;	
	//Heap Sort
	//size	12
	//input		71, 84, 1, 86, 2, 7, 85, 18, 48, 41, 65, 5
	cout<<"\n\n\n\t-------------------------HEAP SORT-------------------------";
	cout<<"\n\tEnter Array size for Heap Sort : ";
	cin>>n;
	Sort Heap(n);
	Heap.fillArray();
	cout<<"\n\tArray : ";
	Heap.printArray();
	Heap.heapSort();
	cout<<"\n\n\tHeap Sort : ";
	Heap.printArray();
	cout<<"\n\t-------------------------HEAP SORT-------------------------";
	//Heap Sort
	
	return 0;
}
