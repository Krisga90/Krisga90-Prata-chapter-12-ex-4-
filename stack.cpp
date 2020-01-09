#include "stack.h"
#include <iostream>


Stack::Stack(unsigned int n)
{
	if (n > 0)
	{
		items = new Item[n];
		size = n;
		top = 0;
	}
	else
		std::cout << "rozmiar tablicy msi byc wiekszy niz '0'.\n";
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == size;
}

bool Stack::push(const Item & item)
{
	if (top < size)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

Stack::~Stack()
{
	delete[] items;
}

Stack::Stack(const Stack & st)
{
	//Item *items;			
	//int size;				
	//int top;
	top = st.top;
	size = st.size;
	items = new Item[size];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
	top = st.top;
}

Stack &  Stack::operator=(const Stack & st)
{
	if (this == &st)
		return *this;
	delete[] items;
	top = st.top;
	size = st.size;
	items = new Item[size];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
	return *this;
}

void Stack::Show()
{
	for (int i = top-1; i >= 0; i--)
		std::cout << items[i] << std::endl;
}