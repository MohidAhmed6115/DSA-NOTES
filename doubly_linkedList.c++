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

		if (target == 0){
			insertAtFront(data);
			return;
		}


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

			if (target == count && currentNode == tail){
				// Logic yet to be written
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

		if (target == 1){
			insertAtFront();
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
			}

			if(target == count && currentNode == tail){
				// Logic yet to be written
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

	void deleteTarget(int target){
		int count = 1;
		if (head == nullptr && tail == nullptr)
			throw runtime_error("List is empty");

		Node<T> *currentNode = head;
		Node<T> *prevNode = nullptr;
		Node<T> *nextNode = nullptr;
		while(currentNode != NULL){
			if (target == count){
				prevNode = currentNode->prev;
				nextNode = currentNode->next;
				prevNode->next = nextNode;
				nextNode->prev = prevNode;
				delete currentNode;
				currentNode = nullptr;
				return;
			}
			currentNode = currentNode->next;
			count++;
		}

	}



	void display(){
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

int main() {
	DoublyLinkedList<int> list;

	list.insertAtFront(5);
	list.insertAtFront(10);
	list.insertAtFront(15);
	list.insertAtFront(20);
	list.insertAtEnd(40);

	// list.insertAfterTarget(3,30);
	// list.insertBeforeTarget(3,30);
	// list.display();
	// list.deleteTarget(2);
	// list.deleteAtFront();
	// list.deleteAtEnd();

	// list.display();
	// list.displayReverse();

	return 0;
}