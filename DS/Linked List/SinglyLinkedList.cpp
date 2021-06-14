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

class SinglyLinkedList
{
	private :
		int count;
		N *head,*end;
	public:
		SinglyLinkedList();
		void insertAtBeginning(int);
		void insertAtEnd(int);
		void deleteAtBeginning();
		void deleteAtEnd();
		void displayListWithAddress();
		void displayList();
		int getCount();
		void sortList(bool);
		void deleteMidNode(int);
		void destroyList();
		void appendList(SinglyLinkedList);
		void mergeList(SinglyLinkedList,SinglyLinkedList);
		void combineList(SinglyLinkedList,SinglyLinkedList);
};

SinglyLinkedList::SinglyLinkedList()
{
	head=end=NULL;
	count=0;
}

int SinglyLinkedList::getCount()
{
	return count;
}

void SinglyLinkedList::insertAtBeginning(int data)
{
	N *newNode=new N();
	assert(newNode);
	newNode->num=data;
	if(head==NULL)	//!head, check if linked list is empty, means head doesn't holds any address
	{
		newNode->next=NULL;
		head=end=newNode;
	}
	else	//linked list exists, insert node at beginning
	{
		newNode->next=head;
		head=newNode;
	}
	++count;
}

void SinglyLinkedList::insertAtEnd(int data)
{
	N *newNode=new N();
	assert(newNode);
	newNode->num=data;
	if(head==NULL)	//!head, check if linked list is empty, means head doesn't holds any address
	{
		head=end=newNode;
	}
	else	//linked list exists, insert node at end
	{
		end->next=newNode;
		newNode->next=NULL;
		end=newNode;
	}
	++count;
}

void SinglyLinkedList::deleteAtBeginning()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head==end)	//check if only 1 node exists in linked list
		{
			N *temp=head;
			head=end=NULL;
			delete temp;
		}
		else	//normal deletion of node from beginning of linked list
		{
			N *temp=head;
			head=temp->next;
			cout<<"\n\n\tDeleted "<<temp->num;
			delete temp;
		}
		--count;
	}
	else
	{
		cout<<"\n\tLinked List Empty!";
	}
}

void SinglyLinkedList::deleteAtEnd()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head==end)	//check if only 1 node exists in linked list
		{
			N *temp=head;
			head=end=NULL;
			delete temp;
		}
		else	//normal deletion of node from end of linked list
		{
			N *temp=head;
			while(temp->next!=end)
			{
				temp=temp->next;
			}
			end=temp;
			temp=temp->next;
			end->next=NULL;
			cout<<"\n\n\tDeleted "<<temp->num;
			delete temp;
		}
		--count;
	}
	else
	{
		cout<<"\n\tLinked List Empty!";
	}
}

void SinglyLinkedList::displayList()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		cout<<"\n\n\tList : ";
		N *node=head;
		while(node)
		{
			cout<<node->num<<"\t";
			node=node->next;
		}
	}
	else
	{
		cout<<"\n\tLinked List Empty!";
	}
}

void SinglyLinkedList::displayListWithAddress()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		N *node=head;
		cout<<"\n\n\tList with Address : \n\t";
		cout<<left<<setw(10)<<"node";
		cout<<left<<setw(10)<<"next";
		cout<<left<<setw(10)<<"data";
		cout<<endl<<"\n\t";
		while(node)
		{
			cout<<left<<setw(10)<<node;
			cout<<left<<setw(10)<<node->next;
			cout<<left<<setw(10)<<node->num;
			cout<<endl<<"\t";
			node=node->next;
		}
	}
	else
	{
		cout<<"\n\tLinked List Empty!";
	}
}

void SinglyLinkedList::sortList(bool descending=false)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		int temp;
		for(N *i=head;i;i=i->next)
		{
			for(N *j=i->next;j;j=j->next)
			{
				if(descending)
				{
					if(i->num<j->num)
					{
						temp=i->num;
						i->num=j->num;
						j->num=temp;
					}
				}
				else
				{
					if(i->num>j->num)
					{
						temp=i->num;
						i->num=j->num;
						j->num=temp;
					}
				}
			}
		}
	}
	else
	{
		cout<<"\n\tLinked List Empty!";
	}
}

void SinglyLinkedList::deleteMidNode(int key)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head->num==key)	//check if key is equal to number of 1st node
		{
			deleteAtBeginning();
		}
		else if(end->num==key)	//check if key is equal to number of last node
		{
			deleteAtEnd();
		}
		else	//normal deletion
		{
			N *node=head;
			while(node)
			{
				if(node->next->num==key)	//check if number of next node is equal to key
				{
					N *temp=node->next;
					node->next=node->next->next;
					cout<<"\n\n\tDeleted "<<temp->num;
					delete temp;
					--count;
					return;
				}
				node=node->next;
				if(node->next==NULL)	//check if compiler has reached last node
				{
					cout<<"\n\n\t"<<key<<" not found in List!";
					return;
				}
			}
		}
	}
	else
	{
		cout<<"\n\tLinked List Empty!";
	}
}

