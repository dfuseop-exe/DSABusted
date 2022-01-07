#include<iostream>
#include<vector>
using namespace std;

int main(){
    int col = 3 , row = 3;
    int arr[row][col] = {{1,2,3} , {4,5,6} , {7,8,9}};
    vector<int> ans;
    

    //we have to print all elements of the array once so total elements are 
    int total = col * row;
    int count = 0 ;

    //index 
    int startRow = 0;
    int startCol = 0;
    int endRow = row-1;
    int endCol = col-1;


    while(count < total){
        //for start row
        
        for(int i = startCol ; count < total && i <= endCol ; i++){
            ans.push_back(arr[startRow][i]);
            count++;
            
        }
        startRow++;


        //for endCol
        for(int i=startRow ; count < total && i <= endRow ; i++){
            ans.push_back(arr[i][endCol]);
            count++;
        }
        endCol--;

        //for endRow
        for(int i = endCol ; count < total && i >= startCol ; i--){
            ans.push_back(arr[endRow][i]);
            count++;
        }
        endRow--;

        //for startCol
        for(int i = endRow ; count < total && i >= startRow ; i--){
            ans.push_back(arr[i][startCol]);
            count++;
            
        }
        startCol++;
    }

    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
}