// Will be studying inherirance which is one of the important pillar of the object oriented programming in c++.

// protected -- Sirf inheritance k liye pass karana h inhe
#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(string name, int age)
    {
        // cout<<"I am the Person class constructor..."<<endl;
        this->name = name;
        this->age = age;
    }
};
// inheritance mode of inheritance.(public)
class Student : public Person
{
public:
    int rollno;
    // to define the type in the student is not necessary for the parent.(only when defining)
    Student(string name, int age, int rollno) : Person(name,age)
    {
        // cout<<"I am the student class constructor..."<<endl;
        this->rollno = rollno;
    }
    void getInfo()
    {
        cout << "name:" << name << endl;
        cout << "age:" << age << endl;
        cout << "rollno:" << rollno << endl;
    }
};
int main()
{
    Student s1("Saket",21,1234);
    // s1.name = "saket";
    // s1.age = 21;
    // s1.rollno = 035;
    s1.getInfo();

    return 0;
}