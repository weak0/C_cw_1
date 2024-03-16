#include  <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *arr, int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            if (arr[start] == arr[i] && start != i) {
                continue;
            }
            swap(&arr[start], &arr[i]);
            permute(arr, start + 1, end);
            swap(&arr[start], &arr[i]);
        }
    }
}

int main() {
    int arr[] = {1,  1, 2,};
    int n = sizeof(arr) / sizeof(arr[0]);
    permute(arr, 0, n - 1);
    return 0;
}