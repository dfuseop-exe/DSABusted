/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private :
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head ;
        ListNode* fast = head-> next ;
        
        while(fast != NULL){
            fast = fast-> next ;
            if(fast != NULL){
                fast = fast-> next ;
            }
            
            slow = slow-> next ;
        }
        
        return slow ;
    }
    
    void deleteNode(ListNode* &node , ListNode* &head){
    
        if(node-> next == NULL){
            head-> next = NULL ;
            delete node ;
            return ;
        }else{
                      

            ListNode* nodeToDelete = node-> next ;
            node-> val = nodeToDelete-> val ;
            node-> next = nodeToDelete-> next ;
            delete nodeToDelete ;
        }
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* middle = findMiddle(head);
        
        //middle nd head same then  if we delete node then head also delete
        if(head == middle)
            return NULL;
            
        deleteNode(middle,head);
        return head ;

    }
};