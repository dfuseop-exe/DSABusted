class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL){
            return NULL ;
        }
        
        ListNode* curr = head ;
        
        while(curr->next != NULL){
            if(curr->val == curr->next->val){
                ListNode* nextNext = curr->next->next ;
                ListNode* nodetodelete = curr->next ;
                curr-> next = nextNext ;
                delete(nodetodelete);
            }else{
                curr = curr-> next ;
            }
        }
        
        return head ;
    }
};