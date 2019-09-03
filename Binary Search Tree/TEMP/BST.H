#ifndef BST_H
#define BST_H
#include"generic_stack.h"
#include<iostream>
using namespace std;
template <typename t>
struct node
{
	t data;
	node<t> *lchild;
	node<t> *rchild;
	node(){data=0; lchild=NULL; rchild=NULL}
	node(node<t>& n)
	{
		data=n.data;
		lchild=n.lchild;
		rchild=n.rchild;

	}
	node operator =(const node<t> & n)
	{
		data=n.data;
		lchild=n.lchild;
		rchild=n.rchild;
	}
	node(t _data, node<t> *_lchild, node<t> *_rchild){data=_data; lchild=_lchild; rchild=_rchild;}
};

template <typename t>
class bst
{
private:
	node<t> *root;
public:
	bst();
	bst(bst &);
	node<t>* return_root()
	{return root;}
	//node<t>* max();
	class iterator;
	iterator start(){return iterator(root);}
	int end(){return size();}
	void insert(const t &);
	void rec_insert(const t & );
	void rec_insert(node<t> *,const t & );
	node<t> *copytree(node<t> *);
	int size();
	void in_order_traversal();
	//stack<node<t>*> descending_order();
	bool delete_(const t &);
	node<t>* find(const t &);

	//~bst();
};


























#endif