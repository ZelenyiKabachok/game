#include "list.h"

template<class Type>
void List<Type>::NewLast(const Type& var)
{
    if(init) {
	    Item *tmp = pLast;
	    pLast = new Item(var, NULL, tmp);
	    tmp->pNext = pLast;
	    size++;
    } else { Create(&var, 1); }
}

template<class Type>
void List<Type>::NewFirst(const Type& var)
{
    if(init) {
	    Item *tmp = pFirst;
	    pFirst = new Item(var, tmp, NULL);
	    tmp->pPrev = pFirst;
	    size++;
    } else { Create(&var, 1); }
}

template<class Type>
void List<Type>::DeleteLast()
{
	Item *tmp = pLast;
	pLast = pLast->pPrev;
	pLast->pNext = NULL;
	delete tmp;
	size--;
    if(size == 0) { init = false; }
}

template<class Type>
void List<Type>::DeleteFirst()
{
	Item *tmp = pFirst;
	pFirst = pFirst->pNext;
	pFirst->pPrev = NULL;
	delete tmp;
	size--;
    if(size == 0) { init = false; }
}

template<class Type>
bool List<Type>::DeleteItem(int index)
{
	Item *tmp = pFirst;
	for(int i = 0; i < index && tmp; i++, tmp = tmp->pNext)
		{}	
	if(tmp == NULL) { return false; }

	if(!tmp->pPrev) { 
		DeleteFirst();
		return true;
	} else if(!tmp->pNext) {
		DeleteLast();
		return true;
	} else {
		Item *pv = tmp->pPrev;
		pv->pNext = tmp->pNext;
		tmp->pNext->pPrev = pv;
	}
	delete tmp;
	size--;
	return true;
}

template<class Type>
Type& List<Type>::operator[](int index)
{
	Item *tmp = pFirst;
	for(int i = 0; i < index; i++, tmp = tmp->pNext)
		{}
	return tmp->data;
}

template <class Type>
List<Type>::~List()
{
	Item *tmp = pFirst;
	while(pFirst) {
		tmp	= pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
}

template <class Type>
void List<Type>::Create(const Type *var, int len)
{
	pFirst = new Item(*var, NULL, NULL);
	pLast = pFirst;
    init = true;
	for(int i = 1; i < len; i++) {
		NewLast(var[i]);	
	}
}

template<class Type>
int List<Type>::Size() { return size; }
