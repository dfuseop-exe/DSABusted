
class Solution {
    private:
    ListNode* solve(ListNode* head){
        
        if(head == NULL){
            return head ;
        }
        
        ListNode* slow = head ;
        ListNode* fast = head ;
        
        while(fast != NULL){
            fast = fast-> next ;
            
            if(fast != NULL){
                fast = fast-> next ;
            }
            
            slow = slow-> next ;
            
            
            if(fast == slow){
                return slow ;
            }
        }
        
        return NULL;
    }
public:
    bool hasCycle(ListNode *head) {
        if(solve(head) != NULL){
            return true;
        }else{
            return false;
        }
    }
};