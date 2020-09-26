#include <iostream>

using namespace std;

class Student
{
private:
    string name;
    int cls, grade;
public:
    Student(string name, int grade, int cls):cls(cls),grade(grade),name(*new string(name)){};
    void display();
    ~Student();
};

Student::~Student()
{
    delete &name;
}

void Student::display()
{
    cout << name << "  " << grade << "  " << cls << endl;
}

int main()
{
    Student stu("mc", 2, 1);
    stu.display();
    system("pause");
    return 0;
}
