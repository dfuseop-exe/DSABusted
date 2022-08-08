#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Graph {
    public:
        unordered_map<int , vector<int> > adj ;

        void addEdge(int u , int v , bool direction){
            // direction 0 -> undirected graph
            // direction 1 -> directed graph

            //create a edge between v nd u   
            adj[v].push_back(u);  

            //check is it is directed undirected graph 
            if(direction == 0){
                adj[u].push_back(v);
            }
    
        void printGraph(){
            for(auto i:adj){ 
                cout<<i.first<<"-> ";
                for(auto j : i.second){
                    cout<<j<<" , " ;
                }
                cout<<endl;
            }
        }
};

int main(){
    cout<<"Enter number of edges"<<endl;
    int edge ;
    cin>>edge ;

    Graph g ;

    for(int i = 0 ; i <edge ; i++){
        int u , v ;
        cin>> u >> v ;
        g.addEdge(u , v , 0) ;
    }

    g.printGraph();
}

