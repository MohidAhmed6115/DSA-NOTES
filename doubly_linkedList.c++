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

	void insertAfterTarget(int target,T data){
		// User Will Enter that position and after that position a new Node will be added like if user say 4 than the node will add at 5
		Node<T> *newNode = new Node<T>;
		int count = 1;
		if (head == nullptr && tail == nullptr) 
			throw runtime_error("No Node is inserted");

		Node<T> *currentNode = head;
		Node<T> *nextNode = nullptr;
		newNode->data = data;
		while(currentNode != NULL){
			if (target == count){
				nextNode = currentNode->next;
				currentNode->next = newNode;
				newNode->next = nextNode;
				newNode->prev = currentNode;
				nextNode->prev = newNode;
				return;
			}
			currentNode = currentNode->next;
			count++;
		}
	}

	void insertBeforeTarget(int target, T data){
		// User Will Enter that position and after that position a new Node will be added like if user say 4 than the node will add at 3
		Node<T> *newNode = new Node<T>;
		int count = 1;
		if (head == nullptr && tail == nullptr)
			throw runtime_error("No Node is inserted");
		
		Node<T> *currentNode = head;
		Node<T> *prevNode = nullptr;
		newNode->data = data;
		while(currentNode != NULL){
			if(target == count){
				prevNode = currentNode->prev;
				prevNode->next = newNode;
				newNode->next = currentNode;
				newNode->prev = prevNode;
			}
			currentNode = currentNode->next;
			count++;
		}
	}

	void deleteTarget(){
		
	}

	void display(){
		Node<T> *current = head;
		while(current != NULL){
			cout<<current->data<<" ";
			current = current->next;
		}
	}
};

int main() {
	DoublyLinkedList<int> list;

	list.insertAtFront(5);
	list.insertAtFront(10);
	list.insertAtFront(15);
	list.insertAtFront(20);
	list.insertAtEnd(40);

	list.insertAfterTarget(3,30);
	// list.insertBeforeTarget(3,30);

	list.display();

	return 0;
}