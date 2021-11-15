#include "list.h"

template<class Type>
void List<Type>::NewLast(const Type& var)
{
	Item *tmp = last;
	last = new Item(var, NULL, tmp);
	tmp->next = last;
	size++;
}

template<class Type>
void List<Type>::NewFirst(const Type& var)
{
	Item *tmp = first;
	first = new Item(var, tmp, NULL);
	tmp->prev = first;
	size++;
}

template<class Type>
void List<Type>::DeleteLast()
{
	Item *tmp = last;
	last = last->prev;
	last->next = NULL;
	delete tmp;
	size--;
}

template<class Type>
void List<Type>::DeleteFirst()
{
	Item *tmp = first;
	first = first->next;
	first->prev = NULL;
	delete tmp;
	size--;
}

template<class Type>
bool List<Type>::DeleteItem(int index)
{
	Item *tmp = first;
	for(int i = 0; i < index && tmp; i++, tmp = tmp->next)
		{}	
	if(tmp == NULL) { return false; }

	if(!tmp->prev) { 
		DeleteFirst();
		return true;
	} else if(!tmp->next) {
		DeleteLast();
		return true;
	} else {
		Item *pv = tmp->prev;
		pv->next = tmp->next;
		tmp->next->prev = pv;
	}
	delete tmp;
	size--;
	return true;
}

template<class Type>
Type& List<Type>::operator[](int index)
{
	Item *tmp = first;
	for(int i = 0; i < index; i++, tmp = tmp->next)
		{}
	return tmp->data;
}

template <class Type>
List<Type>::~List()
{
	Item *tmp = first;
	while(first) {
		tmp	= first;
		first = first->next;
		delete tmp;
	}
}

template <class Type>
void List<Type>::Create(const Type *var, int len)
{
	first = new Item(*var, NULL, NULL);
	last = first;
	for(int i = 1; i < len; i++) {
		NewLast(var[i]);	
	}
}

template<class Type>
int List<Type>::Size() { return size; }
