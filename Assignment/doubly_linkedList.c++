#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;
struct Student
{
	int studentId;
	string studentName;
	double marks;
	Student *prev;
	Student *next;
	Student() {}
	Student(int studentId, string studentName, double marks) : studentId(studentId),studentName(studentName),marks(marks),prev(nullptr),next(nullptr){}
};

class DoublyLinkedList
{

private:
	Student *head;
	Student *tail;

	int getSize()
	{
		int count = 0;
		Student *currentNode = head;
		while (currentNode != nullptr)
		{
			currentNode = currentNode->next;
			count++;
		}
		return count;
	}

public:
	DoublyLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	// Insertion At Front
	void insertAtFront(int studentId,string studentName,double marks)
	{
		Student *newNode = new Student(studentId,studentName,marks);
		newNode->next = head;

		if (head == nullptr)
			tail = newNode;
		else
			head->prev = newNode;

		head = newNode;
	}

	void insertAtEnd(int studentId,string studentName, double marks)
	{
		Student *newNode = new Student(studentId,studentName,marks);
		
		newNode->next = nullptr;
		newNode->prev = tail;

		if (tail == nullptr)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}

	// void insertAfterTarget(T key, T data)
	// {
	// 	Student *front = head;
	// 	Student *end = tail;
	// 	Student *target = nullptr;
	// 	while (front != nullptr && end != nullptr){

	// 		if (front->data == key) {
	// 			target = front;
	// 			break;
	// 		}
	// 		if (end->data == key) {
	// 			target = end;
	// 			break;
	// 		}

	// 		front = front->next;
	// 		end = end->prev;
	// 	}

	// 	if (target == nullptr)
	// 		throw runtime_error("Target not found");

	// 	Student *newNode = new Student(data);
		
	// 	newNode->prev = target;
	// 	newNode->next = target->next;

	// 	if (target->next != nullptr)
	// 		target->next->prev = newNode;
	// 	else
	// 		tail = newNode;

	// 	target->next = newNode;
	// }

	// void insertBeforeTarget(T key, T data)
	// {
	// 	Student *currentNode1 = head;
	// 	Student *currentNode2 = tail;
	// 	Student *target = nullptr;

	// 	while (currentNode1 != nullptr && currentNode2 != nullptr){
			
	// 		if (currentNode1->data == key) {
	// 			target = currentNode1;
	// 			break;
	// 		}
			
	// 		if (currentNode2->data == key) {
	// 			target = currentNode2;
	// 			break;
	// 		}
	// 		currentNode1 = currentNode1->next;
	// 		currentNode2 = currentNode2->prev;


	// 	}

	// 	if (target == nullptr)
	// 		throw runtime_error("Target not found");

	// 	if (target == head)
	// 	{
	// 		insertAtFront(data);
	// 		return;
	// 	}

	// 	Student *newNode = new Student(data);
		
	// 	newNode->next = target;
	// 	newNode->prev = target->prev;

	// 	target->prev->next = newNode;
	// 	target->prev = newNode;
	// }

	// New node is placed AT position pos the old node there shifts forward
	void insertAtPos(int pos, int studentId, string studentName, double marks)
	{
		if (head == nullptr)
			throw runtime_error("No Node is inserted");

		int size = getSize();

		if (pos < 1 || pos > size + 1)
			throw out_of_range("Invalid position");

		if (pos == 1)
		{
			insertAtFront(studentId,studentName,marks);
			return;
		}

		if (pos == size + 1)
		{
			insertAtEnd(studentId,studentName,marks);
			return;
		}

		Student *currentNode = head;
		int count = 1;

		if (pos > size / 2)
		{
			// traverse from tail
			currentNode = tail;
			while (count != size - pos + 1)
			{
				currentNode = currentNode->prev;
				count++;
			}
		}
		else
		{
			// traverse from head
			currentNode = head;
			while (count != pos)
			{
				currentNode = currentNode->next;
				count++;
			}
		}
		Student *newNode = new Student(studentId,studentName,marks);
		
		newNode->prev = currentNode->prev;
		newNode->next = currentNode;

		currentNode->prev->next = newNode;
		currentNode->prev = newNode;
	}

