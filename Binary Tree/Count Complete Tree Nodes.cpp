class Solution {
    private:
    void count(TreeNode* root , vector<int>& ans){

        //base condition
        if(root == NULL){
            return ;
        }

        ans.push_back(root-> val);
        count(root-> left , ans) ;
        count(root-> right , ans) ;
    }
public:
    int countNodes(TreeNode* root) {
        vector<int> ans ;
        count(root , ans) ;
        int size = ans.size();
        return size ;
    }
};


//2 

class Solution {
    private:
    void count(TreeNode* root , int &ans){

        //base condition
        if(root == NULL){
            return ;
        }

        ans++ ;
        count(root-> left , ans) ;
        count(root-> right , ans) ;
    }
public:
    int countNodes(TreeNode* root) {
        int ans = 0;
        count(root , ans) ;
        return ans ;
    }
};