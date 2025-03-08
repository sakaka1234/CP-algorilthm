#include <bits/stdc++.h>
using namespace std;
struct SN
{
    int so;
    SN *next;
};
SN *L;
void outPut(SN *A){
    SN *P;
    P = A;
    while(P != NULL){
        cout << "->" << P->so << endl;
        P = P->next;
    }
}
void Input(SN *&A){ 
    SN *P,*C;
    int x;
    char ch;
    do
    {
       P = new SN;
       cout << "nhap vào de ??";
       cin >> x;
       P->so = x;
       P->next = NULL;
       if(A == NULL){
        L = P;
        C = P;
       }else{
            C->next = P;
            C = P;
       } 
       cout << "Tiep ko ?(y)";
       cin >> ch;
       
    } while (ch == 'y' || ch =='Y');
    
}
SN *TK(int n, SN *A){
    SN *P;
    P = A;
    int dem = 1;
    while(P != NULL && dem < n){
        dem++;
        P = P->next;
    }
    return P;
}
void Insert(int x,int n,SN *&A){
    SN *P;
    SN *Q;
    P = new SN;
    P->so =x;
    if(n==1){
        P->next = L;
        L = P;
    }else{
        Q = TK(n-1,A);
        if(Q== NULL){
            cout << "\n vi tri ko hop le";
        }else{
            P->next = Q->next;
            Q->next = P;
        }
    }
}
void Delete(int x , int n,SN *&A ){
    SN *P;
    SN *Q;
    P = new SN;
    P->so = x;
    if (n == 1){
        P = A;
        A = P->next;
        delete(P);
    }else{
        Q = TK(n-1,A);
        if (Q == nullptr || Q->next == nullptr){
            cout << "Error" << endl;
        }else{
            P = Q->next;
            Q->next = P->next;
            delete(P);
        }
    }

}
int main(){
    L = NULL;
    Input(L);
    cout << "danh sach vua tao" << endl;
    outPut(L);
    cout << "danh sach vua chen" << endl;
    Insert(100,3,L);
    outPut(L);
    Delete(100,3,L);
    outPut(L);
    return 1;
}