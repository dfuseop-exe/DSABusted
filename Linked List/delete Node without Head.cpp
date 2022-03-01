class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {

        struct Node* nodeToDelete = del->next;
        del -> data = nodeToDelete-> data ;
        del-> next = nodeToDelete-> next ;
        
        delete(nodeToDelete);
        
    }

};