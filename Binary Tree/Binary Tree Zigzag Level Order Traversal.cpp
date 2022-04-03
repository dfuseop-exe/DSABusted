class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //for returning ans
        vector<vector<int>> result ;
        
        //base case
        if(root == NULL){
            return result ;
        }
        
        //for LOT
        queue<TreeNode*> q ;
        q.push(root) ;
        
        //for direction
        bool leftToright = true ;
        
        
        while(!q.empty()){

            //for level traversing
            int size = q.size() ;
            vector<int> currLevel(size) ;

            for(int i = 0 ; i < size ; i++){
                
                TreeNode* frontEle = q.front() ;
                q.pop() ;
                
                //determine how to traverse
                int index = leftToright ? i : size - i - 1 ;
                
                currLevel[index] = frontEle-> val ;
                
                if(frontEle-> left){
                    q.push(frontEle-> left) ;
                }
            
                if(frontEle-> right){
                    q.push(frontEle-> right) ;
                }
            }
            
            //change flow of traverse
            leftToright = !leftToright ;
            

            result.push_back(currLevel) ;
        }
        return result ;
    }
};