//using custom heap


class node{
    public : 
        int data ;
        int row ;
        int col ;
        
        node(int data , int row , int col){
            this-> data = data ;
            this-> row = row ;
            this-> col = col ;
        }
};

//custom heap function for comparision 
class campare{
    public :
        bool operator()(node* a , node* b){
            return (a-> data > b-> data) ;
        }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //step 1 - create min heap and push first element of k arrays
        priority_queue<node* , vector<node*> , campare > minheap ;
        
        for(int i = 0 ; i < K ; i++){
            //as a node push karna hai sirf data karenge to track nhi rakh sakte
            node* tmp = new node(arr[i][0] , i , 0 ) ;
            minheap.push(tmp) ;
        }
        
        //ans vector
        vector<int> ans ;
        
        //step 2 - now pop smallest element and push in ans vector and pop pq.top() and
        //push next element of same array while(heap.size() > 0) 
        
        while(minheap.size() > 0){
            //top node
            node* tmp = minheap.top() ;
            
            //push top node value
            ans.push_back(tmp-> data) ;
            
            //pop top (smallest ele) ele
            minheap.pop() ;
            
            //get row = current array
            //get col = current ele of that array
            
            int i = tmp-> row ;
            int j = tmp-> col ;
            
            //now if next element of same array present then push it in min heap
            //agar next index is present for that array means ele exits
            if(j+1 < arr[i].size()){
                
                //create new node
                node* next = new node(arr[i][j+1] , i , j+1) ;
                minheap.push(next) ;
            }
        }
    
        return ans ;
    }
};