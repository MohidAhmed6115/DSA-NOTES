#pragma once

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue{
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

	// Newest element lives at index 0, oldest (front of the queue) at index elementCount-1
	void enqueue(T data){
		// Checking if the array is full for resizing
		if (elementCount == size){
			reSize();
		}

		// Shift everything one step to the right to make room at index 0
		for (int i = elementCount-1; i >= 0; i-- ){
			arr[i+1] = arr[i];
		}
		arr[0] = data;

		elementCount++;
	}

	// Removing the oldest element implementing the FIFO "First In First Out" approach
	void dequeue(){
		if (elementCount == 0)
			throw runtime_error("Queue is empty");

		elementCount--;
	}

	bool isEmpty(){
		return elementCount == 0;
	}

	int getSize(){
		return elementCount;
	}

	void clear(){
		delete[] arr;
		elementCount = 0;
		size = o_size;
		arr = new T[o_size];
	}

	T peekFront(){
		if (elementCount == 0) throw runtime_error("Queue is empty");

		return arr[elementCount-1];
	}

	T peekEnd() {
		if (elementCount == 0) throw runtime_error("Queue is empty");

		return arr[0];
	}

	// Destructor
	~Queue(){
		delete[] arr;
	}

	// Copying would make two queues share one array (double delete)
	Queue() = default;
	Queue(const Queue&) = delete;
	Queue& operator=(const Queue&) = delete;
};