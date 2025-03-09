#include <bits/stdc++.h>
using namespace std;

struct Node {
    int exp;
    int coeff;
    Node* next;
    Node(int c, int e) {
        this->coeff = c;
        this->exp = e;
        this->next = nullptr;
    }
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() {
        head = nullptr;
    }

    void insert(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);
        if (!head || head->exp < exp) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->exp > exp) {
            curr = curr->next;
        }
        if (curr->exp == exp) {
            curr->coeff += coeff;
        } else {
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    void input(int n) {
        for (int i = 0; i < n; i++) {
            int coeff, exp;
            cout << "Enter coefficient and exponent: ";
            cin >> coeff >> exp;
            insert(coeff, exp);
        }
    }

    void output() {
        Node* curr = head;
        if (!curr) {
            cout << "Polynomial is empty" << endl;
            return;
        }
        while (curr) {
            cout << curr->coeff << "x^" << curr->exp;
            if (curr->next) {
                cout << " + ";
            }
            curr = curr->next;
        }
        cout << endl;
    }

    Polynomial add(Polynomial& other) {
        Node* head1 = head;
        Node* head2 = other.head;
        Polynomial result;
        while (head1 || head2) {
            if (head1) {
                result.insert(head1->coeff, head1->exp);
                head1 = head1->next;
            }
            if (head2) {
                result.insert(head2->coeff, head2->exp);
                head2 = head2->next;
            }
        }
        return result;
    }

    Polynomial subtract(Polynomial& other) {
        Node* head1 = head;
        Node* head2 = other.head;
        Polynomial result;
        while (head1 || head2) {
            if (head1) {
                result.insert(head1->coeff, head1->exp);
                head1 = head1->next;
            }
            if (head2) {
                result.insert(-head2->coeff, head2->exp);
                head2 = head2->next;
            }
        }
        return result;
    }

    void readFile(ifstream& file) {
        int n;
        if (!(file >> n)) {
            cout << "Error reading size" << endl;
            return;
        }
        for (int i = 0; i < n; i++) {
            int coeff, exp;
            if (!(file >> coeff >> exp)) {
                cout << "Error reading coefficient or exponent" << endl;
                return;
            }
            insert(coeff, exp);
        }
    }

    void writeFile(ofstream& file) {
        Node* curr = head;
        bool first = true;
        while (curr) {
            if (!first && curr->coeff > 0) {
                file << " + ";
            }
            if (curr->exp == 0) {
                file << curr->coeff;
            } else if (curr->exp == 1) {
                file << curr->coeff << "x";
            } else {
                file << curr->coeff << "x^" << curr->exp;
            }
            first = false;
            curr = curr->next;
        }
        file << endl;
    }
};

int main() {
    Polynomial poly1, poly2;

    int n1, n2;
    cout << "Enter number of terms for Polynomial 1: ";
    cin >> n1;
    poly1.input(n1);

    cout << "Enter number of terms for Polynomial 2: ";
    cin >> n2;
    poly2.input(n2);

    cout << "Polynomial 1: ";
    poly1.output();

    cout << "Polynomial 2: ";
    poly2.output();

    Polynomial sum = poly1.add(poly2);
    cout << "Sum of polynomials: ";
    sum.output();

    Polynomial diff = poly1.subtract(poly2);
    cout << "Difference of polynomials: ";
    diff.output();

    return 0;
}