#include"bst.h"
#include"generic_stack.h"
using namespace std;

template <typename t>
bst<t>::bst()
{
	root=NULL;
}
template <typename t>
bst<t>::bst(bst &obj)
{
	root=copytree(obj.root);
}

template<typename t>
node<t> *bst<t>::copytree(node<t> *n)
{
		if(n==NULL)
			return NULL;
		node<t> *left=copytree(n->lchild);
		node<t> *right=copytree(n->rchild);
		node<t> *newNode=new node<t>;
		newNode->data=n->data;
		newNode->lchild=left;
		newNode->rchild=right;
		return newNode;
}
template <typename t>
node<t>* bst<t>::find(const t &key)
{
		node<t> *curr=root, *prev=NULL;
		while(curr!=NULL)
		{
			if(key<curr->data)
			{
				prev=curr;
				curr=curr->lchild;
			}
			else
			{
				prev=curr;
				curr=curr->rchild;
			}
		}
		return prev;
	}
template <typename t>
void bst<t>::insert(const t &_data)
{
	node<t> *temp=NULL;
	temp=find(_data);
	if(temp==NULL)
		root=new node<t>(_data,NULL,NULL);
	else
	{
		if(_data<temp->data)
			temp->lchild=new node<t>(_data,NULL,NULL);
		else
			temp->rchild=new node<t>(_data,NULL,NULL);
	}
}
template<typename t>
void bst<t>::rec_insert(const t &_data)
{
	if(root==NULL)
		root=new node<t>(_data,NULL,NULL);
	else
		rec_insert(root,_data);
}
template<typename t>
void bst<t>::rec_insert(node<t>* temp,const t &_data)
{
	if(temp==NULL)
	{
		temp=new node<t>(_data,NULL,NULL);
		return;
	}
	else
	{
	    if(_data>temp->data)
			rec_insert(temp->rchild,_data);
		if(_data<temp->data)
			rec_insert(temp->lchild,_data);
	}
}
template<typename t>
void bst<t>::in_order_traversal()
{
	stack<node<t>*> sbst;
	node<t> *curr=root, *temp=NULL;
	while(1)
	{
		while(curr)
		{
			sbst.push(curr);
			curr=curr->lchild;
		}
		if(!sbst.isEmpty())
		{
			curr=sbst.pop();
			cout<<curr->data;
			curr=curr->rchild;
		}
		else
			break;
	}
	cout<<endl;
}
//template<typename t>
//stack<node<t>*> bst<t>::descending_order()
//{
//	stack<node<t>*> sbst, s2;
//	node<t> *curr=root, *temp=NULL;
//	while(1)
//	{
//		while(curr)
//		{
//			sbst.push(curr);
//			curr=curr->rchild;
//		}
//		if(!sbst.isEmpty())
//		{
//			curr=sbst.pop();
//			//cout<<curr->data;
//			s2.push(curr);
//			curr=curr->lchild;
//		}
//		else
//			break;
//	}
//	return s2;
//}
//template<typename t>
//node<t>* bst<t>::max()
//{
//	node<t>*curr=root, prev=NULL;
//	while(curr!=NULL)
//	{	prev=curr;
//	curr=curr->rchild;
//	}
//	return prev;
//}
template<typename t>
int bst<t>::size()
{
	int size1=0;
	stack<node<t>*> sbst;
	node<t> *curr=root, *temp=NULL;
	while(1)
	{
		while(curr)
		{
			sbst.push(curr);
			curr=curr->lchild;
		}
		if(!sbst.isEmpty())
		{
			curr=sbst.pop();
		    size1++;
			curr=curr->rchild;
		}
		else
			break;
	}
	return size1;
}
template<typename t>
bool bst<t>::delete_(const t &_data)
{
	node<t> *curr=root, *prev=NULL, *temp=NULL;
	if(curr==NULL)
			return false;
	while(curr->data!=_data)
	{
		if(curr==NULL)
			return false;
		else if(_data<curr->data)
		{
			prev=curr;
			curr=curr->lchild;
		}
		else
		{
			prev=curr;
			curr=curr->rchild;
		}
		if(curr==NULL)
			return false;
	}
	if(curr->lchild==NULL && curr->rchild==NULL)
	{
		prev->lchild=NULL;
		prev->rchild=NULL;
		delete curr;
		return true;
	}
	if(curr->lchild==NULL && curr->rchild!=NULL && prev->rchild==curr)
	{
		prev->rchild=curr->rchild;
		delete curr;
		return true;
	}
	if(curr->lchild==NULL && curr->rchild!=NULL && prev->lchild==curr)
	{
		prev->lchild=curr->rchild;
		delete curr;
		return true;
	}
	if(curr->lchild!=NULL && curr->rchild==NULL && prev->lchild==curr)
	{
		prev->lchild=curr->lchild;
		delete curr;
		return true;
	}
	if(curr->lchild!=NULL && curr->rchild==NULL && prev->rchild==curr)
	{
		prev->rchild=curr->lchild;
		delete curr;
		return true;
	}
	
	if(curr->lchild!=NULL && curr->rchild!=NULL)
	{
		temp=curr;
		prev=curr;
		curr=curr->rchild;
		while(curr!=NULL)
		{
			prev=curr;
			curr=curr->lchild;
		}
		temp->data=prev->data;
		prev=NULL;
		delete prev;
		return true;
	}
}


template<typename t>
class bst<t>::iterator
{
private:
	node<t> *curr;
	friend bst<t>;
	bst<t> s5;
	stack<node<t>*> s4;
	int counter;

public:
	iterator()
	{
		curr=NULL;
	}
	node<t>*max()
	{
		node<t>*curr=root, prev=NULL;
		while(curr!=NULL)
		{	prev=curr;
		curr=curr->rchild;
		}
		return prev;
	}

	iterator(node<t> *ptr)
	{
		curr=ptr;
	stack<node<t>*> sbst;
    node<t> *temp=NULL;
	while(1)
	{
		while(curr)
		{
			sbst.push(curr);
			curr=curr->rchild;
		}
		if(!sbst.isEmpty())
		{
			curr=sbst.pop();
			//cout<<curr->data;
			s4.push(curr);
			curr=curr->lchild;
		}
		else{
			curr=s4.pop();
				break;}
	}
	}
	iterator &operator++()
	{

		curr=s4.pop();
		return *this;
	}
	iterator& operator++(int _a)  //post Increment
	{
		node<t>* temp=*this;

		++(*this);
		return temp;
	}
	bool operator!=(iterator &a)  
	{
		if(this->curr==a.curr)
			return false;
		return true;
	}
	t& operator*()
	{
		return curr->data;
	}
};

