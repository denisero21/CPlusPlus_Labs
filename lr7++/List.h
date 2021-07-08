//---------------------------------------------------------------------------

#ifndef ListH
#define ListH
#include<vcl.h>

class List {
private:

	class node {
	public:
		node* pNext;
		int data;
		node(int data, node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	node *head;
	int size;

public:
	List()
	{
		head = nullptr;
		size = 0;
	}

	int GetSize() { return size; }

	void Push(int data) {
		if (head == nullptr) {
			head = new node(data);
		}
		else {
			node* current = head;
			while (current->pNext != nullptr) {
				current = current->pNext;
			}
			current->pNext = new node(data);
		}
		size++;
	}

	void Pop(int index) {
		if (index == 0) {
			node* temp = head;
			head = head->pNext;
			delete temp;
		}
		else {
			node* previous = head;
			for (int i = 0; i < index - 1; i++) {
				previous = previous->pNext;
			}
			node* toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;
			delete toDelete;
		}
		size--;
	}

	void RemoveById(int id) {
		int index = 0;
		node* current = head;
		while (current!= nullptr && id != current->data)
		{
			index++;
			current = current->pNext;
		}
		if (current != nullptr)
			Pop(index);
	}

	node* Search(int id) {
		int index = 0;
		node* current = head;
		while (current != nullptr && id != current->data)
		{
			current = current->pNext;
			index++;
		}
		return current;
	}

	int Pick(int index) {
		node* current = head;
		for (int i = 0; i < index - 1; i++) {
			current = current->pNext;
		}
		return current->data;
	}

};
//---------------------------------------------------------------------------
#endif
