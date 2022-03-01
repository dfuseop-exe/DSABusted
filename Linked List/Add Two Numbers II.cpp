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
private:
    int getLen(ListNode* head){
        ListNode* temp = head ;
        int len = 0 ;
        
        while(temp != NULL){
            temp = temp-> next ;
            len++ ;
        }
        
        return len ;
    }
    
    void insertAtHead(ListNode* &head){
        ListNode* newNode = new ListNode(0);
        
        if(head == NULL){
            newNode = head ;
        }
        else{
            newNode-> next = head ;
            head = newNode ;
        }
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
    void print(ListNode* &head){
    ListNode* temp = head ;

    while(temp != NULL){
        cout<<temp-> val<<" ";
        temp = temp-> next ;
    }cout<<endl;
}
    
ListNode* reverse(ListNode* head){
    ListNode* prev = NULL ;
    ListNode* curr = head ;
    ListNode* next = NULL ;
    
    while(curr != NULL){
        next = curr-> next ;
        curr-> next =  prev ;
        prev = curr ;
        curr = next ;
    }
    return prev ;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //step - 1 find len 
        int len1 = 0 ;
        int len2 = 0 ;
        
        len1 = getLen(l1) ;
        len2 = getLen(l2) ;
        
        int maxLen = max(len1 , len2);
       
        if(maxLen == len1){
            
            while(len2 < len1){
                insertAtHead(l2);
                len2++ ;
            }
        }else{
            while(len1 < len2){
                insertAtHead(l1);
                len1++;
            }
        }
        
        l1 = reverse(l1) ;
        l2 = reverse(l2) ;
         
        ListNode* ans = addList(l1 , l2);
        
        ans = reverse(ans) ;
        return ans ;
    }
};