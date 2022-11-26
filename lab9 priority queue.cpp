#include <iostream>
using namespace std;
template<typename T> class Priority_Queue {
private:
	struct PQNode {
		T info; int priority;
		struct PQNode* next;
	};
	PQNode* front; unsigned int sz;
public:
	Priority_Queue() { front = NULL; sz = 0; }
	~Priority_Queue();
	unsigned int size() { return sz; }
	void Push(T data, int priority);
	T Top();
	void Pop();
	void Show();
};
template<class T> void Priority_Queue<T> ::Push(T data, int priority) {
	PQNode* newNode, * currentNode;
	newNode = new PQNode;
	newNode->info = data;
	newNode->priority = priority;
	newNode->next = NULL;
	if (front == NULL || priority > front->priority) {
		newNode->next = front;
		front = newNode;
		sz++;
	}
	else {
		currentNode = front;
		while (currentNode->next != NULL && priority < currentNode->next->priority)
			currentNode = currentNode->next;
		newNode->next = currentNode->next;
		currentNode->next = newNode;
		sz++;
	}
}
template<class T> T Priority_Queue<T> ::Top() {
	if (front != NULL)
		return front->info;
	return 0;
}
template<class T> void Priority_Queue<T> ::Pop() {
	PQNode* currentNode;
	if (front == NULL)
		cout << "Priority Queue is Empty\n";
	else {
		currentNode = front;
		front = front->next;
		delete(currentNode);
		sz--;
	}
}
template<class T> void Priority_Queue<T> ::Show() {
	for (PQNode* t = front; t != NULL; t = t->next)
		cout << t->info << " ";
	cout << endl;
}

template<class T> Priority_Queue<T> :: ~Priority_Queue() {
	PQNode* currentNode;
	while (front != NULL) {
		currentNode = front->next;
		delete front;
		front = currentNode;
	}
}
int main() {
	Priority_Queue <string> PQ;
	char x;
	string name;
	int priority;

	while (1) {
		cout << "[A] - Add Customer" << endl;
		cout << "[G] - Get Customer" << endl;
		cout << "[P] - Print Queue" << endl;
		cout << "[Q] - Quit" << endl;
		cin >> x;
		switch (x) {
		case 'a':
		case 'A':
			cout << "enter Name: "; cin >> name;
			cout << "enter priority of \"" << name << " \" "; cin >> priority;
			PQ.Push(name, priority);
			break;
		case 'G':
		case 'g':
			PQ.Pop();
			break;
		case 'p':
		case 'P':
			cout << endl;
			PQ.Show();
			cout << endl;
			break;
		case 'q':
		case 'Q':
			exit(0);
		default:
			cout << "command not recognized! \n";
			break;
		}

		return 0;
	}
}