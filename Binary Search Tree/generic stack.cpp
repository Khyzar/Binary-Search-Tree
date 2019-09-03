#include"generic_stack.h"
#include <iostream>
#include<conio.h>
using namespace std;


template <typename t>
stack<t>::stack()
{
	data=NULL;
	elements=0;
	size=1;
	data=new t[size];
}
template <typename t>
void stack<t>::allocate_memory()
{
	size++;
	t *temp;
	temp=new t[size];
	for(int i=0; i<size; i++)
		temp[i]=data[i];
	delete []data;
	data=new t[size];
	for(int j=0; j<size; j++)
		data[j]=temp[j];
}

template <typename t>
bool stack <t>::push(const t& _data)
{
	int counter=0;
	if(isFull())
	{	counter=1;
	}
	if(counter==1)
		allocate_memory();
	data[elements++]=_data;
	return true;
}
template <typename t>
t stack<t>::pop()
{
	t x;
	if(isEmpty())
		return false;
	x=data[--elements];
	return x;
}

template <typename t>
void stack<t>::print()
{
	
	for(int i=0; i<size; i++)
 	     cout<<data[i];
	
}
//template<typename type>
//stack<type>::~stack()
//{
//	delete []data;
//	
//}
