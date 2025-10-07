#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (sorted for binary search): ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    int lin = linearSearch(arr, n, key);
    int bin = binarySearch(arr, n, key);

    if (lin != -1) printf("Linear Search: Found at index %d\n", lin);
    else printf("Linear Search: Not found\n");

    if (bin != -1) printf("Binary Search: Found at index %d\n", bin);
    else printf("Binary Search: Not found\n");
}
