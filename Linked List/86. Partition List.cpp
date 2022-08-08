class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> lessOrder ;        
        vector<int> maxOrder ;

        ListNode* temp = head ;
        while(temp != NULL){
            int ele = temp-> val ;
            if(ele < x){
                lessOrder.push_back(ele) ;
            }else{
                maxOrder.push_back(ele) ;
            }
            temp = temp-> next ;
        }
        
        for(int i = 0 ; i < maxOrder.size() ; i++){
            lessOrder.push_back(maxOrder[i]) ;
        }
        
        temp = head ;
        int i = 0 ;
        while(temp != NULL){
            temp-> val = lessOrder[i] ;
            i++ ;
            temp = temp-> next ;
        }
        
        return head ;
    }
};

//optimised

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before_head = new ListNode(0); 
        ListNode* before = before_head ;
        ListNode* after_head = new ListNode(0);
        ListNode* after = after_head ;

        ListNode* temp = head ;
        while(temp != NULL){
            
            if(temp-> val < x){
                before-> next =   temp ;
                before = before-> next ;
            }else{
                after->next = temp ;
                after = after-> next ;
            }
            
            temp = temp-> next ;
        }
        
        //join 
        before-> next = after_head-> next ;
        
        after-> next = NULL ;
        
        return before_head-> next ;
    }
};