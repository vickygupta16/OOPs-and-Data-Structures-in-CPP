#include<iostream>
#include<assert.h>
#include<iomanip>

using namespace std;

struct TreeNode
{
	TreeNode *left;
	int num;
	TreeNode *right;
};

typedef struct TreeNode TN;

class BST
{
	private:
		TN *root;
		int count;
		TN * insertNode(TN *,int);
		TN * deleteNode(TN *,int);
		TN * findSmallest(TN *);	//recursive
		void findSmallestElement(TN *);		//iterative
		TN * findLargest(TN *);		//recursive
		void findLargestElement(TN *);		//iterative
		TN * searchBST(TN *,int);
		void preOrder(TN *);	//Node,Left,Right	(NLR)
		void inOrder(TN *);		//Left,Node,Right	(LNR)
		void postOrder(TN *);	//Left,Right,Node	(LRN)
	public :
		BST();
		int getBSTCount();
		void insertNodeDummy(int);
		void deleteNodeDummy(int);
		void findSmallestDummy();
		void findLargestDummy();
		void searchBSTDummy(int);
		void preOrderDummy();
		void inOrderDummy();
		void postOrderDummy();
};

BST::BST()
{
	count=0;
	root=NULL;
}

void BST::insertNodeDummy(int data)
{
	root=insertNode(root,data);
}

TN * BST::insertNode(TN *root,int data)
{
	if(root==NULL)
	{
		TN *newNode=new TN();
		assert(newNode);
		newNode->num=data;
		newNode->left=newNode->right=NULL;
		++count;
		return newNode;
	}
	else
	{
		if(data<root->num)
		{
			root->left=insertNode(root->left,data);
		}
		else if(data>root->num)
		{
			root->right=insertNode(root->right,data);
		}
		else
		{
			cout<<"\n\tDuplicate values are not allowed!";
		}
		return root;
	}
}

void BST::findSmallestDummy()
{
	if(root)
	{
		findSmallestElement(root);
		TN *temp=findSmallest(root);
		if(!temp)
		{
			return;
		}
		else
		{
			cout<<"\n\n\tSmallest : "<<temp->num;
		}
	}
	else
	{
		cout<<"\n\n\tBST Empty!";
	}
}

TN * BST::findSmallest(TN *root)
{
	if(!root)
	{
		return NULL;
	}
	else
	{
		if(root->left==NULL)
		{
			return root;
		}
		else
		{
			return findSmallest(root->left);
		}
	}
}

void BST::findSmallestElement(TN *root)
{
	while(root->left)
	{
		root=root->left;
	}
	cout<<"\n\n\tSmallest Element : "<<root->num;
}

void BST::findLargestDummy()
{
	if(root)
	{
		findLargestElement(root);
		TN *temp=findLargest(root);
		if(!temp)
		{
			return;
		}
		else
		{
			cout<<"\n\n\tLargest : "<<temp->num;
		}
	}
	else
	{
		cout<<"\n\n\tBST Empty!";
	}
}

TN * BST::findLargest(TN *root)
{
	if(!root)
	{
		return NULL;
	}
	else
	{
		if(root->right==NULL)
		{
			return root;
		}
		else
		{
			findLargest(root->right);
		}
	}
}

void BST::findLargestElement(TN *root)
{
	while(root->right)
	{
		root=root->right;
	}
	cout<<"\n\n\tLargest Element : "<<root->num;
}

int BST::getBSTCount()
{
	return count;
}

void BST::searchBSTDummy(int key)
{
	if(!root)
	{
		cout<<"\n\n\tBST Empty!";
	}
	else
	{
		TN *temp=searchBST(root,key);
		if(!temp)	//temp==NULL
		{
			cout<<"\n\n\t"<<key<<" not found in BST";
		}
		else
		{
			cout<<"\n\n\t"<<temp->num<<" found in BST!";
		}
	}
}

