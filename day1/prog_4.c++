#include<iostream>
using namespace std;

int main(){
    int n = 4;
    // int arr[] = {4,7,5,9,3,2,6,1};
    int arr[] = {5, 5, 5, 5};

    int fstl = arr[0];
    int secl = arr[0];
    
    for(int i = 1; i < n; i++) {
        if(arr[i] > fstl) {
            secl = fstl;
            fstl = arr[i];
        }
        else if(arr[i] < fstl && arr[i] > secl) {
            secl = arr[i];
        }
    }
    cout<<"The first lastest No. is : "<<fstl<<"\n";
    cout<<"The Second Largest No. is : "<<secl;
}