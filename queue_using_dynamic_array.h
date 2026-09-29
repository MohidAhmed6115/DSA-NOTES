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
	
	void enqueue(T data){
		// Checking if the array size is equal to the total elements present in the array for resizing
		if (elementCount == size){
			reSize();
		}


		for (int i = elementCount-1; i >= 0; i-- ){
			arr[i] = arr[i-1];
		}
		arr[0] = data;

		elementCount++;

	}

	// Removing the last added element implementing the LIFO "Last In Front Out" approach
	void dequeue(){
		if (elementCount == 0)
			throw runtime_error("No elements in stack");
		
		elementCount--;
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

	T peekFront(){
		if (elementCount-1 == 0) throw runtime_error("Queue is empty")

		return arr[elementCount-1];
	}
	T peekEnd() {
		if (elementCount-1 == 0) throw runtime_error("Queue is empty")

		return arr[0];
	}

	// Destructor
	~Stack(){
		delete[] arr;
	}

};
