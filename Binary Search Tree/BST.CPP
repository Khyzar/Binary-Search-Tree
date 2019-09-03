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
void bst<t>::rec_insert(node<t>* &temp,const t &_data)
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
			cout<<curr->data<<" ";
			curr=curr->rchild;
		}
		else
			break;
	}
	cout<<endl;
}
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
		while(curr->lchild!=NULL)
		{
			prev=curr;
			curr=curr->lchild;
		}
		temp->data=curr->data;
		if(curr->rchild==NULL)
			delete curr;
		else
		{
			if(prev->rchild==curr)
				prev->rchild=curr->rchild;
			else
				prev->lchild=curr->rchild;
		}
		return true;
	}
}
template<typename t>
bool bst<t>::rec_delete_(const t& _data)
{
	node<t>* prev=NULL;
	return rec_delete_(prev,root,_data);
}
template<typename t>
bool bst<t>::rec_delete_(node<t>*&prev,node<t>*&temp,const t& _data)
{
	if(_data>temp->data)
		return rec_delete_(temp,temp->rchild,_data);
	else if(_data<temp->data)
		return rec_delete_(temp,temp->lchild,_data);
	else
		return rec_delete_(prev,temp);
}
template<typename t>
bool bst<t>::rec_delete_(node<t>*&prev,node<t>*&curr)
{
	node<t>*temp=NULL;
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
		curr=NULL;
		return true;
	}
	
	if(curr->lchild!=NULL && curr->rchild!=NULL)
	{
		temp=curr;
		prev=curr;
		curr=curr->rchild;
		while(curr->lchild!=NULL)
		{
			prev=curr;
			curr=curr->lchild;
		}
		temp->data=curr->data;
		if(curr->rchild==NULL)
			delete curr;
		else
		{
			if(prev->rchild==curr)
				prev->rchild=curr->rchild;
			else
				prev->lchild=curr->rchild;
		}
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
	iterator(node<t>* ptr, int a)
	{
		curr=ptr; node<t>*prev=NULL;
		while(curr!=NULL)
		{	prev=curr;
		curr=curr->rchild;
		}
		curr=prev;
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
		++(*this);
		return *this;
		
	}
	bool operator!=(iterator &a)  
	{
		if(this->curr->data==a.curr->data)
			{print_max();
		return false;}
		return true;
	}
	bool operator<=(iterator &a)
	{
		if(this->curr->data==a.curr->data)
			{
				cout<<curr->data;
				return false;}
		else
			return true;
	}
	void print_max()
	{
		cout<<curr->data;
	}
	t& operator*()
	{
		return curr->data;
	}
};

