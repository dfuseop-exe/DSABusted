#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 10;
    vector<bool> prime(n , true);
    int count = 0;

    prime[0] = prime[1] = true;

    for(int i=2; i<n; i++){
        if(prime[i]){
            count++;

            for(int j=2*i; j<n; j=j+i){
                prime[j]=false;
            }
        }
    }

    cout<<count<<endl;
}
