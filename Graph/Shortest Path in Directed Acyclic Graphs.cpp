#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<limits.h>

using namespace std;

class Graph{
    public:
        unordered_map<int , vector<pair<int , int> > > adj ;
        void addEdge(int u , int v , int w){
            pair<int , int> p = make_pair(v , w) ;
            adj[u].push_back(p) ;
        }

        void printGraph(){
            for(auto i : adj){
                cout<<i.first<<" -> " ;
                for(auto j : i.second){
                    cout<<"[ "<<j.first<<","<<j.second<<" ]"<<" " ;
                }
                cout<<endl;
            }
        }

        //dfs
        void findTopology(int src , vector<bool> &visited ,stack<int> &st ){
            visited[src] = true ;

            for(auto i : adj[src]){
                if(!visited[i.first]){
                    findTopology(i.first , visited , st) ;
                }
            }

            st.push(src);
        }

        void getShortestPath(int src , vector<int> &distance ,stack<int> &st){
            distance[src] = 0 ;

            while(!st.empty()){
                int top = st.top();
                st.pop();

                if(distance[top] != INT_MAX){
                    for(auto i : adj[top]){
                        if( distance[top] + (i.second) < distance[i.first] ){
                            distance[i.first] = distance[top] + (i.second) ;
                        }
                    }   
                }
            }
        }
};

int main(){

    //step 1 - create adjcency list
    Graph g ;
    g.addEdge(0,1,5) ;
    g.addEdge(0,2,3) ;
    g.addEdge(1,2,2) ;
    g.addEdge(1,3,6) ;
    g.addEdge(2,3,7) ;
    g.addEdge(2,4,4) ;
    g.addEdge(2,5,2) ;
    g.addEdge(3,4,-1) ;
    g.addEdge(4,5,-2) ;

    g.printGraph();

    //step 2 - Topological sort
    vector<bool> visited(6,false) ;
    stack<int> st ;

    for(int i = 0 ; i < 6 ; i++){
        if(!visited[i]){
            g.findTopology(i , visited , st) ;
        }
    }

    //step 3 - create distance vector with infinite distance
    vector<int> distance(5) ;
    for(int i = 0 ; i < 6 ; i++){
        distance[i] = INT_MAX ;
    }

    //step 4 - initialise distance of src to 0  as node 1 -> node 1 distance always 0
    int src = 1 ;

    //step 5 - distance calc
    g.getShortestPath(src , distance , st) ;
    
    cout<<endl<<"printing distance vector "<<endl ;
    for(int i = 0 ; i < 6 ; i++){
        cout<<distance[i]<<" ";
    }

}