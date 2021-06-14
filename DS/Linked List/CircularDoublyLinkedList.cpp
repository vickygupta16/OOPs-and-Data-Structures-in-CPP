#include<iostream>
#include<assert.h>
#include<iomanip>

using namespace std;

struct Number
{
	struct Number *prev;
	int num;
	struct Number *next;
};

typedef struct Number N;

class CircularDoublyLinkedList
{
	private :
		int count;
		N *head,*end;
	public :
		CircularDoublyLinkedList();
		int getCount();
		void insertAtBeginning(int);
		void insertAtEnd(int);
		void deleteAtBeginning();
		void deleteAtEnd();
		void displayList(bool);
		void displayReverseList(bool);
		void sortList(bool);
		void destroyList();
		void insertBefore(int,int);
		void insertAfter(int,int);
		void deleteBefore(int);
		void deleteAfter(int);
		void deleteMidNode(int);
		void combineList(CircularDoublyLinkedList,CircularDoublyLinkedList);
		void mergeList(CircularDoublyLinkedList,CircularDoublyLinkedList);
		void appendList(CircularDoublyLinkedList);
};

CircularDoublyLinkedList::CircularDoublyLinkedList()
{
	count=0;
	head=end=NULL;
}

int CircularDoublyLinkedList::getCount()
{
	return count;
}

void CircularDoublyLinkedList::insertAtBeginning(int data)
{
	N *newNode=new N();
	assert(newNode);
	newNode->num=data;
	if(!head)	//head==NULL, check if linked list is empty, means head doesn't holds any address
	{
		head=end=newNode;
		newNode->next=newNode->prev=newNode;
	}
	else	//linked list exists, insert node at beginning
	{
		newNode->next=head;
		newNode->prev=end;
		head->prev=newNode;
		end->next=newNode;
		head=newNode;
	}
	++count;
}

void CircularDoublyLinkedList::insertAtEnd(int data)
{
	N *newNode=new N();
	assert(newNode);
	newNode->num=data;
	if(!head)	//head==NULL, check if linked list is empty, means head doesn't holds any address
	{
		head=end=newNode;
		newNode->prev=newNode->next=newNode;
	}
	else	//linked list exists, insert node at end
	{
		newNode->next=head;
		newNode->prev=end;
		head->prev=end->next=end=newNode;
	}
	++count;
}

