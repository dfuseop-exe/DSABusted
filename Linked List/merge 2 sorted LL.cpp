Node<int>* solve(Node<int>* first, Node<int>* second){
	//if only one data in first so attach to second 
    if(first-> next == NULL){
        first-> next = second ;
        return first ;
    }
    
    Node<int>* curr1 = first ;
    Node<int>* curr2 = second ;
    Node<int>* next1 = curr1-> next ;
    Node<int>* next2 = curr2-> next ;
    
    while((next1 != NULL) && (curr2 != NULL)){
        
        //condition 
        if((curr2-> data >= curr1-> data) && (curr2-> data <= next1-> data)){
            curr1->next = curr2 ;
            next2 = curr2-> next ;
            curr2-> next = next1 ;
            
            curr1 = curr2 ;
            curr2 = next2 ;
        }else{
            curr1 = next1 ;
            next1 = next1-> next ;
            
            if(next1  == NULL){
                curr1-> next = curr2 ;
                return first ;
            }
        }
    }

    //return first 
    return first ;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    //check if any one LL is empty 
    if(first == NULL){
        return second ;
    }
    
    if(second == NULL){
        return first ;
    }
    
    //Now find smallest head first should be small
    if(first-> data <= second->data){
        return solve(first,second);
    }else{
        return solve(second,first);
    }
}


//#Approach 2 (array merge )

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
    
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL){
            return list2 ;
        }
        if(list2 == NULL){
            return list1 ;
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy ;
        
        while(list1 != NULL && list2 != NULL){
            if(list1-> val < list2-> val){
                temp-> next = list1 ;
                temp = list1 ;
                list1 = list1-> next ;
            }else{
                temp-> next = list2 ;
                temp = list2 ;
                list2 = list2-> next ;
            }
        }
        
        while(list2 != NULL){
            temp-> next = list2 ;
            temp = list2 ;
            list2 = list2-> next ;
        }
        
        while(list1 != NULL){
            temp-> next = list1 ;
            temp = list1 ;
            list1 = list1-> next ;
        }
        dummy = dummy-> next ;
        return dummy ;
    }
};