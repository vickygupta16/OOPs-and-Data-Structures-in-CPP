#include<iostream>

using namespace std;

template<class T>
class Stack
{
	private:
		T *arr;
		int size,tos;			//tos : top of stack
	public:
		Stack();
		Stack(int);				//Parameterized Constructor
		void push(T);
		void pop();
		void printStack();
		void topOfStack();
		~Stack();				//Destructor
};

template<class T>
Stack<T>::Stack()
{
	size=5;
	arr=new T[size];
	tos=-1;
}

template<class T>
Stack<T>::Stack(int s)
{
	size=s;
	arr=new T[size];	//dynamic array
	tos=-1;
}

template<class T>
void Stack<T>::push(T data)
{
	if(tos>=size-1)
	{
		cout<<"\n\n\tStack Full!";
		return;
	}
	else
	{
		cout<<"\n\n\tPushed "<<data;
		++tos;
		arr[tos]=data;
	}
}

template<class T>
void Stack<T>::pop()
{
	if(tos<0)
	{
		cout<<"\n\n\tStack Empty!";
	}
	else
	{
		cout<<"\n\n\tPopped "<<arr[tos];
		--tos;
	}
}

template<class T>
void Stack<T>::printStack()
{
	if(tos>-1)
	{
		cout<<"\n\n\tStack : ";
		for(int i=tos;i>=0;--i)
		{
			cout<<"\n\t"<<arr[i];
		}
	}
	else
	{
		cout<<"\n\n\tStack Empty!";
	}
}

template<class T>
void Stack<T>::topOfStack()
{
	if(tos>-1)
	{
		cout<<"\n\n\tTop of Stack : "<<arr[tos];
	}
	else
	{
		cout<<"\n\n\tStack Empty!";
	}
}

template<class T>
Stack<T>::~Stack()
{
	cout<<"\n\n\tDestructor";
	delete arr;
}

int main()
{
	Stack<int> d1;
	Stack<double> d2;
	d1.push(10);
	d1.push(20);
	d1.push(30);
	d1.push(40);
	d1.push(50);
	d1.printStack();
	d2.push(20.4);
	d2.push(30.0);
	d2.push(30.2);
	d2.push(40.4);
	d2.push(50.6);
	d2.printStack();
	cout<<"\n\n\tInt";
	for(int i=0;i<5;i++)
	{
		d1.pop();
	}
	cout<<"\n\n\tDouble";
	for(int i=0;i<5;i++)
	{
		d2.pop();
	}
	return 0;
}
