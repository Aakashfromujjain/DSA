#include <iostream>
using namespace std;

class Solution {
public:
    int findmaxconsecutive(int nums[], int n) {
        int max1 = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                cnt++;
                max1 = max(max1, cnt);
            } else {
                cnt = 0;
            }
        }
        return max1;
    }
};

int main() {
    int arr[] = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);   // length of array

    Solution S1;
    int result = S1.findmaxconsecutive(arr, n);
    cout << result;
}
