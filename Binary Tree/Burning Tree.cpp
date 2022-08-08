class Solution {
  private:
    //normal level order traversal with find target node in one function 
    Node* NodeToParentMapping(Node* root , map<Node*,Node*> &nodeToparent , int target ){
        Node* targetNode = NULL ;
        
        queue<Node*> q ;
        q.push(root) ;
        
        //map root node to parent as null
        nodeToparent[root] = NULL ;
        
        while(!q.empty()){
            Node* frontNode = q.front() ;
            q.pop() ;
            
            //find target
            if(frontNode-> data == target){
                targetNode = frontNode ;
            }
            
            if(frontNode-> left){
                nodeToparent[frontNode-> left] = frontNode ;
                q.push(frontNode-> left) ;
            }
            
            if(frontNode-> right){
                nodeToparent[frontNode-> right] = frontNode ;
                q.push(frontNode-> right) ;
            }
        }
        
        return targetNode ;
    }
    
    int burnTree(Node* targetNode , map<Node*,Node*> &nodeToparent){
        
        //create map for traversal visited node coz if node is visited so we have to ignore that node
        map<Node*,bool> visited ;

        //target node visited        
        visited[targetNode] = true ;
        
        queue<Node*> q ;
        q.push(targetNode) ;
        
        int times = 0 ;
        
        while(!q.empty()){
            //now process 
            int size = q.size() ;
            
            //for checking any change happen or not
            bool flag = false ;
            
            //coz har ek neighboring nodes ke liye process karna hai of frontnode
            for(int i = 0 ; i < size ; i++){
                Node* front = q.front();
                q.pop();
                
                //three conditions
                if(front-> left && !visited[front-> left]){
                    flag = true  ;
                    q.push(front-> left) ;
                    visited[front-> left] = true ;
                }
                
                if(front-> right && !visited[front-> right]){
                    flag = true  ;
                    q.push(front-> right) ;
                    visited[front-> right] = true ;
                }
                
                if(nodeToparent[front] && !visited[nodeToparent[front]]){
                    flag = true  ;
                    q.push(nodeToparent[front]) ;
                    visited[nodeToparent[front]] = true ;
                }
            }
            
            if(flag == true){
                times++ ;
            }
        }
        
        return times ;
        
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        //steps
        //1- nodeToparent mapping
        //2- find target Node
        //3- increase time
        
        int ans = 0 ;
        
        //mapping coz hame parent wale node ka track rakhna kha taki ham use bhi burn kar sake from targetnode
        map<Node*,Node*> nodeToparent ;
        Node* targetNode = NodeToParentMapping(root , nodeToparent , target) ;
        
        ans = burnTree(targetNode , nodeToparent) ;
        
        return ans ;
    }
};
