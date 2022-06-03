#pragma once
#include <iostream>
#include <locale.h>
using namespace std;


template<typename T>
class LIST
{
public:

	
	//Основні методи
	int END();
	int FIRST();
	int MAKENULL();
	int INSERT(int index, int data);
	int DELETE(int index);
	int LOCATE(int data);
	int RETRIEVE(int position, LIST list);
	LIST<T> PREVIOUS(int index);
	void NEXT(int index);

	//Допоміжні методи і оператор
	void push_front(T data);
	void push_beak(T data);
	void PRINTLIST(LIST list);
	T& operator[](const int index);
	//Конструктори 
	LIST();
	~LIST();
	

private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		Node* pPrev;
		T data;


		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}



	};

	int Size;
	Node<T>* head;
	Node<T>* tail;

};
template<typename T>
LIST<T>::LIST()
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
}
template<typename T>
LIST<T>::~LIST()
{
}


//Основні методи

template<typename T>
int LIST<T>::END()
{
	cout << tail->data << endl;
	return tail->data;
}

template<typename T>
int LIST<T>::FIRST()
{
	cout << head->data << endl;
	return head->data;
}

template<typename T>
int LIST<T>::MAKENULL()
{
	Node<T>* temp;
	while(Size)
	{
		temp = head;
		head = head->pNext;
		delete temp;
		Size--;
	
	}
	return 0;
}

template<typename T>
int LIST<T>::INSERT(int index, int data)
{
	if (index == Size-1)
	{
		push_beak(data);
		return 0;
	}
	else if (index == 1)
	{
		push_front(data);
		return 0;
	}
	else
	{
		Node<T>* Ins = head;
		int i = 1;
		while (i < index)
		{
			Ins = Ins->pNext;
			i++;
		}
		Node<T> *PrevIns = Ins->pPrev;
		Node<T> *temp = new Node<T>;

		temp->data = data;

		//Калібровка зв'язків
		if (PrevIns != 0 && Size !=1)
		{
			PrevIns->pNext = temp;
			temp->pNext = Ins;
			temp->pPrev = PrevIns;
			Ins->pPrev = temp;

			Size++;
		}



	}


	return 0;
}

template<typename T>
int LIST<T>::DELETE(int index)
{
	Node<T>* DEL = head;
	
	int i = 0;
	while (i < index)
	{
		DEL = DEL->pNext;
		i++;
	}

	Node<T>* DELprev = DEL->pPrev;
	Node<T>* DELafter = DEL->pNext;
	//якщо удаляємо не голову
	if(DELprev != 0 && Size !=1)
	{
		DELprev->pNext = DELafter;
	}
	//якщо удаляємо не хвіст
	if(DELafter != 0 && Size !=1)
	{
		DELafter->pPrev = DELprev;
	}

	if (index == 0)
	{
		head = DELafter;
	}

	if (index == Size-1)
	{
		tail = DELprev;
	}

	delete DEL;

	Size--;
	return 0;
}

template<typename T>
int LIST<T>::LOCATE(int data)
{
	int position = 0;
	Node<T>* temp = head;
	bool reality = false;
	for (int i = 0; i <Size; i++)
	{
		
		if (temp->data == data) 
		{
			reality = true; 
			break;
		}
		temp = temp->pNext;
		position++;
	}

	if(reality == false)
	{
		cout << "Таких елементів не занйдено" << endl;
	}
	else
	{
		cout << position << endl;
		return position;
	}

}

template<typename T>
int LIST<T>::RETRIEVE(int position,LIST list)
{
	cout << list[position];
	return list[position];
}

template<typename T>
LIST<T> LIST<T>::PREVIOUS(int index)
{
	Node<T>* temp = new Node<T>;
	temp = head;
	int i = 0;
	while (i < index)
	{
		temp = temp->pNext;
		i++;
	}
	
	cout << temp->pPrev << endl;
	return temp->pPrev;
}

template<typename T>
void LIST<T>::NEXT(int index)
{
	Node<T>* temp = new Node<T>;
	temp = head;
	int i = 0;
	while (i < index)
	{
		temp = temp->pNext;
		i++;
	}

	cout << temp->pNext << endl;
}



//Допоміжні методи
template<typename T>
void LIST<T>::push_front(T data)
{
	Node<T>* temp = new Node<T>;
	Node<T>* current = new Node<T>;
	temp->pPrev = 0;
	temp->pNext = head;
	temp->data = data;

	if (Size == 0)
	{
		head = tail = temp;
	}
	else if (Size != 0)
	{
		head = temp;
		current = head->pNext;
		current->pPrev = temp;
	}
	Size++;
}

template<typename T>
void LIST<T>::push_beak(T data)
{
	Node<T>* temp = new Node<T>;
	Node<T>* current = new Node<T>;
	
	temp->pPrev = tail;
	temp->pNext = 0;
	temp->data = data;

	if (Size == 0)
	{
		tail = head = temp;
	}
	else if (Size != 0)
	{
		tail = temp;
		current = tail->pPrev;
		current->pNext = tail;

	}
	Size++;
}

template<typename T>
void LIST<T>::PRINTLIST(LIST list)
{
	for (int i = 0; i < Size; i++)
	{
		cout << list[i] << endl;
	}
}


template<typename T>
T& LIST<T>::operator[](const int index)
{
	Node<T>* temp;
	if (index <= Size / 2)
	{
		temp = this->head;
		int i = 0;
		while (i < index)
		{
			temp = temp->pNext;
			i++;
		}
	}

	else
	{
		temp = this->tail;
		int i = Size-1;
		while (i > index)
		{
			temp = temp->pPrev;
			i--;
		}
	}


	return temp->data;
	

}
