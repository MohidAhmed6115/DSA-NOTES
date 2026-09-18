#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T data;
	Node<T> *next;
};

template <typename T>
class Stack{
private:
	Node<T> *top = nullptr;
public:
	void push(T data){
		Node<T> *newNode = new Node<T>;
		newNode->next = top;
		top = newNode;
		newNode->data = data;
		
	}

	void pop(){

		if (top == nullptr) return;
		Node<T> *currentNode = top;
		top = currentNode->next;
		delete currentNode;
		currentNode = nullptr;
		return;
	}



	void view(){
		Node<T> *currentNode = top;
		while(currentNode != NULL){
			cout<<currentNode->data<<" ";
			currentNode = currentNode->next;
		}
	}

	T peek(){
		if (top == nullptr) throw runtime_error("Can't pop from empty Stack");

		return top->data;
	}

	bool isEmpty(){
		if (top == nullptr) return true;

		return false;
	}

	int size(){
		Node<T> *currentNode = top;
		if (top == nullptr) return 0;
		int size = 0;
		while(currentNode != NULL){
			currentNode = currentNode->next;
			size++;
		}
		return size;
	}

	void clear(){
		Node<T> *currentNode = top;
		while(currentNode != NULL){
			Node<T> *nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}
	}

	~Stack(){
		Node<T> *currentNode = top;
		while(currentNode != NULL){
			Node<T> *nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}
	}
};

