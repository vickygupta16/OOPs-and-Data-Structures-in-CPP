#include<iostream>
#include<assert.h>
#include<iomanip>

using namespace std;

struct Number
{
	Number *prev;
	int num;
	Number *next;
};

typedef struct Number N;

class DoublyLinkedList
{
	private :
		int count;
		N *head,*end;
	public :
		DoublyLinkedList();
		void insertAtBeginning(int);
		void insertAtEnd(int);
		void deleteAtBeginning();
		void deleteAtEnd();
		void displayList(bool);
		void displayReverseList(bool);
		int getCount();
		void sortList(bool);
		void insertBefore(int,int);
		void insertAfter(int,int);
		void deleteBefore(int);
		void deleteAfter(int);
		void deleteMidNode(int);
		void destroyList();
		void combineList(DoublyLinkedList,DoublyLinkedList);
		void mergeList(DoublyLinkedList,DoublyLinkedList);
		void appendList(DoublyLinkedList);
};

DoublyLinkedList::DoublyLinkedList()
{
	head=end=NULL;
	count=0;
}

int DoublyLinkedList::getCount()
{
	return count;
}

void DoublyLinkedList::insertAtBeginning(int data)
{
	N *newNode=new N();
	assert(newNode);
	newNode->num=data;
	if(head==NULL)	//!head, check if linked list is empty, means head doesn't holds any address
	{
		head=end=newNode;
		newNode->prev=newNode->next=NULL;
	}
	else	//linked list exists, insert data at beginning
	{
		newNode->prev=NULL;
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
	}
	++count;
}

void DoublyLinkedList::insertAtEnd(int data)
{
	N *newNode=new N();
	assert(newNode);
	newNode->num=data;
	if(head==NULL)	//!head, check if linked list is empty, means head doesn't holds any address
	{
		head=end=newNode;
		newNode->prev=newNode->next=NULL;
	}
	else	//linked list exists, insert data at end
	{
		newNode->next=NULL;
		newNode->prev=end;
		end->next=newNode;
		end=newNode;
	}
	++count;
}

void DoublyLinkedList::deleteAtBeginning()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head==end)	//check if only 1 node exists in linked list
		{
			N *temp=head;
			head=end=NULL;
			cout<<"\n\tDeleted "<<temp->num<<" from beginning of list.";
			delete temp;
		}
		else	//normal deletion of node from beginning of linked list
		{
			N *temp=head;
			head=temp->next;
			temp->next->prev=NULL;
			cout<<"\n\tDeleted "<<temp->num<<" from beginning of list.";
		}
		--count;
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void DoublyLinkedList::deleteAtEnd()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head==end)	//check if only 1 node exists in linked list
		{
			N *temp=head;
			head=end=NULL;
			cout<<"\n\tDeleted "<<temp->num<<" from end of list.";
			delete temp;
		}
		else	//normal deletion of node from end of linked list
		{
			N *temp=end;
			end=temp->prev;
			temp->prev->next=NULL;
			cout<<"\n\tDeleted "<<temp->num<<" from end of list.";
			delete temp;
		}
		--count;
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void DoublyLinkedList::sortList(bool descending=false)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		int temp;
		N *i,*j;
		for(i=head;i;i=i->next)
		{
			for(j=i->next;j;j=j->next)
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
		cout<<"\n\n\tList is Empty!";
	}
}

void DoublyLinkedList::insertBefore(int key,int data)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head->num==key)	//check if key is equal to number of 1st node
		{
			insertAtBeginning(data);
		}
		else
		{
			N *temp=head;
			while(temp)	//loop till temp holds address of node
			{
				if(temp->num==key)	//check if number of current node is equal to key
				{
					N *newNode=new N();
					assert(newNode);
					newNode->num=data;
					newNode->next=temp;
					newNode->prev=temp->prev;
					temp->prev->next=temp->prev=newNode;
					++count;
					return;
				}
				temp=temp->next;
				if(!temp)	//temp==NULL, check if compiler has reached last node
				{
					cout<<"\n\n\t"<<key<<" not found in List!";
					delete temp;
					return;
				}
			}
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void DoublyLinkedList::insertAfter(int key,int data)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(end->num==key)	//check if key is equal to number of last node
		{
			insertAtEnd(data);
		}
		else
		{
			N *temp=head;
			while(temp)	//loop till temp holds address of node
			{
				if(temp->num==key)	//check if number of current node is equal to key
				{
					N *newNode=new N();
					assert(newNode);
					newNode->num=data;
					newNode->prev=temp;
					newNode->next=temp->next;
					temp->next=temp->next->prev=newNode;
					++count;
					return;
				}
				temp=temp->next;
				if(!temp)
				{
					cout<<"\n\n\t"<<key<<" not found in List!";
					delete temp;
					return;
				}
			}
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void DoublyLinkedList::deleteBefore(int key)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head->num==key)	//check if key is equal to number of 1st node
		{
			cout<<"\n\n\t"<<key<<" at 1st position!";
		}
		else if(head->next->num==key)	//check if key is equal to number of 2nd node
		{
			deleteAtBeginning();
		}
		else
		{
			N *temp=head;
			while(temp)	//loop till temp holds address of node
			{
				if(temp->num==key)	//check if number of current node is equal to key
				{
					temp=temp->prev;
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
					cout<<"\n\n\tDeleted "<<temp->num<<" which was before "<<key;
					delete temp;
					--count;
					return;
				}
				temp=temp->next;
				if(!temp)
				{
					cout<<"\n\n\t"<<key<<" not found in List!";
					delete temp;
					return;
				}
			}
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}	
}

