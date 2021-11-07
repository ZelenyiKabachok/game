#ifndef LIST_H
#define LIST_H

#include <cstdlib>

//Двусвязный список.
template<class Type>
class List {

	struct Item {
		Type data;
		Item *next;
		Item *prev;

		Item(const Type& d, Item *n, Item *p) : data(d), next(n), prev(p) {}
	};
	
	unsigned int size = 1;
	Item *first = NULL;			
	Item *last = NULL;

public:

	List() {}	

//const Type *var должен иметь хотя бы один элемент.
	void Create(const Type *var, int len);

//Добавить элемент в конец.
	void NewLast(const Type& var);

//Добавить элемент в начало.
	void NewFirst(const Type& var);

//Удалить последний элемент.
	void DeleteLast();

//Удалить первый элемент.
	void DeleteFirst();

//Удалить указанный элемент.
	bool DeleteItem(int index);

	int Size();

//Первый индекс 0.
	Type& operator[](int index);

	~List();

};

#endif
