#include <iostream>
#include <math.h> // for pow( , )
#include <fstream>
using namespace std;

class FileReader {

private:
	char expression[80];
public:
	FileReader();
	string read();
	void write_answer(string s);
	int answer = 0;
	string eq;


};
FileReader::FileReader() {
	expression[0] = '\0';
}


void FileReader::write_answer(string s) {
	// eat chars, including newline
	ofstream outfile;
	// open file in append mode
	outfile.open("answers.txt", std::ios_base::app);
	outfile << s << endl;
	system("pause");
}

string FileReader::read() {
	system("CLS");
	const int MAX = 240;
	char buffer[MAX];
	// character buffer
	ifstream infile("expression.txt");
	while (infile) {
		infile.getline(buffer, MAX);
		return buffer;
	}
	return 0;
}



typedef char Type;
class Stack {
private:
	struct node {
		Type data;
		node* next;
	} *head;
public:
	Stack()
	{
		head = NULL;
	}
	Type top() { return head->data; }
	bool IsEmpty();
	void Push(Type Data);
	Type Pop(
	);
	~Stack();
};
bool Stack::IsEmpty() { return head == NULL; }
void Stack::Push(Type Data) {
	node* newNode;
	newNode = new node;
	if (newNode == NULL) {
		cout << endl << "Stack is full";
		return;
	}
	newNode->data = Data;
	newNode->next = head;
	head = newNode;
}
Type Stack::Pop() {
	if (IsEmpty()) {
		cout << "Stack is empty "; return -1;
	}
	node* current; Type Data;
	current = head;
	Data = current->data;
	head = head->next;
	delete current;
	return Data;
}
// deallocates memory
Stack :: ~Stack() {
	node* current;
	while (head != NULL) {
		current = head;
		head = head->next;
		delete head;
	}
}
class In2Post {
private:
	Stack s;
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
			cout << c << " ";
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
					cout << p << " ";
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
					cout << p << " ";
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
			cout << p << " ";
			finale += p;
			finale += " ";
		}
	}
	return finale;
}
int main() {
	FileReader f1;
	string expression = f1.read();
	//string expression = "( a + ( b - c ) ) * ( ( d - e ) ^ ( f + g - h ) )";
	In2Post I2P(expression);
	f1.write_answer(expression);
	string converted = I2P.Convert();
	f1.write_answer(converted);
	system("PAUSE"); return 0;
}