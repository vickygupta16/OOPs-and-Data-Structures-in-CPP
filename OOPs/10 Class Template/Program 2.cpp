#include<iostream>

using namespace std;

template<class T>
class Array
{
	private:
		T *arr;
		int size;
	public:
		Array();
		void getArray();
		void printArray() const;
};

template<class T>
Array<T>::Array()
{
	size=5;
	arr=new T[size];
	for(int i=0;i<size;++i)
	{
		arr[i]=0;
	}
}

template<class T>
void Array<T>::getArray()
{
	cout<<"\n\n\tEnter elements in array : \n";
	for(int i=0;i<size;++i)
	{
		cout<<"\tElement "<<i<<" : ";
		cin>>arr[i];
	}
}

template<class T>
void Array<T>::printArray() const
{
	for(int i=0;i<size;++i)
	{
		cout<<"\t"<<arr[i];
	}
}

int main()
{
	Array<int> a1;
	a1.getArray();
	cout<<"\n\n\tInteger array : ";
	a1.printArray();
	
	Array<float> a2;
	a2.getArray();
	cout<<"\n\n\tFloat array : ";
	a2.printArray();
	return 0;
}
