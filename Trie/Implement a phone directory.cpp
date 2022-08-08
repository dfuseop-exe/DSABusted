class trieNode {
    public :
        char data ;
        trieNode* children[26] ;
        bool isterminal ;

        trieNode(char ch){
            data = ch ;
            for(int i = 0; i < 26 ; i++){
                children[i] = NULL ;
            }
            //used to know where word is terminated
            isterminal = false ;
        }
};
class Trie{
    public :
//create a root node first 
        trieNode* root ;
        
        Trie(){
            root = new trieNode('\0') ;
        }
    

        void insertUtil(trieNode* root , string word){
            //base case 
            if(word.length() == 0){
                //it means all word is inserted so now set isterminal as true 
                root-> isterminal = true ;
                                
                return ;
            }


            //find index of first char of word
            int index = word[0] - 'a' ;

            trieNode* child ;

            //now check is present or absent 
            if(root-> children[index] != NULL){
                //means that character is present as children for root node
                //here just aage bdh jao
                child = root-> children[index] ;
            }else{
                //means absent
                //create kro nd aage bgh jao 
                child = new trieNode(word[0]) ;
                root-> children[index] = child ;
                
            }

            //remaining recursion will handle 
            insertUtil(child ,word.substr(1)) ;
        }

        void insertWord(string word){
            insertUtil(root, word);
        }
    
    
        void printsuggestion(trieNode* curr , vector<string> &temp , string prefix){
    //base case when to fall back - if node is terminal node
    if(curr-> isterminal){
        temp.push_back(prefix) ;
    }
    
    for(int ch = 'a' ; ch < 'z' ; ch++){
        trieNode* next = curr-> children[ch - 'a'] ;
        
        if(next != NULL){
            prefix.push_back(ch) ;
            //recursive call
            printsuggestion(next , temp , prefix) ;
            //back track
            prefix.pop_back() ;
        }
    }
}

vector<vector<string>> getSuggestion (string str){
    
    //create prev ptr 
    trieNode* prev = root ;
    string prefix = "" ;
    vector<vector<string> > output ;
    
    
    for(int i = 0 ; i<str.length() ; i++){
        char lastchar = str[i] ;
        
        prefix.push_back(lastchar) ;
        
        
        //now check for suggestion is present or not
        trieNode* curr = prev-> children[lastchar - 'a'] ; 
            
        if(curr == NULL){
            break ;
        }
          
        vector<string> temp ;
        printsuggestion(curr , temp , prefix) ;
        output.push_back(temp) ;
        
        temp.clear() ;
        
        //move to child of prev 
        prev = curr ;
    }
    
    return output ;
}

};


vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie *t = new Trie() ;

    //insert in trie
    for(int i = 0 ; i<contactList.size() ; i++){
        t-> insertWord(contactList[i]) ;    
    }
    
    //find prefix present in contact or not
    return t-> getSuggestion(queryStr) ;    

}