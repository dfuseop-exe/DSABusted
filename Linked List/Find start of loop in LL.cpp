#include<iostream>
using namespace std;

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

void main(){
    Node* intersection = solve(head);

    Node* slow = head ;

    while(slow != intersection){
        slow = slow-> next ;
        intersection = intersection-> next ;
    }

    return slow;
}

