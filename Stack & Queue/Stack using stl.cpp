#include<stack>
#include<iostream>

using namespace std;

int main(){
    stack<int> st ;

    st.push(1);
    st.push(21);
    st.push(2);
    st.pop();

    cout << st.top() << endl;
    cout<<"is empty ? "<<st.empty()<<endl;
}