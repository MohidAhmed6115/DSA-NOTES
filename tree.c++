#include <iostream>
#include <stdexcept>
#include "stack_using_linkedlist.h"
using namespace std;

template <typename T>
struct Node {
	T data;
	Node *left;
	Node *right;
};

template <typename T>
class Tree {
	private:
		Node<T> *root;
	public:
		Tree() {
			root = nullptr;
		}

		void insert(T data) {
			if (root == nullptr) {
				root->data = data;
				root->left = nullptr;
				root->right = nullptr;
				return;
			}

			bool isGreater = false;
			Node<T> *currentNode = root;
			Node<T> *newNode = new Node;
			newNode->data = data;

			while (currentNode != nullptr) {
				if (data > currentNode->data) {
					currentNode =  currentNode->right;
					isGreater = true;
				}else if ( data < currentNode->data ) {
					currentNode = currentNode->left;
					isGreater = false;
				}
			}

			if (isGreater) {
				currentNode->right = newNode; 
			}else {
				currentNode->left = newNode;
			}

		}

		void display () {
			Node<T> *currentNode = root;
			Stack<T> store;
			while (currentNode != nullptr) {
				store.push(currentNode->data);
				if (currentNode->left != nullptr) {
					currentNode = currentNode->left;
					store.push(currentNode->data);
				}
			}
		}

};