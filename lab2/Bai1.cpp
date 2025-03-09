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
class StudentList{
private:
    Student *head;
public:
    StudentList(){
        head = nullptr;

    }
    void addNewstudent(string name ,int day , int month ,int year,float math,float physic,float english){
        Student *newStudent = new Student{name,day,month,year,math,physic,english,head};
        head = newStudent;
    }
    void input(int n){
        for(int i = 0 ; i < n ; i++){
            string name;
            int day, month, year;
            float mMath;
            float mPhysic;
            float mEnglish;
            cout << "Enter name: " << endl;
            cin.ignore();
            getline(cin,name);
            cout << "Enter birth day: " << endl;
            cin >> day >> month  >> year;
            cout << "Enter points of 3 subjects  :" << endl;
            cin >> mMath >> mPhysic >> mEnglish;
            addNewstudent(name,day,month,year,mMath,mPhysic,mEnglish);
            cout << "U have entered student: " << i+1 <<endl;
            cout << "Continue to student:" << i+2 << endl;
            cin.ignore(); 
        }

    }
    void output(){
        Student *curr = head;
        if(curr == nullptr){
            cout << "None students existing" << endl;
        }
        while(curr != nullptr){
            cout << "Name: "<<curr->name << "\nBirthday: " << curr->day << "/" << curr->month << "/" << curr->year
                 << "\nMath points: " << curr->mMath << " Physic points:" << curr->mPhysic << " English points:" << curr->mEnglish << endl;
            curr = curr->next; 
        }
    }
    void searchByYear(int year){
        Student *curr = head;
        int ans = 0;
        while(curr != nullptr){
            if(curr->year == year){
                ans++;
            }
            curr = curr->next;
        }
        cout << "Number of student(s) was born in " << year <<":" << ans << endl; 
    }
    void existName(string name){
        Student *curr = head;
        bool check = false;
        while(curr != nullptr){
            if(curr->name == name){
                check = true;
                break;
            }
            curr = curr->next;
        }
        cout << (check == true? "YES": "NO") << endl;
    }
    void deleteStudent(string name){
        Student *curr = head, *prev = nullptr;
        
        if (head != nullptr && head->name == name) {
            Student *temp = head;
            head = head->next;
            delete temp;  // Giải phóng bộ nhớ
            cout << "Deleted student: " << name << endl;
            return;
        }
        
        while (curr != nullptr && curr->name != name) {
            prev = curr;
            curr = curr->next;
        }
       
        if (curr == nullptr) {
            cout << "Student not found: " << name << endl;
            return;
        }
        
        prev->next = curr->next;
        delete curr;  
        cout << "Deleted student: " << name << endl;
    }
    void biggestAverage(){
        Student *curr = head;
        if(curr == nullptr){
            cout << "None student existing" << endl;
        }
        float maxAvg = -1.0f;
        while(curr != nullptr){
            float currAvg = (curr->mMath + curr->mPhysic + curr->mEnglish)/3.0f;
            maxAvg = max(maxAvg,currAvg);
        }
        curr = head;
        int i = 0;
        while(curr != nullptr){
            float currAvg = (curr->mMath + curr->mPhysic + curr->mEnglish)/3.0f;
            if(currAvg == maxAvg){
                cout << "Student"<< i+1 <<":" + curr->name << endl;
            }
            curr = curr->next;
        }
    }
    void studentStupidAtMath(){
        Student *curr = head;
        if(curr == nullptr){
            cout << "None student existing" << endl;
        }
        int i = 0;
        while(curr != nullptr){
            if(curr->mMath < 5){
                cout << "Student " << i+1 << curr->name << endl;
            }
            curr = curr->next;
        }
    }
    void writeToFile(){
        ofstream file("studentlist.txt");
        if(!file.is_open()){
            cout << "Failed to open file" << endl;
            return;
        }
        Student *curr = head;
        if(curr == nullptr){
            file << "None student existing" << endl;
            return;
        }
        while(curr != nullptr){
            file  << "Name: "<<curr->name << "\nBirthday: " << curr->day << "/" << curr->month << "/" << curr->year
                << "\nMath points: " << curr->mMath << " Physic points:" << curr->mPhysic << " English points:" << curr->mEnglish << endl;
            curr = curr->next;
        }
        file.close();
    }
};
int main(){
    StudentList list;
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    list.input(n);

    cout << "\nStudent List:\n";
    list.output();

    cout << "\nWriting to file...\n";
    list.writeToFile();
    list.addNewstudent("Tran Thien Phuc",13,12,2005,9,9,9);
    list.output();

    return 0;

}