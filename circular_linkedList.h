#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T> *next;
};

template <typename T>
class CircularLinkedList
{
private:
	Node<T> *head = nullptr;

public:
	void insertAtFront(T data)
	{
		Node<T> *newNode = new Node<T>;
		newNode->data = data;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
			return;
		}

		Node<T> *currentNode = head;
		while (currentNode->next != head)
		{
			currentNode = currentNode->next;
		}

		newNode->next = head;
		head = newNode;
		currentNode->next = head;
	}

	void insertAtEnd(T data)
	{
		Node<T> *newNode = new Node<T>;
		newNode->data = data;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
			return;
		}

		Node<T> *currentNode = head;
		while (currentNode->next != head)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
		newNode->next = head;
	}

	void insertAtPos(int pos, T data)
	{
		if (pos < 1)
			throw runtime_error("Invalid position");

		if (pos == 1)
		{
			insertAtFront(data);
			return;
		}

		if (head == nullptr)
			throw runtime_error("Position out of range");

		// Walk to the node just before the position, stop if we are back at the last node
		Node<T> *prevNode = head;
		int count = 1;
		while (count < pos - 1 && prevNode->next != head)
		{
			prevNode = prevNode->next;
			count++;
		}

		if (count < pos - 1)
			throw runtime_error("Position out of range");

		Node<T> *newNode = new Node<T>;
		newNode->data = data;
		newNode->next = prevNode->next;
		prevNode->next = newNode;
	}

	void display()
	{
		if (head == nullptr) cerr<<"Empty List"
		Node<T> *currentNode = head;
		do
		{
			cout << currentNode->data<< endl;
			currentNode = currentNode->next;
		} while (currentNode != head);
	}
};
