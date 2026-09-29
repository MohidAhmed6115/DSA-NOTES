#include <iostream>
using namespace std;

template <typename T>
struct Node{
	T data;
	Node<T> *next;
};

template <typename T>
class CircularLinkedList {
private:
	Node<T> *head = nullptr;
public:
	void insertAtFront(T data) {
		Node<T> *newNode = new Node<T>;
		newNode->data = data;
		if (head == nullptr) {
			head = newNode;
			newNode->next = head;
			return;
		}

		Node<T> *currentNode = head;
		while( currentNode->next != head ) {
			currentNode = currentNode->next;
		}

		newNode->next = head;
		head = newNode;
		currentNode->next = head;
		cout<<"Inserted\n";
	}

	void insertAtEnd(T data) {
		Node<T> *newNode = new Node<T>;
		newNode->data = data;
		if (head == nullptr) {
			head = newNode;
			newNode->next = head;
			return;
		}

		Node<T> *currentNode = head;
		while (currentNode->next != head) {
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
		newNode->next = head;

	}	

	void insertAtPos(int pos,T data){
		int count = 1;
		Node<T> *newNode = new Node<T>;
		newNode->data = data;
		
		if (pos == 1){
			newNode->next = head;
			head = newNode;
			return;
		}
		
		Node<T> *currentNode = head;
		Node<T> *prevNode = nullptr;

		while (currentNode != nullptr) {

			if (pos == count){
				prevNode->next = currentNode->next;
				delete currentNode;
				currentNode = nullptr;
			}
			
			prevNode = currentNode;
			currentNode = currentNode->next;

		}

	}

	void display(){
		Node<T> *currentNode = head;
		// while(currentNode->next != head){
		// 	cout<<currentNode->data<<" "<<currentNode->next<<endl;
		// 	currentNode = currentNode->next;
		// }
		// cout<<currentNode->data<<" "<<currentNode->next<<endl;
		do
		{
			cout<<currentNode->data<<" "<<currentNode->next<<endl;
			currentNode = currentNode->next;
		} while (currentNode != head);
		
		
	}
};

int main() {
	CircularLinkedList<int> Clist;
	// Clist.insertAtFront(5);
	// Clist.insertAtFront(10);
	// Clist.insertAtFront(15);
	// Clist.insertAtFront(20);
	// Clist.insertAtFront(25);

	Clist.insertAtEnd(20);
	Clist.insertAtEnd(25);
	Clist.insertAtEnd(30);
	Clist.insertAtEnd(35);

	Clist.display();

}