class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mpp;
        int ans = 0 ;
        
        //store count of rows
        for(int i = 0 ; i < grid.size() ; i++){
            mpp[grid[i]]++ ;
        }
        
        
        //take a col and check occurence of that col in map
        for(int i = 0 ; i < grid.size() ; i++){
            vector<int> col ;
            
            for(int j = 0 ; j < grid.size() ; j++){
                col.push_back(grid[j][i]) ;
            }
            
            //store total occurence
            ans+= mpp[col] ;
        }
        
        return ans ;
    }
};