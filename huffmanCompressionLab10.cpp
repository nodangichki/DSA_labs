#include <iostream>
#include <string>
using namespace std;
struct New_Node {
	char data;
	size_t freq;
	New_Node* left;
	New_Node* right;
	New_Node(char data, size_t freq) {
		this->data = data;
		this->freq = freq;
		left = NULL;
		right = NULL;
	}
	~New_Node() {
		delete left;
		delete right;
	}
};
class Priority_Queue {
private:
	struct PQNode
	{
		New_Node* info;
		unsigned int priority;
		struct PQNode* next;
	};
	PQNode* front;
	unsigned int sz;
public:
	Priority_Queue() { front = NULL; sz = 0; }
	~Priority_Queue();
	unsigned int size() { return sz; }
	void Push(New_Node* data);
	New_Node* Top();
	void Pop();
	void Show();
};
Priority_Queue :: ~Priority_Queue() {
	PQNode* currentNode;
	while (front != NULL) {
		currentNode = front->next;
		delete front;
		front = currentNode;
	}
}
void Priority_Queue::Push(New_Node* data) {
	PQNode* newNode, * currentNode;
	newNode = new PQNode;
	newNode->info = data;
	newNode->priority = data->freq;
	newNode->next = NULL;
	if (front == NULL || data->freq < front->priority) {
		newNode->next = front;
		front = newNode;
	}
	else {
		currentNode = front;
		while (currentNode->next != NULL &&
			data->freq > currentNode->next->priority)
			currentNode = currentNode->next;
		newNode->next = currentNode->next;
		currentNode->next = newNode;
	}
	sz++;
}
New_Node* Priority_Queue::Top() {
	if (front != NULL)
		return front->info;
	return 0;
}
void Priority_Queue::Pop() {
	PQNode* currentNode;
	if (front == NULL)
		cout << "Priority Queue is Empty\n";
	else {
		currentNode = front;
		front = front->next;
		delete(currentNode);
	}
	sz--;
}
void Priority_Queue::Show() {
	for (PQNode* t = front; t != NULL; t = t->next)
		cout << t->info << " ";
	cout << endl;
}
class Huffman_Codes {
	New_Node* root;
	void Print_Code(New_Node* currentNode, string str) {
		if (currentNode == NULL)
			return;
		if (currentNode->data == '$') {
			Print_Code(currentNode->left, str + "0");
			Print_Code(currentNode->right, str + "1");
		}
		if (currentNode->data != '$') {
			cout << currentNode->data << " : " << str << "\n";
			Print_Code(currentNode->left, str + "0");
			Print_Code(currentNode->right, str + "1");
		}
	}
public:
	Huffman_Codes() {};
	~Huffman_Codes() { delete root; }
	void Generate_Huffman_Tree(char data[], size_t freq[],
		size_t size) {
		New_Node* left;
		New_Node* right;
		Priority_Queue PQ;
		for (size_t i = 0; i < size; ++i) {
			PQ.Push(new New_Node(data[i], freq[i]));
		}
		while (PQ.size() != 1) {
			left = PQ.Top();
			PQ.Pop();
			right = PQ.Top();
			PQ.Pop();
			root = new New_Node('$', left->freq + right->freq);
			root->left = left;
			root->right = right;
			PQ.Push(root);
		}
		Print_Code(PQ.Top(), "");
	}
};
int main() {
	Huffman_Codes Huff;
	//char data[] = { 'A', 'E', 'I', 'S', 'T', ' ', 'X' };
	//char data[] = { "International Islamic University Islamabad, Faculty of Engineering and Technology, Department of Electrical and Computer Engineering. " };
	char data[] = { "International Islamic University Islamabad, Faculty of Engineering and Technology, Department of Electrical and Computer Engineering. " };
	char abcs[] = { " .,ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };
	size_t freq[sizeof(abcs)];
	for (int i = 0; i < 55; i++)
		freq[i] = 0;

	for (int i = 0; i < 123; i++) {
		for (int j = 0; j < 55; j++) {
			if (data[i] == abcs[j]) {
				freq[j]++;
			}
		}
	}
	cout << "Character Frequency" << endl;

	for (int i = 0; i < 53; i++) {
		if (freq[i] > 0)
			cout << "freq of " << abcs[i] << " = " << freq[i] << endl;
	}


	
	size_t size = sizeof(abcs);
	
	cout << "---------------------" << endl;
	Huff.Generate_Huffman_Tree(abcs, freq, size);

	
		
	return 0;
}