class trieNode{
    public:
    char data ;
    trieNode* children[26] ;
    int childCnt ;
    bool isterminator ;
    
    trieNode(char ch){
        data = ch ;
        for(int i = 0 ; i < 26 ; i++){
            children[i] = NULL ;
        }
        childCnt = 0 ;
        isterminator = false ;
    }
};


class Trie{
    public :
    
    trieNode* root ;
    
    Trie(){
        root = new trieNode('\0') ;
    }
    
    void insertUtil(trieNode* root , string word){
        //base case
        if(word.length() == 0){
            root-> isterminator = true ;
            return ;
        }
        
        int index = word[0] - 'a' ;
        trieNode* child ;
        
        if(root-> children[index] != NULL){
            child = root -> children[index] ;
        }else{
            root->childCnt++ ;
            child = new trieNode(word[0]) ;
            root-> children[index] = child ;
        }
        
        insertUtil(child , word.substr(1)) ;    
    }
    
    void insertWord(string word){
        insertUtil(root , word) ;
    }
    
    
    void getPrefix(string word , string &ans){
        //first word che node la one by one traverse karun check karaych ki childcount kitiy tyancha if 1 asel tr tyala store karaych else break and alse check isterminal condtion
        for(int i = 0 ; i < word.length() ; i++){
            char ch = word[i] ;
            
            //last element hua string ka to bhi break 
            if(root-> isterminator){
                break ;
            }
            
            if(root-> childCnt == 1){
                ans.push_back(ch) ;
                
                //ek node process jhal ki child node la mhanj next letter jikde store aahe tya position la janya sathi
                //aage bdh jao
                int index = ch - 'a' ;
                root = root-> children[index] ;
            }else{
                 break ;
            }
            

        }
    }

    void getPrefixUtil(string word , string &ans , trieNode* root){
        //base case
        if(word.length() == 0 || root-> isterminator == true){
            return  ;
        }
        
        char ch = word[0]  ;
        int index = ch - 'a' ;
        trieNode* child = root-> children[index] ;
        if(root-> childCnt == 1){
            ans.push_back(ch) ;
            getPrefixUtil(word.substr(1) , ans , child) ;
        }else{
            return ;
        }
    }    
     
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *t = new Trie();
        
        for(int i = 0 ; i <strs.size() ; i++){
            t-> insertWord(strs[i]) ;
        }  
        
        string first = strs[0] ;
        string ans = "" ;
        
        t-> getPrefix(first , ans) ;
        
        return ans ;
    }
};