#include<iostream>
#include<assert.h>
#include<iomanip>

using namespace std;

struct Number
{
	int num;
	struct Number *next;
};

typedef struct Number N;

class CircularSinglyLinkedList
{
	private :
		int count;
		N *head,*end;
	public :
		CircularSinglyLinkedList();
		int getCount();
		void insertAtBeginning(int);
		void insertAtEnd(int);
		void deleteAtBeginning();
		void deleteAtEnd();
		void displayList();
		void displayListWithAddress();
		void sortList(bool);
		void deleteNode(int);
		void destroyList();
		void combineList(CircularSinglyLinkedList,CircularSinglyLinkedList);
		void mergeList(CircularSinglyLinkedList,CircularSinglyLinkedList);
		void appendList(CircularSinglyLinkedList);
};

CircularSinglyLinkedList::CircularSinglyLinkedList()
{
	count=0;
	head=end=NULL;
}

int CircularSinglyLinkedList::getCount()
{
	return count;
}

void CircularSinglyLinkedList::insertAtBeginning(int data)
{
	N *newNode=new N();
	assert(newNode);
	newNode->num=data;
	if(!head)	//head==NULL, check if linked list is empty, means head doesn't holds any address
	{
		head=end=newNode;
		newNode->next=end->next=head;
	}
	else	//linked list exists, insert node at beginning
	{
		newNode->next=head;
		end->next=head=newNode;
	}
	++count;
}

void CircularSinglyLinkedList::insertAtEnd(int data)
{
	N *newNode=new N();
	assert(newNode);
	newNode->num=data;
	if(!head)	//head==NULL, check if linked list is empty, means head doesn't holds any address
	{
		head=end=newNode;
		newNode->next=end->next=head;
	}
	else	//linked list exists, insert node at end
	{	
		newNode->next=head;
		end->next=newNode;
		end=newNode;
	}
	++count;
}

