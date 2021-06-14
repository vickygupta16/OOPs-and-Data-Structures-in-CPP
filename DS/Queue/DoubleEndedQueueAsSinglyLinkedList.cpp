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

class QueueSLL
{
	private :
		int count;
		N *front,*rear;
	public :
		QueueSLL();
		int getCount();
		void insertAtRear(int);
		void deleteAtFront();
		void insertAtFront(int);
		void deleteAtRear();
		void displayQueue(bool);
};

QueueSLL::QueueSLL()
{
	count=0;
	front=rear=NULL;
}

int QueueSLL::getCount()
{
	return count;
}

void QueueSLL::insertAtRear(int data)
{
	N *newNode=new N();
	assert(newNode);
	newNode->num=data;
	newNode->next=NULL;
	if(!front)	//front==NULL, check if linked list is empty
	{
		front=rear=newNode;
	}
	else	//normal insertion at rear
	{
		rear->next=newNode;
		rear=newNode;
	}
	++count;
}

void QueueSLL::deleteAtFront()
{
	if(front)	//front!=NULL, check if Queue is not empty
	{
		N *temp=front;
		if(front==rear)	//check if only 1 element is present in Queue
		{
			front=rear=NULL;
		}
		else	//normal deletion from front of Queue
		{
			front=front->next;
		}
		cout<<"\n\n\tDeleted "<<temp->num<<" from front of Queue";
		--count;
		delete temp;
	}
	else
	{
		cout<<"\n\n\tQueue is Empty!";
	}
}

void QueueSLL::insertAtFront(int data)
{
	N *newNode=new N();
	assert(newNode);
	newNode->num=data;
	if(!front)	//front==NULL, check if linked list is empty
	{
		front=rear=newNode;
		newNode->next=NULL;
	}
	else	//normal insertion at front
	{
		newNode->next=front;
		front=newNode;
	}
	++count;
}

void QueueSLL::deleteAtRear()
{
	if(front)	//front!=NULL, check if Queue is not empty
	{
		N *temp=front;
		if(front==rear)		//check if only 1 element exists
		{
			front=rear=NULL;
		}
		else
		{
			while(temp->next!=rear)
			{
				temp=temp->next;
			}
			rear=temp;
			temp=temp->next;
			rear->next=NULL;
		}
		cout<<"\n\n\tDeleted "<<temp->num<<" from Rear of Queue";
		--count;
		delete temp;
	}
	else
	{
		cout<<"\n\n\tQueue is Empty!";
	}
}

void QueueSLL::displayQueue(bool address=false)
{
	if(front)	//front!=NULL, check if linked list is not empty
	{
		N *node=front;
		if(address)
		{
			cout<<"\n\n\tQueue with Address : \n\t"<<left<<setw(10)<<"node";
			cout<<left<<setw(10)<<"next";
			cout<<left<<setw(10)<<"data";
			while(node)
			{
				cout<<"\n\t";
				cout<<left<<setw(10)<<node;
				cout<<left<<setw(10)<<node->next;
				cout<<left<<setw(10)<<node->num;
				node=node->next;
			}
		}
		else
		{
			cout<<"\n\n\tQueue : ";
			while(node)
			{
				cout<<node->num<<"\t";
				node=node->next;
			}
		}
	}
	else
	{
		cout<<"\n\n\tQueue is Empty!";
	}
}

int main()
{
	cout<<"\n\n\t-------Queue as Singly Linked List-------";
	QueueSLL q;	
	int data,ch;
	while(true)
	{
		cout<<"\n\n\t1. Insert at Rear\t2. Delete at Front";
		cout<<"\n\t3. Insert at Front\t4. Delete at Rear";
		cout<<"\n\t5. Queue\t6. Queue with Address";
		cout<<"\n\t7. Count\t8. Exit";
		cout<<"\n\tEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n\tEnter data : ";
				cin>>data;
				q.insertAtRear(data);
				break;
			case 2:
				q.deleteAtFront();
				break;
			case 3:
				cout<<"\n\tEnter data : ";
				cin>>data;
				q.insertAtFront(data);
				break;
			case 4:
				q.deleteAtRear();
				break;
			case 5:
				q.displayQueue();
				break;
			case 6:
				q.displayQueue(true);
				break;
			case 7:
				cout<<"\n\n\tCount : "<<q.getCount();
				break;
			case 8:
				exit(0);
			default:
				cout<<"\n\tInvalid choice!";
		}
	}
	return 0;
}
