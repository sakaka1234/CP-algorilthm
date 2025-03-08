#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    string className;
    float mMath;
    float mPhysical;
};

vector<Student> students;


void addStudent(const string &name, const string &className, float mMath, float mPhysical) {
    Student s = {name, className, mMath, mPhysical};
    students.push_back(s);
}


int searchStudentByName(const string &name) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == name) return i;
    }
    return -1;
}


void editStudentClass(const string &name, const string &newClass) {
    int index = searchStudentByName(name);
    if (index != -1) {
        students[index].className = newClass;
    }
}


void saveToFile(const string &filename) {
    ofstream outFile(filename);
    if (outFile) {
        outFile << students.size() << "\n";
        for (const auto &s : students) {
            outFile << s.name << "\n" << s.className << "\n"
                    << s.mMath << "\n" << s.mPhysical << "\n";
        }
    }
}


void loadFromFile(const string &filename) {
    ifstream inFile(filename);
    if (inFile) {
        students.clear();
        int count;
        inFile >> count;
        inFile.ignore();
        for (int i = 0; i < count; i++) {
            Student s;
            getline(inFile, s.name);
            getline(inFile, s.className);
            inFile >> s.mMath >> s.mPhysical;
            inFile.ignore();
            students.push_back(s);
        }
    }
}


void displayAllStudents() {
    for (const auto &s : students) {
        cout << "Ten: " << s.name
             << ", Lop: " << s.className
             << ", Toan: " << s.mMath
             << ", Vat ly: " << s.mPhysical << "\n";
    }
}

int main() {
    string filename = "students.txt";
    loadFromFile(filename);
    displayAllStudents();

    
    editStudentClass("Nguyen Van A", "12A1");
    saveToFile(filename);

    cout << "\nSau khi chinh sua:\n";
    displayAllStudents();

    return 0;
}
