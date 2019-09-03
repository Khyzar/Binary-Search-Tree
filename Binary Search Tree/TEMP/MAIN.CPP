#include"bst.h"
#include"bst.cpp"
#include"generic_stack.h"
#include<iostream>
using namespace std;

int main()
{
	bst<int> s1;
	s1.insert(5);
	s1.insert(4);
	s1.insert(6);
	s1.insert(8);
	s1.insert(7);
	s1.insert(2);
	cout<<"size of binary search tree\n";
	s1.size();cout<<endl;
	cout<<"in order traversal\n";
	s1.in_order_traversal();cout<<endl;
	cout<<"using iterator\n";
	bst<int>::iterator iter;
	int i=0;
	for(iter=s1.start(); i<s1.end();++iter, i++)
	{
		cout<<*(iter)<<"\n";
	}
	return 0;
}