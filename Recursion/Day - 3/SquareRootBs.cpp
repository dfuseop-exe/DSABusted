#include<iostream>
using namespace std ;


long long int sqrtInteger(int start ,int end , int x , int a){
    int s = start ;
    int e = end ;
    int mid = s + (e-s) / 2 ;
    int ans = a ; 
    //base case 
    if(s > e){
        return ans ;
    }

    int square = mid * mid ;
    if(square <= x){
        ans = mid;
    }

    if(square > x){
        return sqrtInteger(s , mid-1 , x , ans);
    }else{
        return sqrtInteger(mid+1 , end , x , ans );
    }

}

double morePrecision(int num , int Precision , int TempSolution){

    double factor = 1;
    double ans = TempSolution;

    for(int i = 0 ; i < Precision ; i++){
        factor = factor / 10 ;
        for(double j = ans ; (j*j) < num ; j+=factor){
            ans = j ;
        }
    }

    return ans ;
}

int main(){
    int num;
    cin>>num;

    double TempSolution = sqrtInteger(0 ,num ,num , -1);  
    cout<<"Answer is : "<<morePrecision(num , 3 , TempSolution);
}