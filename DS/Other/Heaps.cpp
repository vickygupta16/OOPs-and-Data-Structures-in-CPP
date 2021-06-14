#include<iostream>

using namespace std;

class Heap
{
	private:
		int *harr;
		int size,last;
		void reHeapUp(int);
		void reHeapDown(int,int);
	public:
		Heap(int);
		void printHeap();
		void buildHeap();
		void createArray();
		void deleteHeap();
		void insertHeap(int);
		void heapSort();
		int selectK(int);
};

Heap::Heap(int s)
{
	size=s;
	harr=new int[size];
	last=-1;
}

void Heap::printHeap()
{
	if(last>=0 && last<size)
	{
		cout<<"\n\n\tHeap : ";
		for(int i=0;i<=last;++i)
		{
			cout<<harr[i]<<"\t";
		}
	}
	else
	{
		cout<<"\n\n\tElements does not exist";
	}
}

void Heap::createArray()
{
	cout<<"\n\tKindly enter elements into array : \n";
	int i=0;
	char ch;
	do
	{
		cout<<"\tElement "<<i<<" : ";
		cin>>harr[i];
		last=i;
		if(i==size-1)
		{
			break;
		}
		else
		{
			cout<<"\tEnter more elements? (y/n) : ";
			cin>>ch;
			++i;
		}
	}while(ch=='y');
}

void Heap::buildHeap()
{
	for(int walker=1;walker<=last;++walker)
	{
		reHeapUp(walker);
	}
}

void Heap::reHeapUp(int newNode)
{
	if(newNode!=0)
	{
		int temp;
		int parent=(newNode-1)/2;
		if(harr[newNode]>harr[parent])
		{
			temp=harr[newNode];
			harr[newNode]=harr[parent];
			harr[parent]=temp;
			reHeapUp(parent);
		}
	}
}

void Heap::deleteHeap()
{
	if(last==-1)
	{
		cout<<"\n\n\tHeap Empty!";
		return;
	}
	else
	{
		cout<<"\n\n\tDeleted "<<harr[0];
		harr[0]=harr[last];
		--last;
		reHeapDown(0,last);
	}
}

void Heap::reHeapDown(int root,int lastIndex)
{
	int leftKey,rightKey,largeChildKey,largeChildIndex,lowKey;
	leftKey=rightKey=largeChildKey=largeChildIndex=lowKey=0;
	if((root*2)+1<=lastIndex)
	{
		leftKey=harr[(root*2)+1];
		if((root*2)+2<=lastIndex)
		{
			rightKey=harr[(root*2)+2];
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
		if(harr[root]<harr[largeChildIndex])
		{
			int temp=harr[root];
			harr[root]=harr[largeChildIndex];
			harr[largeChildIndex]=temp;
			reHeapDown(largeChildIndex,lastIndex);
		}
	}
}

void Heap::insertHeap(int data)
{
	if(last==size-1)
	{
		cout<<"\n\n\tHeap Full!";
		return;
	}
	else
	{
		++last;
		harr[last]=data;
		reHeapUp(last);
	}
}

void Heap::heapSort()
{
	int sorted,holdData;
	buildHeap();
	sorted=last;
	while(sorted>0)
	{
		holdData=harr[0];
		harr[0]=harr[sorted];
		harr[sorted]=holdData;
		--sorted;
		reHeapDown(0,sorted);
	}
}

int Heap::selectK(int k)
{
	if(k>last)
	{
		return 0;
	}
	else
	{
		int i=1,temp,holdOut,heapSize,heapLast;
		heapSize=last;
		while(i<k)
		{
			temp=harr[0];
			deleteHeap();
			harr[last+1]=temp;
			++i;
		}
		holdOut=harr[0];
		while(last<=heapSize)
		{
			reHeapUp(last++);
		}
		--last;
		return holdOut;
	}
}

int main()
{
	cout<<"\n\n\t-------Max Heap-------";

	int n=0;
	cout<<"\n\n\tEnter size of Heap Array : ";
	cin>>n;
	Heap h1(n);
	h1.createArray();
	cout<<"\n\tElements entered : ";
	h1.printHeap();
	cout<<"\n\n\tHeap Elements : ";
	h1.buildHeap();
	h1.printHeap();

	cout<<"\n\n\tInserting 33 ....";
	h1.insertHeap(33);
	cout<<"\n\n\tHeap After inserting 33 : ";
	h1.printHeap();
	cout<<"\n\n\tInserting 22 ....";
	h1.insertHeap(22);
	cout<<"\n\n\tHeap After inserting 22 : ";
	h1.printHeap();
	cout<<"\n\n\tInserting 8 ....";
	h1.insertHeap(8);
	cout<<"\n\n\tHeap After inserting 8 : ";
	h1.printHeap();

	cout<<"\n\n\tHeap Elements After Deleting Root : ";
	h1.deleteHeap();
	h1.printHeap();
	cout<<"\n\n\tHeap Elements After Deleting Root : ";
	h1.deleteHeap();
	h1.printHeap();
	cout<<"\n\n\tHeap Elements After Deleting Root : ";
	h1.deleteHeap();
	h1.printHeap();

	cout<<"\n\n\tInserting 60 ....";
	h1.insertHeap(60);
	cout<<"\n\n\tHeap After inserting 60 : ";
	h1.printHeap();
	cout<<"\n\n\tInserting 70 ....";
	h1.insertHeap(70);
	cout<<"\n\n\tHeap After inserting 70 : ";
	h1.printHeap();
	cout<<"\n\n\tInserting 80 ....";
	h1.insertHeap(80);
	cout<<"\n\n\tHeap After inserting 80 : ";
	h1.printHeap();
	
	int knum,kvalue;
	cout<<"\n\n\tEnter value of K : ";
	cin>>knum;
	kvalue=h1.selectK(knum);
	if(kvalue!=0)
	{
		cout<<"\n\tK(th) Highest Number is : "<<kvalue;
	}
	else if(kvalue==0)
	{
		cout<<"\n\tIndex Out of Bound";
	}

	cout<<"\n\n\tHeap Sort : ";
	h1.heapSort();
	h1.printHeap();

	return 0;
}
