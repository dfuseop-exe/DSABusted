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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head ;
        ListNode* prev = NULL ;
        ListNode* next = NULL ;
        
        while(curr != NULL){
            next = curr-> next ;
            curr-> next = prev ;
            prev = curr ;
            curr = next ;
        }
        
        return prev ;
    }
    
    void insertAtTail(ListNode* &head , ListNode* &tail , int val){
        
        ListNode* temp = new ListNode(val);
        //if LL is empty list
        if(head == NULL){
            head = temp ;
            tail = temp ;
            return ;
        }else{
            tail-> next = temp ;
            tail = temp ;
        }
    }
    
    ListNode* addList(ListNode* l1, ListNode* l2){
        //take carry
        int carry = 0 ;
        
        ListNode* ansHead = NULL ;
        ListNode* ansTail = NULL ;
        
        while(l1 != NULL && l2 != NULL){
            int sum = (l1-> val) + (l2-> val) + carry ;
            int digit = sum % 10 ;
            
            //insert digit ans 
            insertAtTail(ansHead,ansTail,digit);
            
            carry = sum / 10 ;
            
            l1 = l1-> next ;
            l2 = l2-> next ;
        }
        
        
        while(l1 != NULL){
            int sum = (l1-> val) + carry ;
            int digit = sum % 10 ;
            
            //insert digit ans 
            insertAtTail(ansHead,ansTail,digit);
            
            carry = sum / 10 ;
            
            l1 = l1-> next ;
        }
        
        while(l2 != NULL){
            int sum = l2-> val + carry ;
            int digit = sum % 10 ;
            
            //insert digit ans 
            insertAtTail(ansHead,ansTail,digit);
            
            carry = sum / 10 ;
            
            l2 = l2-> next ;
        }
        
        while( carry != 0){
            int sum = carry ;
            int digit = sum % 10 ;
            
            //insert digit ans 
            insertAtTail(ansHead,ansTail,digit);
            
            carry = sum / 10 ;
        }
        return ansHead ;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //step - 1 reverse LL 
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        //step - 2 add 2 numbers
        ListNode* ans = addList(l1 , l2);

        return ans ;
        
    }
};



/* 
single loop over

while(first != NULL || second != NULL || carry != 0){
            
            int firstData = 0 ;
            if(first != NULL){
                firstData = first-> data ;
            }
            
            int secondData = 0 ;
            if(second != NULL){
                secondData = second-> data ;
            }
            
            int sum = firstData + secondData + carry ;
            
            int digit = sum % 10 ;
            
            insertAtTail(ansHead , ansTail , digit);
            
            carry = sum / 10 ;
            
            if(first != NULL){
                first = first-> next ;
            }
            
            if(second != NULL){
                second = second-> next ;
            }
        }


*/