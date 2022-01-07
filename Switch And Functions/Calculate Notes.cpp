#include<iostream>
using namespace std;

int main(){
   int amount ;
   cout<<"Enter Amount "<<endl;
   cin>>amount;
   
   int rem = 0;
   
   switch (1)
   {
   case 1:
      cout<<"100$ :- "<<amount/100<<endl;
      rem = amount % 100;
   
   case 2:
      cout<<"50$ :- "<<rem/50<<endl;
      rem = rem % 50;
   
   case 3:
      cout<<"20$ :- "<<rem/20<<endl;
      rem = rem % 20;

   case 4:
      cout<<"1$ :- "<<rem/1<<endl;
      rem = rem % 1;
   }
}