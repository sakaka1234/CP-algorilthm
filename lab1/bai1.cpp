#include <bits/stdc++.h>
using namespace std;

vector<int> *ans = new vector<int>();  

void input() {
    int n;
    cin >> n;
    vector<int> *arr = new vector<int>(n); 
    for (int i = 0; i < n; i++) {
        cin >> (*arr)[i]; 
        if ((*arr)[i] % 2 == 0) {
            ans->push_back((*arr)[i]);  
        }
    }  
}

void output() {
    for (int i = 0; i < ans->size(); i++) {
        cout << (*ans)[i] << " ";
    }
    cout << "\n";
}

int main() {
    input();
    output();  
}
