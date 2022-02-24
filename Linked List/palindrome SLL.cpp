
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head-> next == NULL) return true ;

        
        vector<int> arr ;
        
        while(head != NULL){
            int data = head->val ;
            arr.push_back(data);
            head = head-> next ;
        }
        
        int start = 0 ;
        int end = arr.size()-1 ;

        
        while(start < end){
            
            if(arr[start] != arr[end]){
                return false ;
            }
            start++ ;
            end-- ;
        }
        
        return true ;
    }
};