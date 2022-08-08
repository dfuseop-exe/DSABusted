#include<iostream>
using namespace std;

//our trie node
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
        
        //we want to iterate over all children thats why we looking for next children 
        if(root-> children[index] != NULL){
            child = root -> children[index] ;
        }else{
            root->childCnt++ ;
            child = new trieNode(word[0]) ;
            root-> children[index] = child ;
        }
        
        //from this we traverse next root 
        insertUtil(child , word.substr(1)) ;    
    }
    
    void insertWord(string word){
        insertUtil(root , word) ;
    }

        bool searchUtil(trieNode* root , string word){
            //base case: search 
            if(word.length() == 0){
                
                //word is full present but check this is terminal node for this word or not 
                bool ans = root-> isterminal ; 
                return ans ;
            }

            int index = word[0] - 'A' ;
            trieNode* child ;

            if(root-> children[index] != NULL){
                //present 
                child = root-> children[index] ;
                
            }else{
                //absent 

                return false ;
            }

            return searchUtil(child , word.substr(1)) ;
        }

        bool searchWord(string word){
            bool ans = searchUtil(root , word);
            return ans ;
        }


            void deleteUtil(trieNode* root , string word  ){
            //base case: search 
            if(word.length() == 0){
                //word is full present but check this is terminal node for this word or not 
                root-> isterminal = false ; 
                return  ;
            }

            int index = word[0] - 'A' ;
            trieNode* child ;

            if(root-> children[index] != NULL){
                //present 
                child = root-> children[index] ;
                
            }

            deleteUtil(child , word.substr(1) ) ;
        }

        void deleteWord(string word){
            deleteUtil(root, word) ;
        }
};

int main(){
    Trie *t = new Trie();

    t-> insertWord("ARM") ;
    t-> insertWord("TIME") ;
    t-> insertWord("DO") ;
    

    cout<<"this word is present or not ? "<< t-> searchWord("ARM") <<endl;
    cout<<"this word is present or not ? "<< t-> searchWord("TIME") <<endl;

    cout<<"this word is present or not ? "<< t-> searchWord("TIM<") <<endl;
    cout<<"this word is present or not ? "<< t-> searchWord("DOM") <<endl;
    t-> deleteWord("ARM") ;
    t-> deleteWord("TIME") ;
    cout<<"this word is present or not ? "<< t-> searchWord("TIM") <<endl;
    cout<<"this word is present or not ? "<< t-> searchWord("ARM") <<endl;
    t-> insertWord("ARM") ;
    cout<<"this word is present or not ? "<< t-> searchWord("ARM") <<endl;




}
