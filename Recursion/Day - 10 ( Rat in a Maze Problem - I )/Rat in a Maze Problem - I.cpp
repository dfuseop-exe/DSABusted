
// User function template for C++

class Solution{
    
    private:
    
        bool isSafe( int x , int y ,vector<vector<int>> visited , int n ,  vector<vector<int>> &m ){
            if((x >= 0 && x < n) && (y >= 0 && y < n) && (m[x][y] == 1) && (visited[x][y] == 0)){
                return true ;
            }else{
                return false;
            }
        }
    
        void solve(vector<string> &ans , int x , int y , string path , int n , vector<vector<int>> &m , vector<vector<int>> visited){
            
            //base case
            if(x == n-1 && y == n-1){
                ans.push_back(path);
                return ;
            }
            
            //mark first position as occupied
            visited[x][y] = 1 ;
            
            
            //movement D-L-R-U
            
            //down
            
            int newX = x+1 ;
            int newY = y ;
            
            if(isSafe(newX , newY , visited , n , m)){
                path.push_back('D');
                solve(ans , newX , newY , path , n , m , visited);
                path.pop_back();
            }
            
            
            //Left
            
            newX = x;
            newY = y-1 ;
            
            if(isSafe(newX , newY , visited , n , m)){
                path.push_back('L');
                solve(ans , newX , newY , path , n , m , visited);
                path.pop_back();
            }
            
            
            //Right
            
            newX = x ;
            newY = y+1 ;
            
            if(isSafe(newX , newY , visited , n , m)){
                path.push_back('R');
                solve(ans , newX , newY , path , n , m , visited);
                path.pop_back();
            }
            
            //down
            
            newX = x-1 ;
            newY = y ;
            
            if(isSafe(newX , newY , visited , n , m)){
                path.push_back('U');
                solve(ans , newX ,newY , path , n , m , visited);
                path.pop_back();
            }
            
            
            //mark as untracked 
            visited[x][y] = 0 ;
        }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        //for storing ans
        vector<string> ans ;
        
        if(m[0][0] == 0){
            return ans;
        }
        
        
        //visited array
        vector<vector<int>> visited = m ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                visited[i][j] = 0 ;
            }
        }
        
        int srcx = 0 ;
        int srcy = 0 ;
        
        
        string path = "";
        
        solve(ans , srcx , srcy , path , n , m , visited);
        sort(ans.begin() , ans.end());
        return ans;
    }
};

    


