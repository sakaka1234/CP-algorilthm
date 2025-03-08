#include <bits/stdc++.h>
using namespace std;
struct Student{
    string name;
    int day, month, year;
    
    float mMath;
    float mPhysic;
    float mEnglish;
    Student *next;

};
Student *L;
void input(Student *&A){
    Student *P,*C;
    string name;
    int day, month, year;
    float mMath;
    float mPhysic;
    float mEnglish;
    char choose;
    do{
        P = new Student;
        cout << "Enter name:" << endl;
        getline(cin,name);
        cout << "Enter birthday:" << endl;
        cin >> day >> month >> year;
        cout << "Enter points of subjects:" << endl;
        cin >>mMath >> mPhysic >> mEnglish;
        P->name = name;
        P-> day = day; P->month = month; P->year = year;
        P-> mMath = mMath ; P-> mPhysic = mPhysic; P-> mEnglish = mEnglish;
        if(A == nullptr){
            A = P;
            C = P;
        }else{
            C->next = P;
            C =P;
        }
        cout << "Continue ?" << endl;
        cin >> choose;
        cin.ignore();
    }while(choose == 'y' || choose == 'Y');

}
void output(Student *&A){
    Student *P;
    P = A;
    while(P != nullptr){
        cout << P->name << " " << P->day << " / " << P->month
             << " / " << P->year << " " << P->mMath << " " << P->mPhysic << " " << P->mEnglish << endl;
        P = P->next;
    }
}
Student *TK(int n, Student *&A){
    Student *P;
    P = A;
    int i = 1;
    while(P != nullptr && i < n){
        P = P->next;
        i++;
    }
    return P;
}
void add(Student *&A,int n,string name,int day ,int month, int year, float mMath , float mPhysic, float mEnglish){
    Student *P,*Q;
    P = new Student;
    P->name = name;
    P-> day = day; P->month = month; P->year = year;
    P-> mMath = mMath ; P-> mPhysic = mPhysic; P-> mEnglish = mEnglish;
    P->next = nullptr;
    if(n==1){
        P->next = A;
        A = P;    
    }else{
        Q = TK(n-1,A);
        if(Q == nullptr){
            cout<< "Error" << endl;
        }else{
            P->next = Q->next;
            Q->next = P;
        }
    }
}

int main(){
    L = nullptr;
    input(L);
    output(L);
    add(L,2,"Tran Thien Phuc",23,12,2006,10,10,10);
    cout << "List after adding" << endl;
    output(L);
}