#include"bst.h"
#include"bst.cpp"
#include<iostream>
using namespace std;

int main()
{
	bst<int> s1;
	s1.rec_insert(5);
	s1.rec_insert(4);
	s1.rec_insert(6);
	s1.rec_insert(8);
	s1.rec_insert(7);
	s1.rec_insert(2);
	cout<<"in order traversal\n";
	s1.in_order_traversal();cout<<endl;
	s1.delete_(7);
	cout<<"in order traversal\n";
	s1.in_order_traversal();cout<<endl;
	cout<<"using iterator\n";
	bst<int>::iterator iter;
	int i=0;
	for(iter=s1.start(); iter<=s1.end();iter++)
	{
		cout<<*(iter)<<" ";
	}
	cout<<endl;
	return 0;
}