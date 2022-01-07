#include<iostream>
using namespace std ;

    long long int sqrtInteger(int x){
        int start = 0 ;
        int end = x ;
        long long int mid = start + (end - start) / 2 ;
        long long int ans = 0;
        
        while(start <= end){
            long long int square = (mid * mid);
            if( square == x ){
                return mid;
            }
            
            if(mid * mid < x){
                ans = mid ;
                start = mid+1;
            }else{
                end = mid -1 ;
            }
            
            mid = start + (end - start ) /2 ;
        }
        return ans;
}

double morePrecision(int num , int Precision , int TempSolution){

    double factor = 1;
    double ans = TempSolution;

    for(int i = 0 ; i < Precision ; i++){
        //this will add 0.1 , 0.2 to ans to check sqrt and if it gets greater than number then  exit from inner loop coz of condition and factor again factor / 10 = 0.1 / 10 = 0.01 again same 
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

    double TempSolution = sqrtInteger(num);
    cout<<"Answer is : "<<morePrecision(num , 3 , TempSolution);
    
}

