#include <iostream>  
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
    //int  i, arr[] = { 38, 27, 43, 3, 9, 82, 10 };
    string names[] = { "nodan","gichki","baloch","quetta","islamabad" };
    int sz = sizeof(names) / sizeof(names[0]);
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



