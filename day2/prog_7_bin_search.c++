#include<iostream>
using namespace std;
int bin_search(int arr[],int n,int target){
    int b = 0; 
    int e = n-1;
    while(b <= e){
        int mid = b+(e-b)/2;
        if(arr[mid] == target){
            return mid+1;
        }
        else if(arr[mid] > target){
            e = mid - 1;
        }else {
            b = mid + 1;
        }
    }
    return -1;
    
}
int main(){
    int arr[] = {15,24,36,42,55,65,71,84,97};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 42;

    cout<<"The index of Targeted Element is : "<<bin_search(arr,n,target)<<endl;

}