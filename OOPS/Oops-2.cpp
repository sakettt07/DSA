// Going to study about the Shallow and the Deep copy.
// Till the time we are using the static memory allocation we will not be getting any problem as memory stack will be used.
#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
    string name;
    // double cgpa;     instead of storing it statically we will be storing it dynamically.
    double* cgpaPtr;
    Student(string name,double cgpa){
        this->name=name;
        cgpaPtr=new double;
        *cgpaPtr=cgpa;
    }
    // Student(Student &obj){
    //     this->name=obj.name;
    //     cgpaPtr=new double;
    //     *cgpaPtr=*obj.cgpaPtr;


    // }

    // Destructor 
    // Destructor only deletes the statically allocated memory.
    // to delet the dynamically allocated memory we will be using the delete ptr.
    ~Student(){
        cout<<"Hey i am the destructor lets delete everything..."<<endl;
        delete cgpaPtr;
    }
    void getInfo(){
        cout<<"name: "<<name<<endl;
        cout<<"cgpa: "<<*cgpaPtr<<endl;
    }
};

int main(){
    Student s1("Saket",9.0);
    s1.getInfo();

    // All for understanding the shallow and the deep copy. 

    // Student s2(s1);
    // cout<<"These are the details of the student-->"<<endl;
    // s2.name="Ravi";
    // *(s2.cgpaPtr)=9.5;
    // s2.getInfo();

return 0;
}