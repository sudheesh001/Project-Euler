/***********************************************************************
* Name       : Sudheesh Singanamalla
* Roll       : 127257, Section B
* Subject    : Data Structures and Algorithms
* Submission : 23/September/2013
* Time taken : 
*              End Time   : 10:38 PM
*              Start Time : 09:49 PM
*              Resultant  : --------------------> 49 minutes. 
*                           {Including Comments for easy understanding.}
************************************************************************/
#include <iostream>
using namespace std;
#define MAX 5
class btree
{
	class node
	{
	public:
		int element[5];
		int count;
		node *ptr[6];
		node *parent;
		node():count(0),parent(NULL)
		{
			for(int i=0;i<5;i++)
				element[i]=0;
			for(int i=0;i<6;i++)
				ptr[i]=NULL;
		}
	};
	//Node class ends here.
	node *root;
public:
	btree():root(NULL){} // Constructor.
	int isnodefull(node *t); // Checks if a B5 node is full.
	int isleafnode(node *t); // Checks if B5 node is a leaf node.
	int findpath(int x,node *t); // Finds a path.
	void sortelements(node *t); // Sorts elements in a node.
	void insert(int x); // Main function call procedure, overloaded to call with root.
	void insert(int x,node *t); // Insert function.
	void nodesplit(node *t); // Function containing code for splitting node - Middle value Left , Right
	int keyredistribute(node *t); // Function to show how keys are redistributed.
	void display(); // Main function dispay call.
	void display(node *t); // Overloaded display call from main function taking root parameter.
	// Maybe I need to put a destructor, but well, Compiler, you take care of that !
}; //btree class complete. Milestone 1 !!
// ----------------------- Functions. -----------------------------------
int btree::isnodefull(node *t)
{
	if(t->count>=4)
		return 1;
	else
		return 0;
}
int btree::isleafnode(node *t)
{
	if(t->ptr[0])
		return 0;
	else
		return 1;
}
int btree::findpath(int x,node *t)
{
	if(x<=t->element[0])
		return 0;
	if(x>=t->element[t->count-1])
		return t->count;
	for(int i=0;i<t->count;i++)
		if(x>=t->element[i] && x<=t->element[i+1])
			return i+1;
}
void btree::sortelements(node *t)
{
	int i,j;
	int p;
	node *q;
	for(i=1;i<t->count;i++)
	{
		p=t->element[i];
		q=t->ptr[i+1];
		for(j=i-1;j>=0 && t->element[j]>p;j--)
		{
			t->element[j+1]=t->element[j];
			t->ptr[j+2]=t->ptr[j+1];
		}
		t->element[j+1]=p;
		t->ptr[j+2]=q;
	}
	/*
	cout<<"Seeing sorted elements \n";
	for(i=1;i<t->count;i++)
		cout<<t->element[i]<<" ";
	cout<<"\n\n";
	Note to self : Never run this comment again.
	*/
}
void btree::insert(int x)
{
	insert(x,root);
}
void btree::insert(int x,node *t)
{
	int flag=0;
	if(t)
	{
		int pos=findpath(x,t);
		insert(x,t->ptr[pos]);
		if(isleafnode(t))
		{
			t->element[t->count++]=x;
			sortelements(t);
		}
		if(t->count>4)
		{
			flag=keyredistribute(t);
			if(!flag)
				nodesplit(t);
		}
	}
	else
	if(!t && t==root)
	{
		t=new node;
		t->element[t->count++]=x;
		root=t;
	}
}
// Milestone 2 : Insertion complete.
void btree::nodesplit(node *t)
{
	int pos;
	int i;
	node *p;
	node *q;
	p=t->parent;
	if(!p)
	{
		p=new node;
		p->element[p->count++]=t->element[2];
		p->ptr[0]=t;
		t->parent=p;
		root=p;
	}
	else
	{
		p->element[p->count++]=t->element[2];
		sortelements(p);
		pos=findpath(t->element[2],p);
		p->ptr[pos]=t;
	}
	q=new node;
	pos=findpath(t->element[3],p);
	p->ptr[pos]=q;
	q->parent=p;
	for(i=0;i<2;i++)
	{
		q->element[i]=t->element[i+3];
		q->ptr[i]=t->ptr[i+3];
	}
	q->ptr[i]=t->ptr[i+3];
	t->count=2;
	q->count=2;
	for(i=0;i<=q->count;i++)
		if(q->ptr[i])
			q->ptr[i]->parent=q;
}
int btree::keyredistribute(node *t)
{
	int pos;
	node *p=t->parent;
	node *q;
	if(p && isleafnode(t))
	{
		pos=findpath(t->element[0],p);
		if(pos>0 && !isnodefull(p->ptr[pos-1]))
		{
			q=p->ptr[pos-1];
			q->element[q->count++]=p->element[pos-1];
			p->element[pos-1]=t->element[0];
			for(int i=0;i<t->count;i++)
				t->element[i]=t->element[i+1];
			t->count--;
			return 1;
		}
		if(pos<p->count && !isnodefull(p->ptr[pos+1]))
		{
			q=p->ptr[pos+1];
			for(int i=q->count-1;i>=0;i--)
				q->element[i+1]=q->element[i];
			q->element[0]=p->element[pos];
			p->element[pos]=t->element[--t->count];
			q->count++;
			return 1;
		}
		return 0;
	}
	return 0;
}
// Milestone 3 : Splitting and redistributing. Closer to target.
void btree::display()
{
	display(root);
}
void btree::display(node *t)
{
	if(t)
		for(int i=0;i<=t->count;i++)
		{
			display(t->ptr[i]);
			if(i<t->count)
				cout<<t->element[i]<<"  ";
		}
}
int main()
{
	btree t;
	int a[36]={79,71,48,31,14,13,76,17,67,24,34,74,41,43,3,22,82,73,84,8,75,90,87,100,1,56,12,19,105,120,99,89,23,85,42,81};
	//2   4    7    9    13     15     17      20      25       30       33
	int flag;
	//int size; cout<<"Enter size ? "; cin>>size;
	//int *a = new int[size];
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		//cout<<"Enter number  "<<i+1<<" : ? ";cin>>a[i];
		t.insert(a[i]); //Instead of entering just assigned them all here
		t.display();
		cout<<"\n\n";
		cin.get(); // Press any key to see how output tree modifies.
	}
	// All values displayed.
	cout<<"Final Display \n";
	t.display();
	cin.get();
	return 0;
}
// Complete.
