#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);

    int arr[n];
    printf("------- Enter the array element ------\n");

    for(int i = 0; i < n; i++){
        printf("Enter element %d : ", i+1);
        scanf("%d",&arr[i]);
        printf("\n");
    }

    int t;
    printf("Enter the tergeted Element : ");
    scanf("%d", &t);

    int flag = 0;

    for(int i = 0; i < n; i++){
        if (arr[i] == t){
            printf("Element Found at : %d Index", i);
            flag++;
            break;
        }
    }
    if(flag == 0){
        printf("Element not found !!!");
    }
    return 0;
}