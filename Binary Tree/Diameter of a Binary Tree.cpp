//Approach 1
// class Solution {
// private:
//     int maxDepth(Node* root) {
//         //base case
//         if(root == NULL){
//             return 0 ;
//         }
        
//         int leftHeight = maxDepth(root-> left) ;                              
        // int rightHeight = maxDepth(root-> right) ;
        
//         int ans = max(leftHeight,rightHeight) + 1 ;
        
//         return ans ;

//     }
//   public:
//     // Function to return the diameter of a Binary Tree.
//     int diameter(Node* root) {
//        //base case
//         if(root == NULL){
//             return 0 ;
//         }
        
//         int op1 = diameter(root-> left) ;
//         int op2 = diameter(root-> right) ;
//         int op3 = maxDepth(root-> left) + maxDepth(root-> right) + 1 ;
        
//         int ans = max(op1 , max(op2 , op3)) ;
        
//         return ans ;
//     }
// };


class Solution {
private:
    
    pair<int,int> diameterFast(TreeNode* root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0) ;
            return p ;
        }
        
        pair<int,int> left = diameterFast(root-> left) ;
        pair<int,int> right = diameterFast(root-> right) ;
        
        int Dop1 = left.first ;
        int Dop2 = right.first ;
        int Hop3 = left.second + right.second ;
        
        pair<int,int> ans ;
        ans.first = max(Dop1 , max(Dop2 , Hop3)) ;
        ans.second = max(left.second , right.second) + 1 ;
        
        return ans ;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first ;

    }
};