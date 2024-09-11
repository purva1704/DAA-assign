//Implement a problem of move all zeroes to end of 
//array.
//Statement: Given an array of random numbers, Push all the zero’s 
//of a given array to the end of the array. For example, if the given 
//arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 
//8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be 
//same.


#include <iostream>

// Function to move zeroes to the end of the array using divide and conquer
void moveZeroesToEnd(int arr[], int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;

    // Process the left half
    moveZeroesToEnd(arr, low, mid);
    // Process the right half
    moveZeroesToEnd(arr, mid + 1, high);

    // Merge the two halves
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    int left[leftSize];
    int right[rightSize];

    // Copy elements to temporary arrays
    for (int i = 0; i < leftSize; ++i) {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < rightSize; ++i) {
        right[i] = arr[mid + 1 + i];
    }

    // Merge the two halves with zeroes moved to the end
    int leftIndex = 0, rightIndex = 0, mergeIndex = low;

    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (left[leftIndex] != 0) {
            arr[mergeIndex++] = left[leftIndex++];
        } else {
            leftIndex++;
        }
    }

    while (rightIndex < rightSize) {
        if (right[rightIndex] != 0) {
            arr[mergeIndex++] = right[rightIndex++];
        } else {
            rightIndex++;
        }
    }

    // Fill remaining positions with zeroes
    while (mergeIndex <= high) {
        arr[mergeIndex++] = 0;
    }
}

int main() {
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    moveZeroesToEnd(arr, 0, size - 1);

    std::cout << "Array after moving zeroes to the end: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}