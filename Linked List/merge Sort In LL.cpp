class Solution {
private:
    
    ListNode* middleNode(ListNode* head){
        
        ListNode* slow = head ;
        ListNode* fast = head-> next ;
        
        while(fast != NULL && fast-> next != NULL ){
            fast = fast-> next-> next ;
            slow = slow-> next ;
        }
        
        return slow ;
    }
    
    
    ListNode* mergeList(ListNode* left , ListNode* right){
        
        if(left == NULL){
            return right ;
        }
        if(right == NULL){
            return left ;
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy ;
        
        while(left != NULL && right != NULL){
            if(left-> val < right-> val){
                temp-> next = left ;
                temp = left ;
                left = left-> next ;
            }else{
                temp-> next = right ;
                temp = right ;
                right = right-> next ;
            }
        }
        
        while(right != NULL){
            temp-> next = right ;
            temp = right ;
            right = right-> next ;
        }
        
        while(left != NULL){
            temp-> next = left ;
            temp = left ;
            left = left-> next ;
        }
        dummy = dummy-> next ;
        return dummy ;
    }
public:
    ListNode* sortList(ListNode* head) {
        //base case
        if(head == NULL || head-> next == NULL){
            return head ;
        }
        
        //break into two parts
        
        ListNode* middle = middleNode(head);
        
        ListNode* left = head ;
        ListNode* right = middle-> next ;
        
        middle-> next = NULL ;
        
        
        left = sortList(left);
        right = sortList(right);
        
        ListNode* result = mergeList(left,right);
        
        return result ;
    }
};