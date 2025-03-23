#include<iostream>
using namespace std;

class Student {
    public:
        string name;
        int age;
        int roll_no;
        void display() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Roll No: " << roll_no << endl;
        }
};
void display(Student s) {
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "Roll No: " << s.roll_no << endl;
}
void display(Student *s) {
    cout << "Name: " << s->name << endl;
    cout << "Age: " << s->age << endl;
    cout << "Roll No: " << s->roll_no << endl;
}
int main() {
    Student s1;
    s1.name = "Ibrahim";
    s1.age = 20;
    s1.roll_no = 101;
    s1.display();
    display(s1);
    display(&s1);
    return 0;
}

 // Output
 // Name: John
