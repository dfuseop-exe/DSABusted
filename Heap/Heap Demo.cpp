#include<iostream>
using namespace std;

//max heap
class heap{
    public:
        int arr[100] ;
        int size ;

        heap(){
            size = 0 ;
            arr[0] = -1 ;
        }

        void insert(int val){
            size = size + 1 ;
            int index = size ;

            arr[index] = val ;

        // bottom to top rearrange by finding parent
            while(index > 1){
                int parent = index / 2 ;
                if(arr[index] > arr[parent]){
                    //swap
                    swap(arr[index], arr[parent]) ;
                    index = parent ; //for base case
                }else{
                    return  ;
                }
            }
        }

        void deleteFromHeap(){
            if(size == 0){
                cout<<"Heap is empty"<<endl;
                return ;
            }

            //step 1 -  swap root node and child node value 
            arr[1] = arr[size] ;

            //step 2 - remove last node
            size-- ;

            int i = 1 ; //root on 1st index

            //step 3 - propagate root node on its correct position
            //top to bottom rearrange by finding child
            while(i<size){
                //take child 
                int leftchild = 2 * i ;
                int rightchild = 2 * i + 1 ;

                if(leftchild < size && arr[i] < arr[leftchild]){
                    swap(arr[i], arr[leftchild]); ;
                    i = leftchild ;
                }else if(rightchild < size && arr[i] < arr[rightchild]){
                    swap(arr[i] , arr[rightchild]) ;
                    i = rightchild ;
                }else{
                    return ;
                }
            }
        }


        
        void print(){
            for(int i = 1 ; i <= size ; i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }

       

      
};



void heapify(int arr[] , int n , int i){
            //current item
            int largest = i ;


            int left = 2 * i;
            int right = 2 * i + 1 ;

            //check kel ki largest item mhanj current node ha lahan tr nhi na child peksha asel tr tyala current code kel  
            if(left <= n && arr[left] > arr[largest]){
                largest = left ;
            }

            if(right <= n && arr[right] > arr[largest]){
                largest = right ;
            }

            //and mag current nd child madhe jr child asel largest tr mg largest update jhala asel mg current la swap kel with large child 

            if(largest != i){
                cout<<largest<<endl;
                swap(arr[largest], arr[i]) ;
                heapify(arr , n , largest) ;
            }
        }

void heapSort(int arr[] , int n){
            int size = n ;
            while(size > 1){
                swap(arr[size] , arr[1]) ;
                size-- ;
                heapify(arr , size , 1) ;
            }
        }
int main(){
    heap h ;
    h.insert(35) ;
    h.insert(40) ;
    h.insert(32) ;
    h.insert(45) ;
    h.insert(50) ;

    h.print() ;

    int arr[6] = {-1 , 54 , 53 , 55 , 52 , 50} ;
    int n = 5 ;

   for(int i = n/2 ; i>0 ; i--){
        heapify(arr , n , i) ;
    }

    cout<<"Before sort"<<endl ;
     for(int i = 1 ; i <= n ; i++){
                cout<<arr[i]<<" ";
    }cout<<endl;

 

    //h.deleteFromHeap() ;
    heapSort(arr , n) ;

    cout<<"after sort"<<endl ;
    for(int i = 1 ; i <= n ; i++){
                cout<<arr[i]<<" ";
    }cout<<endl;
    // h.print() ;
}