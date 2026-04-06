#include<iostream>
#include<stack>
using namespace std;

stack<int> curr_st;
stack<int> min_st;

void push(int val){
    curr_st.push(val);

    if(min_st.empty() || val <= min_st.top()){
        min_st.push(val);
    }else{
        min_st.push(min_st.top());
    }
}
void pop(){
    if(!curr_st.empty()){
        curr_st.pop();
        min_st.pop();
    }
}
int top(){
    return curr_st.top();
}
int getmin(){
    return min_st.top();
} 


int main(){
    int arr[] = {84,667,55,48,35,2,35,6,4,7,1,25,48};
    int size = 13;
    for(int i = 0; i < size; i++){
        push(arr[i]);
    }
    cout<<"Minimum Element is : "<<getmin()<<endl;
}