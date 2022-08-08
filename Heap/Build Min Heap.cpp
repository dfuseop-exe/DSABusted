//and we are changing state of array thats why pass as reference
void heapify(vector<int>& arr , int n , int i){
    int smallest = i ;
    
    //0th based indexing
    int left = 2 * i + 1 ;
    int right = 2 * i + 2 ;
    
    //now just compare it with its child
    
    if(left <= n && arr[left] < arr[smallest]){
        smallest = left ;
    }
    
    if(right <= n && arr[right] < arr[smallest]){
        smallest = right ;
    }
    
    //now check smallest is updated or not
    if(smallest != i){
        //it means there is child having smallest element
        //so swap it
        swap(arr[smallest] , arr[i]) ;
        
        //now check further for that smallest subtree
        heapify(arr , n , smallest) ;
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size() ;
    //array ne minheap create karaychay it means we have to inplement heapify algo
    for(int i = n/2 ; i>0 ; i--){
        heapify(arr , n , i) ;
    }
    
    return arr ;
}
