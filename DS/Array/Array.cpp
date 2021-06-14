#include<iostream>

using namespace std;

class Array
{
	private:
		int size;
		int *arr;
		void sequentialSort();
	public:
		Array();
		Array(int);
		void fillArray();
		void printArray();
		int lowest();
		int highest();
		int linearSearch(int);
		void binarySearch(int);
		void combineArray(Array,Array);
		void mergeArray(Array,Array);
};

Array::Array()
{
	size=3;
	arr=new int[size];
	for(int i=0;i<size;++i)
	{
		arr[i]=0;
	}
}

Array::Array(int s)
{
	size=s;
	arr=new int[size];
	for(int i=0;i<size;++i)
	{
		arr[i]=0;
	}
}

void Array::fillArray()
{
	cout<<"\n\n\tEnter "<<size<<" elements in array.\n";
	for(int i=0;i<size;++i)
	{
		cout<<"\tEnter element "<<i+1<<" : ";
		cin>>arr[i];
	}
}

void Array::printArray()
{
	cout<<"\n\tArray elements : ";
	for(int i=0;i<size;++i)
	{
		cout<<arr[i]<<"\t";
	}
}

void Array::sequentialSort()
{
	int temp=0;
	for(int i=0;i<size;++i)
	{
		for(int j=i+1;j<size;++j)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

int Array::lowest()
{
	int low=arr[0];
	for(int i=1;i<size;++i)
	{
		if(low>arr[i])
		{
			low=arr[i];
		}
	}
	return low;
}

int Array::highest()
{
	int high=arr[0];
	for(int i=1;i<size;++i)
	{
		if(high<arr[i])
		{
			high=arr[i];
		}
	}
	return high;
}

int Array::linearSearch(int key)
{
	for(int i=0;i<size;++i)
	{
		if(key==arr[i])
		{
			return i;
		}
	}
	return -1;
}

void Array::binarySearch(int key)
{
	sequentialSort();
	cout<<"\n\tSorted Array";
	printArray();
	int low=0;
	int high=size-1;
	int mid=0;
	while(low<=high)
	{
		mid=int((low+high)/2);
		if(key<arr[mid])
		{
			high=mid-1;
		}
		else if(key>arr[mid])
		{
			low=mid+1;
		}
		else
		{
			cout<<"\n\t"<<key<<" found at index "<<mid<<" in array.";
			return;
		}
	}
	cout<<"\n\t"<<key<<" not found";
}

void Array::combineArray(Array o1,Array o2)
{
	size=o1.size+o2.size;
	arr=new int[size];
	int i,j,k;
	for(i=0,j=0,k=0;k<size;++k)
	{
		if(k%2==0)
		{
			arr[k]=o1.arr[i];
			++i;
		}
		else if(k%2!=0)
		{
			arr[k]=o2.arr[j];
			++j;
		}
		if(i>=o1.size)
		{
			for(++k;j<o2.size;++j,++k)
			{
				arr[k]=o2.arr[j];
			}
		}
		if(j>=o2.size)
		{
			for(++k;i<o1.size;++i,++k)
			{
				arr[k]=o1.arr[i];
			}
		}
	}
}

void Array::mergeArray(Array o1,Array o2)
{
	int i,j,k;
	size=o1.size+o2.size;
	arr=new int[size];
	o1.sequentialSort();
	o2.sequentialSort();
	for(i=0,j=0,k=0;k<size;++k)
	{
		if(o1.arr[i]<o2.arr[j])
		{
			arr[k]=o1.arr[i];
			++i;
			if(i>=o1.size)
			{
				for(++k;k<size;++k,++j)
				{
					arr[k]=o2.arr[j];
				}
			}
		}
		else
		{
			arr[k]=o2.arr[j];
			++j;
			if(j>=o2.size)
			{
				for(++k;k<size;++k,++i)
				{
					arr[k]=o1.arr[i];
				}
			}
		}
	}
}

int main()
{
	cout<<"\n\n\t-------Array-------";
	Array a1(5);
	a1.fillArray();
	a1.printArray();
	
	int lowestNumber=a1.lowest();
	cout<<"\n\n\tLowest number in array : "<<lowestNumber;
	
	int highestNumber=a1.highest();
	cout<<"\n\n\tHighest number in array : "<<highestNumber;
	
	int searchKey=0,linearSearchResult=0;
	cout<<"\n\n\tEnter a key to be searched using Linear Search : ";
	cin>>searchKey;
	linearSearchResult=a1.linearSearch(searchKey);
	if(linearSearchResult!=-1)
	{
		cout<<"\t"<<searchKey<<" found at index "<<linearSearchResult<<" in array";
	}
	else
	{
		cout<<"\t"<<searchKey<<" not found!";
	}
	
	cout<<"\n\n\tEnter a key to be searched using Binary Search : ";
	cin>>searchKey;
	a1.binarySearch(searchKey);

	Array a2(4),a3;
	a2.fillArray();
	a2.printArray();
	cout<<"\n\n\tCombined Array";
	a3.combineArray(a1,a2);
	a3.printArray();
	
	Array a4;
	cout<<"\n\n\tMerged Array";
	a4.mergeArray(a1,a2);
	a4.printArray();

	return 0;
}
