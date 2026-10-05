#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
class Queue{
private:
	Node<T> *head = nullptr;
public:
	void enqueue(T data){
		Node<T> *newNode = new Node<T>;
		newNode->data = data;
		newNode->next = NULL;
		if (head == nullptr){
			head = newNode;
			return;
		}
		Node<T> *currentNode = head;
		while(currentNode->next != NULL){
			currentNode = currentNode->next;
		}	
		currentNode->next = newNode;
	}

	void dequeue(){

		if (head == nullptr) throw runtime_error("Queue is empty");
		Node<T> *currentNode = head;
		head = currentNode->next;
		delete currentNode;
		currentNode = nullptr;
	}

	T peekFront() {
		if (head == nullptr) throw runtime_error("Queue is empty");

		return head->data;
	}

	T peekEnd() {

		if (head == nullptr) throw runtime_error("Queue is empty");

		Node<T> *currentNode = head;
		while(currentNode->next != nullptr){
			currentNode = currentNode->next;
		}
		return currentNode->data;
	}

	bool isEmpty() {
		if (head == nullptr) return true;

		return false;
	}

	int size() {
		if (head == nullptr) return 0;
		int elementCount = 0;
		Node<T> *currentNode = head;
		while(currentNode != nullptr) {
			currentNode = currentNode->next;
			elementCount++;
		}
		return elementCount;

	}

	void display() {
		Node<T> *currentNode = head;
		while(currentNode != nullptr){
			cout<<currentNode->data<<" ";
			currentNode = currentNode->next;
		}
	}

	~Queue(){
		Node<T> *currentNode = head;
		while(currentNode != NULL){
			Node<T> *nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}
	}

};
