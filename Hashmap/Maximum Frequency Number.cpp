int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> count ;
    
    int ansFreq = 0 ;
    int maxFreq = 0 ;
    
    //map freq with that number
    for(int i = 0 ; i < n ; i++){
        //increment freq
        count[arr[i]]++ ;
        //get max
        maxFreq = max(maxFreq , count[arr[i]]) ;
    }
    
    //get ans
    for(int i = 0 ; i < n ; i++){
        if(count[arr[i]] == maxFreq){
            ansFreq = arr[i] ; //that element we have to return
            break ;
        }
    }
    
    return ansFreq ;
}