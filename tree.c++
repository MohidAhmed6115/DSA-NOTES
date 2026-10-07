#include <iostream>
#include <stdexcept>
#include "stack_using_linkedlist.h"
using namespace std;

template <typename T>
struct TreeNode {
	T data;
	TreeNode *left;
	TreeNode *right;
};

template <typename T>
class Tree {
	private:
		TreeNode<T> *root;
	public:
		Tree() {
			root = nullptr;
		}

		void insert(T data) {
			TreeNode<T> *newTreeNode = new TreeNode<T>;
			if (root == nullptr) {
				newTreeNode->data = data;
				newTreeNode->left = nullptr;
				newTreeNode->right = nullptr;
				root = newTreeNode;
				return;
			}
			
			newTreeNode->left = nullptr;
			newTreeNode->right = nullptr;
			bool isGreater = false;
			bool isEqual = false;
			TreeNode<T> *currentTreeNode = root;
			TreeNode<T> *prevNode = nullptr;
			newTreeNode->data = data;

			while (currentTreeNode != nullptr) {
				prevNode = currentTreeNode;
				if (data > currentTreeNode->data) {
					currentTreeNode =  currentTreeNode->right;
					isGreater = true;
				}else if ( data < currentTreeNode->data ) {
					currentTreeNode = currentTreeNode->left;
					isGreater = false;
				}
				else {
					isEqual = true;
					break;
				}
			}

			if (isEqual) {
				delete newTreeNode;
				newTreeNode = nullptr;
				throw runtime_error("Duplicates aren't allowed");
			}

			if (isGreater) {
				prevNode->right = newTreeNode; 
			}else {
				prevNode->left = newTreeNode;
			}
		}

		bool search(T data) {
			if (root == nullptr) throw runtime_error("Tree is Empty");

			TreeNode<T> *currentNode = root;
			while (currentNode != nullptr && data != currentNode->data) {
				if (data > currentNode->data){
					currentNode = currentNode->right;
				}else {
					currentNode = currentNode->left;
				}
			}

			return currentNode == nullptr ? false : true;
		}

		/**
		 * In-Order Display
		 */
		void display () {

			if (root == nullptr) throw runtime_error("Tree is Empty")

			TreeNode<T> *currentTreeNode = root;
			Stack<TreeNode<T>*> store;
			while (currentTreeNode != nullptr || !store.isEmpty() ) {
				if (currentTreeNode != nullptr) {
					store.push(currentTreeNode);
					currentTreeNode = currentTreeNode->left;
				}else {
					TreeNode<T> *current = store.peek();
					store.pop();
					cout<<current->data<<" ";
					currentTreeNode = current->right;
				}
			}
		}

};

/**
 * @todo
 * Find Minimum and Maximum
 * Count Nodes
 * Height
 * isEmpty
 * PreOrder
 * Level Order
 * Delete a node
 * Destructor
 */


int main () {
	Tree<int> t;
	// t.insert(60);
	// t.insert(90);
	// t.insert(50);
	// t.insert(10);
	// t.insert(100);
	t.insert(10);
	t.insert(20);
	t.insert(30);
	t.display();

	cout<<"\n"<<t.search(50);
	
}