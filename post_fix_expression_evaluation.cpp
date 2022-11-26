#include <iostream>
#include <string>
#include <fstream>
#include <math.h> // for pow()
using namespace std;
typedef double Type;
struct Node {
	Type data;
	Node* next;
};
class Stack {
private: Node* head;
public: Stack();
	  bool Is_Empty();
	  Type Top();
	  void Push(Type Data);
	  Type Pop(
	  );
	  ~Stack();
};
Stack::Stack() {
	head = NULL;
}
bool Stack::Is_Empty() {
	return head == NULL;
}
Type Stack::Top() {
	if (!Is_Empty())
		return head->data;
	return NULL;
}
void Stack::Push(Type Data) {
	Node* newNode;
	newNode = new Node;
	if (newNode == NULL) {
		cout << endl << "Stack is full";
		return;
	}
	newNode->data = Data;
	newNode->next = head;
	head = newNode;
}
Type Stack::Pop() {
	if (Is_Empty()) {
		cout << "Stack is empty ";
		return -1;
	}
	Node* current;
	Type Data;
	current = head;
	Data = current->data;
	head = head->next;
	delete current;
	return Data;
}
Stack :: ~Stack() {
	Node* current;
	while (head != NULL) {
		current = head;
		head = head->next;
		delete head;
	}
}
class FileReader {

private:
	char expression[80];
public:
	FileReader();
	string read();
	void write_answer(int s);
	void read_ans();
	int answer = 0;
	string eq;


};
FileReader::FileReader() {
	expression[0] = '\0';
}


void FileReader::write_answer(int s) {
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
	int S_No = 0;
	char buffer[MAX];
	// character buffer
	ifstream infile("expression.txt");
	while (infile) {
		infile.getline(buffer, MAX);
		return buffer;
	}
	return 0;
}
void FileReader::read_ans() {
	system("CLS");
	const int MAX = 240; int S_No = 0;
	char buffer[MAX];
	// character buffer
	ifstream infile("answers.txt");
	while (infile){
		infile.getline(buffer, MAX);
		cout << buffer << endl;
	}
}

class PF_Solver {
private:
	Stack s;
	FileReader f0;
	string expr;
public:
	PF_Solver(string eq);
	double Calculate();
	double Operation(double N1, char Op, double N2);
};
PF_Solver::PF_Solver(string eq) {
	expr = eq;
}
double PF_Solver::Operation(double N1, char Op, double N2)
{
	switch (Op) {
	case '+': return N1 + N2;
	case '-': return N1 - N2;
	case '*': return N1 * N2;
	case '/': return N1 / N2;
	case '^': return pow(N1, N2);
	}
	return 0;
}
double PF_Solver::Calculate() {
	char e; double n1, n2, n3;
	for (unsigned int i = 0; i < expr.size(); i++) {
		e = expr[i];
		if (e == ' ' || e == '\t')
			continue;
		if (e >= '0' && e <= '9')
			s.Push(e - '0');
		else {
			n2 = s.Pop();
			n1 = s.Pop();
			n3 = Operation(n1, e, n2);
			s.Push(n3);
		}
	}
	f0.write_answer(s.Pop());
	return 0;
}

int main() {
	FileReader f1;
	string string1 = f1.read();
	PF_Solver P(string1);
	cout << "expression read from file is: " << string1 << endl;
	P.Calculate();
	f1.read_ans();
	system("PAUSE");
	return 0;
}