void SinglyLinkedList::destroyList()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		N *walker1,*walker2;
		walker1=head;
		while(walker1)
		{
			cout<<"\n\tDestroyed "<<walker1->num;
			walker2=walker1->next;
			delete walker1;
			walker1=walker2;
			--count;
		}
		head=end=NULL;
	}
	else
	{
		cout<<"\n\tLinked List Empty!";
	}
}

void SinglyLinkedList::appendList(SinglyLinkedList sll)
{
	//check if head of object of calling function and head of object passed in parameter
	//has linked list, means both head are not empty
	if(head && sll.head)
	{
		end->next=sll.head;
		count=count+sll.count;
		end=sll.end;
	}
	else
	{
		cout<<"\n\tAny of 2 Linked List is Empty!";
	}
}

void SinglyLinkedList::mergeList(SinglyLinkedList o1,SinglyLinkedList o2)
{
	//check if head of both objects passed in parameter
	//has linked list, means both head are not empty
	if(o1.head && o2.head)
	{
		o1.sortList();	//sorting both the list
		o2.sortList();	//because merging requires sorted data
		N *p1,*p2;
		p1=o1.head;
		p2=o2.head;
		while(p1 && p2)	//loop till pointer p1 & p2 has address of node
		{
			if(p1->num<p2->num)
			{
				insertAtEnd(p1->num);
				p1=p1->next;
			}
			else
			{
				insertAtEnd(p2->num);
				p2=p2->next;
			}
		}
		if(p1 && !p2)	//if pointer p1 has nodes left in linked list and pointer p2 is NULL
		{
			while(p1)	//loop till pointer p1 has address of node
			{
				insertAtEnd(p1->num);
				p1=p1->next;
			}
		}
		if(!p1 && p2)	//if pointer p2 has nodes left in linked list and pointer p1 is NULL
		{
			while(p2)	//loop till pointer p2 has address of node
			{
				insertAtEnd(p2->num);
				p2=p2->next;
			}
		}
	}
	else
	{
		cout<<"\n\tAny of 2 Linked List is Empty!";
	}
}

void SinglyLinkedList::combineList(SinglyLinkedList o1,SinglyLinkedList o2)
{
	//check if head of both objects passed in parameter
	//has linked list, means both head are not empty
	if(o1.head && o2.head)
	{
		N *p1,*p2;
		p1=o1.head;
		p2=o2.head;
		int size=0;
		while(p1 && p2)	//loop till pointer p1 & p2 has address of node from respective linked list
		{
			if(size%2==0)
			{
				insertAtEnd(p1->num);
				p1=p1->next;
			}
			else
			{
				insertAtEnd(p2->num);
				p2=p2->next;
			}
			++size;
		}
		if(p1 && !p2)	//if pointer p1 has nodes left in linked list and pointer p2 is NULL
		{
			while(p1)	//loop till pointer p1 has address of node
			{
				insertAtEnd(p1->num);
				p1=p1->next;
			}
		}
		if(!p1 && p2)	//if pointer p2 has nodes left in linked list and pointer p1 is NULL
		{
			while(p2)	//loop till pointer p2 has address of node
			{
				insertAtEnd(p2->num);
				p2=p2->next;
			}
		}
	}
	else
	{
		cout<<"\n\tAny of 2 Linked List is Empty!";
	}
}

int main()
{
	cout<<"\n\t-------Singly Linked List-------";
	
	SinglyLinkedList a;
	a.insertAtBeginning(20);
	a.insertAtBeginning(30);
	a.insertAtEnd(120);
	a.insertAtEnd(10);
	a.insertAtEnd(50);
	a.insertAtEnd(40);
	a.insertAtBeginning(110);
	
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayListWithAddress();
	
	a.deleteAtBeginning();
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayListWithAddress();
	
	a.deleteAtEnd();
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayListWithAddress();
	
	a.sortList();
	a.displayListWithAddress();
	
	a.sortList(true);
	a.displayListWithAddress();
	
	a.deleteMidNode(110);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayListWithAddress();
	
	a.deleteMidNode(180);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayListWithAddress();

	SinglyLinkedList b;
	b.insertAtBeginning(60);
	b.insertAtEnd(70);
	b.insertAtBeginning(80);
	b.insertAtEnd(90);
	b.insertAtBeginning(100);
	cout<<"\n\n\tCount : "<<b.getCount();
	b.displayListWithAddress();
	
	SinglyLinkedList d;
	d.combineList(a,b);
	cout<<"\n\n\tCount : "<<d.getCount()<<"\n\tCombined List";
	d.displayListWithAddress();
	
	SinglyLinkedList c;
	c.mergeList(a,b);
	cout<<"\n\n\tCount : "<<c.getCount()<<"\n\tMerged List";
	c.displayListWithAddress();
	
	a.appendList(b);
	cout<<"\n\n\tCount : "<<a.getCount()<<"\n\tAppended List";
	a.displayListWithAddress();
	
	a.destroyList();
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayListWithAddress();
	
	return 0;
}
