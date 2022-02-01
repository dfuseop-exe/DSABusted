#include <iostream>
#include <string>
using namespace std;

class Human {

    public:
        int height ;
        int weight ;
        int age ;

        void setData(int height, int weight, int age){
            this->height = height;
            this->weight = weight;
            this->age = age;
        }

        void AmbiguityFunction(){
            cout<<"Ambiguity Function from Human"<<endl;
        }
};


class Men : public Human{
    public:
        string name ;

        void setName(string name){
            this->name = name;
        }

        void getAllData(){
            cout << this->name << endl;
            cout << this->height << endl;
            cout << this->weight << endl;
            cout << this->age << endl;
        }

                void AmbiguityFunction(){
            cout<<"Ambiguity Function from Men"<<endl;
        }
};

int main(){
    Men Sushant;
    Sushant.setData(6 , 64 , 21);
    Sushant.setName("Sushant");
    Sushant.getAllData();

    cout<<endl;
    cout<<endl;

    Sushant.Human::AmbiguityFunction();

}