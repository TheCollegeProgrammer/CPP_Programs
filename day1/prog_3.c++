#include<iostream>
using namespace std;
int main(){
    int j = 0;
    int arr[8] = {0,0,0,4,0,55,1,39};
    for(int i = 0; i < 8; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for(int i = 0; i < 8; i++)
        cout<<(arr[i])<<" ";
    
}