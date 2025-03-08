#include <bits/stdc++.h>
using namespace std;


void inputRandomData(vector<int> *arr, int size) {
    srand(time(0)); 
    arr->clear();
    for (int i = 0; i < size; i++) {
        arr->push_back(rand() % 100); 
    }
}


void printArray(const vector<int> *arr) {
    cout << "Mang gồm " << arr->size() << " phan tử: ";
    for (int num : *arr) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    int size;
    cout << "Nhap kich thưoc mang: ";
    cin >> size;

    vector<int> *arr = new vector<int>;
    inputRandomData(arr, size);
    printArray(arr);

    
    return 0;
}