void DoublyLinkedList::deleteAfter(int key)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(end->num==key)	//check if key is equal to number of last node
		{
			cout<<"\n\n\t"<<key<<" at last position!";
		}
		else if(end->prev->num==key)	//check if key is equal to number of 2nd last node
		{
			deleteAtEnd();
		}
		else
		{
			N *temp=head;
			while(temp)	//loop till temp holds address of node
			{
				if(temp->num==key)	//check if number of current node is equal to key
				{
					temp=temp->next;
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
					cout<<"\n\n\tDeleted "<<temp->num<<" which was after "<<key;
					delete temp;
					--count;
					return;
				}
				temp=temp->next;
				if(!temp)
				{
					cout<<"\n\n\t"<<key<<" not found in List!";
					delete temp;
					return;
				}
			}
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}	
}

void DoublyLinkedList::deleteMidNode(int key)
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
		else
		{
			N *temp=head;
			while(temp)
			{
				if(temp->num==key)
				{
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
					cout<<"\n\n\tDeleting Mid Node "<<temp->num;
					delete temp;
					--count;
					return;
				}
				temp=temp->next;
				if(!temp)
				{
					cout<<"\n\n\t"<<key<<" not found in List!";
					delete temp;
					return;
				}
			}
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void DoublyLinkedList::destroyList()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		N *walker1,*walker2;
		walker1=head;
		while(walker1)	//loop till walker1 has address of node from linked list
		{
			walker2=walker1->next;
			cout<<"\n\tDestroyed "<<walker1->num;
			delete walker1;
			--count;
			walker1=walker2;
		}
		head=end=NULL;
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void DoublyLinkedList::combineList(DoublyLinkedList o1,DoublyLinkedList o2)
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
		cout<<"\n\n\tAny of 2 List is Empty!";
	}
}

void DoublyLinkedList::mergeList(DoublyLinkedList o1,DoublyLinkedList o2)
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
		cout<<"\n\n\tAny of 2 List is Empty!";
	}
}

void DoublyLinkedList::appendList(DoublyLinkedList dll)
{
	//check if head of object of calling function and head of object passed in parameter
	//has linked list, means both head are not empty
	if(head && dll.head)
	{
		end->next=dll.head;
		dll.head->prev=end;
		end=dll.end;
		count=count+dll.count;
	}
	else
	{
		cout<<"\n\n\tAny of 2 List is Empty!";
	}
}

void DoublyLinkedList::displayList(bool address=false)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		N *node=head;
		if(address)
		{
			cout<<"\n\n\tList : \n\t";
			cout<<left<<setw(10)<<"prev";
			cout<<left<<setw(10)<<"node";
			cout<<left<<setw(10)<<"next";
			cout<<left<<setw(10)<<"data";
			cout<<endl<<"\n\t";
			while(node)
			{
				cout<<left<<setw(10)<<node->prev;
				cout<<left<<setw(10)<<node;
				cout<<left<<setw(10)<<node->next;
				cout<<left<<setw(10)<<node->num;
				cout<<"\n\t";
				node=node->next;
			}
		}
		else
		{
			cout<<"\n\n\tList : ";
			while(node)
			{
				cout<<node->num<<"\t";
				node=node->next;
			}
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void DoublyLinkedList::displayReverseList(bool address=false)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		N *node=end;
		if(address)
		{
			cout<<"\n\n\tReverse List : \n\t";
			cout<<left<<setw(10)<<"prev";
			cout<<left<<setw(10)<<"node";
			cout<<left<<setw(10)<<"next";
			cout<<left<<setw(10)<<"data";
			cout<<endl<<"\n\t";
			while(node)
			{
				cout<<left<<setw(10)<<node->prev;
				cout<<left<<setw(10)<<node;
				cout<<left<<setw(10)<<node->next;
				cout<<left<<setw(10)<<node->num;
				cout<<"\n\t";
				node=node->prev;
			}
		}
		else
		{
			cout<<"\n\n\tReverse List : ";
			while(node)
			{
				cout<<node->num<<"\t";
				node=node->prev;
			}
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

int main()
{
	cout<<"\n\t-------Doubly Linked List-------";
	
	DoublyLinkedList a;
	a.insertAtEnd(40);
	a.insertAtBeginning(10);
	a.insertAtBeginning(20);
	a.insertAtEnd(50);
	a.insertAtBeginning(30);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	//a.displayReverseList(true);
	
	a.deleteAtBeginning();
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
		
	a.deleteAtEnd();
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);

	cout<<"\n\n\tAscending Order";
	a.sortList();
	a.displayList(true);

	a.insertBefore(10,60);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	
	a.insertAfter(10,70);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	
	a.deleteBefore(10);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	
	a.deleteAfter(30);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	
	DoublyLinkedList b;
	b.insertAtBeginning(80);
	b.insertAtEnd(60);
	b.insertAfter(80,70);
	cout<<"\n\n\tCount : "<<b.getCount();
	b.displayList(true);
	
	DoublyLinkedList c;
	c.combineList(a,b);
	cout<<"\n\n\tCount : "<<c.getCount();
	c.displayList(true);

	DoublyLinkedList d;
	d.mergeList(a,b);
	cout<<"\n\n\tCount : "<<d.getCount();
	d.displayList(true);
		
	DoublyLinkedList e;
	e.insertAtEnd(120);
	e.insertAfter(120,130);
	e.insertBefore(130,140);
	cout<<"\n\n\tCount : "<<e.getCount();
	e.displayList(true);
	a.appendList(e);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	a.displayReverseList(true);

	a.deleteMidNode(101);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	a.displayReverseList(true);
	
	a.destroyList();
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	
	return 0;
}
