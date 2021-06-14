#include<iostream>
#include<iomanip>

using namespace std;

class Stack
{
	private:
		int *arr;
		int size,top;
	public :
		Stack(int);
		void push(int);
		void pop();
		void stackTop();
		void printStack();
};

Stack::Stack(int s=5)
{
	top=-1;
	size=s;
	arr=new int[size];
	for(int i=0;i<size;++i)
	{
		arr[i]=0;
	}
}

void Stack::push(int data)
{
	if(top==size-1)	//check if top has reached the size of array
	{
		cout<<"\n\n\tStack Full!";
		return;
	}
	else	//enter data at top of stack
	{
		cout<<"\n\n\tPushed "<<data;
		arr[++top]=data;
	}
}

void Stack::pop()
{
	if(top==-1)		//check if array is empty
	{
		cout<<"\n\n\tStack Empty!";
		return;
	}
	else
	{
		cout<<"\n\n\tPopped "<<arr[top];
		--top;
	}
}

void Stack::stackTop()
{
	if(top==-1)		//check if array is empty
	{
		cout<<"\n\n\tStack Empty!";
		return;
	}
	else
	{
		cout<<"\n\tElement at Top : "<<arr[top];
	}
}

void Stack::printStack()
{
	if(top==-1)		//check if array is empty
	{
		cout<<"\n\n\tStack Empty!";
		return;
	}
	else
	{
		cout<<"\n\n\t"<<left<<setw(10)<<"Stack"<<left<<setw(10)<<"Index";
		for(int i=top;i>=0;--i)
		{
			cout<<"\n\t"<<left<<setw(10)<<arr[i]<<left<<setw(10)<<i;
		}
	}
}

int main()
{
	cout<<"\n\n\t-------Stack-------";
	Stack s;
	int ch,data;
	while(true)
	{
		cout<<"\n\n\t1. Push\n\t2. Pop";
		cout<<"\n\t3. Top element\n\t4. Print Stack";
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
				s.stackTop();
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
	return 0;
}
