#pragma once
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
	enum { MAX = 10 };		//sta³a o zasiêgu klasy
	Item *items;			//przechowuje elementy stosu
	int size;				//liczba elementow na stosie
	int top;				//indeks szczytowego elementu stosu				
public:
	Stack(unsigned int n=MAX);
	Stack(const Stack & st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	//zwraca false gdy stos jest pelny
	bool push(const Item & item);		//odk³ada element na stos
	//zwraca false gdy stos jest pusty
	bool pop(Item & item);				//zdejmuje element ze stosu
	Stack &  operator=(const Stack & st);
	void Show();
};

#endif // !1