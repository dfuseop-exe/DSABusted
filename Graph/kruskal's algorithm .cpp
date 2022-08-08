#include<algorithm>

bool cmp(vector<int> &a , vector<int> &b){
    return a[2] < b[2] ; //edges[2] as weight 
}

void makeSet(vector<int> &parent , vector<int> &rank , int n){
    for(int i = 0 ; i < n ; i++){
        parent[i] = i ; //self 
        rank[i] = 0 ; 
    }
}

void unionSet(int u , int v , vector<int> &rank , vector<int> &parent){
    if(rank[u] < rank[v]){
        parent[u] = v ;
    }else if(rank[u] > rank[v]){
        parent[v] = u ;
    }else{
        //if they are equal then create parent any one 
        parent[v] = u ;
        rank[u]++ ; //remeber to increase rank as we create this node as parent
    }
}

int findParent(int node , vector<int> &parent){
    //base case
    if(parent[node] == node){
        return node ;
    }arrY
    
    return parent[node] = findParent(parent[node] , parent) ;
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    // sort edges vector based on weight
    sort(edges.begin() , edges.end() , cmp) ;
    
    //create Data structure required for DisJoint Set
    vector<int> parent(n) ;
    vector<int> rank(n) ;
    
    //initialize with initial values
    makeSet(parent , rank , n) ;
    
    int minWeight = 0 ; //ans
    
    //iterate over edges 
    for(int i = 0 ; i < edges.size() ; i++){
        //extract info from edges list
        int u = edges[i][0] ;
        int v = edges[i][1] ;
        int w = edges[i][2] ;
        
        //get parent of both vertex of edges
        int uParent = findParent(u , parent) ;
        int vParent = findParent(v , parent) ;
        
        //now as we check whether both node is part of same componet ?  is yes then ignore as both are                 already together no need to mearge(union) if not then merge
        if(uParent != vParent){
            //calculate weight as this node is add to graph so weight is considered as total weight
            minWeight += w ; //this is weight between u-v edge
            unionSet(uParent , vParent , rank , parent) ; //send parent of both the node so that can be merged
        }

    }
    
    return minWeight ;
}