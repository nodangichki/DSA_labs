#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct Data {
	char   opr;
	double num;
};

struct Tree_Node {
	Tree_Node* left;
	Data data;
	Tree_Node* right;
};

typedef Tree_Node* SType;
struct Node {
	SType info;
	Node* next;
};

class Stack {
private:
	Node* head;
public:
	Stack();
	bool Is_Empty();
	SType Top();
	void Push(SType Data);
	SType  Pop();
	~Stack();
};

Stack::Stack() {
	head = NULL;
}

bool Stack::Is_Empty() {
	return head == NULL;
}

SType Stack::Top() {
	if (!Is_Empty())
		return head->info;
	return NULL;
}

void Stack::Push(SType Data) {
	Node* newNode;
	newNode = new Node;
	if (newNode == NULL) {
		cout << endl << "Stack is full";
		return;
	}
	newNode->info = Data;
	newNode->next = head; head = newNode;
}
SType Stack::Pop() {
	if (Is_Empty()) {
		cout << "Stack is empty ";
		return NULL;
	}
	Node* current;
	SType Data;
	current = head;
	Data = current->info;
	head = head->next;
	delete current;
	return Data;
}
Stack :: ~Stack() {
	Node* current;
	while (head != NULL) {
		current = head;
		head = head->next;   delete head;
	}
}

class Binary_Expression_Tree {
private:
	Stack St;
	Tree_Node* root;
	Tree_Node* t, * t1, * t2;
	void Pre_Order(Tree_Node*);
	void In_Order(Tree_Node*);
	void Post_Order(Tree_Node*);
	bool Is_Operator(char c);
	Tree_Node* New_Tree_Node(Data d);
	double Evaluate(Tree_Node* node);
public:
	Binary_Expression_Tree() { root = NULL; };
	Binary_Expression_Tree(string Postfix);
	double Evaluate();
	void Pre_Order();
	void In_Order();
	void Post_Order();
};
Tree_Node* Binary_Expression_Tree ::
New_Tree_Node(Data d) {
	Tree_Node* temp = new Tree_Node;
	temp->left = NULL;  temp->right = NULL;
	temp->data = d;
	return temp;
};

bool Binary_Expression_Tree ::
Is_Operator(char c) {
	switch (c) {
	case '+': return true;
	case '-': return true;
	case '*': return true;
	case '/': return true;
	case '^': return true;
	default: return false;
	}
	return false;
}
Binary_Expression_Tree ::
Binary_Expression_Tree(string Postfix) {
	// Traverse through every character of
	// input expression
	for (int i = 0; Postfix[i]; i++) {
		// ignore space and tab 
		if (Postfix[i] == ' ' ||
			Postfix[i] == '\t')
			continue;
		// If operand, simply push into stack
		if (!Is_Operator(Postfix[i])) {
			Data d;
			d.num = Postfix[i] - 0x30;
			d.opr = 0;
			t = New_Tree_Node(d);
			St.Push(t);
		}
		else { // operator
			Data d;
			d.num = 0;
			d.opr = Postfix[i];
			t = New_Tree_Node(d);

			// Pop two top nodes
			t1 = St.Pop();      // Remove top
			t2 = St.Pop();

			//  make them children
			t->right = t1;
			t->left = t2;
			// Add this subexpression to stack
			St.Push(t);
		}
	}
	// connect it with root pointer
	root = St.Pop();
}
double Binary_Expression_Tree ::
Evaluate() {
	return Evaluate(root);
}


double Binary_Expression_Tree ::
Evaluate(Tree_Node* node) {
	// empty tree  
	if (node == NULL)
		return 0;
	// leaf node i.e, an integer  
	if (node->left == NULL &&
		node->right == NULL) {
		return node->data.num;
	}
	// Evaluate left subtree  
	double l_val = Evaluate(node->left);
	// Evaluate right subtree  
	double r_val = Evaluate(node->right);

	// Check which operator to apply  
	if (node->data.opr == '+')
		return l_val + r_val;
	if (node->data.opr == '-')
		return l_val - r_val;
	if (node->data.opr == '*')
		return l_val * r_val;
	if (node->data.opr == '/')
		return l_val / r_val;
	if (node->data.opr == '^')
		return pow(l_val, r_val);
	return 0;
}
void Binary_Expression_Tree::Pre_Order() {
	Pre_Order(root);
}


