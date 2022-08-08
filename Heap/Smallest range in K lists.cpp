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

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        int mini = INT_MAX ;
        int maxi = INT_MIN ;
        
        //step 1 - create a minheap and push first element of all K arrays of size n
        
        priority_queue<node* , vector<node*> , campare > minheap ;
        
        for(int i = 0 ; i < k ; i++){
            
            //fetch element from input array 
            int ele = KSortedArray[i][0] ;
            
            //create new node using fetched element
            node* temp = new node(ele , i , 0) ; 
            
            //update min and max 
            mini = min(mini , ele) ;
            maxi = max(maxi , ele) ;
            
            
            //pushing node in minheap
            minheap.push(temp) ;
        }
        
        
        //update ans_start and ans_end
        
        int start = mini ;
        int end = maxi ;
        
        //step 2 - process the remaining array and find difference using different ranges
        
        while(minheap.size() > 0){
            
            //get top element to process
            node* top = minheap.top() ;
            
            //pop the top
            minheap.pop() ;
            
            //update mini value
            mini = top-> data ;
            
            //find ranges for initial stage 
            if(maxi-mini < end-start){
                //update values as it is smalllest
                end = maxi ;
                start = mini ;
            }
            
            
            //now add new item to minheap if exits n is size of kth array
            if(top->col + 1 < n){
                int ele = KSortedArray[top->row][top->col+1] ;
                //update max value
                maxi = max(maxi ,ele ) ;
                
                //add node
                
                node* next = new node(KSortedArray[top->row][top->col+1] , top->row , top->col+1) ;
                
                //push
                minheap.push(next) ;
            }
            else{
                break ;
            }
            
        }
        
        pair<int,int> ans = make_pair(start , end) ;
        return ans ;
    }
};