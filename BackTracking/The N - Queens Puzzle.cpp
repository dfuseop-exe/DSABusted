bool isSafe(int col , int row , vector<vector<int>> &board , int n){
        int x = row ;
        int y = col ;
        
        //check for same row 
        while(y >= 0){
            if(board[x][y] == 1){
                return false ;
            }
            y-- ;
        }
        
        x = row ;
        y = col ;
        
        //check for upward diagonal 
        while(y >= 0 && x >= 0){
            if(board[x][y] == 1){
                return false ;
            }
            y-- ;
            x-- ;
        }
        
        x = row ;
        y = col ;
        
        //check for dowmward diagonal 
        while(y >= 0 && x < n){
            if(board[x][y] == 1){
                return false ;
            }
            y-- ;
            x++ ;
        }
        
        
        return true ;
        
    }
    
    void addSolution(vector<vector<int>> &board , vector<vector<int>> &ans , int n){
        //ans madhe different different ans solution store karaychet so new vector create krun tyat traverse valur store karun te ans madhe store karav lagel
        
        vector<int> temp ;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                temp.push_back(board[i][j]) ;
            }
        }
        
        //ek solution ans madhe store kel
        ans.push_back(temp) ;
    }

    //by reference coz recursive call madhe state lagnar next function call sathi
    //function  is use to solve for one col remaining will solved by recursion
    void solve(int col , vector<vector<int>> &board , vector<vector<int>> &ans , int n){
        //base case  col traverse
        if(col == n){
            //last la solution  add karav lagel board la traverse karun
            addSolution(board , ans , n) ;
            //back track krun different combination try karun pahav lagel
            return ;
        }
        
        //ek case solve for first col 
        for(int row = 0 ; row < n ; row++){
            if(isSafe(col , row , board , n)){
                //safe aahe tr queen la place kara
                board[row][col] = 1 ;
                //remaining board sathi call
                solve(col+1 , board , ans , n) ;
                //back track 
                board[row][col] = 0 ;
            }
        }
    }
vector<vector<int>> nQueens(int n)
{
	         //n = size that is board is (n*n) size
        
        //step - 1 - create a (n*n) board 
        vector<vector<int>> board (n , vector<int> (n,0)) ;
        
        //step - 2 - create ans vector which store different ans combination from the board 
        vector<vector<int>> ans ;
        
        //recursive function to solve problem we have to process just one col remaining will solved  by recursion
        solve( 0 , board , ans , n) ;
        
        return ans ;
	
}