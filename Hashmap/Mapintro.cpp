#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    //creation of map
    unordered_map<string , int > map ;

    //insertion of map

    //1
    pair<string , int> p1 = make_pair("Sushant" , 1) ;
    map.insert(p1) ;

    //2
    //pair<string , int> p2("Sushant" , 1) ;
    //map.insert(p2) ;

    //3 
    //map["Sushant"] = 1 ; 
    //no duplicate entry for a key in map it will most recent one
    
    map["Harshal"] = 2 ;


    //searching
    cout<<map["Sushant"]<<endl;
    cout<<map.at("Harshal")<<endl;

    //if we try to access non exits key in map then

    //cout<<map.at("unknown")<<endl ; //will give error if key is not exist
    
    //will create key and give 0 as value if key is not present , it is also counted as size
    cout<<map["unknown"] <<endl ; 
    
    cout<<"Size is "<<map.size()<<endl;

    //check key is present or not
    cout<<map.count("Bro")<<endl ; //if not present it will return 0
    cout<<map.count("Sushant")<<endl ; //if present it will return 1


    //to delete 
    map.erase("Sushant") ;

    cout<<"Size is "<<map.size()<<endl;


    //iteration over map
    //1 using loop
    for(auto i : map){
        cout<<i.first<<" "<<i.second<<endl;
    }

    //iterator
    unordered_map <string , int > :: iterator it = map.begin() ;
 
    while(it != map.end()){
        cout<<it->first <<" "<< it->second<<endl;
        it++ ;
    }
}
