class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue <int> maxheap ;
        vector<int> ans ;
        int cnt = 0 ;
        
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix.size() ; j++){
                ans.push_back(matrix[i][j]) ;
            }
        }

        for(int i = 0 ; i < ans.size() ; i++){
            if(i < k){
                maxheap.push(ans[i]) ;
            }
        }
        
        for(int i = k ; i < ans.size() ; i++){
            if(maxheap.top() > ans[i]){
                maxheap.pop() ;
                maxheap.push(ans[i]) ;
            }
        }
        
        return maxheap.top() ;
    }
};
