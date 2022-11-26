#include <iostream>
using namespace std;
typedef char Type;

struct Tree_Node {
	Tree_Node* left;
	Type data;
	Tree_Node* right;
};
typedef Tree_Node* QType;

struct Node {
	QType data;
	Node* next;

};

class Queue {
private:
	Node* front, * rear;
public:
	Queue();
	bool Is_Empty() {
		return front == NULL;
	}
	void Put(QType Data);
	QType Get();
	~Queue();
};
Queue::Queue() {
	front = rear = NULL;
}
void Queue::Put(QType Data) {
	Node* newNode;
	newNode = new Node;
	if (newNode == NULL)
		cout << "\nQueue is full";
	newNode->data = Data;
	newNode->next = NULL;
	if (front == NULL) {
		rear = front = newNode;
		return;
	}
	rear->next = newNode;
	rear = rear->next;
}
QType Queue::Get() {
	if (front == NULL) {
		cout << "Queue is empty"; exit(-1);
	}
	Node* current; QType Data;
	Data = front->data;
	current = front;
	front = front->next;
	delete current; return Data;
}
Queue :: ~Queue() {
	if (front == NULL)
		return;
	Node* current;
	while (front != NULL) {
		current = front;
		front = front->next;
		delete current;
	}
}



class Binary_Tree
{
private:
	Tree_Node* root;
	void Insert
	(Tree_Node*, Type _data);
	Tree_Node* Remove(Tree_Node*, Type _data);
	void Pre_Order
	(Tree_Node*);
	void In_Order
	(Tree_Node*);
	void Post_Order
	(Tree_Node*);
	bool Search
	(Type key, Tree_Node*);
	Tree_Node* Find_Min(Tree_Node*);
	Tree_Node* Find_Max(Tree_Node*);
	void Level_Order(Tree_Node* node);


public:
	Binary_Tree
	();
	void Insert
	(Type _data);
	void Remove
	(Type _data);
	void Pre_Order();
	void In_Order
	();
	void Post_Order();
	bool Search
	(Type _data);
	void Find_Min
	();
	void Find_Max
	();
	void Level_Order();
};
Binary_Tree::Binary_Tree() {
	root = NULL;
}
void Binary_Tree::Insert(Type _data) { Insert(root, _data); }
void Binary_Tree::Insert(Tree_Node* node, Type _data) {
	if (root == NULL) {
		// if tree is empty
		root = new Tree_Node;
		root->data = _data;
		root->left = NULL; root->right = NULL;
	}
	else if (_data >= node->data) {
		if (node->right != NULL) // if right subtree is present
			Insert(node->right, _data);
		// create new node
		else {
			node->right = new Tree_Node;
			node->right->data = _data;
			node->right->left = NULL;
			node->right->right = NULL;
		}
	}
	else {
		// if left subtree is present
		if (node->left != NULL)
			Insert(node->left, _data);
		// create new node
		else {
			node->left = new Tree_Node;
			node->left->data = _data;
			node->left->left = NULL;
			node->left->right = NULL;
		}
	}
}
void Binary_Tree::Find_Min
() {
	Tree_Node* node = Find_Min(root);
	if (node != NULL)
		cout << "Minimum Number is: " << node->data << endl;
}
Tree_Node* Binary_Tree::Find_Min(
	Tree_Node* n) {
	if (n == NULL)
		return NULL;
	if (n->left == NULL)
		return n;
	return Find_Min(n->left);
}
void Binary_Tree::Remove(Type _data) { Remove(root, _data); }
Tree_Node* Binary_Tree::Remove(Tree_Node* node, Type x) {
	if (node == NULL)
		return NULL; // Item not found; do nothing
	if (x < node->data)
		node->left = Remove(node->left, x);
	else if (x > node->data)
		node->right = Remove(node->right, x);
	else {
		// if Node has no child
		if (node->left == NULL &&
			node->right == NULL) {
			delete node;
			return NULL;
		}
		// if Node has one right child
		else if (node->left == NULL &&
			node->right != NULL) {
			Tree_Node* oldNode = node;
			node = node->right;
			delete oldNode;
			return node;
		}
		// if Node has one left child
		else if (node->right == NULL &&
			node->left != NULL) {
			Tree_Node* oldNode = node;
			node = node->left;
			delete oldNode;
			return node;
		}
		else { // if node has two children
			// Replace the data of this node
			// with the smallest data of
			// the right subtree
			node->data =
				Find_Min(node->right)->data;
			// recursively delete smallest node
			node->right = Remove(node->right,
				node->data);
		}
	}
	return node;
}
bool Binary_Tree::Search(Type _data) {
	return Search(_data, root);
}
bool Binary_Tree::Search(Type key, Tree_Node* node) {
	bool found = false;
	if (node == NULL) // node is not present
		return false;
	if (key == node->data) // if node with same data is found
		return true;
	else if (key > node->data)
		found = Search(key, node->right);
	else
		found = Search(key, node->left);

	return found;
}
void Binary_Tree::Pre_Order() { Pre_Order(root); }
void Binary_Tree::Pre_Order(Tree_Node * node) {
	if (node != NULL) {
		cout << node->data << " ";
		Pre_Order(node->left);
		Pre_Order(node->right);
	}
}
void Binary_Tree::In_Order() { In_Order(root); }
void Binary_Tree::In_Order(Tree_Node * node) {
	if (node != NULL) {
		In_Order(node->left);
		cout << node->data << " ";
		In_Order(node->right);
	}
}
void Binary_Tree::Post_Order() { Post_Order(root); }
void Binary_Tree::Post_Order(Tree_Node * node) {
	if (node != NULL) {
		Post_Order(node->left);
		Post_Order(node->right);
		cout << node->data << " ";
	}
}
void Binary_Tree::Find_Max
() {
	Tree_Node* n = Find_Max(root);
	if (n != NULL)
		cout << "Maximum Number is: " << n->data << endl;
}
Tree_Node* Binary_Tree::Find_Max(
	Tree_Node* node) {
	if (node == NULL)
		return NULL;
	if (node->right == NULL)
		return node;
	return Find_Max(node->right);
}
void Binary_Tree::Level_Order(
	Tree_Node* node) {
	Queue Q;
	if (node == NULL) return;
	Q.Put(node);
	while (!Q.Is_Empty()) {
		node = Q.Get();
		cout << node->data << " ";
		if (node->left != NULL)
			Q.Put(node->left);
		if (node->right != NULL)
			Q.Put(node->right);
	}
	cout << endl;
}
void Binary_Tree::Level_Order() {
	Level_Order(root);
}
int main() {
	Binary_Tree tree;
	//int Numbers[] = { 14,15,4,9,7,18,3,5,16,20,17 };
	//int Numbers[] = { 10,3,11,6,1,8,5,9,7 };
	//char characters[] = { 'A','B','C','D','E','F','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	char characters[] = { 'A','B','C','D','E' };
	int size = sizeof(characters);
	for (int i = 0; i < size; i++) {
		tree.Insert(characters[i]);
	}char i; char x;
	while (1) {
	cout << "\n[A] - Add Character\n";
	cout << "[R] - Remove Character\n";
	cout << "[S] - Search Character\n";
	cout << "[P] - Pre - Order Traversal\n";
	cout << "[I] - In - Order Traversal\n";
	cout << "[T] - Post - Order Traversal\n";
	cout << "[L] - Level - Order Traversal\n";
	cout << "[Q] – Quit\n";
	cout << "enter choice: ";
	cin >> i;
		switch (i) {
		case 'a':
		case 'A':
			cout << "\nenter character to be inserted: "; cin >> x;
			tree.Insert(x);
			break;
		case 'R':
		case 'r':
			cout << "\nEnter character to remove: "; cin >> x;
			tree.Remove(x);
			break;
		case 'S':
		case 's':
			char y;
			cout << "\nenter character to search: \n"; cin >> y;
			if (tree.Search(y) == true)
				cout << "found " << y << endl;
			else
				cout << y << " is not present " << endl;
			break;
		case 'p':
		case 'P':
			cout << "\nPre_Order Traversal: " << endl; tree.Pre_Order(); cout << endl;
			break;
		case 'i':
		case 'I':
			cout << "\nIn_Order Traversal: " << endl; tree.In_Order(); cout << endl;
			break;
		case 't':
		case 'T':
			cout << "\nPost_Order Traversal"; tree.Post_Order(); cout << endl;
			break;
		case 'l':
		case 'L':
			cout << "\nLevel_Order Traversal: " << endl; tree.Level_Order(); cout << endl;
			break;
		case 'q':
		case 'Q':
			system("pause"); exit(0);
		}
	}
	
}
