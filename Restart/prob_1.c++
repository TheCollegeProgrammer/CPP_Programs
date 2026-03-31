#include<iostream>
using namespace std;

int find(int arr[], int t, int size){
    for(int i = 0; i < size;i++){
        if(arr[i] == t){
            cout<< "Element found at : "<< i << endl;
        }
    }
}

void swap(int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void reverse_Arr(int arr[], int size){
    int a = 0;
    int b = size-1;
    for(int i = 0; i < size/2; i++){
        swap(&arr[a], &arr[b]);
        a++;
        b--;
    }
    cout<< "Reversed array is : ";
    for(int i = 0; i < size; i++){
        cout<< arr[i] << " ";
    }
    cout << endl;
}

int sum_N(int n){
    if(n == 1) return 1;
    return n + sum_N(n-1);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int t = 5;
    int size = sizeof(arr)/sizeof(int);
    find(arr,t,size);
    reverse_Arr(arr, size);
    cout << "The sum of N is : "<<sum_N(10);

}