	void deleteAtFront()
	{
		if (head == nullptr)
			throw runtime_error("List is empty");

		Student *currentNode = head;

		if (head == tail) // only one node
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			currentNode->next->prev = nullptr;
			head = currentNode->next;
		}
		delete currentNode;
		currentNode = nullptr;
	}

	void deleteAtEnd()
	{
		if (head == nullptr)
			throw runtime_error("List is empty");

		Student *currentNode = tail;

		if (head == tail) // only one node
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			currentNode->prev->next = nullptr;
			tail = currentNode->prev;
		}
		delete currentNode;
		currentNode = nullptr;
	}

	void deleteByPos(int pos)
	{
		if (head == nullptr)
			throw runtime_error("List is empty");

		int size = getSize();
		if (pos < 1 || pos > size)
			throw out_of_range("Invalid position");

		if (pos == 1)
		{
			deleteAtFront();
			return;
		}
		if (pos == size)
		{
			deleteAtEnd();
			return;
		}

		Student *currentNode = nullptr;
		int count = 1;

		if (pos > size / 2)
		{
			// traverse from tail
			currentNode = tail;
			while (count != size - pos + 1)
			{
				currentNode = currentNode->prev;
				count++;
			}
		}
		else
		{
			// traverse from head
			currentNode = head;
			while (count != pos)
			{
				currentNode = currentNode->next;
				count++;
			}
		}

		currentNode->prev->next = currentNode->next;
		currentNode->next->prev = currentNode->prev;
		delete currentNode;
	}

	void deleteById (int studentId) {

		Student *front = head;
		Student *end = tail;
		Student *target = nullptr;
		bool isFound = false;

		if (head == tail && (studentId == head->studentId || studentId == tail->studentId)){
			delete head;
			delete tail;
			head = nullptr;
			tail = nullptr;
			return;
		}

		while( front != nullptr && end != nullptr) {
			
			if (front->studentId == studentId) {
				target = front;
				isFound = true;
				break;
			}
			if (end->studentId == studentId) {
				target = end;
				isFound = true;				
				break;
			}

			front = front->next;
			end = end->prev;

		}

		

		if (isFound) {

			if (target == head) {
			head = target->next;
			target->next->prev = nullptr;
			delete target;
			target = nullptr;
			return;
		}

		if (target == tail) {
			tail = target->prev;
			target->prev->next = nullptr;
			delete target;
			target = nullptr;
			return;
		}

			target->prev->next = target->next;
			target->next->prev = target->prev;
			delete target;
			target = nullptr;
		}else{
			throw runtime_error("Target Not Found");
		}
	}

	void search(int studentId){
		if (head == nullptr && tail == nullptr) throw runtime_error("List is empty");
		Student *currentNode = new Student();
		while ( currentNode != nullptr) {
			if (currentNode->studentId == studentId) {
				cout<<"Student ID: "<<currentNode->studentId<<"\nStudent Name: "<<currentNode->studentName<<"\nMarks: "<<currentNode->marks;
				break;
			}
			currentNode = currentNode->next;
		}
	}

	void display()
	{
		if (head == nullptr)
		{
			cerr << "Nothing to display :(";
			return;
		}
		Student *current = head;
		while (current != nullptr)
		{
			cout<<" Student ID: " << current->studentId << "\nStudent Name: "<<current->studentName<<"\nMarks: "<< current->marks;
			current = current->next;
		}
	}

	void displayReverse()
	{
		Student *current = tail;
		while (current != nullptr)
		{
			cout<<"Student ID: " << current->studentId << "\nStudent Name: "<<current->studentName<<"\nMarks: "<<current->marks;
			current = current->prev;
		}
	}
	~DoublyLinkedList() {
		Student *currentNode = head;
		while( currentNode != nullptr) {
			Student *del = currentNode;
			currentNode = currentNode->next;
			delete del;
			del = nullptr;
		}
	}
};

int main () {
	DoublyLinkedList list;
	int choice = 0;
	while(choice != 9){

		cout<<"Press 1 for Insert At Front\nPress 2 for Insert At End\nPress 3 for Insertin at a specific position\nPress 4 Delete from beginning\nPress 5 for Delete from end\nPress 6 for Delete by Student Id\nPress 7 for Searching Student\nPress 8 to display data in Reverse\nPress 9 to display data\nPress 9 to Exit\nEnter Here: ";
		cin>>choice;
		switch(choice) {
			case 1: {

				int studentId;
				string studentName;
				double marks;
				cout<<"Enter your Student ID: ";
				cin>> studentId;
				cout<<"Enter your student Name: ";
				getline(cin >> ws, studentName);
				cout<<"Enter your marks: ";
				cin>>marks;
				list.insertAtFront(studentId,studentName,marks);
			}
				break;
			case 2:{

				int studentId;
				string studentName;
				double marks;
				cout<<"Enter your Student ID: ";
				cin>> studentId;
				cout<<"Enter your student Name: ";
				getline(cin >> ws, studentName);
				cout<<"Enter your marks: ";
				cin>>marks;
				list.insertAtEnd(studentId,studentName,marks);
			}
			break;
			case 3: {
				int pos;
				int studentId;
				string studentName;
				double marks;
				cout<<"Enter Position: ";
				cin>>pos;
				cout<<"Enter your Student ID: ";
				cin>> studentId;
				cout<<"Enter your student Name: ";
				getline(cin >> ws, studentName);
				cout<<"Enter your marks: ";
				cin>>marks;
				list.insertAtPos(pos,studentId,studentName,marks);
			}
			break;
			case 4: {
				list.deleteAtFront();
				cout<<"Successfully deleted";
			}
			break;
			case 5: {
				list.deleteAtEnd();
				cout<<"Successfully deleted";
			}
			break;
			case 6: {
				int studentId;
				cout<<"Enter Student ID: ";
				cin>>studentId;
				list.deleteById(studentId);
			}
			break;
			case 7: {
				list.displayReverse();
			}
			break;
			case 8: {
				list.display();
			}
			break;
			case 9: {
				cout<<"Exiting...";
			}
			break;
			default:
				cout<<"Wrong Input! Please select from the given option";

		}
	}
}
