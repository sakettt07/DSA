// Starting off with the object oriented programming for the interview process as so many of the companies are asking for it in the apptitude also.
#include<bits/stdc++.h>
using namespace std;

class Teacher{
// Implementing the access modifier.
// By default it is private in nature.
    private:
    double salary=60000;


    public:
    // properties
    string name;
    string dept;

    // methods
    void changeDept(string newDept){
        dept=newDept;
    }

    // ṣpecial setter and getter function.
    void setSalary(double s){
        salary=s;
    }
    double getSalary(){
        return salary;
    }

};

int main(){
    Teacher t1;
    t1.setSalary(20000);
    t1.getSalary();
    t1.dept="Computer Science";
    t1.changeDept("Information technology");
    cout<<"The department of the teacher is: "<<t1.dept<<endl;
    cout<<"The salary of the teacher is :"<<t1.getSalary();

return 0;
}