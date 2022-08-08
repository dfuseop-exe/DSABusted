    bool isSafe(vector<vector<int>>& board , int row , int col , char val){
        for(int i = 0 ; i < board.size() ; i++){
            //check for row & col & 3*3 matrix 
            if(board[row][i] == val){
                return false ;
            }
            
            if(board[i][col] == val){
                return false ;
            }
            
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){
                return false ;
            }
        }
        return true ;
    }

    bool solve(vector<vector<int>>& board){
        int n = board[0].size() ;
        //iterate over all 9*9 matrix 
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){

                //check for empty space
                if(board[row][col] == 0){
                    //empty space is there so we need to try 1-9 value which is safe to place  so loop is there
                    for(int val = 1 ; val <= 9 ; val++){
                        //if the value is safe
                        if(isSafe(board ,row , col , val)){
                            
                            //place on current location
                            board[row][col] = val ;
                            
                            //aage call nd ask to recursion to solve remaining 
                            bool nextSolution = solve(board) ;
                            
                            // if ans is true means solved 
                            if(nextSolution){
                                return true ;
                            }else{
                                //not solved by prev step so back track and check with different value 1-9
                                board[row][col] = 0 ;
                            }
                        }
                    }
                    return  false;
               }
            }   
        }
        return true ;
    }

void solveSudoku(vector<vector<int>>& sudoku)
{
	 solve(sudoku) ;
}