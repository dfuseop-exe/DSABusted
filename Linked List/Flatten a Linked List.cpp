/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/

Node* sortedMerge(Node* list1 , Node* list2){
		
    	//base case
    	if(list1 == NULL){
            return list2 ;
        }
        if(list2 == NULL){
            return list1 ;
        }
        
        Node* dummy = NULL ;

        if(list1-> data < list2-> data){
            dummy = list1 ;
            dummy->child = sortedMerge(list1->child ,list2);
        }else{
            dummy = list2 ;
            dummy-> child = sortedMerge(list1 ,list2->child);
        }
    
    	return dummy ;
           
}

Node* flattenLinkedList(Node* head) 
{
	//base case
    if(head == NULL || head->next == NULL){
        return head ;
    }
    
    Node* down = head ;
    Node* temp = head-> next ;
    head-> next = NULL ;
    
    Node* right = flattenLinkedList(temp);
    
    Node* mergeAns = sortedMerge(down,right);
    return mergeAns ;
}

