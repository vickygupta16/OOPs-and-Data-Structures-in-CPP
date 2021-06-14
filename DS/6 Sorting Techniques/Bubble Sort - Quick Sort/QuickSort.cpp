#include<iostream>

using namespace std;

class Sort
{
	private :
		int *arr;
		int last;
		void medianLeft(int,int);
	public :
		Sort(int);
		void fillArray();
		void printArray();
		void quickSort(int,int,int);
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

void Sort::quickSort(int l,int r,int i)
{
	int pivot,left,right,sortLeft,sortRight,temp;
	left=l;
	right=r;
	medianLeft(left,right);
	pivot=arr[left];
	sortLeft=left+1;
	sortRight=right;
	while(sortLeft<=sortRight)
	{
		while(arr[sortLeft]<pivot)
		{
			sortLeft++;
		}
		while(arr[sortRight]>=pivot)
		{
			sortRight--;
		}
		if(sortLeft<=sortRight)
		{
			temp=arr[sortLeft];
			arr[sortLeft]=arr[sortRight];
			arr[sortRight]=temp;
			sortLeft++;
			sortRight--;
		}
	}
	arr[left]=arr[sortLeft-1];
	arr[sortLeft-1]=pivot;
	i++;
	cout<<"\n\tAfter Pass "<<i<<" : ";
	printArray();
	if(left<sortRight)
	{
		quickSort(left,sortRight-1,i);
	}
	if(sortLeft<right)
	{
		quickSort(sortLeft,right,i);
	}
}

void Sort::medianLeft(int left,int right)
{
	int temp;
	int mid=(left+right)/2;
	if(arr[left]>arr[mid])
	{
		temp=arr[left];
		arr[left]=arr[mid];
		arr[mid]=temp;
	}
	if(arr[left]>arr[right])
	{
		temp=arr[left];
		arr[left]=arr[right];
		arr[right]=temp;
	}
	if(arr[mid]>arr[right])
	{
		temp=arr[mid];
		arr[mid]=arr[right];
		arr[right]=temp;
	}
	temp=arr[left];
	arr[left]=arr[mid];
	arr[mid]=temp;
}

int main()
{
	int n;
	//Quick Sort
	//size 10
	//85	36	87	10	91	18	15	52	73	34
	cout<<"\n\n\n\t-------------------------QUICK SORT-------------------------";
	cout<<"\n\tEnter Array size for Quick Sort : ";
	cin>>n;
	Sort Quick(n);
	Quick.fillArray();
	cout<<"\n\tArray : ";
	Quick.printArray();
	Quick.quickSort(0,n-1,0);
	cout<<"\n\n\tQuick Sort : ";
	Quick.printArray();
	cout<<"\n\t-------------------------QUICK SORT-------------------------";
	//Quick Sort

	return 0;
}
