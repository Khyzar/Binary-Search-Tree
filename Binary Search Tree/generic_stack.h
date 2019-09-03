#ifndef GENERIC_STACK_H
#define GENERIC_STACK_H


template <typename t>
class stack
{
private:
	t *data;
	int elements;
	int size;
public:
	stack()
	{
		data=0;
		elements=0;
		size=1;
		data=new t[size];
	}
	bool isEmpty(){return(elements==0);}
	bool isFull(){return(elements==size);}
	bool push(const t&_data)
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
	void allocate_memory()
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

	t pop()
	{
		t x;
		if(isEmpty())
			return false;
		x=data[--elements];
		return x;
	}
	//void Empty_stack();
	void print()
	{

		for(int i=0; i<size; i++)
			cout<<data[i];

	}
	//~stack();
};

#endif