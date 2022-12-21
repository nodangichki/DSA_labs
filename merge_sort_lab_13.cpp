#include <iostream>  
#include<string>
using namespace std;
typedef string Type;
void merge(Type a[], int low, int high, int mid) {
    int i, j, k;
    Type c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        // Compares  the elements of two subarrays and merges then
        if (a[i] < a[j]) {
            c[k] = a[i];
            k++;
            i++;
        }
        else {
            c[k] = a[j];
            k++; j++;
        }
    }
    // Copies the remaining elements of left array,if there is any
    while (i <= mid) {
        c[k] = a[i];
        k++; i++;
    }
    // Copies the remaining elements of right array,if there is any
    while (j <= high) {
        c[k] = a[j];
        k++; j++;
    }
    for (i = low; i < k; i++)
        a[i] = c[i];
}

void mergesort(Type a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergesort(a, low, mid);  // Recursion call till low<high
        mergesort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
    return;
}
int main() {
    
    int sz;
    cout << "enter number of names: ";
    cin >> sz;
   cout << endl;
    string* names = new string[sz];
    cin.ignore(200, '\n');
    for (int i = 0; i < sz; i++) {
        cout << "enter name " << i+1 << " :"; 
        getline(cin, names[i]);
    }
    cout << "before sorting : ";
    for (int i = 0; i < sz; i++)
        cout << " " << names[i];

    mergesort(names, 0, sz - 1);
    cout << "\nSorted array   : ";
    for (int i = 0; i < sz; i++)
        cout << " " << names[i];
    cout << endl;
    system("PAUSE");
    return 0;
}



