#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node *prev;
	Node *next;
	Node(T data) : data(data),prev(nullptr),next(nullptr){}
};

template <typename T>
class DoublyLinkedList
{

private:
	Node<T> *head;
	Node<T> *tail;

	int getSize()
	{
		int count = 0;
		Node<T> *currentNode = head;
		while (currentNode != nullptr)
		{
			currentNode = currentNode->next;
			count++;
		}
		return count;
	}

public:
	DoublyLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	// Insertion At Front
	void insertAtFront(T data)
	{
		Node<T> *newNode = new Node<T>(data);
		
		
		newNode->next = head;

		if (head == nullptr)
			tail = newNode;
		else
			head->prev = newNode;

		head = newNode;
	}

	void insertAtEnd(T data)
	{
		Node<T> *newNode = new Node<T>(data);
		
		newNode->next = nullptr;
		newNode->prev = tail;

		if (tail == nullptr)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}

	void insertAfterTarget(T key, T data)
	{
		Node<T> *front = head;
		Node<T> *end = tail;
		Node<T> *target = nullptr;
		while (front != nullptr && end != nullptr){

			if (front->data == key) {
				target = front;
				break;
			}
			if (end->data == key) {
				target = end;
				break;
			}

			front = front->next;
			end = end->prev;
		}

		if (target == nullptr)
			throw runtime_error("Target not found");

		Node<T> *newNode = new Node<T>(data);
		
		newNode->prev = target;
		newNode->next = target->next;

		if (target->next != nullptr)
			target->next->prev = newNode;
		else
			tail = newNode;

		target->next = newNode;
	}

	void insertBeforeTarget(T key, T data)
	{
		Node<T> *currentNode1 = head;
		Node<T> *currentNode2 = tail;
		Node<T> *target = nullptr;

		while (currentNode1 != nullptr && currentNode2 != nullptr){
			
			if (currentNode1->data == key) {
				target = currentNode1;
				break;
			}
			
			if (currentNode2->data == key) {
				target = currentNode2;
				break;
			}
			currentNode1 = currentNode1->next;
			currentNode2 = currentNode2->prev;


		}

		if (target == nullptr)
			throw runtime_error("Target not found");

		if (target == head)
		{
			insertAtFront(data);
			return;
		}

		Node<T> *newNode = new Node<T>(data);
		
		newNode->next = target;
		newNode->prev = target->prev;

		target->prev->next = newNode;
		target->prev = newNode;
	}

	// New node is placed AT position pos the old node there shifts forward
	void insertAtPos(int pos, T data)
	{
		if (head == nullptr)
			throw runtime_error("No Node is inserted");

		int size = getSize();

		if (pos < 1 || pos > size + 1)
			throw out_of_range("Invalid position");

		if (pos == 1)
		{
			insertAtFront(data);
			return;
		}

		if (pos == size + 1)
		{
			insertAtEnd(data);
			return;
		}

		Node<T> *currentNode = head;
		int count = 1;

		if (pos > size / 2)
		{
			// traverse from tail
			currentNode = tail;
			while (count != size - pos + 1)
			{
				currentNode = currentNode->prev;
				count++;
			}
		}
		else
		{
			// traverse from head
			currentNode = head;
			while (count != pos)
			{
				currentNode = currentNode->next;
				count++;
			}
		}
		Node<T> *newNode = new Node<T>(data);
		
		newNode->prev = currentNode->prev;
		newNode->next = currentNode;

		currentNode->prev->next = newNode;
		currentNode->prev = newNode;
	}

	void deleteAtFront()
	{
		if (head == nullptr)
			throw runtime_error("List is empty");

		Node<T> *currentNode = head;

		if (head == tail) // only one node
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			currentNode->next->prev = nullptr;
			head = currentNode->next;
		}
		delete currentNode;
	}

	void deleteAtEnd()
	{
		if (head == nullptr)
			throw runtime_error("List is empty");

		Node<T> *currentNode = tail;

		if (head == tail) // only one node
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			currentNode->prev->next = nullptr;
			tail = currentNode->prev;
		}
		delete currentNode;
	}

	void deleteByPos(int pos)
	{
		if (head == nullptr)
			throw runtime_error("List is empty");

		int size = getSize();
		if (pos < 1 || pos > size)
			throw out_of_range("Invalid position");

		if (pos == 1)
		{
			deleteAtFront();
			return;
		}
		if (pos == size)
		{
			deleteAtEnd();
			return;
		}

		Node<T> *currentNode = nullptr;
		int count = 1;

		if (pos > size / 2)
		{
			// traverse from tail
			currentNode = tail;
			while (count != size - pos + 1)
			{
				currentNode = currentNode->prev;
				count++;
			}
		}
		else
		{
			// traverse from head
			currentNode = head;
			while (count != pos)
			{
				currentNode = currentNode->next;
				count++;
			}
		}

		currentNode->prev->next = currentNode->next;
		currentNode->next->prev = currentNode->prev;
		delete currentNode;
	}

	void deleteByData (T key) {

		Node<T> *front = head;
		Node<T> *end = tail;
		Node<T> *target = nullptr;
		bool isFound = false;

		if (head == tail && (key == head->data || key == tail->data)){
			delete head;
			delete tail;
			head = nullptr;
			tail = nullptr;
			return;
		}

		while( front != nullptr && end != nullptr) {
			
			if (front->data == key) {
				target = front;
				isFound = true;
				break;
			}
			if (end->data == key) {
				target = end;
				isFound = true;				
				break;
			}

			front = front->next;
			end = end->prev;

		}

		

		if (isFound) {

			if (target == head) {
			head = target->next;
			target->next->prev = nullptr;
			delete target;
			target = nullptr;
			return;
		}

		if (target == tail) {
			tail = target->prev;
			target->prev->next = nullptr;
			delete target;
			target = nullptr;
			return;
		}

			target->prev->next = target->next;
			target->next->prev = target->prev;
			delete target;
			target = nullptr;
		}else{
			throw runtime_error("Target Not Found");
		}
	}

	void display()
	{
		if (head == nullptr)
		{
			cerr << "Nothing to display :(";
			return;
		}
		Node<T> *current = head;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
	}

	void displayReverse()
	{
		Node<T> *current = tail;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->prev;
		}
	}
	~DoublyLinkedList() {
		Node<T> *currentNode = head;
		while( currentNode != nullptr) {
			Node<T> *del = currentNode;
			currentNode = currentNode->next;
			delete del
			del = nullptr;
		}
	}
};
