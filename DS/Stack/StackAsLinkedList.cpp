#include<iostream>
#include<assert.h>
#include<iomanip>

using namespace std;

struct Number
{
	struct Number *next;
	int num;
};

typedef struct Number N;

class Stack
{
	private:
		int count;
		N *tos;
		void deallocateStack();
	public :
		Stack();
		int getCount();
		void push(int);
		void pop();
		void displayStack(bool);
		void stackTop();
		void freeList();
};

Stack::Stack()
{
	tos=NULL;
	count=0;
}

int Stack::getCount()
{
	return count;
}

void Stack::freeList()
{
	deallocateStack();
}

void Stack::deallocateStack()
{
	if(tos)	//tos!=NULL, check if tos holds some address, i.e. linked list exists
	{
		N *walker1,*walker2;
		walker1=tos;
		while(walker1)
		{
			walker2=walker1->next;
			cout<<"\n\tDeallocating "<<walker1->num<<" from Stack";
			--count;
			delete walker1;
			walker1=walker2;
		}
		tos=NULL;
	}
	else
	{
		cout<<"\n\n\tStack Empty!";
	}
}

void Stack::push(int data)
{
	N *newNode=new N();
	assert(newNode);
	newNode->num=data;
	if(!tos)	//tos==NULL, check if linked list is empty
	{
		newNode->next=NULL;
	}
	else
	{
		newNode->next=tos;
	}
	tos=newNode;
	++count;
}

void Stack::pop()
{
	if(!tos)	//tos==NULL, check if linked list is empty
	{
		cout<<"\n\n\tStack Empty!";
		return;
	}
	else 
	{
		N *temp=tos;
		if(tos->next==NULL)	//!tos->next, check if there exist only 1 element in linked list
		{
			tos=NULL;
		}
		else
		{
			tos=tos->next;
		}
		cout<<"\n\n\tPopped "<<temp->num;
		--count;
		delete temp;
	}
}

void Stack::stackTop()
{
	if(tos)	//tos!=NULL, check if tos holds some address, i.e. linked list exists
	{
		cout<<"\n\n\tTop of Stack : "<<tos->num;
		return;
	}
	else
	{
		cout<<"\n\n\tStack Empty!";
	}
}

void Stack::displayStack(bool address=false)
{
	if(tos)	//tos!=NULL, check if tos holds some address, i.e. linked list exists
	{
		N *node=tos;
		if(address)
		{
			cout<<"\n\n\t"<<left<<setw(10)<<"Stack"<<left<<setw(10)<<"Address";
			while(node)
			{
				cout<<"\n\t";
				cout<<left<<setw(10)<<node->num<<left<<setw(10)<<node;
				node=node->next;
			}
		}
		else
		{
			cout<<"\n\n\tStack : \n\t\t";
			while(node)
			{
				cout<<node->num<<"\n\t\t";
				node=node->next;
			}
		}
	}
	else
	{
		cout<<"\n\n\tStack Empty!";
	}
}

int main()
{
	int ch,data;
	Stack s;
	while(true)
	{
		cout<<"\n\n\t1. Push\n\t2. Pop";
		cout<<"\n\t3. Stack\n\t4. Stack with Address";
		cout<<"\n\t5. Count\n\t6. Top of Stack";
		cout<<"\n\t7. Deallocate Stack\n\t8. Exit";
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
				s.displayStack();
				break;
			case 4:
				s.displayStack(true);
				break;
			case 5:
				cout<<"\n\tCount : "<<s.getCount();
				break;
			case 6:
				s.stackTop();
				break;
			case 7:
				s.freeList();
				break;
			case 8:
				exit(0);
			default:
				cout<<"\n\n\tInvalid choice!";
		}
	}
	return 0;
}
