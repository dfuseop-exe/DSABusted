class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root ;
        while(curr != NULL){
            
            //check morris traversal logic 
            if(curr-> left){
                Node* pred = curr-> left ;
                
                while(pred-> right){
                    pred = pred-> right ;
                }
                
                pred-> right = curr-> right ;
                curr-> right = curr-> left ;
                
                //mark null 
                curr-> left = NULL ;
                
            }
            
            //take to next as left is now pointing null morris trversal says go right
            curr = curr-> right ;
        }
    }
};