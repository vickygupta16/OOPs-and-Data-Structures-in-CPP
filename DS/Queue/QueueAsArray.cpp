#include<iostream>
#include<iomanip>

using namespace std;

class Queue
{
	private :
		int *cirQarr;
		int count,front,rear,size;
	public :
		Queue(int);
		void enQueue(int);
		int deQueue();
		int getQCount();
		void displayQ();
};

Queue::Queue(int s=5)
{
	count=0;
	front=rear=-1;
	size=s;
	cirQarr=new int[size];
}

int Queue::getQCount()
{
	return count;
}

void Queue::enQueue(int data)
{
	if((front==0 && rear==size-1) || (front==rear+1)) //or rear==front-1
	{
		cout<<"\n\n\tQueue is full!";
	}
	else 
	{
		if(front==-1 && rear==-1)	//check if array is empty
		{
			front=rear=0;
			cirQarr[rear]=data;
		}
		else if(rear==size-1)	//check if rear is at last index of array
		{
			rear=0;
			cirQarr[rear]=data;
		}
		else	//normal insertion at rear
		{
			cirQarr[++rear]=data;
		}
		++count;
	}
}

int Queue::deQueue()
{
	if(front==-1 && rear==-1)	//check if array is empty
	{
		cout<<"\n\n\tQueue is Empty!";
		return -1;
	}
	else
	{
		int temp=0;
		if(front==rear)	//check if there is only 1 element in array
		{
			temp=cirQarr[front];
			front=rear=-1;
		}
		else if(front==size-1)	//check if front is at last index, if yes then wrap it to 0th index
		{
			temp=cirQarr[front];
			front=0;
		}
		else	//normal removal from front
		{
			temp=cirQarr[front];
			++front;
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
		cout<<"\n\n\t"<<left<<setw(10)<<"Queue : ";
		int i;
		if(front>=0 && rear>=front)		//normal queue
		{
			for(i=front;i<=rear;++i)
			{
				cout<<cirQarr[i]<<"\t";
			}
			cout<<endl<<"\t"<<left<<setw(10)<<"Index : ";
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
			cout<<endl<<"\t"<<left<<setw(10)<<"Index : ";
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
	cout<<"\n\n\t-------Circular Queue as Array-------";
	
	int data,ch;
	Queue q;
	while(true)
	{
		cout<<"\n\n\t1. Enqueue";
		cout<<"\n\t2. Dequeue";
		cout<<"\n\t3. Count";
		cout<<"\n\t4. Queue";
		cout<<"\n\t5. Quit";
		cout<<"\n\n\tEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n\tEnter data : ";
				cin>>data;
				q.enQueue(data);
				break;
			case 2:
				data=q.deQueue();
				if(data!=-1)
				{
					cout<<"\n\tDequeued "<<data;
				}
				break;
			case 3:
				cout<<"\n\n\tCount : "<<q.getQCount();
				break;
			case 4:
				q.displayQ();
				break;
			case 5:
				exit(0);
			default:
				cout<<"\n\tInvalid choice!";
		}
	}
	
	return 0;
}
