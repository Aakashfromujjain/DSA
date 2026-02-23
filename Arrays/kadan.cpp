#include <stdio.h>
#include <limits.h>

int maxSubarraySum(int arr[], int n) {
    int max_so_far = arr[0];  // Maximum sum found so far
    int max_ending_here = arr[0];  // Maximum sum ending at current position

    for (int i = 1; i < n; i++) {
        // Either extend the existing subarray or start a new one
        max_ending_here = (arr[i] > max_ending_here + arr[i]) ? arr[i] : max_ending_here + arr[i];
        // Update the global maximum
        max_so_far = (max_so_far > max_ending_here) ? max_so_far : max_ending_here;
    }

    return max_so_far;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum Subarray Sum is %d\n", maxSubarraySum(arr, n));
    return 0;
}   
