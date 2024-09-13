// Starting off with the object oriented programming for the interview process as so many of the companies are asking for it in the apptitude also.


// Usage of the this pointer :Points to the current object and avoid the confusion between the compiler.
#include<bits/stdc++.h>
using namespace std;

class Teacher{
// Implementing the access modifier.
// By default it is private in nature.
    private:
    double salary;


    public:
        // properties
    string name;
    string dept;
    string subject;

    // constructor
    // Non parameterized 
    Teacher(){
        dept="Inforamtion Technology.";
        cout<<"The constructor is called."<<endl;
    }

    // Parameterized
    Teacher(string n,string d,string s,double sal){
        this->name=n;
        this->dept=d;
        this->subject=s;
        this->salary=sal;
    }

    // Custom copy constructor:
    Teacher(Teacher &obj){
        cout<<"I am the default copy constructor...."<<endl;
        this->name=obj.name;
        this->dept=obj.dept;
        this->subject=obj.subject;
        this->salary=obj.salary;
    }


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
    // to get the information of the teacher.
    void getInfo(){
        cout<<"name:"<<name<<endl;
        cout<<"Dept:"<<dept<<endl;
        cout<<"subject:"<<subject<<endl;
        cout<<"salary:"<<salary;
    }

};

int main(){

    Teacher t1("aman","mechanical","theory of computation",40000);
    Teacher t2;
    // t1.setSalary(20000);
    // t1.changeDept("Information technology");
    // t1.getInfo();
    Teacher t3(t1);     //this will be the default copy constructor.
    t3.getInfo();



return 0;
}