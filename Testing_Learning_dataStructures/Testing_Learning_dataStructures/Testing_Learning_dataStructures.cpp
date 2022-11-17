#include<iostream>
using namespace std;

int main() {
	int sz;
	double* arr;
	cout << "enter size: "; cin >> sz;
	arr = new double[sz];
	for (int i = 0; i < sz; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < sz; i++) {
		cout << arr[i] << " ";
	}cout << endl;
}