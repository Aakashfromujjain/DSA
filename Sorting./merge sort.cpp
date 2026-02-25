#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Use logical AND (&&)
    while (left <= mid && right <= high) {
        // Compare against arr[right], not arr[high]
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    } // The main while loop MUST end here

    // These loops gather the remaining elements from either half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the sorted temp array back into the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mS(vector<int>& arr, int low, int high) {
    if (low >= high) return; // Base case
    
    int mid = (low + high) / 2;
    
    // Sort the left half (low to mid, NOT low to high)
    mS(arr, low, mid); 
    // Sort the right half
    mS(arr, mid + 1, high);
    
    // Merge them together
    merge(arr, low, mid, high);
}

void mergeSort(vector<int>& arr, int n) {
    mS(arr, 0, n - 1);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Pass 'n' instead of a hardcoded '4'
    mergeSort(arr, n);
    
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << "  ";
    }
    
    return 0;
}
