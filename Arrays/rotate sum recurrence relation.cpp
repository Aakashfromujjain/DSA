class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long n = nums.size();
        long totalSum = 0;
        long currentF = 0;

        // 1. Calculate the sum of all elements (S) and the initial F(0)
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            currentF += (long)i * nums[i];
        }

        long maxVal = currentF;

        // 2. Use the recurrence relation to find F(1) to F(n-1) in O(n)
        for (int i = 1; i < n; i++) {
            // F(k) = F(k-1) + S - n * nums[n-k]
            currentF = currentF + totalSum - n * nums[n - i];
            maxVal = max(maxVal, currentF);
        }

        return (int)maxVal;
    }
};
