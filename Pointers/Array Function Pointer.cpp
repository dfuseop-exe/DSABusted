#include <iostream>
using namespace std;

int PrintSum(int *arr){
    cout<<"size is  "<<sizeof(&arr)<<endl;
    cout<<"After "<<arr<<endl;

    int sum = 0;
    for(int i=0; i<6; i++){ 
        sum += i[arr];
    }
    return sum;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    cout<<"Before "<<arr<<endl;
    int sum = PrintSum(arr);
    cout<<sum<<endl;
}