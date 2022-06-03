#pragma once
#include <iostream>
using namespace std;

template <typename T>
class LIST
{

public:
	LIST();
	~LIST();
	int Getsize() { return Size; }
	void push_back(T data);
	void push_front(T data);
	void printlist(LIST<T> lst);

	
	void MAKENULL();
	void INSERT(T data, int index);
	void DELETE(int index);
	int FIRST();
	int END();
	void RETRIEVE(LIST<T> lst,int index);
	void NEXT(int index);
	void LOCATE(int index);



	T& operator[](const int index);

private:

	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
			
			Node(T data = T(),Node *pNext = nullptr)
			{
				this->pNext= pNext;
				this->data = data;
			}

	};

	int Size;
	Node<T> *head;

};


// Конструктори 

template<typename T>
LIST<T>::LIST()
{
	Size = 0;
	head = nullptr;
	

}

template<typename T>
LIST<T>::~LIST()
{
	MAKENULL();
}



//Основні методи 

template<typename T>
void LIST<T>::MAKENULL()
{
	Node<T>* temp;
	while (Size)
	{
		temp = head;
		head = head->pNext;
		delete temp;
		Size--;
	}
	
}

template<typename T>
void LIST<T>::INSERT(T data, int index)
{
	if (index == 0 )
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1 ; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		
		Size++;
	
	}

}

template<typename T>
inline void LIST<T>::DELETE(int index)
{
	Node<T>* previous = this->head;

	for (int i = 0; i < index - 1; i++)
	{
		previous = previous->pNext;
	}
	Node<T>* toDelete = previous->pNext;
	previous->pNext = toDelete->pNext;
	delete toDelete;
	Size--;

}

template<typename T>
int LIST<T>::FIRST()
{
	//виводить значення першого елемента 
	cout << head->data << endl;
	return head->data;
}

template<typename T>
int LIST<T>::END()
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current->pNext != nullptr)
	{
		current = current->pNext;
		counter++;
	}
	cout << counter << endl;
	return counter;

}

template<typename T>
void LIST<T>::RETRIEVE(LIST<T> lst,int index)
{
	cout << lst[index] << endl;
}

template<typename T>
void LIST<T>::NEXT(int index)
{
	if (index==Size)
	{
		cout << "This is the last item on the list " << endl;
		END();
	}
	else
	{
		int counter = 0;
		Node<T>* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				cout << current->data << endl;
				
				return current->data;
			}
			current = current->pNext;
			counter++;
		}


	}

}

template<typename T>
void LIST<T>::LOCATE(int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (current->data == index)
		{
			cout << current->data << endl;
			cout << counter << "  <= counter" << endl;
			break;
		}
		current = current->pNext;
		counter++;
	}
}








//Додаткові методи 
template<typename T>
void LIST<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
void LIST<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void LIST<T>::printlist(LIST<T> lst)
{
	for (int  i = 0; i < lst.Size; i++)
	{
		cout << lst[i] << endl;
	}

}

//Перегрузка операторів 
template<typename T>
T& LIST<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

}
