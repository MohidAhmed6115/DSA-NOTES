#pragma once

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack{
private:
	int size = 5;

	// Holding the original size when the array was created first
	int o_size = 5;
	T *arr = new T[size];
	int elementCount = 0;

	// Function for resizing the array
	void reSize(){
		int newSize = size * 2;
		T *newArr = new T[newSize];
		for(int i=0;i<elementCount;i++){
			newArr[i] = arr[i];
		}

		delete[] arr;

		arr = newArr;
		size = newSize;
	}

public:

	// Total elements in the stack
	int getSize(){
		return elementCount;
	}

	void push(T data){
		// Checking if the array is full for resizing
		if (elementCount == size){
			reSize();
		}
		arr[elementCount] = data;		// Write first, then move the count
		elementCount++;
	}

	// Removing the last added element implementing the LIFO "Last In First Out" approach
	void pop(){
		if (elementCount == 0)
			throw runtime_error("No elements in stack");

		elementCount--;
	}

	// For viewing the elements inside the Stack
	void view(){
		for(int i=0;i<elementCount;i++){
			cout<<arr[i]<<" ";
		}
	}

	// Checking if the stack is empty or not
	bool isEmpty(){
		return elementCount == 0;
	}

	void clear(){
		delete[] arr;
		elementCount = 0;
		size = o_size;
		arr = new T[o_size];
	}

	T peek(){
		if (elementCount == 0) throw runtime_error("Stack is Empty");

		return arr[elementCount-1];
	}

	// Destructor
	~Stack(){
		delete[] arr;
	}

	// Copying would make two stacks share one array (double delete)
	Stack() = default;
	Stack(const Stack&) = delete;
	Stack& operator=(const Stack&) = delete;
};