void CircularDoublyLinkedList::deleteAtBeginning()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head==end)	//check if only 1 node exists in linked list
		{
			N *temp=head;
			head=end=NULL;
			cout<<"\n\n\tDeleted "<<temp->num<<" from beginning";
			count=0;
			delete temp;
		}
		else	//normal deletion of node from beginning of linked list
		{
			N *temp=head;
			end->next=head->next;
			head->next->prev=end;
			head=head->next;
			cout<<"\n\n\tDeleted "<<temp->num<<" from beginning";
			--count;
			delete temp;
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularDoublyLinkedList::deleteAtEnd()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head==end)	//check if only 1 node exists in linked list
		{
			N *temp=head;
			head=end=NULL;
			count=0;
			cout<<"\n\n\tDeleted "<<temp->num<<" from end!";
			delete temp;
		}
		else	//normal deletion of node from beginning of linked list
		{
			N *temp=end;
			head->prev=end->prev;
			end->prev->next=head;
			end=end->prev;
			cout<<"\n\n\tDeleted "<<temp->num<<" from end!";
			--count;
			delete temp;
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularDoublyLinkedList::insertBefore(int key,int data)
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
			do
			{
				if(temp->num==key)
				{
					cout<<"\n\n\tInserted "<<data<<" before "<<temp->num;
					N *newNode=new N();
					assert(newNode);
					newNode->num=data;
					newNode->prev=temp->prev;
					newNode->next=temp;
					temp->prev->next=temp->prev=newNode;
					++count;
					return;
				}
				temp=temp->next;
				if(temp==head)
				{
					cout<<"\n\n\t"<<key<<" not found in list!";
				}
			}while(temp!=head);
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularDoublyLinkedList::insertAfter(int key,int data)
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
			do
			{
				if(temp->num==key)
				{
					cout<<"\n\n\tInserted "<<data<<" after "<<temp->num;
					N *newNode=new N();
					assert(newNode);
					newNode->num=data;
					newNode->prev=temp;
					newNode->next=temp->next;
					temp->next->prev=temp->next=newNode;
					++count;
					return;
				}
				temp=temp->next;
				if(temp==head)
				{
					cout<<"\n\n\t"<<key<<" not found in list!";
					return;
				}
			}while(temp!=head);
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularDoublyLinkedList::deleteBefore(int key)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head->num==key)	//check if key is equal to number of 1st node
		{
			cout<<"\n\n\t"<<key<<" is at 1st position!";
		}
		else if(head->next->num==key)	//check if key is equal to number of 2nd node
		{
			deleteAtBeginning();
		}
		else
		{
			N *temp=head;
			do
			{
				if(temp->num==key)
				{
					N *node=temp->prev;
					temp->prev->prev->next=temp;
					temp->prev=temp->prev->prev;
					cout<<"\n\n\tDeleted "<<node->num<<" which was before "<<key;
					--count;
					delete node;
					return;
				}
				temp=temp->next;
				if(temp==head)
				{
					cout<<"\n\n\t"<<key<<" not found in list!";
				}
			}while(temp!=head);
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularDoublyLinkedList::deleteAfter(int key)
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
			do
			{
				if(temp->num==key)
				{
					N *node=temp->next;
					temp->next->next->prev=temp;
					temp->next=temp->next->next;
					cout<<"\n\n\tDeleted "<<node->num<<" which was after "<<key;
					--count;
					delete node;
					return;
				}
				temp=temp->next;
				if(temp==head)
				{
					cout<<"\n\n\t"<<key<<" not found in list!";
				}
			}while(temp!=head);
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularDoublyLinkedList::deleteMidNode(int key)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		if(head==end)	//check if only 1 node exists in linked list
		{
			N *temp=head;
			head=end=NULL;
			--count;
			cout<<"\n\n\tDeleted "<<temp->num;
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
		else
		{
			N *temp=head;
			do
			{
				if(temp->num==key)
				{
					cout<<"\n\n\tDeleted "<<temp->num;
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
					--count;
					delete temp;
					return;
				}
				temp=temp->next;
				if(temp==head)
				{
					cout<<"\n\n\t"<<key<<" not found in list!";
					return;
				}
			}while(temp!=head);
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularDoublyLinkedList::combineList(CircularDoublyLinkedList o1,CircularDoublyLinkedList o2)
{
	//check if head of both objects passed in parameter
	//has linked list, means both head are not empty
	if(o1.head && o2.head)
	{
		N *p1=o1.head;
		N *p2=o2.head;
		int size=0;
		do
		{
			if(size%2==0)
			{
				insertAtEnd(p1->num);
				p1=p1->next;
				if(p1==o1.head)	//check if pointer p1 has reached 1st node of its respective linked list
				{
					p1=NULL;
					break;
				}
			}
			else
			{
				insertAtEnd(p2->num);
				p2=p2->next;
				if(p2==o2.head)	//check if pointer p2 has reached 1st node of its respective linked list
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
		cout<<"\n\n\tAny of 2 list is empty!";
	}
}

void CircularDoublyLinkedList::mergeList(CircularDoublyLinkedList o1,CircularDoublyLinkedList o2)
{
	//check if head of both objects passed in parameter
	//has linked list, means both head are not empty
	if(o1.head && o2.head)
	{
		o1.sortList(false);	//sorting both the list
		o1.displayList(true);
		o2.sortList(false);	//because merging requires sorted data
		o2.displayList(true);
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
		cout<<"\n\n\tAny of 2 list is empty!";
	}
}

void CircularDoublyLinkedList::appendList(CircularDoublyLinkedList cdll)
{
	//check if head of object of calling function and head of object passed in parameter
	//has linked list, means both head are not empty
	if(head && cdll.head)
	{
		head->prev=cdll.end;
		cdll.end->next=head;
		end->next=cdll.head;
		cdll.head->prev=end;
		end=cdll.end;
		count=count+cdll.count;		
	}
	else
	{
		cout<<"\n\n\tAny of 2 list is empty!";
	}
}

void CircularDoublyLinkedList::sortList(bool descending=false)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		N *i=head;
		N *j=i->next;
		int temp;
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

void CircularDoublyLinkedList::displayList(bool address=false)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		N *node=head;
		if(address)
		{
			cout<<"\n\n\tList with Address : \n\t";
			cout<<left<<setw(10)<<"prev";
			cout<<left<<setw(10)<<"node";
			cout<<left<<setw(10)<<"next";
			cout<<left<<setw(10)<<"data";
			cout<<endl<<"\t";
			do
			{
				cout<<left<<setw(10)<<node->prev;
				cout<<left<<setw(10)<<node;
				cout<<left<<setw(10)<<node->next;
				cout<<left<<setw(10)<<node->num;
				cout<<"\n\t";
				node=node->next;
			}while(node!=head);
		}
		else
		{
			cout<<"\n\n\tList : ";
			do
			{
				cout<<node->num<<"\t";
				node=node->next;
			}while(node!=head);
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularDoublyLinkedList::displayReverseList(bool address=false)
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		N *node=end;
		if(address)
		{
			cout<<"\n\n\tReverse List with Address : \n\t";
			cout<<left<<setw(10)<<"prev";
			cout<<left<<setw(10)<<"node";
			cout<<left<<setw(10)<<"next";
			cout<<left<<setw(10)<<"data";
			cout<<endl<<"\t";
			do
			{
				cout<<left<<setw(10)<<node->prev;
				cout<<left<<setw(10)<<node;
				cout<<left<<setw(10)<<node->next;
				cout<<left<<setw(10)<<node->num;
				cout<<"\n\t";
				node=node->prev;
			}while(node!=end);
		}
		else
		{
			cout<<"\n\n\tReverse List : ";
			do
			{
				cout<<node->num<<"\t";
				node=node->prev;
			}while(node!=end);
		}
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

void CircularDoublyLinkedList::destroyList()
{
	if(head)	//head!=NULL, check if head holds some address, means linked list exists
	{
		cout<<endl;
		N *walker1,*walker2;
		walker1=head;
		do
		{
			walker2=walker1->next;
			--count;
			cout<<"\n\tDestroyed "<<walker1->num;
			delete walker1;
			walker1=walker2;
		}while(walker1!=head);	//check if compiler has reached to 1st node
		head=end=NULL;
	}
	else
	{
		cout<<"\n\n\tList is Empty!";
	}
}

int main()
{
	cout<<"\n\n\t-------Circular Doubly Linked List-------";
	
	CircularDoublyLinkedList a;
	a.insertAtBeginning(90);
	a.insertAtEnd(40);
	a.insertAtBeginning(60);
	a.insertAtBeginning(20);
	a.insertAtEnd(50);
	//a.displayReverseList(true);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	
	CircularDoublyLinkedList b;
	b.insertAtEnd(70);
	b.insertAtBeginning(30);
	b.insertAtEnd(100);
	b.insertAfter(70,10);
	b.insertBefore(10,80);
	cout<<"\n\n\tCount : "<<b.getCount();
	b.displayList(true);
	
	CircularDoublyLinkedList c;
	c.combineList(a,b);
	cout<<"\n\n\tCount : "<<c.getCount();
	c.displayList(true);

	CircularDoublyLinkedList d;
	d.mergeList(a,b);
	cout<<"\n\n\tCount : "<<d.getCount();
	d.displayList(true);

	CircularDoublyLinkedList e;
	e.insertAtEnd(20);
	e.insertAtBeginning(190);
	e.insertAfter(20,800);
	e.insertBefore(800,450);
	e.appendList(a);
	cout<<"\n\n\tCount : "<<e.getCount();
	e.displayList(true);
	e.displayReverseList(true);
	
	a.deleteAtBeginning();
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	a.displayReverseList(true);
	
	a.deleteAtEnd();
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	a.displayReverseList(true);
	
	a.sortList(true);
	a.displayList(true);
	a.displayReverseList(true);
	
	a.insertBefore(10,60);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	a.displayReverseList(true);
	
	a.insertAfter(10,80);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	a.displayReverseList(true);
	
	a.deleteBefore(30);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	a.displayReverseList(true);
	
	a.deleteAfter(20);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	a.displayReverseList(true);
	
	a.deleteMidNode(10);
	cout<<"\n\n\tCount : "<<a.getCount();
	a.displayList(true);
	a.displayReverseList(true);
	
	a.destroyList();
	a.displayList(true);
	a.displayReverseList(true);
	
	return 0;
}
