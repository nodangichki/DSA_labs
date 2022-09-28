#include <iostream>
using namespace std;
const int MAX = 100;
class String {
private:s
	char str[MAX];
public:
	String();
	String(const char*);
	void Insert(int pos, char ch);
	void Del(int pos);
	void Print();
	void Println();
	int Search(char ch);
	String SubString(int start, int end);
};
String::String() {
	str[0] = &#39; \0 & #39;;
}
String::String(const char* s) {
	int i = 0;
	for (; s[i]; i++) {
		str[i] = s[i];
	}
	str[i] = &#39; \0 & #39;;
}
// inserts a character at given position position
void String::Insert(int pos, char ch) {
	// Shift elements to right
	int i = MAX - 1;
	for (; i & gt; pos; i--)
		str[i] = str[i - 1];
	str[i] = ch;
}
// deletes an element from the given position position
void String::Del(int pos) {
	// skip to the desired position
	int i = pos;
	for (; str[i]; i++)
		str[i] = str[i + 1];
}

Lab 1: String OperationsPage 7
// searches String for a given element character
int String::Search(char ch) {
	// Traverse the String
	int i = 0;
	for (; i & lt; MAX; i++) {
		if (str[i] == ch) {
			return i; // return character position
		}
	}
	return -1;
}
// Returns Substring
String String::SubString(int start, int total_characters) {
	String temp;
	int i = start;
	int end = start + total_characters;
	for (; i & lt; end & amp; &amp; i & lt; MAX; i++) {
		temp.str[i - start] = str[i];
	}
	temp.str[i - start] = &#39; \0 & #39;;
	return temp;
}
// displays the contents of a String
void String::Print() {
	cout& lt; &lt; str;
}
void String::Println() {
	cout& lt; &lt; str& lt; &lt; endl;
}
void main()
{
	String str1(&quot; 0123456789 & quot;);
	String str2(&quot; Ali & quot;); str2.Println();
	str2.Insert(0, &#39; &#39;);
	str2.Insert(0, &#39; M & #39;); str2.Println();
	str2.Del(2); str2.Println();
	str2.Insert(2, &#39; A & #39;); str2.Println();
	String str3 = str1.SubString(5, 3);
	str3.Println();
}