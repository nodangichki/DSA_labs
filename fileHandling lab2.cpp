#include <iostream>
#include <fstream> // for file streams
using namespace std;
const int MAX = 200;
class Book {
private:
	char title[80];
	char auther[80];
	double price;
public:
	Book();
	void Add();
	void Read_All();
	void Search(string item);
	void Del(int R_no);
	void Update(int R_no);
};
Book::Book() {
	title[0] = '\0';
	auther[0] = '\0';
	price = 0.0;
}
void Book::Add() {
	cout << "Enter title : ";
	// eat chars, including newline
	cin.ignore(80, '\n');
	cin.getline(title, 80);
	cout << "Enter Auther : "; cin.getline(auther, 80);
	cout << "Enter Price : "; cin >> price;
	cout << "Following data has been entered" << endl;
	cout << "Title = " << title << endl;
	cout << "Auther = " << auther << endl;
	cout << "Price = " << price << endl;
	ofstream outfile;
	// open file in append mode
	outfile.open("books.txt", std::ios_base::app);
	outfile << title << "\\" << auther << "\\" << price << endl;
	system("pause");
}
void Book::Read_All() {
	system("CLS");
	const int MAX = 240; int S_No = 0;
	char buffer[MAX];
	// character buffer
	ifstream infile("books.txt");
	while (infile) {
		infile.getline(buffer, MAX);
		 cout << buffer<< endl;
		if (strlen(buffer) > 0) {
			const char* delim = "\\";
			char* next_token;
			char* title = strtok_s(buffer, delim, &next_token);
			char* auther = strtok_s(NULL, delim, &next_token);
			char* prc = strtok_s(NULL, delim, &next_token);
			cout << "#" << ++S_No << endl;
			cout << " Title = " << title << endl;
			cout << " Auther = " << auther << endl;
			cout << " Price = " << prc << endl;
		}
	}
}
//my added functions
void Book::Search(string item) {
	system("CLS");
	const int MAX = 240;
	char buffer[MAX];
	ifstream infile("books.txt");
	while (infile) {
		infile.getline(buffer, MAX);
		if (strlen(buffer) > 0) {
			const char* delim = "\\";
			char* next_token;
			char* title = strtok_s(buffer, delim, &next_token);
			char* auther = strtok_s(NULL, delim, &next_token);
			char* prc = strtok_s(NULL, delim, &next_token);
			//searching 
			if (item == title || item == auther || item == prc) {
				cout << "Item found! " << endl;
				cout << " Title = " << title << endl;
				cout << " Auther = " << auther << endl;
				cout << " Price = " << prc << endl;
				cout << endl << endl << endl;
				break;
			}
			else {
				cout << "item not found in the records!" << endl;
				break;
			}
		}
	}
}
void Book::Del(int R_no) {
	system("CLS");
	char choice;
	int S_no = 0;
	const int MAX = 240;
	char buffer[MAX];
	ifstream infile("books.txt");
	ofstream outfile("temp.txt");
	while (infile) {
		infile.getline(buffer, MAX);
		if (strlen(buffer) > 0) {
			const char* delim = "\\";
			char* next_token;
			char* title = strtok_s(buffer, delim, &next_token);
			char* auther = strtok_s(NULL, delim, &next_token);
			char* prc = strtok_s(NULL, delim, &next_token);
			++S_no;
			if (S_no == R_no) {
				cout << "you sure about deletin dis? [y=yes, n=no]" << endl;
				cout << "S.NO: " << S_no << endl;
				cout << "title: " << title << endl;
				cout << "auther: " << auther << endl;
				cout << "Price: " << prc << endl;
				cin >> choice;
				if (choice == 'y' || choice == 'Y') {
					continue;
				}
				else
					outfile << title << "\\" << auther << "\\" << prc << endl;
			}
			else
				outfile << title << "\\" << auther << "\\" << prc << endl;

		}
		
	}
	infile.close();
	outfile.close();
	remove("books.txt");
	rename("temp.txt", "books.txt");
}
void Book::Update(int R_no) {
	system("CLS");
	char choice;
	int S_no = 0;
	const int MAX = 240;
	char buffer[MAX];
	ifstream infile("books.txt");
	ofstream outfile("temp.txt");
	while (infile) {
		infile.getline(buffer, MAX);
		if (strlen(buffer) > 0) {
			const char* delim = "\\";
			char* next_token;
			char* title = strtok_s(buffer, delim, &next_token);
			char* auther = strtok_s(NULL, delim, &next_token);
			char* prc = strtok_s(NULL, delim, &next_token);
			++S_no;

			if (S_no == R_no) {
				cout << "you sure about update this record? [y=yes, n=no]" << endl;
				cout << "S.NO: " << S_no << endl;
				cout << "title: " << title << endl;
				cout << "auther: " << auther << endl;
				cout << "Price: " << prc << endl;
				cin >> choice;
				if (choice == 'y' || choice == 'Y') {
					cout << "Enter new title : ";
					cin.ignore(80, '\n');
					cin.getline(title, 80);
					cout << "Enter new Auther : "; cin.getline(auther, 80);
					cout << "Enter new Price : "; cin >> price;

					outfile << title << "\\" << auther << "\\" << prc << endl;
				}
				else {
					outfile << title << "\\" << auther << "\\" << prc << endl;
				}
			}
			else
				outfile << title << "\\" << auther << "\\" << prc << endl;

		}
	}
	infile.close();
	outfile.close();
	remove("books.txt");
	rename("temp.txt", "books.txt");
}


int main() {
	Book my_books;
	char choice;
	char search_item[80];
	int Record_no;
	
	while (1) {
		cout << "a - Add a Book" << endl;
		cout << "r - Read All Books" << endl;
		cout << "q - Quit" << endl;
		cout << "s - Search for a record" << endl;
		cout << "d - Delete a record" << endl;
		cout << "u - Update a record" << endl;
		cin >> choice;
		switch (choice) {
		case 'a':
		case 'A':my_books.Add();
			break;
		case 'r':
		case 'R':my_books.Read_All();
			break;
		case 'q':
		case 'Q': exit(0);
		case 's':
		case 'S': {
			cout << "enter title, author or price you want to search: ";
			cin.ignore(80, '\n');
			cin.getline(search_item, 80);
			my_books.Search(search_item);
			break;
		}
		case 'd':
		case 'D': {
			cout << "enter record number: ";
			cin >> Record_no;
			my_books.Del(Record_no);
			break;
		}
		case 'u':
		case 'U': {
			cout << "enter record number: ";
			cin >> Record_no;
			my_books.Update(Record_no);
		}
		
		}
	}
	system("PAUSE");
	return 0;
}