void CircularSinglyLinkedList::deleteAtBeginning()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head==end)	//check if only 1 node exists in linked list
		{
			N *temp=head;
			head=end=NULL;
			cout<<"\n\n\tDeleted "<<temp->num<<" from beginning!";
			count=0;
			delete temp;
		}
		else	//normal deletion of node from beginning of linked list
		{
			N *temp=head;
			end->next=head->next;
			head=head->next;
			cout<<"\n\n\tDeleted "<<temp->num<<" from beginning!";
			delete temp;
			--count;
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularSinglyLinkedList::deleteAtEnd()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head==end)	//check if only 1 node exists in linked list
		{
			N *temp=head;
			head=end=NULL;
			cout<<"\n\n\tDeleted "<<temp->num<<" from end!";
			count=0;
			delete temp;
		}
		else	//normal deletion of node from beginning of linked list
		{
			N *temp=head;
			while(temp->next!=end)
			{
				temp=temp->next;
			}
			end=temp;
			temp=temp->next;
			end->next=head;
			cout<<"\n\n\tDeleted "<<temp->num<<" from end!";
			delete temp;
			--count;
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularSinglyLinkedList::deleteNode(int key)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head==end)	//check if only 1 node exists in linked list
		{
			N *temp=head;
			head=end=NULL;
			cout<<"\n\n\tDeleted "<<temp->num;
			count=0;
			delete temp;
		}
		else if(head->num==key)	//check if key is equal to number of 1st node
		{
			deleteAtBeginning();
		}
		else if(end->num==key)	//check if key is equal to number of last node
		{
			deleteAtEnd();
		}
		else	//normal deletion
		{
			N *temp=head;
			while(temp->next->num!=key)	//check if key is equal to number of next node
			{
				temp=temp->next;
				if(temp->next==head)	//check if compiler has reached to 1st node
				{
					cout<<"\n\n\t"<<key<<" not found in list!";
					return;
				}
			}
			N *node=temp->next;
			temp->next=temp->next->next;
			--count;
			cout<<"\n\n\tDeleted "<<node->num<<" from list!";
			delete node;
			return;
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularSinglyLinkedList::sortList(bool descending=false)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		int temp=0;
		N *i,*j;
		i=head;
		j=i->next;
		do
		{
			do
			{
				if(descending)
				{
					if(i->num>j->num)
					{
						temp=i->num;
						i->num=j->num;
						j->num=temp;
					}
				}
				else
				{
					if(i->num<j->num)
					{
						temp=i->num;
						i->num=j->num;
						j->num=temp;
					}
				}
				j=j->next;
			}while(j!=head);
			i=i->next;
		}while(i!=head);
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularSinglyLinkedList::displayList()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		N *node=head;
		cout<<"\n\n\tList : ";
		do
		{
			cout<<node->num<<"\t";
			node=node->next;
		}while(node!=head);
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularSinglyLinkedList::displayListWithAddress()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		cout<<"\n\n\tList with Address : \n\t";
		N *node=head;
		cout<<left<<setw(10)<<"node";
		cout<<left<<setw(10)<<"next";
		cout<<left<<setw(10)<<"data";
		do
		{
			cout<<"\n\t";
			cout<<left<<setw(10)<<node;
			cout<<left<<setw(10)<<node->next;
			cout<<left<<setw(10)<<node->num;
			node=node->next;
		}while(node!=head);
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularSinglyLinkedList::destroyList()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		N *walker1,*walker2;
		walker1=head;
		do
		{
			walker2=walker1->next;
			cout<<"\n\tDestroyed "<<walker1->num;
			delete walker1;
			--count;
			walker1=walker2;
		}while(walker1!=head);	//check if compiler has reached to 1st node
		head=end=NULL;
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularSinglyLinkedList::combineList(CircularSinglyLinkedList o1,CircularSinglyLinkedList o2)
{
	//check if head of both objects passed in parameter
	//has linked list, means both head are not empty
	if(o1.head && o2.head)
	{
		N *p1,*p2;
		p1=o1.head;
		p2=o2.head;
		int size=0;
		do
		{
			if(size%2==0)
			{
				insertAtEnd(p1->num);
				p1=p1->next;
				if(p1==o1.head)
				{	
					p1=NULL;
					break;
				}
			}
			else
			{
				insertAtEnd(p2->num);
				p2=p2->next;
				if(p2==o2.head)
				{
					p2=NULL;
					break;
				}
			}
			++size;
		}while(p1 && p2);	//loop till pointer p1 & p2 has address of node from respective linked list
		if(p1 && !p2)	//if pointer p1 has nodes left in linked list and pointer p2 is NULL
		{
			do
			{
				insertAtEnd(p1->num);
				p1=p1->next;
			}while(p1!=o1.head);	//loop till pointer p1 doesn't reach 1st node
		}
		if(!p1 && p2)	//if pointer p2 has nodes left in linked list and pointer p1 is NULL
		{
			do
			{
				insertAtEnd(p2->num);
				p2=p2->next;
			}while(p2!=o2.head);	//loop till pointer p2 doesn't reach 1st node
		}
	}
	else
	{
		cout<<"\n\n\tAny of 2 List is Empty!";
	}
}

void CircularSinglyLinkedList::mergeList(CircularSinglyLinkedList o1,CircularSinglyLinkedList o2)
{
	//check if head of both objects passed in parameter
	//has linked list, means both head are not empty
	if(o1.head && o2.head)
	{
		o1.sortList();	//sorting both the list
		o2.sortList();	//because merging requires sorted data
		N *p1=o1.head;
		N *p2=o2.head;
		do
		{
			if(p1->num<p2->num)
			{
				insertAtEnd(p1->num);
				p1=p1->next;
				if(p1==o1.head)
				{
					p1=NULL;
					break;
				}
			}
			else
			{
				insertAtEnd(p2->num);
				p2=p2->next;
				if(p2==o2.head)
				{
					p2=NULL;
					break;
				}
			}
		}while(p1 && p2);	//loop till pointer p1 & p2 has address of node of respective linked list
		if(p1 && !p2)	//if pointer p1 has nodes left in linked list and pointer p2 is NULL
		{
			do
			{
				insertAtEnd(p1->num);
				p1=p1->next;
			}while(p1!=o1.head);	//loop till pointer p1 doesn't reach 1st node
		}
		if(!p1 && p2)	//if pointer p2 has nodes left in linked list and pointer p1 is NULL
		{
			do
			{
				insertAtEnd(p2->num);
				p2=p2->next;
			}while(p2!=o2.head);	//loop till pointer p2 doesn't reach 1st node
		}
	}
	else
	{
		cout<<"\n\n\tAny of 2 List is Empty!";
	}
}

void CircularSinglyLinkedList::appendList(CircularSinglyLinkedList csll)
{
	//check if head of object of calling function and head of object passed in parameter
	//has linked list, means both head are not empty
	if(head && csll.head)
	{
		end->next=csll.head;
		csll.end->next=head;
		end=csll.end;
		count=count+csll.count;
	}
	else
	{
		cout<<"\n\n\tAny of 2 List is Empty!";
	}
}

int main()
{
	cout<<"\n\n\t-------Circular Linked List-------\n";
	
	CircularSinglyLinkedList a;
	a.insertAtEnd(50);
	a.insertAtBeginning(10);
	a.insertAtEnd(30);
	a.insertAtBeginning(20);
	a.insertAtBeginning(40);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayListWithAddress();
	//a.displayList();
	
	CircularSinglyLinkedList b;
	b.insertAtBeginning(80);
	b.insertAtBeginning(70);
	b.insertAtEnd(90);
	b.insertAtEnd(60);
	b.insertAtBeginning(100);
	cout<<"\n\n\tCount : "<<b.getCount();
	b.displayListWithAddress();
	
	CircularSinglyLinkedList c;
	c.combineList(a,b);
	cout<<"\n\n\tCount : "<<c.getCount();
	c.displayListWithAddress();
	
	CircularSinglyLinkedList d;
	d.mergeList(a,b);
	cout<<"\n\n\tCount : "<<d.getCount();
	d.displayListWithAddress();
	
	CircularSinglyLinkedList e;
	e.insertAtEnd(120);
	e.appendList(a);
	cout<<"\n\n\tCount : "<<e.getCount();
	e.displayListWithAddress();

	a.deleteAtEnd();
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayListWithAddress();
	
	a.deleteAtBeginning();
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayListWithAddress();
	
	a.deleteNode(10);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayListWithAddress();
	
	a.destroyList();
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayListWithAddress();
	
	return 0;
}
