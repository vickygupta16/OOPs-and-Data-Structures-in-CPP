#include<iostream>

using namespace std;

class Stack
{
	private:
		int *arr,size,tos;		//tos : top of stack
	public:
		Stack();				//Default Constructor
		Stack(int);				//Parameterized Constructor
		void push(int);
		void pop();
		void printStack();
		void topOfStack();
		~Stack();				//Destructor
		class Full{};			//exception class
		class Empty{};			//exception class
};

Stack::Stack()
{
	size=5;
	arr=new int[size];	//dynamic array
	tos=-1;
}

Stack::Stack(int s)
{
	size=s;
	arr=new int[size];
	tos=-1;
}

void Stack::push(int data)
{
	if(tos>=size-1)
	{
		throw Full();
	}
	else
	{
		cout<<"\n\n\tPushed "<<data;
		++tos;
		arr[tos]=data;
	}
}

void Stack::pop()
{
	if(tos<0)
	{
		throw Empty();
	}
	else
	{
		cout<<"\n\n\tPopped "<<arr[tos];
		--tos;
	}
}

void Stack::printStack()
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

void Stack::topOfStack()
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

Stack::~Stack()
{
	cout<<"\n\n\tDestructor";
	delete arr;
}

int main()
{
	Stack s;
	int ch,data;
	while(true)
	{
		try
		{
			cout<<"\n\n\t1. Push\n\t2. Pop";
			cout<<"\n\t3. Top of Stack\n\t4. Stack";
			cout<<"\n\t5. Exit";
			cout<<"\n\tEnter your choice : ";
			cin>>ch;
			switch(ch)
			{
				case 1:
					cout<<"\n\tEnter data : ";
					cin>>data;
					s.push(data);
					break;
				case 2:
					s.pop();
					break;
				case 3:
					s.topOfStack();
					break;
				case 4:
					s.printStack();
					break;
				case 5:
					exit(0);
				default:
					cout<<"\n\tInvalid choice!";
			}
		}
		catch(Stack::Full)
		{
			cout<<"\n\n\tStack Overflow!";
		}
		catch(Stack::Empty)
		{
			cout<<"\n\n\tStack Underflow!";
		}
	}
	return 0;
}
