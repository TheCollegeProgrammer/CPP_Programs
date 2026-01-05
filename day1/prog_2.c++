#include<iostream>
using namespace std;

int main(){
    int n = 9;
    int arr[n] = {4,8,7,6,4,8,5,2,9};

    int left = 0;
    int right = n-1;

    while(left < right){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}