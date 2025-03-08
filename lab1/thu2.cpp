#include <bits/stdc++.h>
using namespace std;
struct Student
{
    string Hovaten;
    string masinhvien;
    double aver;
    Student *next;
};
Student *L;
void input(Student *&A){
    Student *P,*C;
    string nameofstudent;
    string id;
    double point;
    char ch;
    do{
        P = new Student;
        cout <<"enter name:" << endl;
        getline(cin,nameofstudent);
        cout << "enter id:" << endl;
        cin >> id;
        cout << "enter average point:" << endl;
        cin >> point;
        P->Hovaten = nameofstudent;
        P->masinhvien = id;
        P->aver = point;
        P->next = NULL;
        if(A == NULL){
            L = P;
            C = P;
        }else{
            C->next = P;
            C = P;
        }
        cout << "continue ?" << endl;
        cin >> ch;
        cin.ignore();
    }while(ch == 'y' || ch == 'Y');
}

void output(Student *&A){
    Student *P = A;
    int stt = 0;
    cout << left << setw(6) << "Order" 
         << setw(20) << "Name" 
         << setw(15) << "ID" 
         << setw(18) << "Average Point" << endl;
    cout << string(59, '-') << endl; 
    while (P != NULL) {
        stt++;
        cout << left << setw(6) << stt
             << setw(20) << P->Hovaten
             << setw(15) << P->masinhvien
             << setw(18) << fixed << setprecision(2) << P->aver << endl;
        P = P->next;
    }
}
Student *Search(int n, Student *A){
    Student *P;
    P =A;
    int dem = 1;
    while(P != NULL && dem < n){
        dem++;
        P = P->next;
    }
    return P;
}
void Insert(string name,string id , double point ,int n , Student *&A){
    Student *P,*Q;
    P = new Student;
    P->Hovaten = name;
    P->masinhvien = id;
    P->aver = point;
    if(n == 1){
        P->next = L;
        L = P;
    }else{
        Q = Search(n-1,A);
        if(Q == NULL){
            cout << "Invalid Position" << endl;
        }else{
            P->next = Q->next;
            Q->next = P;
        }
    }
}
int main(){
    L = NULL;
    input(L);
    output(L);
    cout << "List after insert:" << endl;
    Insert("Tran Truong Sa","IT998",9.8,1,L);
    output(L);
}