/Statement: Given an array of 1s and 0s which has all 
//1s first followed by all 0s? Find the number of 0s. 
//Count the number of zeroes in the given array.

#include <iostream>

// Function to find the index of the first occurrence of 0
int findFirstZeroIndex(const int arr[], int low, int high) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    // If mid is the first zero
    if (arr[mid] == 0 && (mid == 0 || arr[mid - 1] == 1)) {
        return mid;
    }

    // If the mid is 1, search in the right half
    if (arr[mid] == 1) {
        return findFirstZeroIndex(arr, mid + 1, high);
    }

    // Otherwise, search in the left half
    return findFirstZeroIndex(arr, low, mid - 1);
}

// Function to count the number of zeroes in the array
int countZeroes(const int arr[], int size) {
    int firstZeroIndex = findFirstZeroIndex(arr, 0, size - 1);

    // If no zero is found, return 0
    if (firstZeroIndex == -1) {
        return 0;
    }

    // Total number of zeroes is the total length of the array minus the index of the first zero
    return size - firstZeroIndex;
}

int main() {
    int arr1[] = {1, 1, 1, 1, 0, 0};
    int arr2[] = {1, 0, 0, 0, 0};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "Number of zeroes in arr1: " << countZeroes(arr1, size1) << std::endl;  // Output: 2
    std::cout << "Number of zeroes in arr2: " << countZeroes(arr2, size2) << std::endl;  // Output: 4

    return 0;
}