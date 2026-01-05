#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

int main(){
    
    char s[] = "aaabbdd";
    int n = sizeof(s)/sizeof(s[0]) - 1;
    map<char, int> freq;
    
    for(int i = 0; i < n; i++){
        freq[s[i]]++;
    }
    int least = INT_MAX;
    for(auto it: freq){
        if(it.second < least){
            least = it.second;
        }
    }

    for(auto it: freq){
        if(it.second == least){
            cout<<"The least frequency of char is : "<<it.second<<" & char is : "<<it.first<<endl;
            break;
        }
    }
}