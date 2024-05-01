#include <iostream>

// Insertion sort function to sort individual buckets
void insertionSort(float bucket[], int size) {
    for (int i = 1; i < size; ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n) {
    // 1) Create n empty buckets
    const int numBuckets = n;
    const int bucketSize = 1000; // Assuming range of input is [0, 1)
    float b[numBuckets][bucketSize];
    int bucketIndex[numBuckets] = {0};

    // 2) Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi][bucketIndex[bi]++] = arr[i];
    }

    // 3) Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++) {
        insertionSort(b[i], bucketIndex[i]);
    }

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketIndex[i]; j++) {
            arr[index++] = b[i][j];
        }
    }
}

// Driver program to test above function
int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    std::cout << "Sorted array is \n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}