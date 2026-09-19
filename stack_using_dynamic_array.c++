#pragma once

#include <iostream>
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
		size = newSize;
		T *newArr = new T[newSize];
		for(int i=0;i<elementCount;i++){
			newArr[i] = arr[i];
		}

		delete[] arr;

		arr = newArr;
	}

public:
	
	// It will return total elements in the array not the top filled index
	int top(){
		return elementCount;
	}

	void push(T data){
		// Checking if the array size is equal to the total elements present in the array for resizing
		if (elementCount == size){
			reSize();
		}

		arr[elementCount] = data;

		elementCount++;

	}

	// Removing the last added element implementing the LIFO "Last In Front Out" approach
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
		return (elementCount == 0) ? true: false;
	}

	void clear(){
		delete[] arr;
		elementCount = 0;
		T *newArr = new T[o_size];
		size = o_size;
		arr = newArr;
	}

	T peek(){
		return arr[elementCount-1];
	}

	// Destructor
	~Stack(){
		delete[] arr;
	}

};
