class Solution
{
    void inorderTraversal(Node* root , vector<int>& v ){
        //base case
        if(root == NULL){
            return ;
        }
        
        inorderTraversal(root-> left , v) ;
        v.push_back(root-> data) ;
        inorderTraversal(root-> right , v) ;
    }
    
    vector<int> meargeTwoVector(vector<int> nums1 , vector<int> nums2 ){
        
            vector<int> ans(nums1.size() + nums2.size()) ;
            
            int i = 0;
            int j = 0;
            int k = 0;
            
            int m = nums1.size() ;
            int n  = nums2.size() ;
        
            while(i < m && j < n){
                if(nums1[i] < nums2[j]){
                    ans[k] = nums1[i];
                    i++;
                    k++;
                }else{
                    ans[k] = nums2[j];
                    k++;
                    j++;
                }
            }
            while(i<m){
                ans[k] = nums1[i];
                i++;
                k++;
            }
            while(j<n){
                ans[k] = nums2[j];
                j++;
                k++;
            }  
        

        return ans ;
    }
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
           vector<int> v1 ;
           vector<int> v2 ;
            
           //step 1
           //Inorder Traversal
           inorderTraversal(root1 , v1) ;
           inorderTraversal(root2 , v2) ;
           
           
           //step 2
           //mearge both vectors
           
           return meargeTwoVector(v1,v2) ;
           
    }
};