void Binary_Expression_Tree ::
Pre_Order(Tree_Node* node) {
	if (node != NULL) {

		if (node->data.opr == 0)
			cout << node->data.num << " ";
		else
			cout << node->data.opr << " ";

		Pre_Order(node->left);
		Pre_Order(node->right);
	}
}

void Binary_Expression_Tree::In_Order() {
	In_Order(root);
}


void Binary_Expression_Tree ::
In_Order(Tree_Node* node) {
	if (node != NULL) {

		In_Order(node->left);

		if (node->data.opr == 0)
			cout << node->data.num << " ";
		else
			cout << node->data.opr << " ";

		In_Order(node->right);
	}
}
void Binary_Expression_Tree::Post_Order() {
	Post_Order(root);
}


void Binary_Expression_Tree ::
Post_Order(Tree_Node* node) {
	if (node != NULL) {

		Post_Order(node->left);

		Post_Order(node->right);

		if (node->data.opr == 0)
			cout << node->data.num << " ";
		else
			cout << node->data.opr << " ";
	}
}

/*

		my code
*/

typedef char Typepos;
class Stackpos {
private:
	struct nodepos {
		Typepos data;
		nodepos* next;
	} *head;
public:
	Stackpos()
	{
		head = NULL;
	}
	Typepos top() { return head->data; }
	bool IsEmpty();
	void Push(Typepos Data);
	Typepos Pop(
	);
	~Stackpos();
};
bool Stackpos::IsEmpty() { return head == NULL; }
void Stackpos::Push(Typepos Datapos) {
	nodepos* newNode;
	newNode = new nodepos;
	if (newNode == NULL) {
		cout << endl << "Stack is full";
		return;
	}
	newNode->data = Datapos;
	newNode->next = head;
	head = newNode;
}
Typepos Stackpos::Pop() {
	if (IsEmpty()) {
		cout << "Stack is empty "; return -1;
	}
	nodepos* current; Typepos Data;
	current = head;
	Data = current->data;
	head = head->next;
	delete current;
	return Data;
}
// deallocates memory
Stackpos :: ~Stackpos() {
	nodepos* current;
	while (head != NULL) {
		current = head;
		head = head->next;
		delete head;
	}
}
class In2Post {
private:
	Stackpos s;
	string expr;
public:
	In2Post(string eq);
	bool is_operand(char op);
	int Priority(char op);
	string Convert();
};
In2Post::In2Post(string eq) {
	expr = eq;
}
bool In2Post::is_operand(char op) {
	switch (op) {
	case '+': return false;
	case '-': return false;
	case '*': return false;
	case '/': return false;
	case '^': return false;
	case '(': return false;
	case ')': return false;
	default: return true;
	}
}
int In2Post::Priority(char op) {
	switch (op) {
	case '^': return 3;
	case '*':
	case '/': return 2;
	case '+':
	case '-': return 1;
	default: return 0;
	}
}
string In2Post::Convert() {
	char c, p;
	string finale = "";
	for (unsigned int i = 0; i < expr.size(); i++) {
		c = expr[i];
		if (c == ' ' || c == '\t') continue;
		else if (is_operand(c)) {
			//cout << c << " ";
			finale += c;
			finale += " ";
		}
		else if (c == '(')
			s.Push(c);
		else if (c == ')') {
			while (true) {
				p = s.Pop();
				if (p == '(')
					break;
				else {
					//cout << p << " ";
					finale += p;
					finale += " ";
				}
			}
		}
		else {
			while (!s.IsEmpty() && (Priority(c) <= Priority(s.top())))
			{
				p = s.Pop();
				if (p != ')' && p != '(') {
					//cout << p << " ";
					finale += p;
					finale += " ";
				}
			}
			s.Push(c);
		}
	}
	while (!s.IsEmpty()) {
		p = s.Pop();
		if (p != ')' && p != '(') {
			//cout << p << " ";
			finale += p;
			finale += " ";
		}
	}
	return finale;
}






int main() {
	
	string expression = "( ( ( ( 3 + 1 ) * 3 ) / ( ( 9 - 5 ) + 2 ) ) - ( ( 3 * ( 7 - 4 ) ) + 6 ) ) ";
	cout << "given expression:- " << expression;
	In2Post I2P1(expression);
	string conv4 = I2P1.Convert();
	cout << "\n\nconverted to postfix:-" <<conv4<<endl;
	Binary_Expression_Tree BET(conv4);
	cout << "\nAnswer = " << BET.Evaluate()<<"\n\n";
	cout << endl;
	system("PAUSE"); return 0;
	

}
