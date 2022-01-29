#include<iostream>
using namespace std;

class Student {
    private :
        int value;
        static int data;
    public :

        static void StaticFunction (){
            data = 70;
            cout<<data<<endl;
        }

        Student(){
             cout<<"Default constructor called"<<endl;
        }

        Student(int value){
            this->value = value;
        }

        void getValue(){
            cout<<value<<endl;
        }

        void setValue(int value){
            this->value = value;
        }

        ~Student(){
            cout<<"Default Destructor called"<<endl;
        }
};

int main(){
    Student s1 ;

    s1.StaticFunction();
    s1.setValue(10);
    s1.getValue();

    Student *s2 = new Student(500);
    s2->getValue();

    Student s3(*(s2));
    s3.setValue(400);
    s3.getValue();
}