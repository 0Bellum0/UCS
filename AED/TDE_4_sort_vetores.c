#include <stdio.h>
#define N 1000

void bubbleSort(int arr[N]) {
    int i, j, temp;
    for (i = 0; i < N-1; i++) {
        for (j = 0; j < N-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void arrValues(int arr[N]){
    srand(time(NULL));
    int i, value;
    value = rand() % 1000;
    for(i=0; i<N; i++){
        arr[i] = value;
    }
}

void printArray(int arr[N]) {
    for (int i = 0; i < N; i++){
        if(i==N-1){
            printf("%d/n", arr[i]);
        }
        printf("%d, ", arr[i]);
        }
}

int main() {
    int arr[N];
    arrValues(arr);

    printf("Array original:\n");
    printArray(arr);

    bubbleSort(arr);

    printf("Array ordenado:\n");
    printArray(arr);

    return 0;
}