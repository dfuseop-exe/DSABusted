
bool isSafe(int x , int y , vector < vector < int >> &arr  ,  vector<vector<int> > v , int n){
    if((x < n && x >= 0) && ((y < n && y >= 0)) && v[x][y] != 1 && arr[x][y] == 1){
        return true ;
    }else{
        return false ;
    }
}

void solve(int x ,int y ,vector < vector < int >> &arr ,v , vector < string > &ans , string path , int n)
{
    //base case
    if(x == n-1 && y == n-1){ vector<vector<int> > 
        ans.push_back(path) ;
        return ;
    }
    
    v[x][y] = 1 ;
    
    //DLRU 
    //down
    if(isSafe(x+1 , y , arr , v , n)) {
        solve(x+1 , y , arr , v ,ans , path +'D' , n ) ;
    }
    
    //left
    if(isSafe(x, y-1, arr , v , n)) {
        solve(x , y-1 , arr , v,ans  ,path + 'L' , n ) ;
    }
    
    //right
    if(isSafe(x , y+1 , arr , v , n)) {
        solve(x , y+1 , arr , v ,ans, path + 'R' , n ) ;
    }
    
    //up
    if(isSafe(x-1 , y , arr , v , n)) {
        solve(x-1 , y , arr , v,ans , path + 'U' , n ) ;
    }
    
    v[x][y] = 0 ;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector < string > ans ; 
    string path = "" ;
    
    //agar starting node hi open mahi hai to return ho jao
    if(arr[0][0] == 0){
        return ans ;
    }
    
    //visited array
    vector<vector<int> > v = arr ;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j ++){
            v[i][j] = 0 ;
        }
    }
    
    solve(0 ,0 , arr , v , ans , path , n);
    return ans ;
}


