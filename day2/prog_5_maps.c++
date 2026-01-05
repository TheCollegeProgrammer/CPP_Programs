#include<iostream>
#include<map>
using namespace std;

int main(){
    int n = 38;
    int arr[] = {7,5,4,3,9,2,5,7,4,9,8,6,5,4,8,7,5,6,4,2,5,4,3,6,8,5,4,7,5,6,9,8,5,4,7,5,8,6};

    map<int, int> freq;

    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    for(auto it: freq){
        cout<< it.first <<" -> "<< it.second << endl;
    }
}