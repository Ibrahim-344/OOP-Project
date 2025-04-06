#include<iostream>
using namespace std;


class Student {
public:
    int id;
    string name;

    void printDetails() const { // notice const here
        cout << id << " " << name << endl;
    }
};
int main() {
    Student student1;
    student1.id = 1;
    student1.name = "Ibrahim";

    // Call the printDetails method
    student1.printDetails();

    return 0;
}
