#include <iostream>
#include <stdlib.h>
using namespace std;
typedef string Type;
struct Node {
	Type data;
	Node* next;
};
class Queue {
private:
	Node* front, * back;
	int sz;
public:
	Queue();
	void Push(Type Data);
	void Pop();
	Type Front();
	Type Back();
	int Size() { return sz; }
	void Print();
	~Queue();
};
Queue::Queue() {
	front = back = NULL;
	sz = 0;
}
void Queue::Push(Type Data) {
	Node* newNode;
	newNode = new Node;
	newNode->data = Data;
	newNode->next = NULL;
	if (front == NULL) { // if queue is empty
		back = front = newNode;
	}
	else {
		back->next = newNode;
		back = back->next;
	}
	sz++;
}
void Queue::Pop() {
	if (front == NULL)
		return;
	Node* current = front;
	front = front->next;
	cout << current->data;
	delete current;
	sz--;
}
Type Queue::Front() {
	if (front == NULL)
		return NULL;
	return front->data;
}
Type Queue::Back() {
	if (back == NULL)
		return NULL;
	return back->data;
}
void Queue::Print() {
	for (Node* curr = front; curr != NULL; curr = curr->next)
		cout << curr->data << " " << endl;
	cout << endl;
}
Queue :: ~Queue() {
	Node* current;
	while (front != NULL) {
		current = front;
		front = front->next;
		delete current;
	}
}
int main() {
	Queue q; char choice; char n[80];
	while (1) {
		cout << "[A] - Add Customer" << endl;
		cout << "[G] - Get Customers" << endl;
		cout << "[P] - Print Customers" << endl;
		cout << "[Q] - Quit" << endl;
		cin >> choice;
		switch (choice) {
		case 'A':
		case 'a':
			cout << "Enter Customer name: ";
			cin.ignore(80, '\n');
			cin.getline(n, 80);
			q.Push(n);
			break;
		case 'G':
		case 'g':
			q.Pop();
			cout << endl;
			break;
		case 'p':
		case 'P': cout << "\nCustomer Name: \n"; q.Print();
			break;
		
		case 'q':
		case 'Q':
			system("pause"); exit(0);
		
		}
	}
	system("PAUSE");
	return 0;
}