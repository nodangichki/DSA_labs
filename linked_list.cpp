#include <iostream>
#include <string>
using namespace std;
template<typename T> class Linked_List {
private:
	struct node {
		T data;
		node* next;
	} *head;
public:
	Linked_List();
	void push_back(T Data);
	void push_front(T Data);
	void addafter(int loc, T Data);
	void display();
	int count();
	void del(T Data);
	T front();
	T back();
	void pop_front();
	void pop_back();
	~Linked_List();
};
template<typename T> Linked_List<T> ::Linked_List() {
	head = NULL;
}
template<typename T> void Linked_List<T> ::push_back(T Data) {
	node* current, * newNode;
	if (head == NULL) { // list is empty then create first node
		head = new node;
		head->data = Data;
		head->next = NULL;
	}
	else { // go to last node
		current = head;
		while (current->next != NULL)
			current = current->next;
		newNode = new node; // add node at the end
		newNode->data = Data;
		newNode->next = NULL;
		current->next = newNode;
	}
}

// adds a node at the beginning
template<typename T> void Linked_List<T> ::push_front(T Data) {
	node* newNode;
	newNode = new node;
	// add new node
	newNode->data = Data;
	newNode->next = head;
	head = newNode;
}
template<typename T> void Linked_List<T>::addafter(int loc,
	T Data) {
	node* current, * newNode;
	current = head;
	for (int i = 0; i < loc; i++) {
		// skip to desired portion
		current = current->next;
		if (current == NULL) { // if reached at end of linked list
			cout << "\nThere are less than "
				<< loc << " elements in list" << endl;
			return;
		}
	}
	newNode = new node; // insert new node
	newNode->data = Data;
	newNode->next = current->next;
	current->next = newNode;
}
// displays the contents of the link list
template<typename T> void Linked_List<T> ::display() {
	node* current = head; cout << endl;
	while (current != NULL) { // traverse the entire linked list
		cout << current->data << " ";
		current = current->next;
	}
}
// counts the number of nodes present
template<typename T> int Linked_List<T> ::count() {
	node* current = head; int c = 0;
	while (current != NULL) { // traverse the entire linked list
		current = current->next;
		c++;
	}
	return c;
}
// deletes the specified node
template<typename T> void Linked_List<T> ::del(T Data) {
	node* previous = nullptr, * current = head;
	while (current != NULL) {
		if (current->data == Data) {
			// if node to be deleted is the first node
			if (current == head)
				head = current->next;
			else
				previous->next = current->next;
			delete current; // free memory occupied by node
			return;
		}
		// traverse the linked list till the last node is reached
		else {
			previous = current;
			current = current->next; // go to the next node
		}
	}
	cout << "\n\nElement " << Data << " not found";
}

// my additions
template<typename T> T Linked_List<T> ::front() {
	return head->data;
}
template<typename T> T Linked_List<T> ::back() {
	node* current;
	current = head;
	while (current->next != NULL)
		current = current->next;
	return current->data;
}
template<typename T> void Linked_List<T>::pop_front() {
	node* current;
	current = head;
	head = head->next;
	delete current;
	
}
template<typename T> void Linked_List<T>::pop_back() {
	if (head->next == NULL)
		head = NULL;
	else {
		node* current, * previous = nullptr;
		current = head;
		while (current->next != NULL) {
			previous = current;
			current = current->next;
		}
		delete current;
		previous->next = NULL;
	}
}
// deallocates memory
template<typename T> Linked_List<T> :: ~Linked_List() {
	node* current;
	while (head != NULL) {
		current = head->next;
		delete head;
		head = current;
	}
}
int main() {
	Linked_List<int> list1;
	list1.push_back(30); list1.push_back(40);
	list1.push_back(50);
	cout << "\nData in the linked list: "; list1.display();
	list1.push_front(20); list1.push_front(10);
	cout << "\n\nlinked list after addition at the beginning: ";
	list1.display();
	list1.addafter(2, 35);
	cout << "\n\nlinked list after addition at given position: ";
	list1.display();
	cout << "\nNo. of elements in linked list " << list1.count();
	list1.del(35);
	cout << "\n\n linked list after deletion: "; list1.display();
	cout << "\n\nNo. of elements in linked list: " << list1.count();
	cout << "\ndata at front of linked list: "<< list1.front();
	cout << "\ndata at back of linked list: " << list1.back();
	list1.pop_front();
	cout << "\n\nlinked list after poping front: ";
	list1.display();
	list1.pop_back();
	cout << "\n\nlinked list after poping back: ";
	list1.display();
	cout << endl;
	system("PAUSE");
	return 0;	
}