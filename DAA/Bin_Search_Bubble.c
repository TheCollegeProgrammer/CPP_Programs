#include<stdio.h>

int main(){
    int comparision = 0;
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
        for(int j = i+1; j < n; j++){
            int temp = 0;
            comparision++;
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("The array is  : \n");
    for(int i = 0; i < n; i++){
        comparision++;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // binary search
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        comparision++;

        if (arr[mid] == t) {
            printf("Element found at index %d\n", mid);
            flag = 1;
            break;
        }
        else if (arr[mid] < t) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (flag == 0) {
        printf("Element not found\n");
    }

    printf("The Comparision is : %d\n", comparision);
    float avg_comparision = comparision/n;
    printf("the Average Comparision is : %.2f", avg_comparision);


    return 0;
}