#include<iostream>
using namespace std;
int main(){
    int n = 8;
    int arr[n] = {5,8,7,4,9,6,3,0};
    int min = arr[0];
    int max = arr[0];

    for(int i = 0; i < n; i++){
        if (min > arr[i]){
            min = arr[i];
        }
        if (max < arr[i]){
            max = arr[i];
        }
    }
    cout<<"The minimum value is : "<< min<<"\n";
    cout<<"The maximum value is : "<< max;
}