#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node{
	T data;
	Node *prev;
	Node *next;
};

template <typename T>
class DoublyLinkedList{

private:
	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;

	int getSize(){
		int count = 1;
		Node<T> *currentNode = head;
		while(currentNode->next != nullptr){
			currentNode = currentNode->next;
			count++;
		}
		return count;
	}

public:



	// Insertion At Front 
	void insertAtFront(T data){
		Node<T> *newNode = new Node<T>;
		newNode->data = data;
		if(head == nullptr && tail == nullptr){
			newNode->next = head;
			newNode->prev = nullptr;
			tail = newNode;
		}else{
			newNode->next = head;
			head->prev = newNode;
			newNode->prev = nullptr;
		}
		head = newNode;
		
	}

	void insertAtEnd(T data){
		Node<T> *newNode = new Node<T>;
		newNode->data = data;
		if(head == nullptr && tail == nullptr){
			newNode->next = head;
			newNode->prev = nullptr;
			tail = newNode;
			head = newNode;
			return;
		}

		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
		newNode->next = nullptr;

	}


	void insertAfterTarget(T key, T data) {

		Node<T> *currentNode = head;
		Node<T> newNode = nullptr;
		while (currentNode != NULL && currentNode->data != key){
			currentNode = currentNode->next;
		}
		
		newNode->data = data;
		newNode->next = currentNode->next;
		currentNode->next = newNode;

	}
	void insertBeforeTarget(T key, T data) {

		Node<T> *currentNode = head;
		Node<T> *prevNode = nullptr;
		Node<T> newNode = nullptr;
		while (currentNode != NULL && currentNode->data != key){
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
		
		newNode->data = data;
		newNode->next = prevNode->next;
		prevNode->next = newNode;

	}
	

	void insertAtPos(int target, T data){
		// User Will Enter that position and after that position a new Node will be added at that position
		Node<T> *newNode = new Node<T>;
		int count = 1;
		if (head == nullptr && tail == nullptr)
			throw runtime_error("No Node is inserted");

		if (target == 1){
			insertAtFront(data);
			return;
		}

		
		Node<T> *currentNode = head;
		Node<T> *prevNode = nullptr;
		newNode->data = data;
		while(currentNode != NULL){
			if(target == count){
				prevNode = currentNode->prev;
				prevNode->next = newNode;
				newNode->next = currentNode;
				newNode->prev = prevNode;
				return;
			}

			currentNode = currentNode->next;
			count++;
		}
	}

	void deleteAtFront(){
		if (head == nullptr && tail == nullptr) 
			throw runtime_error("List is empty");

		Node<T> *currentNode = head;
		Node<T> *nextNode = currentNode->next;
		nextNode->prev = nullptr;
		head = nextNode;
		delete currentNode;
		currentNode = nullptr;
	}

	void deleteAtEnd(){
		if (head == nullptr && tail == nullptr)
			throw runtime_error("List is empty");

		Node<T> *currentNode = tail;
		Node<T> *prevNode = currentNode->prev;
		prevNode->next = nullptr;
		tail = prevNode;
		delete currentNode;
		currentNode = nullptr;
}

void deleteByPos(int pos) {
    if (head == nullptr && tail == nullptr)
        throw runtime_error("List is empty");

    int size = getSize();
    if (pos < 1 || pos > size)
        throw out_of_range("Invalid position");

    if (pos == 1) {
        deleteAtFront();
        return;
    }
    if (pos == size) {
        deleteAtEnd();
        return;
    }

    Node<T> *currentNode = nullptr;
    int count = 1;

    if (pos > size / 2) {
        // traverse from tail
        currentNode = tail;
        while (currentNode != nullptr && count != size - pos + 1) {
            currentNode = currentNode->prev;
            count++;
        }
    } else {
        // traverse from head
        currentNode = head;
        while (currentNode != nullptr && count != pos) {
            currentNode = currentNode->next;
            count++;
        }
    }

    Node<T> *prevNode = currentNode->prev;
    Node<T> *nextNode = currentNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete currentNode;
}

	void display(){
		if (head == nullptr) {
			cerr<<"Nothing to display :(";
			return;
		}
		Node<T> *current = head;
		while(current != NULL){
			cout<<current->data<<" ";
			current = current->next;
		}
		
	}
	void displayReverse(){
		Node<T> *current = tail;
		while(current != NULL){
			cout<<current->data<<" ";
			current = current->prev;
		}
	}
};
