#include<iostream>
#include<iomanip>

using namespace std;

class Queue
{
	private :
		int *cirQarr;
		int size,count,front,rear;
	public :
		Queue(int);
		void insertAtRear(int);
		void insertAtFront(int);
		int deleteAtFront();
		int deleteAtRear();
		int getQCount();
		void displayQ();
};

Queue::Queue(int s=5)
{
	size=s;
	front=rear=-1;
	count=0;
	cirQarr=new int[size];
}

int Queue::getQCount()
{
	return count;
}

void Queue::insertAtRear(int data)
{
	if((front==0 && rear==size-1) || (front==rear+1)) //rear==front-1
	{
		cout<<"\n\n\tQueue is Full!";
	}
	else
	{
		if(front==-1 && rear==-1)	//check if it's first element to be inserted
		{
			front=rear=0;
		}
		else if(rear==size-1)	//chech if rear is at last index, if yes then wrap at 0
		{
			rear=0;
		}
		else //normal insert at rear
		{
			++rear;
		}
		cirQarr[rear]=data;
		++count;
	}
}

void Queue::insertAtFront(int data)
{
	if((front==0 && rear==size-1) || (front==rear+1)) //rear==front-1
	{
		cout<<"\n\n\tQueue is Full!";
	}
	else
	{
		if(front==-1 && rear==-1)	//check if it's 1st element to be inserted
		{
			front=rear=0;
		}
		else if(front==0)	//check if front is at beginning of array, if yes then wrap to last index
		{
			front=size-1;
		}
		else	//normal insertion at front
		{
			--front;
		}
		cirQarr[front]=data;
		++count;
	}
}

int Queue::deleteAtFront()
{
	if(front==-1 && rear==-1)	//check if array is empty
	{
		cout<<"\n\n\tQueue is Empty!";
		return -1;
	}
	else
	{
		int temp=cirQarr[front];
		if(front==rear)	//check if there is only 1 element in array
		{
			front=rear=-1;
		}
		else if(front==size-1)	//check if front is at last index, if yes then wrap it to 0th index
		{
			front=0;
		}
		else	//normal removal from front
		{
			++front;
		}
		--count;
		return temp;
	}
}

int Queue::deleteAtRear()
{
	if(front==-1 && rear==-1)	//check if array is empty
	{
		cout<<"\n\n\tQueue is Empty!";
		return -1;
	}
	else
	{
		int temp=cirQarr[rear];
		if(front==rear)	//check if there is only 1 element in array
		{
			front=rear=-1;
		}
		else if(rear==0)	//check if rear is at 0th index, if yes then wrap to last index
		{
			rear=size-1;
		}
		else	//normal removal from rear of array
		{
			--rear;
		}
		--count;
		return temp;
	}
}

void Queue::displayQ()
{
	if(front==-1 && rear==-1)	//check if array is empty
	{
		cout<<"\n\n\tQueue is Empty!";
	}
	else
	{
		int i;
		cout<<"\n\n\t"<<left<<setw(10)<<"Queue : ";
		if(front>=0 && rear>=front)		//normal queue
		{
			for(i=front;i<=rear;++i)
			{
				cout<<cirQarr[i]<<"\t";
			}
			cout<<"\n\t"<<left<<setw(10)<<"Index : ";
			for(i=front;i<=rear;++i)
			{
				cout<<i<<"\t";
			}
		}
		else if(front>rear)		//circular queue
		{
			for(i=front;i<size;++i)
			{
				cout<<cirQarr[i]<<"\t";
			}
			for(i=0;i<=rear;++i)
			{
				cout<<cirQarr[i]<<"\t";
			}
			cout<<"\n\t"<<left<<setw(10)<<"Index : ";
			for(i=front;i<size;++i)
			{
				cout<<i<<"\t";
			}
			for(i=0;i<=rear;++i)
			{
				cout<<i<<"\t";
			}
		}
	}
}

int main()
{
	cout<<"\n\n\t-------Double Ended Queue as Array-------";
	
	int ch,data;
	Queue q;
	while(true)
	{
		cout<<"\n\n\t1. Insert at Rear\t2. Insert at Front";
		cout<<"\n\t3. Delete at Front\t4. Delete at Rear";
		cout<<"\n\t5. Count\t6. Queue\t7. Exit";
		cout<<"\n\n\tEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n\tEnter data : ";
				cin>>data;
				q.insertAtRear(data);
				break;
			case 2:
				cout<<"\n\tEnter data : ";
				cin>>data;
				q.insertAtFront(data);
				break;
			case 3:
				data=q.deleteAtFront();
				if(data!=-1)
				{
					cout<<"\n\tDequeued "<<data;
				}
				break;
			case 4:
				data=q.deleteAtRear();
				if(data!=-1)
				{
					cout<<"\n\tDequeued "<<data;
				}
				break;
			case 5:
				cout<<"\n\n\tCount : "<<q.getQCount();
				break;
			case 6:
				q.displayQ();
				break;
			case 7:
				exit(0);
			default:
				cout<<"\n\tInvalid choice!";
		}
	}
	return 0;
}
