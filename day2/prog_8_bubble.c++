#include<iostream>
using namespace std;

int bubble(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<"The Sorted  Array is : ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {55,41,24,36,8,94,25,05,16,34,85,7,6,14,25,73,61,86,92,04,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble(arr,n);

}