TN * BST::searchBST(TN *root,int key)
{
	if(!root)
	{
		return NULL;
	}
	else
	{
		if(key<root->num)
		{
			searchBST(root->left,key);
		}
		else if(key>root->num)
		{
			searchBST(root->right,key);
		}
		else
		{
			return root;
		}
	}
}

void BST::preOrderDummy()
{
	if(!root)	//root==NULL
	{
		cout<<"\n\n\tBinary Search Tree is Empty!";
	}
	else
	{
		cout<<"\n\tPreOrder : ";
		preOrder(root);
	}
}

void BST::preOrder(TN *root)
{
	if(!root)	//root==NULL
	{
		return;
	}
	else
	{
		cout<<"\t"<<root->num;
		preOrder(root->left);
		preOrder(root->right);
	}
}

void BST::inOrderDummy()
{
	if(!root)	//root==NULL
	{
		cout<<"\n\n\tBinary Search Tree is Empty!";
	}
	else
	{
		cout<<"\n\tInOrder : ";
		inOrder(root);
	}
}

void BST::inOrder(TN *root)
{
	if(!root)	//root==NULL
	{
		return;
	}
	else
	{
		inOrder(root->left);
		cout<<"\t"<<root->num;
		inOrder(root->right);
	}
}

void BST::postOrderDummy()
{
	if(!root)	//root==NULL
	{
		cout<<"\n\n\tBinary Search Tree is Empty!";
	}
	else
	{
		cout<<"\n\tPostOrder : ";
		postOrder(root);
	}
}

void BST::postOrder(TN *root)
{
	if(!root)	//root==NULL
	{
		return;
	}
	else
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<"\t"<<root->num;
	}
}

void BST::deleteNodeDummy(int key)
{
	root=deleteNode(root,key);
}

TN * BST::deleteNode(TN *root,int key)
{
	TN *temp1,*temp2;
	if(!root)	//root==NULL
	{
		return NULL;
	}
	else
	{
		if(key<root->num)
		{
			root->left=deleteNode(root->left,key);
		}
		else if(key>root->num)
		{
			root->right=deleteNode(root->right,key);
		}
		else
		{
			if(root->left==root->right)	//root->left=root->right=NULL?
			{
				delete root;
				--count;
				return NULL;
			}
			else if(!root->left)	//root->left==NULL
			{
				temp1=root->right;
				delete root;
				--count;
				return temp1;
			}
			else if(!root->right)	//root->right==NULL
			{
				temp1=root->left;
				delete root;
				--count;
				return temp1;
			}
			else
			{
				temp1=temp2=root->right;
				while(temp1->left)
				{
					temp1=temp1->left;
				}
				temp1->left=root->left;
				delete root;
				--count;
				return temp2;
			}
		}
	}
	return root;
}

int main()
{
	cout<<"\n\n\t-------Binary Search Tree-------";
	BST b;
	b.insertNodeDummy(14);
	b.insertNodeDummy(23);
	b.insertNodeDummy(7);
	b.insertNodeDummy(10);
	b.insertNodeDummy(33);
	b.insertNodeDummy(56);
	b.insertNodeDummy(80);
	b.insertNodeDummy(66);
	b.insertNodeDummy(70);
	
	cout<<"\n\n\tCount : "<<b.getBSTCount();
	cout<<"\n\n";
	b.preOrderDummy();
	cout<<"\n\n";
	b.inOrderDummy();
	cout<<"\n\n";
	b.postOrderDummy();
	
	b.findSmallestDummy();
	b.findLargestDummy();
	
	b.searchBSTDummy(56);
	b.searchBSTDummy(30);
	
	b.deleteNodeDummy(23);
	cout<<"\n\n\tCount : "<<b.getBSTCount();
	cout<<"\n\n";
	b.preOrderDummy();
	cout<<"\n\n";
	b.inOrderDummy();
	cout<<"\n\n";
	b.postOrderDummy();
	
	return 0;
}
