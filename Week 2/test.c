#include <stdio.h>

int main() {
    int n = 5;
    int arr[n];

    printf("Original order:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }

    printf("\nInverted order:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    return 0;
}
