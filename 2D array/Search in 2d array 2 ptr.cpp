#include<iostream>
using namespace std;

int main(){
    int col = 3 , row = 3;
    int arr[row][col] = {{1,2,3} , 
                         {4,5,6} , 
                         {7,8,9}};
    int key = 14;
    bool found = false;

    int colIndex = col-1;
    int rowIndex = 0;

    while(colIndex >= 0 && rowIndex < row){
        int element = arr[rowIndex][colIndex];
        cout<<element<<endl;
        if(element == key){
            found = true;
            break;
        }else if(element < key){
            rowIndex++;
        }else{
            colIndex--;
        }
    } 

     if(found){
        cout<<"found"<<endl;
    }else{
        cout<<"Not Found"<<endl;

    }   
}