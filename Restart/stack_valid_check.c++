#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char> st;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        } 
        else {
            if(st.empty()) return false;

            if((s[i] == ')' && st.top() == '(') ||
               (s[i] == '}' && st.top() == '{') ||
               (s[i] == ']' && st.top() == '[')){
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty(); // stack empty hona chahiye
}

int main(){
    string s = "{[([{}])]}";

    if(isValid(s)){
        cout<<"Given String is Valid"<<endl;
    } else {
        cout<<"Given String is Invalid"<<endl;
    }
}