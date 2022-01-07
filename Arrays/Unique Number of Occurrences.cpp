#include<iostream>
using  namespace std;

int main(){
    int size ;
    cin>>size;
     
    int arr[size];
    

    int counter[size]={0};

    for(int i = 0 ; i<size ; i++){
        cin>>arr[i];
    }


//sort
    for(int i=0;i<size-1;i++){
    for(int j=i+1;j<size;j++){
      if(arr[j]<arr[i]){
        int temp = arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
      }
    }    
  }

//store Occurrence

    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == arr[i+1]){
            counter[j]+=1;
        }
        else{
            counter[j]+=1;
            j++;
        }
    }

//check for unique Occurrence

    bool isUnique = true ;

    for (int k = 0; k < j; k++){
        for(int z = k+1 ; z<j ; z++){
            if(counter[k] == counter[z]){
                isUnique = false;
                break;
            }
        }
    }

    cout<<isUnique<<endl;

}