class Solution {
public:
    
        bool isSafe(int col , int row , vector<string> &board , int n){
        int x = row ;
        int y = col ;
        
        //check for same row 
        while(y >= 0){
            if(board[x][y] == 'Q'){
                return false ;
            }
            y-- ;
        }
        
        x = row ;
        y = col ;
        
        //check for upward diagonal 
        while(y >= 0 && x >= 0){
            if(board[x][y] == 'Q'){
                return false ;
            }
            y-- ;
            x-- ;
        }
        
        x = row ;
        y = col ;
        
        //check for dowmward diagonal 
        while(y >= 0 && x < n){
            if(board[x][y] == 'Q'){
                return false ;
            }
            y-- ;
            x++ ;
        }
        
        
        return true ;
        
    }
    

    //by reference coz recursive call madhe state lagnar next function call sathi
    //function  is use to solve for one col remaining will solved by recursion
    void solve(int col , vector<string> &board , vector<vector<string>> &ans , int n){
        //We have arranged all the queens so store ans and return
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        //ek case solve for first col 
        for(int row = 0 ; row < n ; row++){
            if(isSafe(col , row , board , n)){
                //safe aahe tr queen la place kara
                board[row][col] = 'Q' ;
                //remaining board sathi call
                solve(col+1 , board , ans , n) ;
                //back track 
                board[row][col] = '.';
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
            
        //n = size that is board is (n*n) size
        
        //step - 1 - create a (n*n) board 
         vector<string> board(n);//A single board
        string s(n,'.');//Pos in the board
        for(int i=0;i<n;i++) board[i] = s;//Initialize empty board
        
        //step - 2 - create ans vector which store different ans combination from the board 
        vector<vector<string>> ans ;
        
        //recursive function to solve problem we have to process just one col remaining will solved  by recursion
        solve( 0 , board , ans , n) ;
        
        return ans ;
        
    }
};