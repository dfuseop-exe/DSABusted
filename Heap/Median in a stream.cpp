#include<queue>

int signum(int a , int b){
    if(a == b){
        return 0 ;
    }else if(a > b){
        return 1 ;
    }else {
        return -1 ; 
    }
}

//pass by reference coz we want prev state of all this ds to process new ele
void getMedian(int ele , priority_queue<int> &maxheap ,priority_queue<int , vector<int> , greater<int> > &minheap , int &median ){
    
    switch(signum(maxheap.size() , minheap.size())){
        //both heaps are of n size
        case 0 : {
            if(ele < median){
                maxheap.push(ele) ;
                median = maxheap.top() ;
            }else{
                minheap.push(ele) ;
                median = minheap.top() ;
            }
            break ;
        }
            
        case 1 :{
            if(ele < median){
                minheap.push(maxheap.top());
                maxheap.pop() ;
                maxheap.push(ele) ;
                median = (maxheap.top() + minheap.top()) / 2 ;
            }else{
                minheap.push(ele) ;
                median = (maxheap.top() + minheap.top()) / 2 ;
            }
            break ;
 
        }
         
        case -1 :{
            if(ele < median){
                maxheap.push(ele) ;
                median = (maxheap.top() + minheap.top()) / 2 ;
            }else{
                maxheap.push(minheap.top()) ;
                minheap.pop() ;
                minheap.push(ele) ;
                median = (maxheap.top() + minheap.top()) / 2 ;
            }
            break ;
            
        }
    }
    
}

vector<int> findMedian(vector<int> &arr, int n){
	//step 1 - insert element in queue based on value and get medium at same         point of time as it is running stream
    
    priority_queue<int> maxheap ;
    priority_queue<int , vector<int> , greater<int> > minheap ;
    int median = 0 ;
    
    vector<int> ans ;
    
    for(int i = 0 ; i< n ; i++){
        getMedian(arr[i] , maxheap , minheap , median) ;
        ans.push_back(median) ;
    }
    
    return ans ;
}
